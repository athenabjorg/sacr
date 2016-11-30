#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include <vector>
#include <algorithm>
#include <string>
#include "scientist.h"
#include "dataaccess.h"

using namespace std;

class ScientistService
{
public:
    ScientistService();

    //
    vector<Scientist> getScientists(/* TODO: parameters */);
    void addScientist(string name, char gender, int birth, int death, int age); // add scientist in to vector
    void removeScientist(string name);
    void scientistSort(int sortType);
    vector<Scientist> findScientistByName(string name);
    vector<Scientist> findScientistByGender(char gender);
    vector<Scientist> findScientistByBirth(int birth);
    vector<Scientist> findScientistByDeath(int death);
    vector<Scientist> findScientistByAge(int age);

private:

    vector<Scientist> _scientists;
};

#endif // SCIENTISTSERVICE_H
