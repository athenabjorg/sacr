#ifndef FUNFACTS_H
#define FUNFACTS_H

#include <string>

using namespace std;

class FunFacts
{
public:
    FunFacts();
    string getFunFact();

private:

    int _iterator;
};

#endif // FUNFACTS_H
