#include "dataaccess.h"


using namespace std;

DataAccess::DataAccess()
{

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("DataBase.sqlite");  // witch database to select ( aka what file )

}


// ---------------------------------- SCIENTIST FUNCTIONS ---------------------------------- //

void DataAccess::saveScientist(Scientist newScientist)
{   // Saves a scientist to the database.

    string line, name, gender;
    int birthYear, deathYear;


    name = newScientist.getName();
    gender = newScientist.getGender();
    birthYear = newScientist.getBirth();
    deathYear = newScientist.getDeath();


    line = "INSERT INTO Scientists(name,gender,born,died) "
            "VALUES(\"" + name + "\",\"" + gender + "\"," + to_string(birthYear) + "," + to_string(deathYear) + ")";

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input);
    db.close();
}
void DataAccess::updateScientist(Scientist scientist)
{   // Updates the information for an existing scientist.

    string line, name, gender;
    int birthYear, deathYear;


    name = scientist.getName();
    gender = scientist.getGender();
    birthYear = scientist.getBirth();
    deathYear = scientist.getDeath();


    line = "UPDATE Scientists"
           "SET Gender = \"" + gender + "\", born = " + to_string(birthYear) + ", Died = " + to_string(deathYear) + ", Valid = 1"
           "WHERE Name LIKE \"" + name + "\"";

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input);
    db.close();
}

vector<Scientist> DataAccess::loadScientists()
{   // Loads scientists from a database, into a vector.

    vector<Scientist> scientists;
    string name, gender;
    int birthYear, deathYear;

    db.open();
    QSqlQuery query;
    query.exec("SELECT * FROM Scientists WHERE valid = 1");

    while (query.next())
    {
        string name = query.value(1).toString().toStdString();
        string gender = query.value(2).toString().toStdString();
        birthYear = query.value(3).toInt();
        deathYear = query.value(4).toInt();

        Scientist scientist(name, gender[0], birthYear, deathYear);
        scientists.push_back(scientist);
    }

    db.close();
    return scientists;
}
vector<Scientist> DataAccess::loadScientists(int loadType, string parameter)
{   // Adds scientists from a database into a vector, depending on input.
    // 0 = load by exact name, 1 = load by name, 2 = load by gender, 3 = load by birth year
    // 5 = load by death year
    // 4 and 6 are loaded in the loadScientist function with 3 parameters.
    // 7 and 8 (load by age) are loaded in the service class.

    vector<Scientist> scientists;
    string line, name, gender;
    int birthYear, deathYear;


    switch(loadType) // TODO case 2 (gender) virkar ekki
    {
        case 0: line = "SELECT * FROM Scientists  Where Name LIKE \"" + parameter + "\" AND valid = 1"; // load by exact name
                break;
        case 1: line = "SELECT * FROM Scientists  Where Name LIKE \"%" + parameter + "%\" AND valid = 1"; // load by name
                break;
        case 2: line = "SELECT * FROM Scientists  Where Gender LIKE \"%" + parameter + "%\" AND valid = 1"; // load by gender
                break;
        case 3: line = "SELECT * FROM Scientists  Where Born LIKE " + parameter + " AND valid = 1"; // load by birth year
                break;
        case 5: line = "SELECT * FROM Scientists  Where Died LIKE " + parameter + " AND valid = 1"; // load by death year
                break;
    }

    QString input = QString::fromStdString(line);
    db.open();
    QSqlQuery query;
    query.exec(input);

    while (query.next())
    {
        string name = query.value(1).toString().toStdString();
        string gender = query.value(2).toString().toStdString();
        birthYear = query.value(3).toInt();
        deathYear = query.value(4).toInt();

        Scientist scientist(name, gender[0], birthYear, deathYear);
        scientists.push_back(scientist);

    }

    db.close();
    return scientists;
}
vector<Scientist> DataAccess::loadScientists(int loadType, string parameter1, string parameter2)
{   // Adds scientists from a database into a vector, depending on input.
    // 4 = load by birth year range, 6 = load by death year range, 8 = load by age range.
    // 1, 2, 3, and 5 are used in the loadScientist function with 2 parameters.
    // 7 and 8 are sorted in the service class.

    vector<Scientist> scientists;
    string line, name, gender;
    int birthYear, deathYear;

    switch(loadType)
    {
        case 4: line = "SELECT * FROM scientists WHERE Born BETWEEN " + parameter1 + " AND " + parameter2 + " AND valid = 1"; // load by birth year range
                break;
        case 6: line = "SELECT * FROM scientists WHERE Died BETWEEN " + parameter1 + " AND " + parameter2 + " AND valid = 1"; // load by death year range
                break;
    }

    QString input = QString::fromStdString(line);
    db.open();
    QSqlQuery query;
    query.exec(input);

    while (query.next())
    {
        string name = query.value(1).toString().toStdString();
        string gender = query.value(2).toString().toStdString();
        birthYear = query.value(3).toInt();
        deathYear = query.value(4).toInt();

        Scientist scientist(name, gender[0], birthYear, deathYear);
        scientists.push_back(scientist);

    }

    db.close();
    return scientists;
}

