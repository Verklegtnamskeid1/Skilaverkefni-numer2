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

void AddComputer(QString name, int type, int yearbuilt, int builtornot)
{
    QHash<QString, QString> buffer;
    buffer.insert("Computers_Name", name);
    buffer.insert("Computers_Type", QString::number(type));
    buffer.insert("Computers_YearBuilt", QString::number(yearbuilt));
    buffer.insert("Computers_BuiltOrNot", QString::number(builtornot));
    connection.insert("computers", buffer);
}
void AddConnection(int personid, int computerid);
{
    QHash<QString, QString> buffer;
    buffer.insert("Persons_ID", QString::number(personid));
    buffer.insert("Computers_ID", QString::number(computerid));
    connection.insert("owners", buffer);
}


void sk2data::AddComputer(QString name, int type, int yearbuilt, int builtornot)
{
QHash<QString, QString> buffer;
buffer.insert("Computers_Name", name);
buffer.insert("Computers_Type", QString::number(type));
buffer.insert("Computers_YearBuilt", QString::number(yearbuilt));
buffer.insert("Computers_BuiltOrNot", QString::number(builtornot));
connection.insert("computers", buffer);
}
void sk2data::AddConnection(int personid, int computerid)
{
QHash<QString, QString> buffer;
buffer.insert("Persons_ID", QString::number(personid));
buffer.insert("Computers_ID", QString::number(computerid));
connection.insert("owners", buffer);
}


QVector<QHash<QString, QString> > sk2data::QueryPerson(QString row="Persons_ID", bool asc = true)
{
    QVector<QHash<QString, QString> > map;



    QHash<QString, QString> sort;
    sort["sortby"] = row;
    if (asc) sort["sortorder"] = connection.ASC;
    else { sort["sordorder"] = connection.DESC;}

    sort["sortorder"] = row;

    QHash<int, QHash<QString, QString> > buffer =
             connection.query("persons", connection.EmptySearch,
                            sort);

    QHashIterator<int, QHash<QString, QString>> i(buffer);
    QHash<QString, QString> printorder;
    printorder.insert("PrintOrder", "ID:Name:Gender:Born:Died");
    map << printorder;


    while (i.hasNext())
    {
     i.next();
     QString gender, yeardeath;
     QHash<QString, QString> result;

     result.insert("ID", i.value()["Persons_ID"]);
     result.insert("Name", i.value()["Persons_Name"]);

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
         result.insert("Died", i.value()["Persons_YearDeath"]);

     }

    map << result;


    }
    return map;
}
