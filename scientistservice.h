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

    void scientistSort(int sortType);
        // Sort list by parameter: 1 = name(A-Z), 2 = name(Z-A), 3 = gender,
        //                              4 = birth, 5 = death, 6 = age.

    vector<Scientist> findScientistByName(string name);
        // Returns all scientists whos name includes the string entered. Case insensitive.

    vector<Scientist> findScientistByGender(char gender);
        // Returns all scientists of that gender.

    vector<Scientist> findScientistByBirth(int birth);
        // Returns all scientists born that year.

    vector<Scientist> findScientistByBirthRange(int birth1, int birth2);
        // Returns all scientists born in that year range.

    vector<Scientist> findScientistByDeath(int death);
        // Returns all scientists that died that year, or death = 0 if still alive.

    vector<Scientist> findScientistByDeathRange(int death1, int death2);
        // Returns all scientists who died in that year range.

    vector<Scientist> findScientistByAge(int age);
        // Returns all scientists of that age.

    vector<Scientist> findScientistByAgeRange(int age1, int age2);
        // Returns all scientists in that age range.



private:

    vector<Scientist> _scientists;

    DataAccess _data;

    void scientistSortForFind(int sortType, vector<Scientist>& scientists);
        // Sort list by sortType: 1 = name(A-Z), 2 = name(Z-A), 3 = gender,
        //                              4 = birth, 5 = death, 6 = age.
        // Sorts the list provided by the find function without saving to file,
        // so that the search result is displayed according to the search type.
};

#endif // SCIENTISTSERVICE_H
