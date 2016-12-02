#include "dataaccess.h"
#include "scientist.h"

using namespace std;

DataAccess::DataAccess()
{

}
void DataAccess::saveScientists(const vector<Scientist>& scientists)  // From vector to text file
{
    /*
     * This function uses ofstream to save the vector from scientists from service layer
     * to the scientists.txt file.
     */

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

}
vector<Scientist> DataAccess::loadScientists()                  // From text file to vector
{
    /*
     * This function uses ifstream to read from scientists.txt file and read them
     * into a vector in service layer of the program.
     */

    vector<Scientist> scientists;
    Scientist scientist;

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

            scientist.setName(name);
            scientist.setGender(charGender);
            scientist.setBirth(intBirthYear);
            scientist.setDeath(intDeathYear);
            scientist.setAge(intAge);

            scientists.push_back(scientist);
        }

    file.close( );
    }

    return scientists;
}