void DataAccess::removeScientist(string inputName)
{   // Removes scientists by name.

    string line;

    line = "UPDATE Scientists SET Valid = 0 WHERE Name LIKE \"%" + inputName + "%\"";

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input); // open table scientists
    db.close();

    removeRelation(1, inputName);
}
void DataAccess::removeAllScientists()
{   // Removes all scientists from the database. Careful!

    string line;

    line = "DELETE FROM Scientists";

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input); // open table scientists
    db.close();

    removeAllRelations();
}

vector<Scientist> DataAccess::sortScientists(int sortType)
{   // Sort by sortType: 1 = name(A-Z), 2 = name(Z-A), 3 = gender(f-m), 4 = gender(m-f), 5 = birth year(0-9),
    // 6 = birth year(9-0) 7 = death year(0-9), 8 = death year(9-0)
    // 9 and 10 (sort by age) are sorted in the service class.

    vector<Scientist> scientists;
    string line, name, gender;
    int birthYear, deathYear;

    switch(sortType)
    {
        case 1: line = "SELECT * FROM Scientists WHERE valid = 1 ORDER BY Name ASC"; // sort by name(A-Z)
                break;
        case 2: line = "SELECT * FROM Scientists WHERE valid = 1 ORDER BY Name DESC"; // sort by name(Z-A)
                break;
        case 3: line = "SELECT * FROM Scientists WHERE valid = 1 ORDER BY Gender ASC"; // sort by gender(f-m)
                break;
        case 4: line = "SELECT * FROM Scientists WHERE valid = 1 ORDER BY Gender DESC"; // sort by gender(m-f)
                break;
        case 5: line = "SELECT * FROM Scientists WHERE valid = 1 ORDER BY Born ASC"; // sort by birth year(0-9)
                break;
        case 6: line = "SELECT * FROM Scientists WHERE valid = 1 ORDER BY Born DESC"; // sort by birth year(9-0)
                break;
        case 7: line = "SELECT * FROM Scientists WHERE valid = 1 ORDER BY DIED ASC"; // sort by death year(0-9)
                break;
        case 8: line = "SELECT * FROM Scientists WHERE valid = 1 ORDER BY DIED DESC"; // sort by death year(9-0)
                break;
    }

    QString input = QString::fromStdString(line);
    db.open();
    QSqlQuery query;
    query.exec(input);

    while (query.next())
    {
        string name = query.value(1).toString().toStdString();
        string gender = query.value(2).toString().toStdString();
        birthYear = query.value(3).toInt();
        deathYear = query.value(4).toInt();


        Scientist scientist(name, gender[0], birthYear, deathYear);
        scientists.push_back(scientist);

    }

    db.close();
    return scientists;
}

bool DataAccess::doesScientistExist(string name)
{   //checks if a scientist by that name exists already

    vector<Scientist> scientists;

    scientists = loadScientists(0, name);

    if(scientists.size() > 0)
    {
        return true;
    }

    return false;
}


