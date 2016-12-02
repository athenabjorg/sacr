#include "scientistservice.h"


using namespace std;


//operator overloading functions for scientistSort.
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


ScientistService::ScientistService()
{

}

vector<Scientist> ScientistService::getScientists()
{   // Uploads the list of scientists from file.

    DataAccess data;

    _scientists = data.loadScientists();

    return _scientists;
}

bool ScientistService::addScientist(string name, char gender, int birth, int death, int age)
{   // Adds a scientist to the list and updates the file.
    // Returns true if adding succeded, false otherwise.

    Scientist scientist(name, gender, birth, death, age);
    DataAccess data;

    if (findScientistByName(name).size() > 0)
    {
        return false;
    }

    else
    {
        _scientists.push_back(scientist);
        data.saveScientists(_scientists);
        return true;
    }
}

bool ScientistService::removeScientist(string name)
{   // Removes a scientist with that name from the vector. Case insensitive.
    // Returns true if removing succeded, false otherwise.

    DataAccess data;
    vector<Scientist> scientistsToRemove = findScientistByName(name);

    if (scientistsToRemove.size() > 0)
    {
        for (size_t i = 0; i < scientistsToRemove.size(); i++)
        {
            Scientist toRemove = scientistsToRemove.at(i);

            _scientists.erase(remove(_scientists.begin(), _scientists.end(), toRemove), _scientists.end());
        }

        data.saveScientists(_scientists);

        return true;
    }

    return false;
}

void ScientistService::removeAllScientists()
{   // Removes ALL scientists from the list. Be careful with this.

    DataAccess data;
    _scientists.clear();

    data.saveScientists(_scientists);
}

// TODO ------------------  void ScientistService::replaceScientist()


void ScientistService::scientistSort(int sortType)
{    // Sort by parameter: 1 = name(A-Z), 2 = name(Z-A), 3 = gender
     //							4 = birth, 5 = death, 6 = age.

    DataAccess data;

    if (sortType == 1)
    {
        sort(_scientists.begin(), _scientists.end(), sortByNameAsc);
    }
    else if (sortType == 2)
    {
        sort(_scientists.begin(), _scientists.end(), sortByNameDesc);
    }
    else if (sortType == 3)
    {
        sort(_scientists.begin(), _scientists.end(), sortByGender);
    }
    else if (sortType == 4)
    {
        sort(_scientists.begin(), _scientists.end(), sortByBirth);
    }
    else if (sortType == 5)
    {
        sort(_scientists.begin(), _scientists.end(), sortByDeath);
    }
    else if (sortType == 6)
    {
        sort(_scientists.begin(), _scientists.end(), sortByAge);
    }

    data.saveScientists(_scientists);
}

void ScientistService::scientistSortForFind(int sortType, vector<Scientist>& scientists)
{   // Sort by parameter, 1 = name(A-Z), 2 = name(Z-A), 3 = gender, 4 = birth, 5 = death, 6 = age.
    // Sorts the list provided by the find function,
    // without saving to file or the main _scientists vector.

    if (sortType == 1)
    {
        sort(scientists.begin(), scientists.end(), sortByNameAsc);
    }
    else if (sortType == 2)
    {
        sort(scientists.begin(), scientists.end(), sortByNameDesc);
    }
    else if (sortType == 3)
    {
        sort(scientists.begin(), scientists.end(), sortByGender);
    }
    else if (sortType == 4)
    {
        sort(scientists.begin(), scientists.end(), sortByBirth);
    }
    else if (sortType == 5)
    {
        sort(scientists.begin(), scientists.end(), sortByDeath);
    }
    else if (sortType == 6)
    {
        sort(scientists.begin(), scientists.end(), sortByAge);
    }
}

vector<Scientist> ScientistService::findScientistByName(string name)
{   // Returns all scientists whos name includes the string entered. Case insensitive.

    vector<Scientist> scientist;
    string databaseName;
    int pos = -1;

    cout << name << "   <-------- name in find function" << endl;

    for (size_t i = 0; i < _scientists.size(); i++)
    {
        databaseName = _scientists[i].getName();
        transform(databaseName.begin(), databaseName.end(), databaseName.begin(), ::tolower);
        transform(name.begin(), name.end(), name.begin(), ::tolower);

        pos = databaseName.find(name);

        if (pos > -1)
        {
            scientist.push_back(_scientists[i]);
        }
    }

    scientistSortForFind(1, scientist);

    return scientist;
}

vector<Scientist> ScientistService::findScientistByGender(char gender)
{   // Returns all scientists of that gender.

    vector<Scientist> scientist;

    for (size_t i = 0; i < _scientists.size(); i++)
    {
        if (_scientists[i].getGender() == gender)
        {
            scientist.push_back(_scientists[i]);
        }
    }

    return scientist;
}

vector<Scientist> ScientistService::findScientistByBirth(int birth)
{   // Returns all scientists born that year.

    vector<Scientist> scientist;

    for (size_t i = 0; i < _scientists.size(); i++)
    {
        if (_scientists[i].getBirth() == birth)
        {
            scientist.push_back(_scientists[i]);
        }
    }

    return scientist;
}

vector<Scientist> ScientistService::findScientistByBirthRange(int birth1, int birth2)
{   // Returns all scientists born in that year range.

    vector<Scientist> scientist;
    int temp;
    if(birth1 > birth2)
    {
        temp = birth1;
        birth1 = birth2;
        birth2 = temp;
    }
    for (size_t i = 0; i < _scientists.size(); i++)
    {
        if (_scientists[i].getBirth() >= birth1 && _scientists[i].getBirth() <= birth2)
        {
            scientist.push_back(_scientists[i]);
        }
    }

    scientistSortForFind(4, scientist);

    return scientist;
}

vector<Scientist> ScientistService::findScientistByDeath(int death)
{   // Returns all scientists that died that year, or death = 0 if still alive.

    vector<Scientist> scientist;

    for (size_t i = 0; i < _scientists.size(); i++)
    {
        if (_scientists[i].getDeath() == death)
        {
            scientist.push_back(_scientists[i]);
        }
    }

    return scientist;
}

vector<Scientist> ScientistService::findScientistByDeathRange(int death1, int death2)
{   // Returns all scientists who died in that range.

    vector<Scientist> scientist;
    int temp;
    if(death1 > death2)
    {
        temp = death1;
        death1 = death2;
        death2 = temp;
    }
    for (size_t i = 0; i < _scientists.size(); i++)
    {
        if (_scientists[i].getDeath() >= death1 && _scientists[i].getDeath() <= death2)
        {
            scientist.push_back(_scientists[i]);
        }
    }

    scientistSortForFind(5, scientist);

    return scientist;
}

vector<Scientist> ScientistService::findScientistByAge(int age)
{   // Returns all scientists of that age.

    vector<Scientist> scientist;

    for (size_t i = 0; i < _scientists.size(); i++)
    {
        if (_scientists[i].getAge() == age)
        {
            scientist.push_back(_scientists[i]);
        }
    }

    return scientist;
}

vector<Scientist> ScientistService::findScientistByAgeRange(int age1, int age2)
{   // Returns all scientists in that age range.

    vector<Scientist> scientist;
    int temp;
    if(age1 > age2)
    {
        temp = age1;
        age1 = age2;
        age2 = temp;
    }
    for (size_t i = 0; i < _scientists.size(); i++)
    {
        if (_scientists[i].getAge() >= age1 && _scientists[i].getAge() <= age2)
        {
            scientist.push_back(_scientists[i]);
        }
    }

    scientistSortForFind(6, scientist);

    return scientist;
}
