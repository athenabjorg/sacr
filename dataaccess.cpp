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
void DataAccess::saveScientists(Scientist newScientist)  // Saving to database SQLite
{
    string sName, line, name, gender, strBirthYear, strDeathYear;
    int birthYear, deathYear;


    name = newScientist.getName();
    gender = newScientist.getGender();
    birthYear = newScientist.getBirth();
    deathYear = newScientist.getDeath();

    strBirthYear = to_string(birthYear);
    strDeathYear = to_string(deathYear);

    sName = "INSERT INTO Scientists(name,gender,birth,death) "
            "VALUES(\"" + name + "\",\"" + gender + "\"," + strBirthYear + "," + strDeathYear + ")";


    QString input = QString::fromStdString(sName);
    db.open();
    QSqlQuery query;
    query.exec(input);
    db.close();


}
vector<Scientist> DataAccess::loadScientists()                  // From text file to vector
{
    /*
     * This function uses SQLite Manager database and adds scientits table   into a vector.
     */

    vector<Scientist> scientists;
    string line, name, gender, birthYear, deathYear, age;
    //char charGender;
    int intBirthYear, intDeathYear, intAge;

    db.open();
    QSqlQuery query;
    query.exec("SELECT * FROM Scientists"); // open table scientists

    while (query.next())
    {
        string name = query.value(1).toString().toStdString();
        string stringGender = query.value(2).toString().toStdString();
        int intBirthYear = query.value(3).toInt();
        int intDeathYear = query.value(4).toInt();
        char charGender = stringGender[0];

        Scientist scientist(name, charGender, intBirthYear, intDeathYear, intAge);
        scientists.push_back(scientist);
    }

    db.close();
    return scientists;
}
vector<Scientist> DataAccess::loadScientistByName(string inputName)
{
    vector<Scientist> scientists;
    string line, name, gender, birthYear, deathYear, age;
    //char charGender;
    int intBirthYear, intDeathYear, intAge;


    line = "SELECT * FROM Scientists  Where Name LIKE \"%" + inputName + "%\"";

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input); // open table scientists


    while (query.next())
    {
        string name = query.value(1).toString().toStdString();
        string stringGender = query.value(2).toString().toStdString();
        int intBirthYear = query.value(3).toInt();
        int intDeathYear = query.value(4).toInt();
        char charGender = stringGender[0];

        Scientist scientist(name, charGender, intBirthYear, intDeathYear, intAge);
        scientists.push_back(scientist);
    }

    db.close();
    return scientists;
}
vector<Scientist> DataAccess::loadScientistByGender(char inputGender)
{
    vector<Scientist> scientists;
    string line, name, gender, birthYear, deathYear, age, strGender = "";
    int intBirthYear, intDeathYear, intAge;
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
        int intBirthYear = query.value(3).toInt();
        int intDeathYear = query.value(4).toInt();
        char charGender = stringGender[0];

        Scientist scientist(name, charGender, intBirthYear, intDeathYear, intAge);
        scientists.push_back(scientist);
    }

    db.close();
    return scientists;
}
vector<Scientist> DataAccess::loadScientistByBirth(int inputBirth)
{
    vector<Scientist> scientists;
    string line, name, gender, birthYear, deathYear, age;
    int intBirthYear, intDeathYear, intAge;

    line = "SELECT * FROM Scientists  Where Birth LIKE " + inputBirth;

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input); // open table scientists


    while (query.next())
    {
        string name = query.value(1).toString().toStdString();
        string stringGender = query.value(2).toString().toStdString();
        int intBirthYear = query.value(3).toInt();
        int intDeathYear = query.value(4).toInt();
        char charGender = stringGender[0];

        Scientist scientist(name, charGender, intBirthYear, intDeathYear, intAge);
        scientists.push_back(scientist);
    }

    db.close();
    return scientists;
}
vector<Scientist> DataAccess::loadScientistByBirthRange(int inputBirth1, int inputBirth2)
{
    vector<Scientist> scientists;
    string line, name, gender, birthYear, deathYear, age;
    int intBirthYear, intDeathYear, intAge;

    line = "SELECT * FROM scientists WHERE born BETWEEN " + to_string(inputBirth1) + " AND " + to_string(inputBirth2);

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input); // open table scientists


    while (query.next())
    {
        string name = query.value(1).toString().toStdString();
        string stringGender = query.value(2).toString().toStdString();
        int intBirthYear = query.value(3).toInt();
        int intDeathYear = query.value(4).toInt();
        char charGender = stringGender[0];

        Scientist scientist(name, charGender, intBirthYear, intDeathYear, intAge);
        scientists.push_back(scientist);
    }

    db.close();
    return scientists;
}
vector<Scientist> DataAccess::loadScientistByDeath(int inputDeath)
{
    vector<Scientist> scientists;
    string line, name, gender, birthYear, deathYear, age;
    int intBirthYear, intDeathYear, intAge;

    line = "SELECT * FROM Scientists  Where Died LIKE " + to_string(inputDeath);

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input); // open table scientists


    while (query.next())
    {
        string name = query.value(1).toString().toStdString();
        string stringGender = query.value(2).toString().toStdString();
        int intBirthYear = query.value(3).toInt();
        int intDeathYear = query.value(4).toInt();
        char charGender = stringGender[0];

        Scientist scientist(name, charGender, intBirthYear, intDeathYear, intAge);
        scientists.push_back(scientist);
    }

    db.close();
    return scientists;
}
vector<Scientist> DataAccess::loadScientistByDeathRange(int inputDeath1, int inputDeath2)
{
    vector<Scientist> scientists;
    string line, name, gender, birthYear, deathYear, age;
    int intBirthYear, intDeathYear, intAge;

    line = "SELECT * FROM scientists WHERE Died BETWEEN " + to_string(inputDeath1) + " AND " + to_string(inputDeath2);

    QString input = QString::fromStdString(line);

    db.open();
    QSqlQuery query;
    query.exec(input); // open table scientists


    while (query.next())
    {
        string name = query.value(1).toString().toStdString();
        string stringGender = query.value(2).toString().toStdString();
        int intBirthYear = query.value(3).toInt();
        int intDeathYear = query.value(4).toInt();
        char charGender = stringGender[0];

        Scientist scientist(name, charGender, intBirthYear, intDeathYear, intAge);
        scientists.push_back(scientist);
    }

    db.close();
    return scientists;
}








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
