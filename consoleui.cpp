#include "main.h"
#include "consoleui.h"
#include "cvs.cpp"

ConsoleUI::ConsoleUI()
{
}



searchdef ConsoleUI::DefineSearch()
{

    cout << "\nHow shall I sort the results:" << endl
         << "0: By ID" << endl
         << "1: By name" << endl
         << "2: By gender" << endl
         << "3: By year born" << endl
         << "4: By year died" << endl
         << "";
   int sortby, sort;
   QString input = cin.readLine();
   int inputid = input.toInt();
   switch (inputid)
   {
       case(1): case(2): case(3): case(4):
        sortby = SORTY_BY[inputid];
       break;
       case(0): default:
        sortby = SORT_BY_ID; break;
   }


   cout << "\nSort by accending or descending?" << endl
        << "1: Asscending" << endl
        << "2: Descending" << endl;

   input = cin.readLine();
   inputid = input.toInt();
   switch(inputid)
   {
    case (2):
        sort = SORT_DESCENDING; break;
    case(1): default:
        sort = SORT_ASCENDING;
    }

    return searchdef(sortby, sort);
}

void ConsoleUI::Delete()
{
    cout << "Enter id of entry to delete: " << endl;
    int idDelete = cin.readLine().toInt();
    gogn.remove_person(idDelete);
}


void ConsoleUI::Print(QVector<person> result)
{

    foreach(person item, result)
    {
       QString gender;
       QString died;
       if(item.gender == 0) gender = "Male";
       else gender = "Female";
       if (item.year_death == 0) died = " is still alive and computing";
       else {
           died = QString::number(item.year_death);
       }

       cout << endl << "ID: " << item.id << "\n"
       << "Name: " << item.name << "\n"
       << "Gender: " << gender << "\n"
       << "Year born: " << item.year_born << "\t"
       << "Year died: " << died << endl;
    }
       cout << "_____" << endl;
}

void ConsoleUI::List()
{
    searchdef search = DefineSearch();
    QVector<person> results =   gogn.query(GET_ALL, QString(""),
                                search.sort, search.sortby);
    Print(results);
}



void ConsoleUI::AddPerson()
{
    cout << "\nEnter name:" << endl;
    QString name = cin.readLine();

    if (name.isEmpty())
    {
        cout << "\nPlease type a name" << endl;
        return;
    }

    cout << "\nEnter gender (0 male, 1 female):" << endl;
    int gender= cin.readLine().toInt();
    QString genderstring = 0 ? "Female" : "Male";
    cout << endl << "Enter year born:" << endl;
    int yearborn = cin.readLine().toInt();

    if (gender == 0) cout << "Is he dead? (y/n Y/N)" << endl;
    else cout << "Is she dead? (y/n Y/N)" << endl;
    QString yn = cin.readLine();
    int yeardead;

    if (yn == "Y" || yn == "y")
    {
        cout << "\nEnter year dead:"<< endl;
        yeardead = cin.readLine().toInt();
    }
    else
    {
        yeardead = -1;
    }

    if (yearborn == yeardead || yeardead < yearborn)
    {
        /* Afsakið hrokann en hér gerum við ráð fyrir því að fólk sem nær ekki að
         * að verða ársgamalt geti orðið frægt í tölvugeiranum */
        cout << "Year born and year dead are incorrect. Please fix. " << endl << endl;
        return;
    }

    if (yearborn < 1500 || yeardead <1500 )
    {
        cout << "Please check if your years are correct! " << endl << endl;
    }

    yeardead = -1 ? yeardead : 0;

    QString yeardeadstring = 0 ? QString::number(yeardead) : "Still alive";

    cout
         << "Name: " << name << endl
         << "Gender: "  << genderstring << endl
         << "Year born " << yearborn << endl
         << "Year dead: " << yeardeadstring << endl
         << "Do you wish to insert this entry: (y/n Y/N)" << endl;
    yn = cin.readLine();
    if (yn == "Y" || yn == "y")
    {
        gogn.add_person(name, gender, yearborn, yeardead);
        cout << "\nPerson added!" << endl;
    }
    else
        return;
}

void ConsoleUI::Search()
{
    cout << "\nSearch" << endl
         << "0: in field id" << endl
         << "1: in field name" << endl
         << "2: in field gender" << endl
         << "3: in field year born" << endl
         << "4: in field year died" << endl;

   QString input = cin.readLine();
   int inputid = input.toInt();
   if (inputid > 4 || inputid < 0 ) inputid = 1;
   inputid = GET_BY[inputid];

   cout << "\nEnter search text:" << endl;

   QString searchstring = cin.readLine();

   searchdef search = DefineSearch();
   QVector<person> results =   gogn.query(inputid, searchstring,
                               search.sort, search.sortby);
   Print(results);


}

void ConsoleUI::loadfile()
{
    /* Opna skrá */
    cout << "Open file: " << FILENAME << endl ;
    QVector<QStringList> list = openCSVfile();

    if (list.empty()) cout << "File does not exist or is empty!" << endl;
    else cout << "Imported " << list.count() << " entrie(s) " << endl;
    cout << endl;

    gogn.insertlist(list);
}

void ConsoleUI::savefile()
{
    cout << "Saving to file: " << FILENAME << endl;
    saveCSVfile(gogn.query());
    cout << endl;
}

void ConsoleUI::quitmsg()
{
    cout << endl;
    cout << "Goodbye! " << endl;
    cout << endl;
}


void ConsoleUI::start()
{
    loadfile();

    while(1){
    cout << "Welcome!" << endl
         << "Choose one of the following:" << endl
         << "1. List" << endl
         << "2. Search" << endl
         << "3. Insert person" << endl
         << "4. Delete person" << endl
         << "5. Save and quit" << endl
         << "6. Quit" << endl;
    int inputid = cin.readLine().toInt();



    switch(inputid){
    case 1: List();
        break;
    case 2: Search();
        break;
    case 3: AddPerson();
        break;
    case 4: Delete();
        break;
    case 5:
        savefile();
    case 6:
        quitmsg();
        return;
        break;
    default:
        cout << "Invalid input." << endl;
        break;
    }
    cout << endl;
}
}

QTextStream cout(stdout);
QTextStream cin(stdin);



