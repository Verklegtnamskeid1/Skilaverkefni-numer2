#ifndef SK2DATA_H
#define SK2DATA_H

class sk2data
{
public:
    sk2data();
    /* Remove */
    void RemoveComputer(int id);
    void RemoveConnection(int id);
    void RemovePerson(int id);

    /* Add */
    void AddComputer(QString name, int type, int yearbuilt, int builtornot);
    void AddConnection(int personid, int computerid);
    void AddPerson(QString name, int gender, int yearborn, int yeardead);

    /* Query */
    void QueryComputer(); /* Sækir allt */
    void QueryConnection();
    void QueryPerson();

    void QueryComputer(int id); /* sækja id*/
    void QueryConnection(int id);
    void QueryPerson(int id);

};

#endif // SK2DATA_H
