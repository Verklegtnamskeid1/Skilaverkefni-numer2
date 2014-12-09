#include "sk2data.h"
// QHash<int, QHash<QString, QString> >
sk2data::sk2data()
{
}


void sk2data::AddPerson(QString name, int gender, int yearborn, int yeardead)
{
    QHash<QString, QString> buffer;
    buffer.insert("Persons_Name", name);
    buffer.insert("Persons_Sex", QString::number(gender));
    buffer.insert("Persons_YearBorn", QString::number(yearborn));
    buffer.insert("Persons_YearDeath", QString::number(yeardead));
    connection.insert("persons", buffer);

}

QVector<QMap<QString, QString> > sk2data::QueryPerson()
{
    QVector<QMap<QString, QString> > map;

    QHash<int, QHash<QString, QString> > buffer =
             connection.query("persons", connection.EmptySearch,
                            connection.DefaultSort);
    QHashIterator<int, QHash<QString, QString>> i(buffer);
    while (i.hasNext())
    {
     i.next();
     QString gender, yeardeath;
     QMap<QString, QString> result;

     result.insert("ID", i.value()["Persons_ID"]);
     if (i.value()["Persons_Gender"] == "1")
     {
         result.insert("Gender", "Female");

     }
     else
     {
         result.insert("Gender", "Male");

     }
     result.insert("Born", i.value()["Persons_YearBorn"]);
     if (i.value()["Persons_YearDeath"] == "0")
     {
         result.insert("Died", "Alive");

     }
     else
     {
         result.insert("Born", i.value()["Persons_YearDeath"]);

     }

    map << result;


    }
    return map;
}
