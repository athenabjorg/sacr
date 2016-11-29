#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include <vector>
#include "scientist.h"

using namespace std;

class ScientistService
{
public:
    ScientistService();

    //
    vector<Scientist> getScientists(/* TODO: parameters */);
    void addScientist(string name, char gender, int age, int death = 0); // add scientist in to vector
    void scientistSort(int sortType);


private:

    vector<Scientist> _scientists;
};

#endif // SCIENTISTSERVICE_H
