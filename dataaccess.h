#ifndef DATAACCESS_H
#define DATAACCESS_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <QtSql>

#include "scientist.h"

using namespace std;

class DataAccess
{
public:

    DataAccess();

    void saveScientists(Scientist newScientist);
        // Saves the vector of scientists to a file.

    vector<Scientist> loadScientists();
        // Loads scientists from a file, into a vector.

    void removeScientist(string inputName);
    void removeAllScientists();


    vector<Scientist> loadScientistByName(string name);
    vector<Scientist> loadScientistByGender(char inputGender);
    vector<Scientist> loadScientistByBirth(int inputBirth);
    vector<Scientist> loadScientistByBirthRange(int inputBirth1, int inputBirth2);
    vector<Scientist> loadScientistByDeath(int inputDeath);
    vector<Scientist> loadScientistByDeathRange(int inputDeath1, int inputDeath2);

private:

        QSqlDatabase db;

};

#endif // DATAACCESS_H
