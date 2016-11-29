#include "performerservice.h"
#include <algorithm>

using namespace std;

struct PerformerComparison {
  bool operator() (Performer i,Performer j) { return (i.getName()<j.getName());}
};

PerformerService::PerformerService()
{

}

vector<Performer> PerformerService::getPerformers(/* TODO: parameters */)
{
    vector<Performer> performers;

    Performer p("Duran Duran", 56);
    Performer p2("Madonna", 55);
    Performer p3("David Bowie", 55);

    performers.push_back(p);
    performers.push_back(p2);
    performers.push_back(p3);

    // TODO: business logic!

    // Sort by name:
    PerformerComparison cmp;
    std::sort(performers.begin(), performers.end(), cmp);

    return performers;
}
