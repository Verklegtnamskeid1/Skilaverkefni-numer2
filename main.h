#ifndef MAIN_H
#define MAIN_H
#include <QtCore>

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


static const int OUTPUT_ERROR = -99;
#endif // MAIN_H
