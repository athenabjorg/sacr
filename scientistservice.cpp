#include "scientistservice.h"


using namespace std;


//operator overloading for scientistSort.
bool sortByNameAsc (const Scientist &a, const Scientist &b) { return a.getName()   <  b.getName();   }
bool sortByNameDesc(const Scientist &a, const Scientist &b) { return a.getName()   >  b.getName();   }
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

bool ScientistService::addScientist (string name, char gender, int birth, int death, int age)
{   // Adds a scientist to the list and updates the file.
    Scientist scientist(name, gender, birth, death, age);
    DataAccess data;

    if (findScientistByName(name).size() > 0)
    {
        return false;
    }

    _scientists.push_back(scientist);

    data.saveScientists(_scientists);

    return true;
}

bool ScientistService::removeScientist (string name)
{   // removes a scientist with that name from the vector
    DataAccess data;

    if (findScientistByName(name).size() > 0)
    {
        Scientist toRemove = findScientistByName(name).at(0);

        _scientists.erase(remove(_scientists.begin(), _scientists.end(), toRemove), _scientists.end());

        data.saveScientists(_scientists);

        return true;
    }


    return false;
}

void ScientistService::scientistSort   (int sortType)
{    // Sort by parameter, 1 = name(A-Z), 2 = name(Z-A), 3 = gender, 4 = birth, 5 = death, 6 = age
     // change to switch case?

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
}

vector<Scientist> ScientistService::findScientistByName   (string name)
{   // Returns all scientists with the full name specified.
    // TODO leita eftir part úr nafni?
    vector<Scientist> scientist;

    for (size_t i = 0; i < _scientists.size(); i++)
    {
        if (_scientists[i].getName() == name)
        {
            scientist.push_back(_scientists[i]);
        }
    }

    return scientist;
}

vector<Scientist> ScientistService::findScientistByGender (char gender)
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

vector<Scientist> ScientistService::findScientistByBirth  (int birth)
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

vector<Scientist> ScientistService::findScientistByDeath  (int death)
{   // Returns all scientists that died that year, or death = 0 for still alive..
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

vector<Scientist> ScientistService::findScientistByAge    (int age)
{   // Returns all scientists with same age as parameter ( int age )
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
