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
    vector<Scientist> getScientist(/* TODO: parameters */);
};

#endif // SCIENTISTSERVICE_H
