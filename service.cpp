#include "service.h"


using namespace std;


bool sortByAgeAsc (const Scientist &a, const Scientist &b) { return a.getAge()    <  b.getAge();    }
bool sortByAgeDesc(const Scientist &a, const Scientist &b) { return a.getAge()    >  b.getAge();    }
//operator overloading functions for scientistSort.

service::service()
{
    _scientists = _data.loadScientists();
    _computers = _data.loadComputers();
}
int service::whatYearIsIt() const
{   // Returns the current year.

    time_t     currentTime;
    struct tm* timeinfo;

    time(&currentTime);
    timeinfo = localtime(&currentTime);

    int currentYear = (timeinfo->tm_year + 1900);
    return currentYear;
}


// ---------------------------------- SCIENTIST FUNCTIONS ---------------------------------- //

vector<Scientist> service::getScientists()
{   // Returns the list of scientists from a database.

    return _data.loadScientists();
}

bool service::addScientist(string id, string name, string gender, string born, string died, string picurl, string about, string abouturl)
{   // Adds a scientist to the list and updates the database.
    // Returns true if adding succeded, false otherwise.

    if(_data.doesScientistExist(name) == false)
    {
        Scientist scientist(id, name, gender, born, died, picurl, about, abouturl);

        _scientists.push_back(scientist);
        _data.saveScientist(scientist);
        return true;
    }

    return false;

}
bool service::updateScientist(string id, string name, string gender, string born, string died, string picurl, string about, string abouturl)
{   // Updates a scientist in the database.
    // Returns true if adding succeded, false otherwise.

    if(_data.doesScientistExist(name) == true)
    {
        Scientist scientist(id, name, gender, born, died, picurl, about, abouturl);

        _scientists.push_back(scientist);
        _data.updateScientist(scientist);
        return true;
    }

    return false;

}

