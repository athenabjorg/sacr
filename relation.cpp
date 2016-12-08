#include "relation.h"

Relation::Relation()
{

}
Relation::Relation(string scientist, string computer, int year)
{
    _scientist = scientist;
    _computer = computer;
    _year = year;
}

string Relation::getScientist()
{
    return _scientist;
}

string Relation::getComputer()
{
    return _computer;
}

int Relation::getYear()
{
    return _year;
}
