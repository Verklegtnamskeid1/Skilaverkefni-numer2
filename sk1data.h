#ifndef SK1DATA_H
#define SK1DATA_H

class sk1Data
{
public:

    sk1Data();

    void add_person(QString name, int gender, int year_born, int year_death);
    QVector<person> query(QString queryString);


    QVector<person> query(int search = GET_ALL, QString searchstring = QString(""),
                          int sort_by = SORT_BY_ID, int sort = SORT_ASCENDING);





private:
    bool lock;
    int latestid;
    QVector<person> entries;

};

#endif // SK1DATA_H
