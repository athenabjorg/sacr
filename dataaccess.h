#ifndef DATAACCESS_H
#define DATAACCESS_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <QtSql>

#include "scientist.h"
#include "computer.h"

using namespace std;

class DataAccess
{
public:

    DataAccess();

    void saveScientist(Scientist newScientist);
        // Saves a scientist to the database.

    vector<Scientist> loadScientists();
    vector<Scientist> loadScientists(int loadType, string parameter);
    vector<Scientist> loadScientists(int loadType, string parameter1, string parameter2);
        // Loads scientists from a database, into a vector.

    bool doesScientistExist(string name);

    void removeScientist(string inputName);

    void removeAllScientists();

    vector<Scientist> sortScientists(int sortType);


    void saveComputer(Computer newComputer);

    vector<Computer> loadComputers();
    vector<Computer> loadComputers(int loadType, string parameter);
    vector<Computer> loadComputers(int loadType, string parameter1, string parameter2);

    void removeComputer(string inputName);
    void removeAllComputers();


    vector<Computer> sortComputers(int sortType);

    bool doesComputerExist(string name);

private:

        QSqlDatabase db;

};

#endif // DATAACCESS_H
