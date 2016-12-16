#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

using namespace std;

class Computer
{
public:
    Computer();
    Computer(string id, string name, string year, string type, string built, string picurl, string about, string abouturl);

    string getID() const;
    string getName() const;
    string getYear() const;
    string getType() const;
    string getBuilt() const;
    string getPicurl() const;
    string getAbout() const;
    string getAbouturl() const;


private:

    string _id;
    string _name;
    string _year;
    string _type;
    string _built;
    string _picurl;
    string _about;
    string _abouturl;


};

#endif // COMPUTER_H
