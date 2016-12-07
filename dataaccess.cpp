#include "dataaccess.h"
#include "scientist.h"
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

    line = "DELETE * FROM Scientists  Where Name LIKE \"%" + inputName + "%\"";

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input); // open table scientists
    db.close();
}

void DataAccess::removeAllScientists()
{
    db.open();
    QSqlQuery query;
    query.exec("DELETE FROM Scientists"); // open table scientists
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
     //   valid = query.value(5).toBool();


        Scientist scientist(name, gender[0], birthYear, deathYear);
        scientists.push_back(scientist);
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
     //   valid = query.value(5).toBool();

        Scientist scientist(name, gender[0], birthYear, deathYear);
        scientists.push_back(scientist);
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
     //   valid = query.value(5).toBool();

        Scientist scientist(name, gender[0], birthYear, deathYear);
        scientists.push_back(scientist);
    }

    db.close();
    return scientists;
}
/*
vector<Scientist> DataAccess::loadScientistByName(string inputName)
{
    vector<Scientist> scientists;
    string line, name, gender, birthYear, deathYear;
    //char charGender;
    int intBirthYear, intDeathYear;
    char charGender;

    line = "SELECT * FROM Scientists  Where Name LIKE \"%" + inputName + "%\"";

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input); // open table scientists


    while (query.next())
    {
        string name = query.value(1).toString().toStdString();
        string stringGender = query.value(2).toString().toStdString();
        intBirthYear = query.value(3).toInt();
        intDeathYear = query.value(4).toInt();
        charGender = stringGender[0];

        Scientist scientist(name, charGender, intBirthYear, intDeathYear);
        scientists.push_back(scientist);
    }

    db.close();
    return scientists;
}
vector<Scientist> DataAccess::loadScientistByGender(char inputGender)
{
    vector<Scientist> scientists;
    string line, name, gender, birthYear, deathYear, strGender = "";
    int intBirthYear, intDeathYear;
    char charGender;


    strGender = inputGender;
    line = "SELECT * FROM Scientists  Where Gender LIKE \"%" + strGender + "%\"";


    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input); // open table scientists


    while (query.next())
    {
        string name = query.value(1).toString().toStdString();
        string stringGender = query.value(2).toString().toStdString();
        intBirthYear = query.value(3).toInt();
        intDeathYear = query.value(4).toInt();
        charGender = stringGender[0];

        Scientist scientist(name, charGender, intBirthYear, intDeathYear);
        scientists.push_back(scientist);
    }

    db.close();
    return scientists;
}
vector<Scientist> DataAccess::loadScientistByBirth(int inputBirth)
{
    vector<Scientist> scientists;
    string line, name, gender, birthYear, deathYear;
    int intBirthYear, intDeathYear;
    char charGender;

    line = "SELECT * FROM Scientists  Where Birth LIKE " + inputBirth;

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input); // open table scientists


    while (query.next())
    {
        string name = query.value(1).toString().toStdString();
        string stringGender = query.value(2).toString().toStdString();
        intBirthYear = query.value(3).toInt();
        intDeathYear = query.value(4).toInt();
        charGender = stringGender[0];

        Scientist scientist(name, charGender, intBirthYear, intDeathYear);
        scientists.push_back(scientist);
    }

    db.close();
    return scientists;
}
vector<Scientist> DataAccess::loadScientistByBirthRange(int inputBirth1, int inputBirth2)
{
    vector<Scientist> scientists;
    string line, name, gender, birthYear, deathYear;
    int intBirthYear, intDeathYear;
    char charGender;

    line = "SELECT * FROM scientists WHERE born BETWEEN " + to_string(inputBirth1) + " AND " + to_string(inputBirth2);

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input); // open table scientists


    while (query.next())
    {
        string name = query.value(1).toString().toStdString();
        string stringGender = query.value(2).toString().toStdString();
        intBirthYear = query.value(3).toInt();
        intDeathYear = query.value(4).toInt();
        charGender = stringGender[0];

        Scientist scientist(name, charGender, intBirthYear, intDeathYear);
        scientists.push_back(scientist);
    }

    db.close();
    return scientists;
}
vector<Scientist> DataAccess::loadScientistByDeath(int inputDeath)
{
    vector<Scientist> scientists;
    string line, name, gender, birthYear, deathYear;
    int intBirthYear, intDeathYear;
    char charGender;

    line = "SELECT * FROM Scientists  Where Died LIKE " + to_string(inputDeath);

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input); // open table scientists


    while (query.next())
    {
        string name = query.value(1).toString().toStdString();
        string stringGender = query.value(2).toString().toStdString();
        intBirthYear = query.value(3).toInt();
        intDeathYear = query.value(4).toInt();
        charGender = stringGender[0];

        Scientist scientist(name, charGender, intBirthYear, intDeathYear);
        scientists.push_back(scientist);
    }

    db.close();
    return scientists;
}
vector<Scientist> DataAccess::loadScientistByDeathRange(int inputDeath1, int inputDeath2)
{
    vector<Scientist> scientists;
    string line, name, gender, birthYear, deathYear;
    int intBirthYear, intDeathYear;
    char charGender;

    line = "SELECT * FROM scientists WHERE Died BETWEEN " + to_string(inputDeath1) + " AND " + to_string(inputDeath2);

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input); // open table scientists


    while (query.next())
    {
        string name = query.value(1).toString().toStdString();
        string stringGender = query.value(2).toString().toStdString();
        intBirthYear = query.value(3).toInt();
        intDeathYear = query.value(4).toInt();
        charGender = stringGender[0];

        Scientist scientist(name, charGender, intBirthYear, intDeathYear);
        scientists.push_back(scientist);
    }

    db.close();
    return scientists;
}

*/






// OLD CODE
/*
ofstream file;
file.open("scientists.txt");

if(file.is_open())
{
    for(size_t i = 0; i < scientists.size(); i++)
    {
        file << scientists[i].getName()   <<  ",";
        file << scientists[i].getGender() <<  ",";
        file << scientists[i].getBirth()  <<  ",";
        file << scientists[i].getDeath()  <<  ",";
        file << scientists[i].getAge()    << endl;
    }
    file.close( );
}
*/

/*
vector<Scientist> scientists;


string line, name, gender, birthYear, deathYear, age;
const string delimiter = ",";
char charGender;
int intBirthYear, intDeathYear, intAge, delimiterPos;

ifstream file;
file.open("scientists.txt");

if(file.is_open())
{
    while(getline(file, line))
    {
        delimiterPos = line.find(delimiter);
        name = line.substr(0, delimiterPos);
        line.erase(0, delimiterPos + 1);

        delimiterPos = line.find(delimiter);
        gender = line.substr(0, delimiterPos);
        line.erase(0, delimiterPos + 1);

        delimiterPos = line.find(delimiter);
        birthYear = line.substr(0, delimiterPos);
        line.erase(0, delimiterPos + 1);

        delimiterPos = line.find(delimiter);
        deathYear = line.substr(0, delimiterPos);
        line.erase(0, delimiterPos + 1);

        delimiterPos = line.find(delimiter);
        age = line.substr(0, delimiterPos);

        charGender = gender[0];
        intBirthYear = atoi(birthYear.c_str());
        intDeathYear = atoi(deathYear.c_str());
        intAge = atoi(age.c_str());


        Scientist scientist(name, charGender, intBirthYear, intDeathYear, intAge);

        scientists.push_back(scientist);
    }

file.close( );
}



return scientists;

*/
