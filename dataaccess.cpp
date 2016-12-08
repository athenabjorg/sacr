#include "dataaccess.h"


using namespace std;

DataAccess::DataAccess()
{

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("DataBase.sqlite");  // witch database to select ( aka what file )

}


// ---------------------------------- SCIENTIST FUNCTIONS ---------------------------------- //

void DataAccess::saveScientist(Scientist newScientist)  // Saving to SQLite database
{
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

vector<Scientist> DataAccess::loadScientists()                  // From text file to vector
{
    /*
     * This function uses SQLite Manager database and adds scientits table into a vector.
     */

    vector<Scientist> scientists;
    string name, gender;
    int birthYear, deathYear;
    bool valid;

    db.open();
    QSqlQuery query;
    query.exec("SELECT * FROM Scientists");

    while (query.next())
    {
        string name = query.value(1).toString().toStdString();
        string gender = query.value(2).toString().toStdString();
        birthYear = query.value(3).toInt();
        deathYear = query.value(4).toInt();
        valid = query.value(5).toBool();

        if(valid)
        {
            Scientist scientist(name, gender[0], birthYear, deathYear);
            scientists.push_back(scientist);
        }
    }

    db.close();
    return scientists;
}
vector<Scientist> DataAccess::loadScientists(int loadType, string parameter)                  // From text file to vector
{
    /*
     * This function uses SQLite Manager database and adds scientits table into a vector.
     * 1 = load by name, 2 = load by gender, 3 = load by birth year
     * 5 = load by death year, 7 = load by age, 9 load by ...
     * 4, 6 and 8 are used in the loadScientist function with 3 parameters.
     */

    vector<Scientist> scientists;
    string line, name, gender;
    int birthYear, deathYear;
    bool valid;


    switch(loadType) // TODO case 2 (gender) virkar ekki
    {
        case 0: line = "SELECT * FROM Scientists  Where Name LIKE \"" + parameter + "\""; // load by whole name
                break;
        case 1: line = "SELECT * FROM Scientists  Where Name LIKE \"%" + parameter + "%\""; // load by name
                break;
        case 2: line = "SELECT * FROM Scientists  Where Gender LIKE \"%" + parameter + "%\""; // load by gender
                break;
        case 3: line = "SELECT * FROM Scientists  Where Born LIKE " + parameter; // load by birth year
                break;
        case 5: line = "SELECT * FROM Scientists  Where Died LIKE " + parameter; // load by death year
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
        valid = query.value(5).toBool();

        if(valid)
        {
            Scientist scientist(name, gender[0], birthYear, deathYear);
            scientists.push_back(scientist);
        }
    }

    db.close();
    return scientists;
}
vector<Scientist> DataAccess::loadScientists(int loadType, string parameter1, string parameter2)
{
    /*
     * This function uses SQLite Manager database and adds scientits table into a vector.
     * 4 = load by birth year range, 6 = load by death year range, 8 = load by age range.
     * 1, 2, 3, 5 and 7 are used in the loadScientist function with 2 parameters.
     */

    vector<Scientist> scientists;
    string line, name, gender;
    int birthYear, deathYear;
    bool valid;


    switch(loadType)
    {
        case 4: line = "SELECT * FROM scientists WHERE Born BETWEEN " + parameter1 + " AND " + parameter2; // load by birth year range
                break;
        case 6: line = "SELECT * FROM scientists WHERE Died BETWEEN " + parameter1 + " AND " + parameter2; // load by death year range
                break;
        case 8: // load by age range
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
        valid = query.value(5).toBool();

        if(valid)
        {
            Scientist scientist(name, gender[0], birthYear, deathYear);
            scientists.push_back(scientist);
        }
    }

    db.close();
    return scientists;
}

void DataAccess::removeScientist(string inputName)
{
    string line;

    line = "UPDATE Scientists SET Valid = 0 WHERE Name LIKE \"%" + inputName + "%\"";

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input); // open table scientists
    db.close();

    removeRelation(1, inputName);
}
void DataAccess::removeAllScientists() // Not practical
{
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
    // 6 = birth year(9-0) 7 = death year(0-9), 8 = death year(9-0), 9 = age(0-9), 10 = age(9-0)

    vector<Scientist> scientists;
    string line, name, gender;
    int birthYear, deathYear;
    bool valid;

    switch(sortType)
    {
        case 1: line = "SELECT * FROM Scientists ORDER BY Name ASC"; // sort by name(A-Z)
                break;
        case 2: line = "SELECT * FROM Scientists ORDER BY Name DESC"; // sort by name(Z-A)
                break;
        case 3: line = "SELECT * FROM Scientists ORDER BY Gender ASC"; // sort by gender(f-m)
                break;
        case 4: line = "SELECT * FROM Scientists ORDER BY Gender DESC"; // sort by gender(m-f)
                break;
        case 5: line = "SELECT * FROM Scientists ORDER BY Born ASC"; // sort by birth year(0-9)
                break;
        case 6: line = "SELECT * FROM Scientists ORDER BY Born DESC"; // sort by birth year(9-0)
                break;
        case 7: line = "SELECT * FROM Scientists ORDER BY DIED ASC"; // sort by death year(0-9)
                break;
        case 8: line = "SELECT * FROM Scientists ORDER BY DIED DESC"; // sort by death year(9-0)
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
        valid = query.value(5).toBool();

        if(valid)
        {
            Scientist scientist(name, gender[0], birthYear, deathYear);
            scientists.push_back(scientist);
        }
    }

    db.close();
    return scientists;
}

