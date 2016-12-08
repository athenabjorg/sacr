#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <vector>
#include <string>
#include <QtSql>
#include <iostream> // TEMP<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

#include "scientist.h"
#include "computer.h"


using namespace std;

class DataAccess
{
public:

    DataAccess();


    // ---------------------------------- SCIENTIST FUNCTIONS ---------------------------------- //

    void saveScientist(Scientist newScientist);
        // Saves a scientist to the database.

    vector<Scientist> loadScientists();
    vector<Scientist> loadScientists(int loadType, string parameter);
    vector<Scientist> loadScientists(int loadType, string parameter1, string parameter2);
        // Loads scientists from a database, into a vector.

    void removeScientist(string inputName);
    void removeAllScientists();

    vector<Scientist> sortScientists(int sortType);

    bool doesScientistExist(string name);


    // ---------------------------------- COMPUTER FUNCTIONS ---------------------------------- //

    void saveComputer(Computer newComputer);

    vector<Computer> loadComputers();
    vector<Computer> loadComputers(int loadType, string parameter);
    vector<Computer> loadComputers(int loadType, string parameter1, string parameter2);

    void removeComputer(string inputName);
    void removeAllComputers();

    vector<Computer> sortComputers(int sortType);

    bool doesComputerExist(string name);


    // ---------------------------------- RELATION FUNCTIONS ---------------------------------- //

    // relations functions go here


private:

        QSqlDatabase db;

};

#endif // DATAACCESS_H