// ---------------------------------- COMPUTER FUNCTIONS ---------------------------------- //

void DataAccess::saveComputer(Computer newComputer)
{   // Saves a computer to the database.

    string line, name, type;
    int year;
    bool built;

    name = newComputer.getName();
    type = newComputer.getType();
    year = newComputer.getYear();
    built = newComputer.getBuilt();

    line = "INSERT INTO Computers(name,type,year,built) "
            "VALUES(\"" + name + "\",\"" + type + "\"," + to_string(year) + "," + to_string(built) + ")";

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input);
    db.close();
}
void DataAccess::updateComputer(Computer computer)
{   // Updates the information for an existing computer.

    string line, name, type;
    int year;
    bool built;


    name = computer.getName();
    type = computer.getType();
    year = computer.getYear();
    built = computer.getBuilt();


    line = "UPDATE Computers "
           "SET Type = \"" + type + "\", year = " + to_string(year) + ", built = " + to_string(built) + ", Valid = 1 "
           "WHERE Name LIKE \"" + name + "\"";
    cout << line << endl;

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input);
    db.close();


}

vector<Computer> DataAccess::loadComputers()
{   // Adds list of computers from a database into a vector.

    vector<Computer> computers;
    string line, name, type;
    int year;
    bool built;

    line = "SELECT * FROM computers WHERE valid = 1 ";

    QString input = QString::fromStdString(line);
    db.open();
    QSqlQuery query;
    query.exec(input);

    while (query.next())
    {
        name = query.value(1).toString().toStdString();
        year = query.value(2).toInt();
        type = query.value(3).toString().toStdString();
        built = query.value(4).toBool();


        Computer computer(name, year, type, built);
        computers.push_back(computer);

    }

    db.close();
    return computers;
}
vector<Computer> DataAccess::loadComputers(int loadType, string parameter)
{   // Loads computers from a database, into a vector, depenting on loadType.
    // 0 = load by exact name, 1 = load by name, 2 = load by year built, 4 = load by type, 5 = load by if built.
    // 3 is used in the loadScientist function with 3 parameters.

    vector<Computer> computers;
    string line, name, type;
    int year;
    bool built;


    switch(loadType)
    {
        case 0: line = "SELECT * FROM Computers Where Name LIKE \"" + parameter + "\" AND valid = 1"; // load by exact name
                break;
        case 1: line = "SELECT * FROM Computers Where Name LIKE \"%" + parameter + "%\" AND valid = 1"; // load by name
                break;
        case 2: line = "SELECT * FROM Computers Where Year LIKE \"%" + parameter + "%\" AND valid = 1"; // load by year built
                break;
        case 4: line = "SELECT * FROM Computers Where Type LIKE  \"" + parameter + "\" AND valid = 1"; // load by type
                break;
        case 5: line = "SELECT * FROM Computers Where Built LIKE " + parameter + " AND valid = 1"; // load by if built
                break;
    }

    QString input = QString::fromStdString(line);
    db.open();
    QSqlQuery query;
    query.exec(input);

    while (query.next())
    {
        name = query.value(1).toString().toStdString();
        year = query.value(2).toInt();
        type = query.value(3).toString().toStdString();
        built = query.value(4).toBool();


        Computer computer(name, year, type, built);
        computers.push_back(computer);

    }

    db.close();
    return computers;
}
vector<Computer> DataAccess::loadComputers(int loadType, string parameter1, string parameter2)
{   // Loads computers from a database, into a vector, depenting on loadType.
    // 3 = load by build year range.
    // 0, 1, 2 and 5 are used in the loadScientist function with 2 parameters.

    vector<Computer> computers;
    string line, name, type;
    int year;
    bool built;


    switch(loadType)
    {
        case 3: line = "SELECT * FROM computers WHERE year BETWEEN " + parameter1 + " AND " + parameter2 + " AND valid = 1"; // load by build/design year range
                break;
    }

    QString input = QString::fromStdString(line);
    db.open();
    QSqlQuery query;
    query.exec(input);

    while (query.next())
    {
        name = query.value(1).toString().toStdString();
        year = query.value(2).toInt();
        type = query.value(3).toString().toStdString();
        built = query.value(4).toBool();


        Computer computer(name, year, type, built);
        computers.push_back(computer);
    }

    db.close();
    return computers;
}

