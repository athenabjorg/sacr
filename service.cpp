#include "service.h"


using namespace std;


bool sortByAgeAsc (const Scientist &a, const Scientist &b) { return a.getAge()    <  b.getAge();    }
bool sortByAgeDesc(const Scientist &a, const Scientist &b) { return a.getAge()    >  b.getAge();    }


service::service()
{
     _scientists = _data.loadScientists();
     _computers = _data.loadComputers();
}


// ---------------------------------- SCIENTIST FUNCTIONS ---------------------------------- //

vector<Scientist> service::getScientists()
{   // Returns the list of scientists from file.

    return _scientists;
}

bool service::addScientist(string name, char gender, int birth, int death)
{   // Adds a scientist to the list and updates the file.
    // Returns true if adding succeded, false otherwise.

    if(_data.doesScientistExist(name) == false)
    {
        Scientist scientist(name, gender, birth, death);

        _scientists.push_back(scientist);
        _data.saveScientist(scientist);
        return true;
    }

    return false;

}
bool service::updateScientist(string name, char gender, int birth, int death)
{   // Updates a scientist to the list and updates the file.
    // Returns true if adding succeded, false otherwise.

    if(_data.doesScientistExist(name) == true)
    {
        Scientist scientist(name, gender, birth, death);

        _scientists.push_back(scientist);
        _data.updateScientist(scientist);
        return true;
    }

    return false;

}

bool service::removeScientist(string name)
{   // Removes a scientist with that name from the vector. Case insensitive.
    // Returns true if removing succeded, false otherwise.

    vector<Scientist> scientistsToRemove = findScientist(1, name);

    if (scientistsToRemove.size() > 0)
    {
        for (size_t i = 0; i < scientistsToRemove.size(); i++)
        {
            Scientist toRemove = scientistsToRemove.at(i);

            _scientists.erase(remove(_scientists.begin(), _scientists.end(), toRemove), _scientists.end());
        }

        _data.removeScientist(name);

        return true;
    }

    return false;
}
void service::removeAllScientists()
{   // Removes ALL scientists from the list. Be careful with this.

    _scientists.clear();

    _data.removeAllScientists();
}

vector<Scientist> service::scientistSort(int sortType)
{    // Sort by sortType: 1 = name(A-Z), 2 = name(Z-A), 3 = gender (f-m), 4 = gender (m-f),
     // 5 = birth year(0-9), 6 = birth year(9-0) 7 = death year(0-9), 8 = death year(0-9), 9 = age(0-9), 10 = age(9-0)

    vector<Scientist> scientists = _scientists;

    if(sortType == 9)
    {
        sort(scientists.begin(), scientists.end(), sortByAgeAsc);
    }
    else if(sortType == 10)
    {
        sort(scientists.begin(), scientists.end(), sortByAgeDesc);
    }
    else
    {
        scientists = _data.sortScientists(sortType);
    }
    return scientists;
}

vector<Scientist> service::findScientist(int findType, string parameter)       // Search vector by type
{   // Returns all scientists whos name includes the string entered. Case insensitive.

    vector<Scientist> scientists;

    if(findType == 7)
    {
        for(unsigned int i = 0; i < _scientists.size(); i++)
        {

            if(_scientists[i].getAge() == stoi(parameter))
            {
                scientists.push_back(_scientists[i]);
            }
        }
    }
    else
    {
        scientists = _data.loadScientists(findType, parameter);
    }



    return scientists;
}
vector<Scientist> service::findScientist(int findType, string parameter1, string parameter2)       // Search vector by type
{   // Returns all scientists whos name includes the string entered. Case insensitive.

    vector<Scientist> scientists;

    if(findType == 8)
    {
        if(stoi(parameter1) > stoi(parameter2))
        {
            string temp = parameter1;
            parameter1 = parameter2;
            parameter2 = temp;
        }
        for(unsigned int i = 0; i < _scientists.size(); i++)
        {

            if((_scientists[i].getAge() >= stoi(parameter1)) && (_scientists[i].getAge() <= stoi(parameter2)))
            {
                scientists.push_back(_scientists[i]);
            }
        }
    }
    else
    {
        scientists = _data.loadScientists(findType, parameter1, parameter2);
    }



    return scientists;
}

