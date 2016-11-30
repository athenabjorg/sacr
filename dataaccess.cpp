#include "dataaccess.h"
#include <fstream>
#include "scientist.h"
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

DataAccess::DataAccess()
{

}
void DataAccess::saveScientists(vector<Scientist>& scientists)
{
    ofstream file;
    file.open("scientists.csv");

    for(size_t i = 0; i < scientists.size(); i++)
    {
        file << scientists[i].getName() << ", ";
        file << scientists[i].getGender() << ", ";
        file << scientists[i].getAge() << ", ";
        file << scientists[i].getDeath() << endl; // Spurning hvort það þurfi að vera endl á
                                                  //öllum atriðum til að geta notað getline hér fyrir neðan.
    }

    file.close( );
}

vector<Scientist> DataAccess::loadScientists()
{
    vector<Scientist> scientists;
    Scientist scientist;

    ifstream file;
    file.open("scientists.csv");

    string line;
    if(file.is_open())
    {
    while(getline(file, line)) //ná í
    {
        stringstream linestream(line);
        string data;
        string theName = " ";
        char theGender = ' ';
        int theBirthYear = 0;
        int theDeathYear = 0;

        getline(linestream, line, '\t');  // read up-to the tab

        // Read the values using the operator >>
        linestream >> theName >> theGender >> theBirthYear >> theDeathYear;
        scientist.setName(theName);
        scientist.setGender(theGender);
        scientist.setAge(theBirthYear);
        scientist.setDeath(theDeathYear);

        scientists.push_back(scientist);
    }

    file.close( );
    }

    return scientists;
}

