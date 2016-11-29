#include <iostream>
#include <string>
#include "consoleui.h"
#include "scientist.h"

using namespace std;

ConsoleUI::ConsoleUI()
{

}

// Should not contain logic for individual commands, that should be in separate functions!
void ConsoleUI::run()
{
    string command;
    do
    {
        cout << "Select one of the following options: " << endl;
        cout << "Add - add a programmer/computer scientist" << endl;
        cout << "List - add a programmer/computer scientist" << endl;
        cout << "Quit - end program" << endl;


        cin >> command;

        if(command == "add" || command == "Add" || command == "ADD") // Could possibly be improved upon
        {
           userMenuAdd();
        }
        if(command == "list" || command == "List" || command == "LIST") // Could possibly be improved upon
        {
           userMenuList();
        }
    }while(command != "quit");



}
void ConsoleUI::userMenuAdd()
{
    string name;
    char gender;
    int birthYear;
    int deathYear = 0;
    //int age = 22; // TEMP

    cout << "Enter the programmer's/computer scientist's name: ";
    cin >> name; // TODO - take in as ( GETLINE )

    cout << "Enter the programmer's/computer scientist's gender (m/f): ";
    cin >> gender;

    cout << "Enter the programmer's/computer scientist's year of birth: ";
    cin >> birthYear;

    cout << "Enter the programmer's/computer scientist's year of death (leave empty if not applicable): ";
    cin >> deathYear;

    Scientist newScientist(name, gender, birthYear, deathYear);
}
void ConsoleUI::userMenuList()
{
    vector<Scientist> scientist = _service.getScientist();

    cout << "Performer name:" << endl;
    cout << "===============" << endl;
    for (size_t i = 0; i< scientist.size(); ++i)
    {
        cout << scientist[i].getName() << endl;
    }
}

