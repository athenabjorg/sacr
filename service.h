#ifndef service_H
#define service_H

#include <vector>
#include <algorithm>   // <---------- remove?
#include <string>

#include "dataaccess.h"
#include "scientist.h"
#include "computer.h"
#include "relation.h"

using namespace std;

class service
{
public:

    service();

    string getFunFact();

    // ---------------------------------- SCIENTIST FUNCTIONS ---------------------------------- //

    vector<Scientist> getScientists();
    // Uploads the list of scientists from database.

    bool addScientist(string name, char gender, int birth, int death);
    // Adds a scientist to the database.
    // Returns true if adding succeded, false otherwise.

    bool updateScientist(string name, char gender, int birth, int death);
    // Updates a scientist in the database.
    // Returns true if adding succeded, false otherwise.

    bool removeScientist(string name);
    // Removes a scientist with that name from the database. Case insensitive.
    // Returns true if removing succeded, false otherwise.e.

    void removeAllScientists();
    // Removes ALL scientists from the list. Be careful with this.

    vector<Scientist> scientistSort(int sortType);
    // Sort by sortType: 1 = name(A-Z), 2 = name(Z-A), 3 = gender(f-m), 4 = gender(m-f), 5 = birth year(0-9),
    // 6 = birth year(9-0) 7 = death year(0-9), 8 = death year(9-0), 9 = age(0-9), 10 = age(9-0).

    vector<Scientist> findScientist(int findType, string parameter);
    vector<Scientist> findScientist(int findType, string parameter1, string parameter2);
    // Returns all scientists whos name includes the string entered. Case insensitive.
    // findType 0 = load by exact name, 1 = load by name, 2 = load by gender, 3 = load by birth year
    // 4 = load by birth year range, 5 = load by death year, 6 = death year range, 7 = load by age, 8 = load by age range.

    bool doesScientistExist(string name);
    // Checks if a scientist by that name exists already

    Scientist getScientistInfo(string name);

    // ---------------------------------- COMPUTER FUNCTIONS ---------------------------------- //

    vector<Computer> getComputers();
    // Uploads the list of copmuters from database.

    bool addComputer(string name, int year, string type, bool built);
    // Adds a copmuter to the database.
    // Returns true if adding succeded, false otherwise.

    bool updateComputer(string name, int year, string type, bool built);
    // Updates a computer in the database.
    // Returns true if adding succeded, false otherwise.

    bool removeComputer(string name);
    // Removes a computer with that name from the database. Case insensitive.
    // Returns true if removing succeded, false otherwise.

    void removeAllComputers();
    // Removes ALL copmuters from the list. Be careful with this.

    vector<Computer> computerSort(int sortType);
    // Sort by sortType: 1 = name(A-Z), 2 = name(Z-A), 3 = type(A-Z), 4 = type(Z-A), 5 = year made(0-9),
    // 6 = year made(9-0), 7 = if built(n-y), 8 = if built (y-n), 9 = years since built(0-9), 10 = years since built(0-9)

    vector<Computer> findComputer(int findType, string parameter);
    vector<Computer> findComputer(int findType, string parameter1, string parameter2);
    // Loads computers from a database, into a vector, depenting on loadType.
    // 0 = load by exact name, 1 = load by name, 2 = load by year built
    // 3 = load by year built range, 4 = load by type, 5 = load by if built.

    bool doesComputerExist(string name);
    // Checks if a computer by that name exists already

    // ---------------------------------- RELATION FUNCTIONS ---------------------------------- //

    vector<Relation> getRelations();
    // Uploads the list of relations from database.

    bool addRelation(string scientist, string computer);
    // Adds a relation to the database.
    // Returns true if adding succeded, false otherwise.

    bool removeRelation(int removeType, string name);
    // Removes a relation with that name from the database. Case insensitive.
    // Returns true if removing succeded, false otherwise.
    bool removeRelation(string scientist, string computer);
    // Removes a relation with that scientist and computer name from the database. Case insensitive.
    // Returns true if removing succeded, false otherwise.
    void removeAllRelations();
    // Removes ALL relations from the list. Be careful with this.

    vector<Relation> relationSort(int sortType);
    // Sort by sortType: 1 = scientist name(A-Z), 2 = scientist name(Z-A), 3 = computer name(A-Z)
    // 4 = computer name(Z-A), 5 = year made(0-9), 6 = year made(9-0).

    vector<Relation> findRelation(int findType, string parameter);
    vector<Relation> findRelation(int findType, string parameter1, string parameter2);
    // Loads relations from a database, into a vector, depenting on loadType.
    // 0 = load by exact scientist name, 1 = load by scientist name,
    // 2 = load by exact computer name, 3 = load by computer name, 4 = load by year computer built
    // 5 = load by year built range, 6 = load by exact scientist and computer.

    bool doesRelationExist(string scientist, string computer);
    // Checks if a relation by that name exists already


private:

    vector<Scientist> _scientists;
    vector<Computer> _computers;
    vector<Relation> _relations;

    DataAccess _data;

};

#endif // service_H
