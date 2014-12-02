#ifndef MAIN_H
#define MAIN_H
#include <QtCore>


/* person er skilgreining á færslunum um einstaklingana
 * sem við vinnum með
 * tekur einsog er:
 * id - id
 * name - nafn
 * gender - kyn
 * year_born - fæðingarár
 * year_death - dánarár
 * */

/* person jonthor;
 * person.id = 1;
 * person.name = QString("Jón Þór");
 * person.gender = 1; 1 er kona í forritinu hehe
 * person.year_born = 1984;
 * person.year_death = 3050;
 *
  person jonthor = person(1,QString("Jón Þór", 1, 1984,3050);
*/


struct person
{
       int id;
       QString name;
       int gender;
       int year_born;
       int year_death;

       person(int in_id, QString in_name, int in_gender,
              int in_year_born, int in_year_death):
       id(in_id),
       name(in_name),
       gender(in_gender),
       year_born(in_year_born),
       year_death(in_year_death)
       {}
       person()
       {}


};


/* Til að bæta læsileika á virkni sk1data (og seinna meir sambærilegra klassa */
static const int GET_ALL = 100;
static const int GET_BY_ID = 200;
static const int GET_BY_NAME = 300;
static const int GET_BY_GENDER = 400;
static const int GET_BY_YEARBORN = 500;
static const int GET_BY_YEARDEATH = 600;

static const int SORT_DESCENDING = 100;
static const int SORT_ASCENDING = 200;

static const int SORT_BY_ID = 200;
static const int SORT_BY_NAME = 300;
static const int SORT_BY_GENDER = 400;
static const int SORT_BY_YEARBORN = 500;
static const int SORT_BY_YEARDEATH = 600;

static const int SORTY_BY [5] = { SORT_BY_ID, SORT_BY_NAME,
                                  SORT_BY_GENDER, SORT_BY_YEARBORN,
                                  SORT_BY_YEARDEATH };
static const int GET_BY [5]  = {GET_BY_ID, GET_BY_NAME,
                                GET_BY_GENDER, GET_BY_YEARBORN,
                                GET_BY_YEARDEATH};


static const int OUTPUT_ERROR = -99; /* Ónotað einsog er */

static const QString FILENAME = "file";
#endif // MAIN_H