bool service::doesScientistExist(string name)
{
    return _data.doesScientistExist(name);
}

// ---------------------------------- COMPUTER FUNCTIONS ---------------------------------- //

vector<Computer> service::getComputers()
{
    vector<Computer> computers;

    computers = _data.loadComputers();

    return computers;
}

bool service::addComputer(string name, int year, string type, bool built)
{   // Adds a scientist to the list and updates the file.
    // Returns true if adding succeded, false otherwise.

    if(_data.doesComputerExist(name) == false)
    {
        Computer computer(name, year, type, built);

        _computers.push_back(computer);
        _data.saveComputer(computer);
        return true;
    }

    return false;

}
bool service::updateComputer(string name, int year, string type, bool built)
{   // Adds a scientist to the list and updates the file.
    // Returns true if adding succeded, false otherwise.

    if(_data.doesComputerExist(name) == true)
    {
        Computer computer(name, year, type, built);

        _computers.push_back(computer);
        _data.updateComputer(computer);
        return true;
    }

    return false;

}

bool service::removeComputer(string name)
{
    _data.removeComputer(name);
    return true;
}
void service::removeAllComputers()
{
    _data.removeAllComputers();
}

vector<Computer> service::computerSort(int sortType)
{    // Sort by sortType: 1 = name(A-Z), 2 = name(Z-A), 3 = gender (f-m), 4 = gender (m-f),
     // 5 = birth year(0-9), 6 = birth year(9-0) 7 = death year(0-9), 8 = age(0-9), 9 = age(9-0)

    vector<Computer> computers;

    computers = _data.sortComputers(sortType);

    return computers;

}

vector<Computer> service::findComputer(int findType, string parameter)       // Search vector by type
{
    vector<Computer> computers;

    computers = _data.loadComputers(findType, parameter);

    return computers;
}
vector<Computer> service::findComputer(int findType, string parameter1, string parameter2)       // Search vector by type
{
    vector<Computer> computers;

    computers = _data.loadComputers(findType, parameter1, parameter2);

    return computers;
}

bool service::doesComputerExist(string name)
{
    return _data.doesComputerExist(name);
}


// ---------------------------------- RELATION FUNCTIONS ---------------------------------- //


vector<Relation> service::getRelations()
{
    vector<Relation> relations;

    relations = _data.loadRelations();

    return relations;
}

bool service::addRelation(string scientist, string computer)
{   // Adds a scientist to the list and updates the file.
    // Returns true if adding succeded, false otherwise.

    int year = _data.yearComputerBuilt(computer);

    if(_data.doesRelationExist(scientist, computer))
    {
    }
    else
    {
        Relation relation(scientist, computer, year);

        _relations.push_back(relation);
        _data.saveRelation(relation);

        return true;
    }

    return false;
}

bool service::removeRelation(int removeType, string name)
{
    _data.removeRelation(removeType, name);

    return true;
}

void service::removeAllRelations()
{
    _data.removeAllRelations();
}

vector<Relation> service::relationSort(int sortType)
{

    vector<Relation> relations;

    relations = _data.sortRelations(sortType);

    return relations;

}

vector<Relation> service::findRelation(int findType, string parameter)       // Search vector by type
{
    vector<Relation> relations;

    relations = _data.loadRelations(findType, parameter);

    return relations;
}
vector<Relation> service::findRelation(int findType, string parameter1, string parameter2)       // Search vector by type
{
    vector<Relation> relations;

    relations = _data.loadRelations(findType, parameter1, parameter2);

    return relations;
}

bool service::doesRelationExist(string scientist, string computer)
{
    return _data.doesRelationExist(scientist, computer);
}
