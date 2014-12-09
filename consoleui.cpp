#include "main.h"
#include "consoleui.h"

ConsoleUI::ConsoleUI()
{
}


/* searchdef ConsoleUI::DefineSearch()
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
*/
void ConsoleUI::Delete()
{
    cout << "What do you want to delete?" << endl
         << "0: Person" << endl
         << "1: Computer" << endl
         << "2: Connection" << endl;
    int pickdelete = cin.readLine().toInt();

    cout << "What ID do you want to delete?" << endl;
    int deleteID = cin.readLine().toInt();

    switch(pickdelete){
    case 0: DeletePerson(deleteID);
        break;
    case 1: DeleteComputer(deleteID);
        break;
    case 2: DeleteConnection(deleteID);
        break;
    default:
        cout << "Invalid input." << endl;
        break;

    }

}

void ConsoleUI::DeletePerson(int deleteID)
{

}
void ConsoleUI::DeleteComputer(int deleteID)
{

}
void ConsoleUI::DeleteConnection(int deleteID)
{

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
    cout << "What list would you like to display" << endl
         << "0: Person" << endl
         << "1: Computer" << endl
         << "2: Connection" << endl;
    int picklist = cin.readLine().toInt();

    switch(picklist){
    case 0: ListPerson();
        break;
    case 1: ListComputer();
        break;
    case 2: ListConnection();
        break;
    default:
        cout << "Invalid input." << endl;
        break;
    }


}

void ConsoleUI::ListPerson()
{
    searchdef search = DefineSearch();
    QVector<person> results =   gogn.query(GET_ALL, QString(""),
                                search.sort, search.sortby);
    Print(results);
}

void ConsoleUI::ListComputer()
{

}

void ConsoleUI::ListConnection()
{

}

void ConsoleUI::Add()
{

    cout << "\nInsert" << endl
         << "0: Person" << endl
         << "1: Computer" << endl
         << "2: Connection"<<endl;
    int input = cin.readLine().toInt();



    switch(input){
    case 0: AddPerson();
        break;
    case 1: AddComputer();
        break;
    case 2: AddConnection();
        break;

    default:
        cout << "Invalid input." << endl;
        break;
    }
    cout << endl;
}
void ConsoleUI::AddComputer(){
    cout << "\nEnter name:" << endl;
    QString Computers_name = cin.readLine();

    cout << "\nEnter type: \n0: Electronic \n1: Mechanical \n2: Electro-mechanical \n3: Transistor \n4: Other" << endl;
    int Computers_type = cin.readLine().toInt();

    cout << "\nEnter year it was built:" << endl;
    int Computers_yearbuilt = cin.readLine().toInt();

    cout << "\nWas it built? (y/n Y/N):" << endl;
    int Computers_builtornot = cin.readLine().toInt();

}
void ConsoleUI::AddConnection() {


    cout <<"\nEnter how you want to create a connection"<<endl
         << "0: By person ID" << endl
         << "1: By computer ID" << endl;

    int connect = cin.readLine().toInt();

    switch(connect){
    case 0: connectionperson();
        break;
    case 1: connectioncomputer();
        break;
    default:
        cout << "Invalid input." << endl;
        break;
    }
    cout << endl;
}
void ConsoleUI::PersonConnection()
{
    cout << "Enter the Person's ID you want to connect to a computer." << endl;
    int PERSONID = cin.readLine().toInt();
    cout << "Now enter the computer's ID you want to connect to " /*<< PERSONNAME*/ /*ÞARF AÐ REDDSSU*/ << endl;
    int COMPUTERID = cin.readLine().toInt();
}
void ConsoleUI::ComputerConnection()
{
    cout << "Enter the Computer's ID you want to connect to a person." << endl;
    int COMPUTERID = cin.readLine().toInt();
    cout << "Now enter the person's ID you want to connect to " /*<< COMPUTERNAME*/ /*ÞARF AÐ REDDSSU*/ << endl;
    int PERSONID = cin.readLine().toInt();
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

    QString yn;
    if (gender == 0) cout << "Is he dead? (y/n Y/N)" << endl;
    else cout << "Is she dead? (y/n Y/N)" << endl;
    yn = cin.readLine();
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


    QString yeardeadstring;

    if (yn == "Y" || yn == "y"){
        yeardeadstring = QString::number(yeardead);
    }
    else
    {
        yeardeadstring = "Still alive";
    }

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
    cout << "What do you want to search for?" << endl
         << "0: A person" << endl
         << "1: A computer" << endl
         << "2: A connection" << endl;

    int SearchInput = cin.readLine().toInt();

    switch(SearchInput){
    case 0: SearchPerson();
        break;
    case 1: SearchComputer();
        break;
    case 2: SearchConnection();
        break;
    default:
        cout << "Invalid input." << endl;
        break;
    }

    /*
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
    */

    }

void ConsoleUI::SearchPerson()
{
}
void ConsoleUI::SearchComputer()
{
}
void ConsoleUI::SearchConnection()
{
}


    void ConsoleUI::quitmsg()
    {
        cout << endl;
        cout << "Goodbye! " << endl;
        cout << endl;
    }


    void ConsoleUI::start()
    {

        while(1){
        cout << "Welcome!" << endl
             << "Choose one of the following:" << endl
             << "1. List" << endl
             << "2. Search" << endl
             << "3. Insert " << endl
             << "4. Delete " << endl
             << "5. Quit" << endl;
        int inputid = cin.readLine().toInt();



        switch(inputid){
        case 1: List();
            break;
        case 2: Search();
            break;
        case 3: Add();
            break;
        case 4: Delete();
            break;
        case 5:
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



