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
    cout << "ID\tName\t\t\t\tGender\tBorn\tDied" << endl;
    cout << "_______________________________________________________________________" << endl;

    foreach(person item, result)
    {
       QString gender;
       QString died;
       if(item.gender == 0) gender = "Male";
       else gender = "Female";
       if (item.year_death == 0) died = "-";
       else {
           died = QString::number(item.year_death);
       }


       cout << item.id << "\t"
            << item.name << "\t\t\t"
            << gender << "\t"
            << item.year_born << "\t"
            << died << endl;

//       cout << endl << "ID: " << item.id << "\n"
//       << "Name: " << item.name << "\n"
//       << "Gender: " << gender << "\n"
//       << "Year born: " << item.year_born << "\t"
//       << "Year died: " << died << endl;
    }
       cout << "_______________________________________________________________________" << endl;
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

    if ((yearborn == yeardead || yeardead < yearborn) && yeardead != -1)
    {
        /* Afsakið hrokann en hér gerum við ráð fyrir því að fólk sem nær ekki að
         * að verða ársgamalt geti orðið frægt í tölvugeiranum */
        cout << "Year born and year dead are incorrect. Please fix. " << endl << endl;
        return;
    }

    if (yearborn < 1500 || (yeardead <1500 && yeardead != -1) )
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


/*
    1: List
        1: Person				1: ID 2: Name 3: Gender 4: Born 5: Death					1: ASCENDING 2: DESCENDING
        2: Computer				1: ID 2: Name 3: Type 4: YearBuilt 5: Builtornot-Y/N			1: ASC 2: DESC
        3: Connection			1: Computers -> 1: ID -> COMPUTERNAME was made by PERSONS... 2: Persons -> 1:ID.. -> PERSONNAME made COMPUTERNAME

    2: Search
        1: Person				By 1: ID 2: Name 3: Gender 4: YearBorn 5: YearDeath
        2: Computer				By 1: ID 2: Name 3: Type 4: YearBuilt 5: Builtornot
        3: Connection			By 1: Computername ( Computer was built by Persons_name), 2: Persons_name(has built computers_name)


    3: Insert
        1: Person				Enter name, Enter Gender(0 male, 1 female), Enter year born, Enter year dead
        2: Computer 			Enter name, enter type, enter year built (Electronic 0,Mechanical 1,Electro-mechanical 2,
                                Transistor 3, Other 4), was it built? Y/N,

        3: Connection			By 1: Computer ID 2: Person ID
                                If 1: Enter the Computer's ID you want to connect to a person.	-> Enter Computer ID -> Now enter the person's ID you want to connect to COMPUTERNAME
                                If 2: Enter the Person's ID you want to connect to a computer. -> Enter Persons ID -> Now enter the computer's ID you want to connect to PERSONNAME
    4: Delete
        1: Person				Enter the ID of the person you want to delete.
        2: Computer				Enter the ID of the computer you want to delete.
        3: Connection			Enter the ID of the computer which connection you want to delete.

    5: Save

    6: Quit


*/



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


        /*
         * Bara til að hafa hvernig við hugsum að þetta eigi að líta út
         *
         *      cout << "Welcome!" << endl
             << "Choose one of the following:" << endl
             << "1. List" << endl
             << "2. Search" << endl
             << "3. Insert <<endl
             << "4. Delete" << endl
             << "5. Save" << endl
             << "6. Quit" << endl;


             if (input = 1)

       ( cout<<"\nList"<<endl
        <<"0: the computers
        <<"1: the persons
        <<2: both
        <<3: by owners
        Og útfrá þessu verður:
        Input = 0
        <<"0: by year built
        <<"1: built or not
        <<"2: by id
        <<"3: by name
        <<"4: by type)


       ( Input ==1
        Eins og áður nema viðbættum möguleiki af
        <<5: by computers built )

        Input == 2
        //cout<< "\nSearch << endl
         //<<"0: by computers
         //<<"1: by person
         //<<"2: owner by id
        Sjá fyrir ofan
    *
    * Input == 3
    * (cout<< "\nInsert << endl
         <<"0: computer
         <<"1: person
         <<"2: owner )


         Insert == 4

       ( cout<<"\nDelete"<<endl
        <<"0: a computer
        <<"1: a person
        <<2:  a owner )

                */


        while(1){
        cout << "Welcome!" << endl
             << "Choose one of the following:" << endl
             << "1. List" << endl
             << "2. Search" << endl
             << "3. Insert person" << endl
             << "4. Delete person" << endl
             << "5. Save" << endl
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
            break;
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



