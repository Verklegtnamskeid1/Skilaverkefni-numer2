#include "main.h"
#include "sk1data.h"



<<<<<<< HEAD
int main()
=======

int main(int argc, char *argv[])
>>>>>>> 0273a9cff1f63ca785b72b078bd5f34788b55086
{
    sk1Data gogn;
    gogn.add_person(QString("hehe"), 1, 2, 3);
    gogn.add_person(QString("hehe"), 1, 2, 3);
    gogn.add_person(QString("hahahehe"), 1, 4, 3);
    QVector<person> data = gogn.query();
}

