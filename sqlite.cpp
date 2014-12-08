#include "sqlite.h"
#include <iostream>
sqlite::sqlite()
{
    db = QSqlDatabase::addDatabase("QSQLITE");/* Skilgreinir hvaða SQL dræver hún á að nota */
    db.setDatabaseName("Skil2.sqlite");
    searchQuery = QSqlQuery(db);
    tables = table.split(", ");
    if (db.isValid())
    {

        db.open();
        if (db.isOpen())
        {

        }
    }
    else
    {
        /* villu skilaboð */
    }
}
void sqlite::query(QString WHAT=QString("*"),
                   QString TABLE=QString("Persons"),
                   QString SORT=QString(""))
{
    searchQuery.prepare("SELECT "+WHAT+" FROM "+TABLE + " "+SORT);
    searchQuery.exec();
    // while(searchQuery.next()){}
}