bool DataAccess::doesScientistExist(string name)
{
    vector<Scientist> scientists;

    scientists = loadScientists(0, name);

    if(scientists.size() > 0)
    {
        return true;
    }

    return false;
}


// ---------------------------------- COMPUTER FUNCTIONS ---------------------------------- //

void DataAccess::saveComputer(Computer newComputer)  // Saving to SQLite database
{
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

vector<Computer> DataAccess::loadComputers()                  // From text file to vector
{
    /*
     * Adds list of computers from a database into a vector.
     */

    vector<Computer> computers;
    string line, name, type;
    int year;
    bool built, valid;

    line = "SELECT * FROM computers";

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
        valid = query.value(5).toBool();

        if(valid)
        {
            Computer computer(name, year, type, built);
            computers.push_back(computer);
        }
    }

    db.close();
    return computers;
}
vector<Computer> DataAccess::loadComputers(int loadType, string parameter)                  // From text file to vector
{
    /*
     * Adds list of computers from a database into a vector.
     * 0 = load by whole name, 1 = load by name, 2 = load by year built, 4 = load by type, 5 = load by if built.
     * 3 is used in the loadScientist function with 3 parameters.
     */

    vector<Computer> computers;
    string line, name, type;
    int year;
    bool built, valid;


    switch(loadType)
    {
        case 0: line = "SELECT * FROM Computers Where Name LIKE \"" + parameter + "\""; // load by whole name
                break;
        case 1: line = "SELECT * FROM Computers Where Name LIKE \"%" + parameter + "%\""; // load by name
                break;
        case 2: line = "SELECT * FROM Computers Where Year LIKE \"%" + parameter + "%\""; // load by year built/designed
                break;
        case 4: line = "SELECT * FROM Computers Where Type LIKE  \"" + parameter + "\""; // load by type
                break;
        case 5: line = "SELECT * FROM Computers Where Built LIKE " + parameter; // load by if built
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
        valid = query.value(5).toBool();

        if(valid)
        {
            Computer computer(name, year, type, built);
            computers.push_back(computer);
        }
    }

    db.close();
    return computers;
}
vector<Computer> DataAccess::loadComputers(int loadType, string parameter1, string parameter2)
{
    /*
     * Adds list of computers from a database into a vector.
     * 3 = load by build year range.
     * 0, 1, 2 and 5 are used in the loadScientist function with 2 parameters.
     */

    vector<Computer> computers;
    string line, name, type;
    int year;
    bool built, valid;


    switch(loadType)
    {
        case 3: line = "SELECT * FROM computers WHERE year BETWEEN " + parameter1 + " AND " + parameter2; // load by build/design year range
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
        valid = query.value(5).toBool();

        if(valid)
        {
            Computer computer(name, year, type, built);
            computers.push_back(computer);
        }
    }

    db.close();
    return computers;
}

