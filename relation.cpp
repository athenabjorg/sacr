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

string Relation::getScientist() const
{
    return _scientist;
}

string Relation::getComputer() const
{
    return _computer;
}

int Relation::getYear() const
{
    return _year;
}
