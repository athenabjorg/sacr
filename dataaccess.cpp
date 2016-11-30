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

    while(file)
    {
        /*getline(file, scientist.getName(), ',' );
        getline(file, scientist.getGender(), ',' );
        getline(file, scientist.getAge(), ',' );
        getline(file, scientist.getDeath());
*/
    }

    file.close( );

    return scientists;
}
