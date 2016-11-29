#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include <vector>
#include "scientist.h"
#include "dataaccess.h"

using namespace std;

class ScientistService
{
public:
    ScientistService();

    //
    vector<Scientist> getScientists(/* TODO: parameters */);
    void addScientist(string name, char gender, int age, int death = 0); // add scientist in to vector
    void removeScientist(string name);
    void scientistSort(int sortType);
    vector<Scientist> findScientistByName(string name);
    vector<Scientist> findScientistByGender(char gender);
    vector<Scientist> findScientistByAge(int age);
    vector<Scientist> findScientistByDeath(int death);

private:

    vector<Scientist> _scientists;
};

#endif // SCIENTISTSERVICE_H
