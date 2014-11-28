#include "main.h"
#include "sk1data.h"



int main()
{
    sk1Data gogn;
    gogn.add_person(QString("hehe"), 1, 2, 3);
    gogn.add_person(QString("hehe"), 1, 2, 3);
    gogn.add_person(QString("hahahehe"), 1, 4, 3);
    QVector<person> data = gogn.query();
}

