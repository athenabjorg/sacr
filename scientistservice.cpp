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
    vector<Scientist> performers;

    Scientist p("Duran Duran", 56);
    Scientist p2("Madonna", 55);
    Scientist p3("David Bowie", 55);

    performers.push_back(p);
    performers.push_back(p2);
    performers.push_back(p3);

    // TODO: business logic!

    // Sort by name:
    ScientistComparison cmp;
    std::sort(performers.begin(), performers.end(), cmp);

    return performers;
}