void DataAccess::removeComputer(string inputName)
{
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
{
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
    // 6 = year made(9-0)

    vector<Computer> computers;
    string line, name, type;
    int year;
    bool valid, built;

    switch(sortType)
    {
        case 1: line = "SELECT * FROM Computers ORDER BY Name ASC"; // sort by name(A-Z)
                break;
        case 2: line = "SELECT * FROM Computers ORDER BY Name DESC"; // sort by name(Z-A)
                break;
        case 3: line = "SELECT * FROM Computers ORDER BY Year ASC"; // sort by Year(0-9)
                break;
        case 4: line = "SELECT * FROM Computers ORDER BY Year DESC"; // sort by Year(9-0)
                break;
        case 5: line = "SELECT * FROM Computers ORDER BY Type ASC"; // sort by type(A-Z)
                break;
        case 6: line = "SELECT * FROM Computers ORDER BY Type DESC"; // sort by type(Z-A)
                break;
        case 7: line = "SELECT * FROM Computers ORDER BY Built ASC"; // sort by if built(N-Y)
                break;
        case 8: line = "SELECT * FROM Computers ORDER BY Built DESC"; // sort by if built(Y-N)
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
        valid = query.value(5).toBool();

        if(valid)
        {
            Computer computer(name, year, type, built);
            computers.push_back(computer);
        }
    }

    db.close();
    return computers;
}

bool DataAccess::doesComputerExist(string name)
{
    vector<Computer> computers;

    computers = loadComputers(0, name);

    if(computers.size() > 0)
    {
        return true;
    }

    return false;
}

int DataAccess::yearComputerBuilt(string computer)
{
    string line;
    int year;
    bool valid;

    line = "SELECT year FROM computers WHERE name LIKE \"" + computer + "\"";

    QString input = QString::fromStdString(line);
    db.open();
    QSqlQuery query;
    query.exec(input);

    year = query.value(2).toInt();
    valid = query.value(5).toBool();

    db.close();

    if(valid)
    {
        return year;
    }

    return 0;
}

// ---------------------------------- RELATION FUNCTIONS ---------------------------------- //

void DataAccess::saveRelation(const Relation newRelation)  // Saving to SQLite database
{
    string line, scientist, computer, scientistID, computerID;

    scientist = newRelation.getScientist();
    computer = newRelation.getComputer();

    db.open();
    QSqlQuery query;
    QString input;

    input = QString::fromStdString("SELECT ID FROM Scientists WHERE name LIKE \"" + scientist + "\"");
    query.exec(input);
    scientistID = query.value(0).toString().toStdString();

    input = QString::fromStdString("SELECT ID FROM Computers WHERE name LIKE \"" + computer + "\"");
    query.exec(input);
    computerID = query.value(0).toString().toStdString();

    line = "INSERT INTO Relations (ScientistID, computerID) VALUE (\"" + scientistID + "\", \"" + computerID + "\")";

    input = QString::fromStdString(line);

    query.exec(input);
    db.close();

}

vector<Relation> DataAccess::loadRelations()                  // From text file to vector
{
    /*
     * Adds list of computers from a database into a vector.
     */

    vector<Relation> relations;
    string line, scientist, computer, scientistID, computerID;
    bool year, valid;

    line = sqlRelationTable();

    QString input = QString::fromStdString(line);
    db.open();
    QSqlQuery query;

    query.exec(input);

    while (query.next())
    {
        /*
        scientistID = query.value(0).toString().toStdString();
        computerID = query.value(1).toString().toStdString();
        valid = query.value(2).toBool();

        line = "SELECT name FROM Scientists WHERE id LIKE \"" + scientistID + "\"";
        input = QString::fromStdString(line);
        parameterQuery.exec(input);
        scientist = query.value(0).toString().toStdString();

        line = "SELECT name FROM Computers WHERE id LIKE \"" + computerID + "\"";
        input = QString::fromStdString(line);
        parameterQuery.exec(input);
        computer = query.value(0).toString().toStdString();

        line = "SELECT year FROM Copmuters WHERE id LIKE \"" + computerID + "\"";
        input = QString::fromStdString(line);
        parameterQuery.exec(input);
        year = query.value(0).toInt();

        */

        scientist = query.value(0).toString().toStdString();
        computer = query.value(1).toString().toStdString();
        year = query.value(2).toInt();
        valid = query.value(3).toBool();

        if(valid)
        {
            Relation relation(scientist, computer, year);
            relations.push_back(relation);
        }
    }
    db.close();

    return relations;

}
vector<Relation> DataAccess::loadRelations(int loadType, string parameter)                  // From text file to vector
{
    vector<Relation> relations;
    string line, computer, scientist;
    int year;
    bool valid;


    switch(loadType)
    {
        case 0: line = sqlRelationTable() + "Where scientist LIKE \"" + parameter + "\""; // load by whole scientist name
                break;
        case 1: line = sqlRelationTable() + "Where scientist LIKE \"%" + parameter + "%\""; // load by scientist name
                break;
        case 2: line = sqlRelationTable() + "Where computer LIKE \"" + parameter + "\""; // load by whole computer name
                break;
        case 3: line = sqlRelationTable() + "Where computer LIKE \"%" + parameter + "%\""; // load by computer name
                break;
        case 4: line = sqlRelationTable() + "Where year LIKE \"" + parameter + "\""; // load by year computer built
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
        valid = query.value(3).toBool();

        if(valid)
        {
            Relation relation(scientist, computer, year);
            relations.push_back(relation);
        }
    }

    db.close();

    return relations;
}
vector<Relation> DataAccess::loadRelations(int loadType, string parameter1, string parameter2)
{
    /*
     * Adds list of computers from a database into a vector.
     * 3 = load by build year range.
     * 0, 1, 2 and 5 are used in the loadScientist function with 2 parameters.
     */

    vector<Relation> relations;
    string line, computer, scientist;
    int year;
    bool valid;


    switch(loadType)
    {
        case 5: line = sqlRelationTable() + "WHERE year BETWEEN " + parameter1 + " AND " + parameter2; // load by year range when computer built
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
        valid = query.value(3).toBool();

        if(valid)
        {
            Relation relation(scientist, computer, year);
            relations.push_back(relation);
        }
    }

    db.close();

    return relations;
}

void DataAccess::removeRelation(int removeType, string inputName)
{
    string line;

    switch(removeType)
    {
        case 1: line = "UPDATE Relations SET Valid = 0 WHERE Scientist LIKE \"%" + inputName + "%\"";
                break;
        case 2: line = "UPDATE Relations SET Valid = 0 WHERE Computer LIKE \"%" + inputName + "%\"";
                break;
    }

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input);
    db.close();
}
void DataAccess::removeAllRelations()
{
    string line;

    line = "DELETE FROM Relations";

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input);
    db.close();

}

