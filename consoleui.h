#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <string>
#include <iostream>

class ConsoleUI
{
public:
    ConsoleUI();
    void start();
private:
    void List();
    void Search();
    void AddPerson();
};

#endif // CONSOLEUI_H