bool service::removeScientist(string name)
{   // Removes a scientist with that name from the database. Case insensitive.
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
{   // Sort by sortType: 1 = name(A-Z), 2 = name(Z-A), 3 = gender(f-m), 4 = gender(m-f), 5 = birth year(0-9),
    // 6 = birth year(9-0) 7 = death year(0-9), 8 = death year(9-0), 9 = age(0-9), 10 = age(9-0).

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

vector<Scientist> service::findScientist(int findType, string parameter)
{   // Returns all scientists whos name includes the string entered. Case insensitive.
    // findType 0 = load by exact name, 1 = load by name, 2 = load by gender, 3 = load by birth year
    // 4 = load by birth year range, 5 = load by death year, 7 = load by age.
    // 6 and 8 are loaded in the findScientist class with three parameters

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
    // findType 6 = death year range, 8 = load by age range.
    // 0, 1, 2, 3, 4, 5 and 7 are loaded in the findScientist class with two parameters

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
{   // Checks if a scientist by that name exists already

    return _data.doesScientistExist(name);
}

Scientist service::getScientist(string name)
{
    Scientist scientist;
    scientist = _data.loadScientist(name);

    return scientist;
}

// ---------------------------------- COMPUTER FUNCTIONS ---------------------------------- //

vector<Computer> service::getComputers()
{   // Uploads the list of copmuters from database.

    vector<Computer> computers;

    computers = _data.loadComputers();

    return computers;
}

bool service::addComputer(string id, string name, string year, string type, string built, string picurl, string about, string abouturl)
{   // Adds a copmuter to the database.
    // Returns true if adding succeded, false otherwise.

    if(_data.doesComputerExist(name) == false)
    {
        Computer computer(id, name, year, type, built, picurl, about, abouturl);

        _computers.push_back(computer);
        _data.saveComputer(computer);
        return true;
    }

    return false;

}
bool service::updateComputer(string id, string name, string year, string type, string built, string picurl, string about, string abouturl)
{   // Updates a copmuter in the database.
    // Returns true if adding succeded, false otherwise.

    if(_data.doesComputerExist(name) == true)
    {
        Computer computer(id, name, year, type, built, picurl, about, abouturl);

        _computers.push_back(computer);
        _data.updateComputer(computer);
        return true;
    }

    return false;

}

bool service::removeComputer(string name)
{   // Removes a copmuter with that name from the database. Case insensitive.
    // Returns true if removing succeded, false otherwise.

    _data.removeComputer(name);
    return true;
}
void service::removeAllComputers()
{   // Removes ALL computers from the list. Be careful with this.

    _data.removeAllComputers();
}

vector<Computer> service::computerSort(int sortType)
{   // Sort by sortType: 1 = name(A-Z), 2 = name(Z-A), 3 = type(A-Z), 4 = type(Z-A), 5 = year made(0-9),
    // 6 = year made(9-0), 7 = if built(n-y), 8 = if built (y-n).

    vector<Computer> computers;

    computers = _data.sortComputers(sortType);

    return computers;

}

vector<Computer> service::findComputer(int findType, string parameter)       // Search vector by type
{   // Loads computers from a database, into a vector, depenting on loadType.
    // 0 = load by exact name, 1 = load by name, 2 = load by year built
    // 4 = load by type, 5 = load by if built.
    // 3 loaded in the findComputer funciton with three parameters

    vector<Computer> computers;

    computers = _data.loadComputers(findType, parameter);

    return computers;
}
vector<Computer> service::findComputer(int findType, string parameter1, string parameter2)       // Search vector by type
{   // Loads computers from a database, into a vector, depenting on loadType.
    // 3 = load by year built range.
    // 0, 1, 2, 4 and 5 are loaded in the findCOmputer function with two parameters.

    vector<Computer> computers;

    computers = _data.loadComputers(findType, parameter1, parameter2);

    return computers;
}

bool service::doesComputerExist(string name)
{   // Checks if a copmuter by that name exists already

    return _data.doesComputerExist(name);
}

Computer service::getComputer(string name)
{
    Computer computer;
    computer = _data.loadComputer(name);

    return computer;
}


// ---------------------------------- RELATION FUNCTIONS ---------------------------------- //


vector<Relation> service::getRelations()
{   // Uploads the list of relations from database.

    vector<Relation> relations;

    relations = _data.loadRelations();

    return relations;
}

bool service::addRelation(string scientist, string computer)
{   // Adds a relation to the database.
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
{   // Removes a relation with that name from the database. Case insensitive.
    // Returns true if removing succeded, false otherwise.

    _data.removeRelation(removeType, name);

    return true;
}
bool service::removeRelation(string scientist, string computer)
{   // Removes a relation with that scientist and computer name from the database. Case insensitive.
    // Returns true if removing succeded, false otherwise.

    _data.removeRelation(scientist, computer);

    return true;
}
void service::removeAllRelations()
{   // Removes ALL relations from the list. Be careful with this.

    _data.removeAllRelations();
}

vector<Relation> service::relationSort(int sortType)
{   // Sort by sortType: 1 = scientist name(A-Z), 2 = scientist name(Z-A), 3 = computer name(A-Z)
    // 4 = computer name(Z-A), 5 = year made(0-9), 6 = year made(9-0).

    vector<Relation> relations;

    relations = _data.sortRelations(sortType);

    return relations;

}

vector<Relation> service::findRelation(int findType, string parameter)       // Search vector by type
{   // Loads relations from a database, into a vector, depenting on loadType.
    // 0 = load by exact scientist name, 1 = load by scientist name,
    // 2 = load by exact computer name, 3 = load by computer name, 4 = load by year computer built
    // 5 is loaded in the loadRelations function with three parameters.

    vector<Relation> relations;

    relations = _data.loadRelations(findType, parameter);

    return relations;
}
vector<Relation> service::findRelation(int findType, string parameter1, string parameter2)       // Search vector by type
{   // Loads relations from a database, into a vector, depenting on loadType.
    // 5 = load by year built range, 6 = load by exact scientist and computer.
    // 0, 1, 2, 3 and 4 are loaded in the loadRelations function with two parameters.

    vector<Relation> relations;

    relations = _data.loadRelations(findType, parameter1, parameter2);

    return relations;
}

bool service::doesRelationExist(string scientist, string computer)
{   // Checks if a relation by that name exists already

    return _data.doesRelationExist(scientist, computer);
}
