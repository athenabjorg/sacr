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
     _scientists = _data.loadScientists();
}

vector<Scientist> ScientistService::getScientists() //CHECK
{   // Returns the list of scientists from file.

    return _scientists;
}

bool ScientistService::addScientist(string name, char gender, int birth, int death) // CHECK
{   // Adds a scientist to the list and updates the file.
    // Returns true if adding succeded, false otherwise.

    Scientist scientist(name, gender, birth, death);

     _scientists.push_back(scientist);
     _data.saveScientist(scientist);
     return true;

}
bool ScientistService::removeScientist(string name) // TODO
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

        // TODO KOMA ÞESSU TIL SKILA TIL DATABASE

        return true;
    }

    return false;
}
void ScientistService::removeAllScientists()
{   // Removes ALL scientists from the list. Be careful with this.

    _scientists.clear();

    _data.removeAllScientists();
}

void ScientistService::scientistSort(int sortType) // TODO SOON
{    // Sort by parameter: 1 = name(A-Z), 2 = name(Z-A), 3 = gender
     //							4 = birth, 5 = death, 6 = age.


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

    // TODO PRENTA ÚT SORTIÐ
}
void ScientistService::scientistSortForFind(int sortType, vector<Scientist>& scientists) // TODO, DELETE?
{   // Sort list by sortType: 1 = name(A-Z), 2 = name(Z-A), 3 = gender,
    //                              4 = birth, 5 = death, 6 = age.
    // Sorts the list provided by the find function without saving to file,
    // so that the search result is displayed according to the search type.

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






vector<Scientist> ScientistService::findScientist(int findType, string parameter)       // Search vector by type
{   // Returns all scientists whos name includes the string entered. Case insensitive.

    vector<Scientist> scientists;

    scientists = _data.loadScientists(findType, parameter);

    return scientists;
}
vector<Scientist> ScientistService::findScientist(int findType, string parameter1, string parameter2)       // Search vector by type
{   // Returns all scientists whos name includes the string entered. Case insensitive.

    vector<Scientist> scientists;

    scientists = _data.loadScientists(findType, parameter1, parameter2);

    return scientists;
}
