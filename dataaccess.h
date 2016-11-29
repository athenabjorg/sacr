#ifndef DATAACCESS_H
#define DATAACCESS_H
#include <vector>
#include "scientist.h"

using namespace std;

class DataAccess
{
public:
    DataAccess();

private:
    void saveScientists(vector<Scientist>& scientists);
};

#endif // DATAACCESS_H
