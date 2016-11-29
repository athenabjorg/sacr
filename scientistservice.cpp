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

vector<Scientist> ScientistService::getScientist(/* TODO: parameters */)
{
    return _scientists;
    vector<Scientist> scientist;
/*
    // scientist = sækja scientists frá dataaccess



    // TODO: business logic!


    return scientist;
    */
}

void ScientistService::addScientist(string name, char gender, int age, int death)
{   //bætir scientist við listann
    Scientist scientist(name, gender, age, death);

    // er scientist til fyrir? þá sleppa push og senda villuboð
    _scientists.push_back(scientist);

    //senda _scientists til dataaccess til að savea í skránna
}

// delete a scientist from the list, uppfæra textaskrá



// raða listanum, eftir nafni -> aldri, kyni, dánarári


// leita í listanum








