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
    void saveScientists(vector<Scientist>& scientists);
    vector<Scientist> loadScientists();

private:

};

#endif // DATAACCESS_H
