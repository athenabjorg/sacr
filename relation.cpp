#include "relation.h"

Relation::Relation()                                                // Constructor
{

}
Relation::Relation(string scientist, string computer, int year)     // Constructor with parameters
{
    _scientist = scientist;
    _computer = computer;
    _year = year;
}

string Relation::getScientist() const                               // Returns scientist
{
    return _scientist;
}
string Relation::getComputer() const                                // Returns computer
{
    return _computer;
}
int Relation::getYear() const                                       // Returns current year
{
    return _year;
}
