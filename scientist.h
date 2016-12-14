#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>
#include <ctime>

using namespace std;

class Scientist
{
public:
    Scientist();
    Scientist(string name, char gender, int birth, int death); //vantar bool valid aftast?
    Scientist(string id, string name, string birth, string death, string picurl, string about, string abouturl);
    string getName()      const;
    string getGender()    const;
    int    getBirth()     const;
    int    getDeath()     const;
    int    getAge()       const;

    friend bool operator == (const Scientist& a, const Scientist& b);

    string getInfoID() const;
    string getInfoBorn() const;
    string getInfoDied() const;
    string getInfoPicurl() const;
    string getInfoAbout() const;
    string getInfoAbouturl() const;

private:

    string _name;
    char   _gender;
    int    _birth;
    int    _death;
    int    _age;

    string _id;
    string _born;
    string _died;
    string _picurl;
    string _about;
    string _abouturl;

    int    whatYearIsIt() const;
    // Returns the current year.
};

#endif // SCIENTIST_H
