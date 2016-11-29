#include "scientistservice.h"
#include <algorithm>

using namespace std;

struct ScientistComparison {
  bool operator() (Scientist i,Scientist j) { return (i.getName()<j.getName());}
};

ScientistService::ScientistService()
{

}

vector<Scientist> ScientistService::getScientist(/* TODO: parameters */)
{
    vector<Scientist> scientist;

    /*Scientist p("Duran Duran", 56);
    Scientist p2("Madonna", 55);
    Scientist p3("David Bowie", 55);

    scientist.push_back(p);
    scientist.push_back(p2);
    scientist.push_back(p3);
*/
    // TODO: business logic!

    // Sort by name:
    ScientistComparison cmp;
    std::sort(scientist.begin(), scientist.end(), cmp);

    return scientist;
}
