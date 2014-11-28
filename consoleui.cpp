#include "consoleui.h"

using namespace std;

ConsoleUI::ConsoleUI()
{
}

void ConsoleUI::List()
{}
void ConsoleUI::AddPerson()
{}
void ConsoleUI::Search()
{}

void ConsoleUI::start() {
    int input;

    while(1){
    cout << "Welcome!\nChoose one of the following:\n1. List\n2. Search\n3. Insert person\n4. Quit" << endl;

    cin >> input;

    switch(input){
    case 1: List();
        break;
    case 2: Search();
        break;
    case 3: AddPerson();
        break;
    case 4: return;
        break;
    default:
        cout << "Invalid input." << endl;
        break;
    }
    cout << endl;
}
}



