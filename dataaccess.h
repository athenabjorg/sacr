#ifndef DATAACCESS_H
#define DATAACCESS_H
#include <vector>
#include "scientist.h"

using namespace std;

class DataAccess
{
public:
    DataAccess();
    void saveScientists(vector<Scientist>& scientists);

private:

};

#endif // DATAACCESS_H
