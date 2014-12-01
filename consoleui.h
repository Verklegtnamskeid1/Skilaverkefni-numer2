#ifndef CONSOLEUI_H
#define CONSOLEUI_H

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
    void Print(QVector<person> result);
    void Delete();


    searchdef DefineSearch();

};

extern QTextStream cout;
extern QTextStream cin;

#endif // CONSOLEUI_H