void DataAccess::removeComputer(string inputName)
{   // Removes computers by name.

    string line;

    line = "UPDATE Computers SET Valid = 0 WHERE Name LIKE \"%" + inputName + "%\"";

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input); // open table scientists
    db.close();

    removeRelation(2, inputName);
}
void DataAccess::removeAllComputers()
{   // Removes all computers from the database. Careful!

    string line;

    line = "DELETE FROM Computers";

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input);
    db.close();

    removeAllRelations();
}

vector<Computer> DataAccess::sortComputers(int sortType)
{   // Sort by sortType: 1 = name(A-Z), 2 = name(Z-A), 3 = type(A-Z), 4 = type(Z-A), 5 = year made(0-9),
    // 6 = year made(9-0), 7 = if built(n-y), 8 = if built (y-n).
    // 9 and 10 (sort by years since built) are sorted in the service class.

    vector<Computer> computers;
    string line, name, type;
    int year;
    bool built;

    switch(sortType)
    {
        case 1: line = "SELECT * FROM Computers WHERE valid = 1 ORDER BY Name ASC"; // sort by name(A-Z)
                break;
        case 2: line = "SELECT * FROM Computers WHERE valid = 1 ORDER BY Name DESC"; // sort by name(Z-A)
                break;
        case 3: line = "SELECT * FROM Computers WHERE valid = 1 ORDER BY Year ASC"; // sort by Year(0-9)
                break;
        case 4: line = "SELECT * FROM Computers WHERE valid = 1 ORDER BY Year DESC"; // sort by Year(9-0)
                break;
        case 5: line = "SELECT * FROM Computers WHERE valid = 1 ORDER BY Type ASC"; // sort by type(A-Z)
                break;
        case 6: line = "SELECT * FROM Computers WHERE valid = 1 ORDER BY Type DESC"; // sort by type(Z-A)
                break;
        case 7: line = "SELECT * FROM Computers WHERE valid = 1 ORDER BY Built ASC"; // sort by if built(N-Y)
                break;
        case 8: line = "SELECT * FROM Computers WHERE valid = 1 ORDER BY Built DESC"; // sort by if built(Y-N)
                break;
    }

    QString input = QString::fromStdString(line);
    db.open();
    QSqlQuery query;
    query.exec(input);

    while (query.next())
    {
        string name = query.value(1).toString().toStdString();
        string type = query.value(3).toString().toStdString();
        year = query.value(2).toInt();
        built = query.value(4).toBool();

        Computer computer(name, year, type, built);
        computers.push_back(computer);
    }

    db.close();
    return computers;
}

bool DataAccess::doesComputerExist(string name)
{   // Checks if a computer by that name exists already

    vector<Computer> computers;

    computers = loadComputers(0, name);

    if(computers.size() > 0)
    {
        return true;
    }

    return false;
}

int DataAccess::yearComputerBuilt(string computer)
{   // Returns what year a computer was built.

    string line;
    int year;

    line = "SELECT year FROM computers WHERE name LIKE \"" + computer + "\"AND valid = 1 ";

    QString input = QString::fromStdString(line);
    db.open();

    QSqlQuery query;
    query.exec(input);
    query.next();

    year = query.value(0).toInt();

    db.close();

    return year;
}


// ---------------------------------- RELATION FUNCTIONS ---------------------------------- //

