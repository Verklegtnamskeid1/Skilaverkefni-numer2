#ifndef SQLITE_H
#define SQLITE_H
#include <QtSql>

static const int PERSONS_TABLE = 0;
static const int OWNERS_TABLE = 1;
static const int COMPUTERS_TABLE = 2;

class sqlite
{
public:
    sqlite();
    //get_

private:
   const QString table = "Persons, Owners, Computers";
   QStringList tables;
   /* Taflan Person er
    * Persons_ID(int) Persons_Name(String) Person_Sex(String) Person_YoB(int) Person_YoD(int)
    *
    * Taflan Owners er
    * Computers_ID Persons_ID
    *
    * Taflan Computers er:
    * Computers_ID(int) Name(string) YearBuilt (int) Type (string) BuiltOrNot(bool)
*/
   QSqlDatabase db;
   QSqlQuery searchQuery;
   void query(QString WHAT, QString TABLE, QString SORT);

};

#endif // SQLITE_H
