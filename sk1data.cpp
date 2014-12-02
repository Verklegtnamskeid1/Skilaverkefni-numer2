#include "main.h"
#include "sk1data.h"




sk1Data::sk1Data()
 {
     lock = false;
     latestid = 0;
 }


/* Föll til að aðstoða við std::sort*/

/* Raða eftir person.name */
bool sortname(person a, person b)
{
    return (a.name.toLower() < b.name.toLower());
}

/* Raða eftir person.gender */
bool sortgender(person a, person b)
{
    return (a.gender < b.gender);
}

/* Raða eftir person.year_born */
bool sortyearborn(person a, person b)
{
    return (a.year_born < b.year_born);
}
/* Raða eftir person.year_death*/
bool sortyeardeath(person a, person b)
{
    return (a.year_death < b.year_death);
}
/* Raða eftir person.id */
bool sortid(person a, person b)
{
    return (a.id < b.id);
}


/* Fjarlægir ALLAR færslur með id (það er jú fræðilegur möguleiki einsog er
 * að færslur hafi sama id */

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

/* Fallið sem birtir færslur sem uppfylla ákveðin skilyrði, nýtist til að birta, leita og raða */
QVector<person> sk1Data::query(int search, QString searchstring, int sort_by, int sort)
{
    QVector<person> buffer;

    /* Veljum viðeigandi færslur, ef GET_ALL birtum allt */
    if (search == GET_ALL) buffer = entries;
    else if (search == GET_BY_NAME) /* gúlp þurfum að leita af searchstring í person.name */
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
        /* Við erum að leita að tölu og því
         * breytum við searchstring í int */

        /* Kallað er á fallið með searchstring sem QString
         * og því breytum við því hér í int */
        int searchnumber = searchstring.toInt();
        int compare = 0;

        foreach(person item, entries)
        {
            /* Tökum int compare og látum það fá gildi þeirrar breytu sem við leitum af */
            switch(search) /* Látum int compare vera viðeigandi breytu */
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
            if (compare == searchnumber) /* 'edda viljum við, 'edda pushum við */
                buffer.push_back(item);
         }
    }

    /* Hér sortum við allt sem við erum með í buffer */
    switch(sort_by)
    {
       case(SORT_BY_NAME): /* Raða útfrá person.name*/
            std::sort(buffer.begin(), buffer.end(), sortname);
            break;
       case(SORT_BY_GENDER): /* Raða útfrá person.gender */
            std::sort(buffer.begin(), buffer.end(), sortgender);
            break;
       case(SORT_BY_YEARBORN): /* Raða útfrá person.year_born */
            std::sort(buffer.begin(), buffer.end(), sortyearborn);
            break;
       case(SORT_BY_YEARDEATH): /* Raða útfrá person.year_death */
            std::sort(buffer.begin(), buffer.end(), sortyeardeath);
            break;
       default: /* Gerum ráð fyrir að plebbs/notandi vilji raða eftir id */
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