void DataAccess::saveRelation(const Relation newRelation)
{   // Saves a relation to the database.

    string line, scientist, computer, scientistID, computerID;

    scientist = newRelation.getScientist();
    computer = newRelation.getComputer();

    db.open();
    QSqlQuery query;
    QString input;

    line = "SELECT ID FROM Scientists WHERE name LIKE \"" + scientist + "\"";
    input = QString::fromStdString(line);
    query.exec(input);
    query.next();
    scientistID = query.value(0).toString().toStdString();


    line = "SELECT ID FROM Computers WHERE name LIKE \"" + computer + "\"";
    input = QString::fromStdString(line);
    query.exec(input);
    query.next();
    computerID = query.value(0).toString().toStdString();

    line = "INSERT INTO Relations (ScientistID, computerID) VALUES (" + scientistID + ", " + computerID + ")";

    input = QString::fromStdString(line);

    query.exec(input);
    db.close();

}

vector<Relation> DataAccess::loadRelations()
{   // Loads relations from a database, into a vector, depenting on loadType.

    vector<Relation> relations;
    string line, scientist, computer, scientistID, computerID;
    int year;

    line = sqlRelationTable();

    QString input = QString::fromStdString(line);
    db.open();
    QSqlQuery query;

    query.exec(input);

    while (query.next())
    {

        scientist = query.value(0).toString().toStdString();
        computer = query.value(1).toString().toStdString();
        year = query.value(2).toInt();

        Relation relation(scientist, computer, year);
        relations.push_back(relation);

    }
    db.close();

    return relations;

}
vector<Relation> DataAccess::loadRelations(int loadType, string parameter)
{   // Loads relations from a database, into a vector, depenting on loadType.
    // 0 = load by exact scientist name, 1 = load by scientist name,
    // 2 = load by exact computer name, 3 = load by computer name, 4 = load by year computer built
    // 5 is loaded in the loadRelations function with three parameters.

    vector<Relation> relations;
    string line, computer, scientist;
    int year;

    switch(loadType)
    {
        case 0: line = sqlRelationTable() + "Where scientist LIKE \"" + parameter + "\" AND r.valid = 1"; // load by exact scientist name
                break;
        case 1: line = sqlRelationTable() + "Where scientist LIKE \"%" + parameter + "%\" AND r.valid = 1"; // load by scientist name
                break;
        case 2: line = sqlRelationTable() + "Where computer LIKE \"" + parameter + "\" AND r.valid = 1"; // load by whole computer name
                break;
        case 3: line = sqlRelationTable() + "Where computer LIKE \"%" + parameter + "%\" AND r.valid = 1"; // load by computer name
                break;
        case 4: line = sqlRelationTable() + "Where year LIKE \"" + parameter + "\" AND r.valid = 1"; // load by year computer built
                break;
    }

    cout << line << endl;

    QString input = QString::fromStdString(line);
    db.open();
    QSqlQuery query;
    query.exec(input);

    while (query.next())
    {
        scientist = query.value(0).toString().toStdString();
        computer = query.value(1).toString().toStdString();
        year = query.value(2).toInt();

        Relation relation(scientist, computer, year);
        relations.push_back(relation);

    }

    db.close();

    return relations;
}
vector<Relation> DataAccess::loadRelations(int loadType, string parameter1, string parameter2)
{   // Loads relations from a database, into a vector, depenting on loadType.
    // 5 = load by year built range.
    // 0, 1, 2, 3 and 4 are loaded in the loadRelations function with two parameters.

    vector<Relation> relations;
    string line, computer, scientist;
    int year;

    switch(loadType)
    {
        case 5: line = sqlRelationTable() + "WHERE year BETWEEN " + parameter1 + " AND " + parameter2 + " AND r.valid = 1"; // load by year range when computer built
                break;
    }

    QString input = QString::fromStdString(line);
    db.open();
    QSqlQuery query;
    query.exec(input);

    while (query.next())
    {
        scientist = query.value(0).toString().toStdString();
        computer = query.value(1).toString().toStdString();
        year = query.value(2).toInt();

        Relation relation(scientist, computer, year);
        relations.push_back(relation);
    }

    db.close();

    return relations;
}

