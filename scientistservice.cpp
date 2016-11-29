#include "scientistservice.h"
#include <algorithm>
#include <string>

using namespace std;


//operator overloading fyrir sort fallið
bool sortByName(const Scientist &a, const Scientist &b) { return a.getName() < b.getName(); }

bool sortByGender(const Scientist &a, const Scientist &b) { return a.getGender() < b.getGender(); }

bool sortByAge(const Scientist &a, const Scientist &b) { return a.getAge() < b.getAge(); }

bool sortByDeath(const Scientist &a, const Scientist &b) { return a.getDeath() < b.getDeath(); }


ScientistService::ScientistService()
{

}

vector<Scientist> ScientistService::getScientists(/* TODO: parameters */)
{   //sækir listann af scientists svo consoleui geti prentað það
    //er betra að sækja listann úr skrá eða senda bara vectorinn sem við erum með?
    vector<Scientist> scientist;
    DataAccess data;

    scientist = data.loadScientists();

    return scientist;
}

void ScientistService::addScientist(string name, char gender, int age, int death)
{   //bætir scientist við listann
    Scientist scientist(name, gender, age, death);
    DataAccess data;
    // TODO er scientist til fyrir? þá sleppa push og senda villuboð
    // eða spurja hvort notandinn vilja örugglega bæta þeim við aftur?

    _scientists.push_back(scientist);

    data.saveScientists(_scientists);
}

void ScientistService::removeScientist(string name)
{   //virkar ekki?
   // _scientists.erase(remove(_scientists.begin(), _scientists.end(), name), _scientists.end());
}

void ScientistService::scientistSort(int sortType)
{    // sort by parameter, 1 = name, 2 = gender, 3 = age, 4 = death
     // always sorts by name. (should we keep this?)
     // change to switch case?
     // make it return _scientists, so console can print it out right away?

    sort(_scientists.begin(), _scientists.end(), sortByName);

    if (sortType == 2)
    {
        sort(_scientists.begin(), _scientists.end(), sortByGender);
    }
    else if (sortType == 3)
    {
        sort(_scientists.begin(), _scientists.end(), sortByAge);
    }
    else if (sortType == 4)
    {
        sort(_scientists.begin(), _scientists.end(), sortByDeath);
    }
}


vector<Scientist> ScientistService::findScientistByName(string name)
{   //leita að upplýsingum um scientist eftir nafni
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

vector<Scientist> ScientistService::findScientistByGender(char gender)
{   //leita að upplýsingum um scientist eftir kyni
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

vector<Scientist> ScientistService::findScientistByAge(int age)
{   //leita að upplýsingum um scientist eftir fæðingarári
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

vector<Scientist> ScientistService::findScientistByDeath(int death)
{   //leita að upplýsingum um scientist eftir dánarári
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
