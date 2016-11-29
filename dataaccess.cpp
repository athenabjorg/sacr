#include "dataaccess.h"
#include <fstream>
#include "scientist.h"
#include <vector>

using namespace std;

DataAccess::DataAccess()
{

}
void DataAccess::saveScientists(vector<Scientist>& scientists)
{
    ofstream file;
    file.open("scientists.csv"); // spurning hvort þetta eigi að vera .txt eða .csv

    for(size_t i = 0; i <= scientists.size(); i++)
    {
        file << scientists[i].getName() << ", ";
        file << scientists[i].getGender() << ", ";
        file << scientists[i].getAge() << ", ";
        file << scientists[i].getDeath() << ". " << endl;
    }

    file.close( );
}

vector<Scientist> DataAccess::loadScientists()
{
    vector<Scientist> scientists;
    Scientist scientist;

    // TODO read file, scientists.push_back(scientist)

    return scientists;
}
