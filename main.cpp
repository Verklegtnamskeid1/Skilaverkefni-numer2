#include "main.h"
#include "sk1data.h"


void debug_print(QVector<person> buffer)
{

    QTextStream(stdout) << "" << endl;

    foreach(person item, buffer)
    {

        QTextStream(stdout) << "id:" << item.id << "\t"
                            << "name:" << item.name << "\t"
                            << "gender:" << item.gender << "\t"
                            << "year born:" << item.year_born << "\t"
                            << "year died:" << item.year_death << endl;


    }

    QTextStream(stdout)  << "______" << "" << endl;
}


int main(int argc, char *argv[])
{
    sk1Data gogn;
    gogn.add_person(QString("z"), 0, 20, 3);
    gogn.add_person(QString("a"), 1, 10, 3);
    gogn.add_person(QString("hahahehe"), 1, 444, 3);

    QTextStream(stdout) << "All without sorting" << endl;
    QVector<person> data = gogn.query();
    debug_print(data);

    QTextStream(stdout) << "haha without sorting" << endl;
    data = gogn.query(GET_BY_NAME, "haha");
    debug_print(data);


    QTextStream(stdout) << "gender 0 without sorting" << endl;
    data = gogn.query(GET_BY_GENDER, "0");
    debug_print(data);

    QTextStream(stdout) << "all with sorting" << endl;
    data = gogn.query(GET_ALL, "", SORT_BY_NAME);
    debug_print(data);


    QTextStream(stdout) << "all with sorting descending" << endl;
    data = gogn.query(GET_ALL, "", SORT_BY_NAME, 100);
    debug_print(data);


    QTextStream(stdout) << "all with sorting year born" << endl;
    data = gogn.query(GET_ALL, "", SORT_BY_YEARBORN);
    debug_print(data);





}

