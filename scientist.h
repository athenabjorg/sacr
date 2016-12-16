#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>
#include <ctime>

using namespace std;

class Scientist
{
public:
    Scientist();
    Scientist(string id, string name, string gender, string born, string died, string picurl, string about, string abouturl);

    string getID() const;
    string getName()      const;
    string getGender()    const;
    string getBorn() const;
    string getDied() const;
    string getPicurl() const;
    string getAbout() const;
    string getAbouturl() const;
    int getAge() const;

    friend bool operator == (const Scientist& a, const Scientist& b);

private:

    string _id;
    string _name;
    string _gender;
    string _born;
    string _died;
    string _picurl;
    string _about;
    string _abouturl;
    int _age;

    int    whatYearIsIt() const;
    // Returns the current year.
};

#endif // SCIENTIST_H
