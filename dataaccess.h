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
    void updateScientist(Scientist scientist);
        // Updates the information for an existing scientist.

    vector<Scientist> loadScientists();
    vector<Scientist> loadScientists(int loadType, string parameter);
    vector<Scientist> loadScientists(int loadType, string parameter1, string parameter2);
        // Loads scientists from a database, into a vector, depenting on loadType.
        // 0 = load by exact name, 1 = load by name, 2 = load by gender, 3 = load by birth year
        // 4 = load by birth year range, 5 = load by death year, 6 = death year range.
        // 7 and 8 are loaded in the service class.

    void removeScientist(string inputName);
        // Removes scientists by name.
    void removeAllScientists();
        // Removes all scientists from the database. Careful!

    vector<Scientist> sortScientists(int sortType);
        // Sort by sortType: 1 = name(A-Z), 2 = name(Z-A), 3 = gender(f-m), 4 = gender(m-f), 5 = birth year(0-9),
        // 6 = birth year(9-0) 7 = death year(0-9), 8 = death year(9-0)
        // 9 and 10 (sort by age) are sorted in the service class.

    bool doesScientistExist(string name);
        // Checks if a scientist by that name exists already

    // ---------------------------------- COMPUTER FUNCTIONS ---------------------------------- //

    void saveComputer(Computer newComputer);
        // Saves a computer to the database.
    void updateComputer(Computer computer);
        // Updates the information for an existing computer.

    vector<Computer> loadComputers();
    vector<Computer> loadComputers(int loadType, string parameter);
    vector<Computer> loadComputers(int loadType, string parameter1, string parameter2);
        // Loads computers from a database, into a vector, depenting on loadType.
        // 0 = load by exact name, 1 = load by name, 2 = load by gender, 3 = load by birth year
        // 4 = load by birth year range, 5 = load by death year, 6 = death year range.
        // 7 and 8 are loaded in the service class.

    void removeComputer(string inputName);
        // Removes computers by name.
    void removeAllComputers();
        // Removes all computers from the database. Careful!

    vector<Computer> sortComputers(int sortType);
        // Sort by sortType: 1 = name(A-Z), 2 = name(Z-A), 3 = gender(f-m), 4 = gender(m-f), 5 = birth year(0-9),
        // 6 = birth year(9-0) 7 = death year(0-9), 8 = death year(9-0)
        // 9 and 10 (sort by age) are sorted in the service class.

    bool doesComputerExist(string name);
        // Checks if a computer by that name exists already

    int yearComputerBuilt(string computer);
        // Returns what year a copmuter was built.

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
