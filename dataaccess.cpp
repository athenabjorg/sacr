#include "dataaccess.h"
#include <QtSql>
#include <iostream> // TEMP<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#include <sstream>

using namespace std;

DataAccess::DataAccess()
{

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("DataBase.sqlite");  // witch database to select ( aka what file )

}

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

void DataAccess::removeScientist(string inputName)
{
    string line;

    line = "UPDATE Scientists SET Valid = 0 WHERE Name LIKE \"%" + inputName + "%\"";

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input); // open table scientists
    db.close();
}

void DataAccess::removeAllScientists() // Not practical
{
    /*
    db.open();
    QSqlQuery query;
    query.exec("DELETE FROM Scientists"); // open table scientists
    db.close();
    */
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
        case 1: line = "SELECT * FROM Scientists  Where Name LIKE \"%" + parameter + "%\""; // load by name
                break;
        case 2: line = "SELECT * FROM Scientists  Where Gender LIKE \"%" + parameter + "%\""; // load by gender
                break;
        case 3: line = "SELECT * FROM Scientists  Where Birth LIKE " + parameter; // load by birth year
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
        case 4: line = "SELECT * FROM scientists WHERE born BETWEEN " + parameter1 + " AND " + parameter2; // load by birth year range
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
        case 3: line = "SELECT * FROM Scientists ORDER BY G ASC"; // sort by gender(f-m)
                break;
        case 4: line = "SELECT * FROM Scientists ORDER BY Name DESC"; // sort by gender(m-f)
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

    scientists = loadScientists(1, name);

    if(scientists.size() > 0)
    {
        return true;
    }

    return false;
}

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

//removecomputer

//removeallcomputers

// loadcomputers
// load 2 par
// load 3 par

vector<Computer> DataAccess::sortComputers(int sortType)
{   // Sort by sortType: 1 = name(A-Z), 2 = name(Z-A), 3 = gender(f-m), 4 = gender(m-f), 5 = birth year(0-9),
    // 6 = birth year(9-0) 7 = death year(0-9), 8 = death year(9-0), 9 = age(0-9), 10 = age(9-0)

    vector<Computer> computers;
    string line, name, type;
    int yearBuilt;
    bool valid, built;

    switch(sortType)
    {
        case 1: line = "SELECT * FROM Computers ORDER BY Name ASC"; // sort by name(A-Z)
                break;
        case 2: line = "SELECT * FROM Computers ORDER BY Name DESC"; // sort by name(Z-A)
                break;
        case 3: line = "SELECT * FROM Computers ORDER BY Type ASC"; // sort by type(A-Z)
                break;
        case 4: line = "SELECT * FROM Computers ORDER BY Type DESC"; // sort by type(Z-A)
                break;
        case 5: line = "SELECT * FROM Computers ORDER BY Year Built ASC"; // sort by year made(0-9)
                break;
        case 6: line = "SELECT * FROM Computers ORDER BY Year Built DESC"; // sort by year made(9-0)
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
        yearBuilt = query.value(2).toInt();
        built = query.value(4).toBool();
        valid = query.value(5).toBool();

        if(valid)
        {
            //Computer computer(name, yearBuilt, type, built);
            //computers.push_back(computer);
        }
    }

    db.close();
    return computers;
}

bool DataAccess::doesComputerExist(string name)
{
    vector<Computer> computers;

    //computers = loadComputers(1, name);

    if(computers.size() > 0)
    {
        return true;
    }

    return false;
}
