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
    file.open("scientists.txt");

    for(size_t i = 0; i <= scientists.size(); i++)
    {
        file << scientists[i].getName() << ", ";
        file << scientists[i].getGender() << ", ";
        file << scientists[i].getAge() << ", ";
        file << scientists[i].getDeath() << ". " << endl;
    }

    file.close( );
}
