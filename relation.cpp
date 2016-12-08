#include "relation.h"

Relation::Relation()
{

}
Relation::Relation(string scientist, string computer)
{
    _scientist = scientist;
    _computer = computer;
}

string Relation::getScientist()
{
    return _scientist;
}

string Relation::getComputer()
{
    return _computer;
}
