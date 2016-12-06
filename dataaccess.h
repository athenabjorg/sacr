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

private:

        QSqlDatabase db;

};

#endif // DATAACCESS_H
