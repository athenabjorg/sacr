#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <vector>
#include <string>
#include <QtSql>
#include <iostream> // TEMP<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

#include "scientist.h"
#include "computer.h"
#include "relation.h"

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

    int yearComputerBuilt(string computer);

    // ---------------------------------- RELATION FUNCTIONS ---------------------------------- //

    void saveRelation(const Relation newRelation);

    vector<Relation> loadRelations();
    vector<Relation> loadRelations(int loadType, string parameter);
    vector<Relation> loadRelations(int loadType, string parameter1, string parameter2);

    void removeRelation(int removeType, string inputName);
    void removeAllRelations();

    vector<Relation> sortRelations(int sortType);

    bool doesRelationExist(string scientist, string computer);


private:

        QSqlDatabase db;

        string sqlRelationTable();

};

#endif // DATAACCESS_H
