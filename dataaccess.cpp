#include "dataaccess.h"
#include "scientist.h"

using namespace std;

DataAccess::DataAccess()
{

}
void DataAccess::saveScientists(vector<Scientist>& scientists)
{
    ofstream file;
    file.open("scientists.txt");

    for(size_t i = 0; i < scientists.size(); i++)
    {
        file << scientists[i].getName() << " ";
        file << scientists[i].getGender() << " ";
        file << scientists[i].getBirth() << " ";
        file << scientists[i].getDeath() << " ";
        file << scientists[i].getAge() << endl; // Spurning hvort það þurfi að vera endl á
                                                  //öllum atriðum til að geta notað getline hér fyrir neðan.
    }

    file.close( );
}
vector<Scientist> DataAccess::loadScientists()
{
    vector<Scientist> scientists;
    Scientist scientist;

    string line;
    stringstream lineStream;
    string name, gender, birthYear, deathYear, age;
    char charGender;
    int intBirthYear, intDeathYear, intAge;

    ifstream file;
    file.open("scientists.txt");

    if(file.is_open())
    {
        while(getline(file, line))
        {
            stringstream lineStream(line);
            lineStream >> name >> gender >> birthYear >> deathYear >> age;

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

