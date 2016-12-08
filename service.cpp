#include "service.h"


using namespace std;


//operator overloading functions for scientistSort. TODO REMOVE?? geyma bara age?
bool sortByNameAsc (const Scientist &a, const Scientist &b)
{   // also makes the sort case insensitive.
    string aName = a.getName(), bName = b.getName();
    transform(aName.begin(), aName.end(), aName.begin(), ::tolower);
    transform(bName.begin(), bName.end(), bName.begin(), ::tolower);
    return aName < bName;
}
bool sortByNameDesc(const Scientist &a, const Scientist &b)
{   // also makes the sort case insensitive.
    string aName = a.getName(), bName = b.getName();
    transform(aName.begin(), aName.end(), aName.begin(), ::tolower);
    transform(bName.begin(), bName.end(), bName.begin(), ::tolower);
    return aName > bName;
}
bool sortByGender  (const Scientist &a, const Scientist &b) { return a.getGender() <  b.getGender(); }
bool sortByBirth   (const Scientist &a, const Scientist &b) { return a.getBirth()  <  b.getBirth();  }
bool sortByDeath   (const Scientist &a, const Scientist &b) { return a.getDeath()  <  b.getDeath();  }
bool sortByAge     (const Scientist &a, const Scientist &b) { return a.getAge()    <  b.getAge();    }


service::service()
{
     _scientists = _data.loadScientists();
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
     // 5 = birth year(0-9), 6 = birth year(9-0) 7 = death year(0-9), 8 = age(0-9), 9 = age(9-0)

    vector<Scientist> scientists;

    scientists = _data.sortScientists(sortType);

    return scientists;

}

vector<Scientist> service::findScientist(int findType, string parameter)       // Search vector by type
{   // Returns all scientists whos name includes the string entered. Case insensitive.

    vector<Scientist> scientists;

    scientists = _data.loadScientists(findType, parameter);

    return scientists;
}
vector<Scientist> service::findScientist(int findType, string parameter1, string parameter2)       // Search vector by type
{   // Returns all scientists whos name includes the string entered. Case insensitive.

    vector<Scientist> scientists;

    scientists = _data.loadScientists(findType, parameter1, parameter2);

    return scientists;
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


// ---------------------------------- RELATION FUNCTIONS ---------------------------------- //

//relations functions here
