#include "scientistservice.h"
#include <algorithm>
#include <string>

using namespace std;

struct ScientistComparison {
  bool operator() (Scientist a,Scientist b) { return (a.getName()<b.getName());}
};

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

    // Sort by name:
    ScientistComparison cmp;
    std::sort(scientist.begin(), scientist.end(), cmp);

    return scientist;
    */
}

void ScientistService::addScientist(string name, char gender, int age, int death)
{   //bætir scientist við listann
    Scientist scientist(name, gender, age, death);
    _scientists.push_back(scientist);

    //senda _scientists til dataaccess til að savea í skránna
}









