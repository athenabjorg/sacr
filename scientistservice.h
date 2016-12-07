#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include <vector>
#include <algorithm>
#include <string>
#include "scientist.h"
#include "dataaccess.h"
#include "computer.h"

using namespace std;

class ScientistService
{
public:

    ScientistService();

    vector<Scientist> getScientists();
        // Uploads the list of scientists from file.

    bool addScientist(string name, char gender, int birth, int death);
        // Adds a scientist to the list and updates the file.
        // Returns true if adding succeded, false otherwise.

    bool removeScientist(string name);
        // Removes a scientist with that name from the vector. Case insensitive.
        // Returns true if removing succeded, false otherwise.

    void removeAllScientists();
        // Removes ALL scientists from the list. Be careful with this.

    vector<Scientist> scientistSort(int sortType);
        // Sort by sortType: 1 = name(A-Z), 2 = name(Z-A), 3 = gender (f-m), 4 = gender (m-f),
        // 5 = birth year(0-9), 6 = birth year(9-0) 7 = death year(0-9), 8 = age(0-9), 9 = age(9-0)
    vector<Computer> computerSort(int sortType);



    vector<Scientist> findScientist(int findType, string parameter);
    vector<Scientist> findScientist(int findType, string parameter1, string parameter2);

    vector<Computer> findComputer(int findType, string parameter);
    vector<Computer> findComputer(int findType, string parameter1, string parameter2);






private:

    vector<Scientist> _scientists;

    DataAccess _data;

};

#endif // SCIENTISTSERVICE_H
