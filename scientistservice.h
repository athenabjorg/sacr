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
    vector<Scientist> getScientists();
    bool addScientist(string name, char gender, int birth, int death, int age);
    bool removeScientist(string name);
    void removeAllScientists();
    void scientistSort(int sortType);

    vector<Scientist> findScientistByName(string name);
    vector<Scientist> findScientistByGender(char gender);
    vector<Scientist> findScientistByBirth(int birth);
    vector<Scientist> findScientistByBirthRange(int birth1, int birth2);
    vector<Scientist> findScientistByDeath(int death);
    vector<Scientist> findScientistByDeathRange(int death1, int death2);
    vector<Scientist> findScientistByAge(int age);
    vector<Scientist> findScientistByAgeRange(int age1, int age2);

private:

    vector<Scientist> _scientists;

    void scientistSortForFind(int sortType, vector<Scientist>& scientists);
};

#endif // SCIENTISTSERVICE_H
