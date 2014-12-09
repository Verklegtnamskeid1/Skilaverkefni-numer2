#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "sk2data.h"

struct searchdef
{
    int sort;
    int sortby;

    searchdef(int sortget, int sortbyget):
        sort(sortget),
        sortby(sortbyget)
    {}
    searchdef()
    {}
};

class ConsoleUI
{
public:
    ConsoleUI();
    void start();
private:
    void List();
    void Search();
    void AddPerson();
    void Print(QHash<int, QHash<QString, QString> > result);
    void Delete();

    sk2data gogn;

    void quitmsg();
    searchdef DefineSearch();
    void connectioncomputer();
    void connectionperson();
    void AddConnection();
    void AddComputer();
    void Add();
    void ListPerson();
    void ListComputer();
    void ListConnection();
};

extern QTextStream cout;
extern QTextStream cin;

#endif // CONSOLEUI_H
