#include "main.h"
#include "sk1data.h"
#include "consoleui.h"


ConsoleUI::ConsoleUI()
{
}



searchdef ConsoleUI::DefineSearch()
{

    cout << "\nHow shall I sort the results:" << endl
         << "0: By id" << endl
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
       if(item.gender == 0) gender = "Male";
       else gender = "Female";

       cout << "id:" << item.id << "\t"
       << "name:" << item.name << "\t"
       << "gender:" << gender << "\t"
       << "year born:" << item.year_born << "\t"
       << "year died:" << item.year_death << endl;
    }
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

    cout << "\nEnter gender (0 male, 1 female):" << endl;
    int gender= cin.readLine().toInt();

    cout << endl << "Enter year born:" << endl;
    int yearborn = cin.readLine().toInt();

    cout << "\nEnter year dead:"<< endl;
    int yeardead = cin.readLine().toInt();

    gogn.add_person(name, gender, yearborn, yeardead);

    cout << "\nPerson added!" << endl;

}

void ConsoleUI::Search()
{
    cout << "\nSearch" << QString::fromUtf8("…") << endl
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

void ConsoleUI::start() {


    while(1){
    cout << "Welcome!" << endl
         << "Choose one of the following:" << endl
         << "1. List" << endl
         << "2. Search" << endl
         << "3. Insert person" << endl
         << "4. Delete person" << endl
         << "5. Quit" << endl;

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
    case 5: return;
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



