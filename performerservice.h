#ifndef PERFORMERSERVICE_H
#define PERFORMERSERVICE_H

#include <vector>
#include "performer.h"

using namespace std;

class PerformerService
{
public:
    PerformerService();

    //
    vector<Performer> getPerformers(/* TODO: parameters */);
};

#endif // PERFORMERSERVICE_H
