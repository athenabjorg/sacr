#ifndef DATAACCESS_H
#define DATAACCESS_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "scientist.h"

using namespace std;

class DataAccess
{
public:

    DataAccess();

    void saveScientists(const vector<Scientist>& scientists);
        // Saves the vector of scientists to a file.

    vector<Scientist> loadScientists();
        // Loads scientists from a file, into a vector.

private:

};

#endif // DATAACCESS_H
