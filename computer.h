#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

using namespace std;

class Computer
{
public:
    Computer();
    Computer(string name, int yearBuilt, string type, bool built);
    Computer(string id, string name, string year, string type, string picurl, string about, string abouturl);
    string  getName() const;
    string  getType() const;
    int     getYear() const;
    bool    getBuilt() const;
    int     getYearsSinceBuilt() const;

    string getInfoID() const;
    string getInfoYear() const;
    string getInfoType() const;
    string getInfoPicurl() const;
    string getInfoAbout() const;
    string getInfoAbouturl() const;


private:
    string _name;
    string _type;
    int _year;
    bool _built;
    int _yearsSinceBuilt;

    string _id;
    string _yearMade;
    string _picurl;
    string _about;
    string _abouturl;

    int whatYearIsIt() const;

};

#endif // COMPUTER_H
