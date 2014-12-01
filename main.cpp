#include "main.h"
#include "sk1data.h"
#include "consoleui.h"

int main()
{
    /* Þetta opnar skjalið og hendir því inn
    QFile csv("file");
    if (csv.exists() && csv.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&csv);
        QString line = "";
        while (!line.isNull())
        {
            line = in.readLine();
            QStringList rows = line.split(",");
            if (rows.count() == 5)
            {
                /* otharfi einsog er a vista id serstaklega */

                // int id = rows[0].toInt();
                QString name = rows[1];
                int gender = rows[2].toInt();
                int yearborn = rows[3].toInt();
                int yeardead = rows[4].toInt();
                gogn.add_person(name, gender, yearborn, yeardead);

            }
        }

        csv.close();
    }


    /* Starta console */
    ConsoleUI ui = ConsoleUI();
    ui.start();


    /* Vista skjalið og hætta */
    QVector<person> results =   gogn.query();
    QFile write("file");
    write.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream wf(&write);
    foreach(person item,results )
    {
        wf << item.id <<","<<
              item.name<<","<<
              item.gender<<","<<
              item.year_born<<","<<
              item.year_death<<endl;
    }
    write.flush();
    write.close();

    return 0;
}