void DataAccess::removeRelation(int removeType, string inputName)
{   // Removes relation by either; removeType 1 = scientist name, 2 = computer name.

    string line, scientistID, computerID;

    db.open();
    QSqlQuery query;
    QString input;

    switch(removeType)
    {
        case 1: line = "SELECT ID FROM Scientists WHERE name LIKE \"" + inputName + "\"";
                input = QString::fromStdString(line);
                query.exec(input);
                query.next();
                scientistID = query.value(0).toString().toStdString();

                line = "UPDATE Relations SET Valid = 0 WHERE ScientistID LIKE \"%" + scientistID + "%\"";
                break;

        case 2: line = "SELECT ID FROM Computers WHERE name LIKE \"" + inputName + "\"";
                input = QString::fromStdString(line);
                query.exec(input);
                query.next();
                computerID = query.value(0).toString().toStdString();

                line = "UPDATE Relations SET Valid = 0 WHERE ComputerID LIKE \"%" + computerID + "%\"";
                break;
    }

    input = QString::fromStdString(line);
    query.exec(input);

    db.close();
}
void DataAccess::removeAllRelations()
{   // Removes all relations from the database. Careful!

    string line;

    line = "DELETE FROM Relations";

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input);
    db.close();

}

vector<Relation> DataAccess::sortRelations(int sortType)
{   // Sort by sortType: 1 = scientist name(A-Z), 2 = scientist name(Z-A), 3 = computer name(A-Z)
    // 4 = computer name(Z-A), 5 = year made(0-9), 6 = year made(9-0).

    vector<Relation> relations;
    string line, scientist, computer;
    int year;

    switch(sortType)
    {
        case 1: line = sqlRelationTable() + "WHERE r.valid = 1 ORDER BY Scientist ASC"; // sort by scientist name(A-Z)
                break;
        case 2: line = sqlRelationTable() + "WHERE r.valid = 1 ORDER BY Scientist DESC"; // sort by scientist name(Z-A)
                break;
        case 3: line = sqlRelationTable() + "WHERE r.valid = 1 ORDER BY Computer ASC"; // sort by computer name(A-Z)
                break;
        case 4: line = sqlRelationTable() + "WHERE r.valid = 1 ORDER BY Computer DESC"; // sort by computer name(Z-A)
                break;
        case 5: line = sqlRelationTable() + "WHERE r.valid = 1 ORDER BY Year ASC"; // sort by year made(0-9)
                break;
        case 6: line = sqlRelationTable() + "WHERE r.valid = 1 ORDER BY Year DESC"; // sort by year made(9-0)
                break;
    }

    QString input = QString::fromStdString(line);
    db.open();
    QSqlQuery query;
    query.exec(input);

    while (query.next())
    {
        scientist = query.value(0).toString().toStdString();
        computer = query.value(1).toString().toStdString();
        year = query.value(2).toInt();

        Relation relation(scientist, computer, year);
        relations.push_back(relation);
    }

    db.close();
    return relations;
}

bool DataAccess::doesRelationExist(string scientist, string computer)
{   // Checks if a relation between that scientist and computer exists already

    string line;
    bool valid;

    db.open();
    QSqlQuery query;

    line = sqlRelationTable() + "WHERE scientist LIKE \"" + scientist + "\" AND computer LIKE \"" + computer + "\"";

    QString input = QString::fromStdString(line);

    query.exec(input);

    while (query.next())
    {
        valid = query.value(3).toBool();

        if(valid)
        {
            db.close();
            return true;
        }
    }

    db.close();

    return false;
}

string DataAccess::sqlRelationTable()
{   // Returns a SQL query string that is used as a base for the relation function queries;
    // Column 0 = scientist, 1 = computer, 2 = year, 3 = valid.

    string line;

    line = "SELECT s.Name AS 'Scientist', c.Name AS 'Computer', c.Year, r.Valid AS 'Valid' "
           "FROM Relations r "
           "JOIN Scientists s ON s.ID = r.ScientistID "
           "JOIN Computers c ON c.ID = r.ComputerID ";

    return line;
}
