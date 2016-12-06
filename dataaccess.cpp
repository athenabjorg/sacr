#include "dataaccess.h"
#include "scientist.h"
#include <QtSql>
#include <iostream> // TEMP<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#include <sstream>

using namespace std;

DataAccess::DataAccess()
{

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.sqlite");  // witch database to select ( aka what file )
    db.open();

}
//void DataAccess::saveScientists(const vector<Scientist>& scientists)  // From vector to text file
void DataAccess::saveScientists(const Scientist newScientist)  // Saving to database SQLite
{
    /*
     * This function uses ofstream to save the vector of scientists to the scientists.txt file.
     */
    string sName, line, name, gender, birthYear, deathYear, age;


    name = newScientist.getName();
    gender = newScientist.getGender();
    birthYear = newScientist.getBirth();
    deathYear = newScientist.getDeath();



    sName = "INSERT INTO Scientists(name,gender,birth,death) "
            "VALUES(\"" + name + "\",\"" + gender + "\"," + birthYear + "," + deathYear + ")";



    cout << sName;

    QString input = QString::fromStdString(sName);



    //db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("test.sqlite");  // witch database to select ( aka what file )

    //db.open();      // open database
    QSqlQuery query;
    query.exec(input); // open table scientists
    db.close();


}
vector<Scientist> DataAccess::loadScientists()                  // From text file to vector
{
    /*
     * This function uses ifstream to read from scientists.txt file and read them into a vector.
     */

    vector<Scientist> scientists;
    string line, name, gender, birthYear, deathYear, age;
    //char charGender;
    int intBirthYear, intDeathYear, intAge;


    //db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("test.sqlite");  // witch database to select ( aka what file )


    //db.open();      // open database
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

    //db.close();
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