vector<Relation> DataAccess::sortRelations(int sortType)
{
    vector<Relation> relations;
    string line, scientist, computer;
    int year;
    bool valid;


    switch(sortType)
    {
        case 1: line = sqlRelationTable() + "ORDER BY Scientist ASC"; // sort by scientist name(A-Z)
                break;
        case 2: line = sqlRelationTable() + "ORDER BY Scientist DESC"; // sort by scientist name(Z-A)
                break;
        case 3: line = sqlRelationTable() + "ORDER BY Computer ASC"; // sort by computer name(A-Z)
                break;
        case 4: line = sqlRelationTable() + "ORDER BY Computer DESC"; // sort by computer name(Z-A)
                break;
        case 5: line = sqlRelationTable() + "ORDER BY Year ASC"; // sort by year made(0-9)
                break;
        case 6: line = sqlRelationTable() + "ORDER BY Year DESC"; // sort by year made(9-0)
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
        valid = query.value(3).toBool();

        if(valid)
        {
            Relation relation(scientist, computer, year);
            relations.push_back(relation);
        }
    }

    db.close();
    return relations;
}

bool DataAccess::doesRelationExist(string scientist, string computer)
{
    string line;
    bool valid;

    line = sqlRelationTable() + "WHERE scientist LIKE \"" + scientist + "\" AND computer LIKE \"" + computer + "\"";

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;

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
{   // Column 0 = scientist, 1 = computer, 2 = year, 3 = valid.

    string line;

    line = "SELECT s.Name AS 'Scientist', c.Name AS 'Computer', c.Year, r.Valid "
           "FROM Relations r "
           "JOIN Scientists s ON s.ID = r.ScientistID "
           "JOIN Computers c ON c.ID = r.ComputerID ";

    return line;
}
