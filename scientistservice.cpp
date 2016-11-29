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

    Scientist p("Duran Duran", 'm', 1987, 1556);
    Scientist p2("Madonna",'f', 1957, 1556);
    Scientist p3("David Bowie",'m', 1287, 1556);

    scientist.push_back(p);
    scientist.push_back(p2);
    scientist.push_back(p3);

    // TODO: business logic!

    // Sort by name:
    ScientistComparison cmp;
    std::sort(scientist.begin(), scientist.end(), cmp);

    return scientist;
}
