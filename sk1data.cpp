#include "main.h"
#include "sk1data.h"




sk1Data::sk1Data()
 {
     lock = false;
     latestid = 0;
 }



bool sortname(person a, person b)
{
    return (a.name.toLower() < b.name.toLower());
}

bool sortgender(person a, person b)
{
    return (a.gender < b.gender);
}
bool sortyearborn(person a, person b)
{
    return (a.year_born < b.year_born);
}
bool sortyeardeath(person a, person b)
{
    return (a.year_death < b.year_death);
}
bool sortid(person a, person b)
{
    return (a.id < b.id);
}


void sk1Data::remove_person(int id)
{
    while (lock) {} /* Uhh, threading safe, algjörlega tilgangslaust so far! */
    lock = true;

    int a = 0;
    foreach(person item, entries)
    {

        if (item.id == id)
        {
            entries.remove(a);
        }
        a++;
     }
    lock = false;

}


QVector<person> sk1Data::query(int search, QString searchstring, int sort_by, int sort)
{
    QVector<person> buffer;
    int compare = 0;

    /* Veljum viðeigandi færslur */
    if (search == GET_ALL) buffer = entries;
    else if (search == GET_BY_NAME)
    {
        foreach(person item, entries)
        {
            if (item.name.contains(searchstring, Qt::CaseInsensitive))
            {
                buffer.push_back(item);
            }
        }

    }
    else {
        int searchnumber = searchstring.toInt();

        foreach(person item, entries)
        {
            switch(search)
            {
                case(GET_BY_ID):
                    compare = item.id;
                    break;
                case(GET_BY_GENDER):
                    compare = item.gender;
                    break;
                case(GET_BY_YEARBORN):
                    compare = item.year_born;
                    break;
                case(GET_BY_YEARDEATH):
                    compare = item.year_death;
                    break;
            }
            if (compare == searchnumber)
                buffer.push_back(item);
         }
    }

    /* Hér þarf að vera sort */

    switch(sort_by)
    {
       case(SORT_BY_NAME):
            std::sort(buffer.begin(), buffer.end(), sortname);
            break;
       case(SORT_BY_GENDER):
            std::sort(buffer.begin(), buffer.end(), sortgender);
            break;
       case(SORT_BY_YEARBORN):
            std::sort(buffer.begin(), buffer.end(), sortyearborn);
            break;
       case(SORT_BY_YEARDEATH):
            std::sort(buffer.begin(), buffer.end(), sortyeardeath);
            break;
       default:
            std::sort(buffer.begin(), buffer.end(), sortid);
    }





    /* Snúum vektornum við ef beðið er um DESCENDING */
    if (sort != SORT_ASCENDING)
    {


        int size = buffer.count();
        QVector<person> buffer2;

        for (int a = (size -1); a >= 0; a--)
        {
            buffer2.push_back(buffer[a]);
        }

        buffer = buffer2;


    }

    return buffer;

}

void sk1Data::add_person(int id, QString name, int gender, int year_born, int year_death)
{
    while (lock) {} /* Uhh, threading safe, algjörlega tilgangslaust so far! */
    lock = true;
    person input = person(id, name, gender, year_born, year_death);
    entries.push_back(input);
    latestid = id+1;
    lock = false;
}


void sk1Data::add_person(QString name, int gender, int year_born, int year_death)
{
    while (lock) {} /* Uhh, threading safe, algjörlega tilgangslaust so far! */
    lock = true;
    person input = person(latestid++, name, gender, year_born, year_death);
    entries.push_back(input);
    lock = false;
}
sk1Data gogn;

