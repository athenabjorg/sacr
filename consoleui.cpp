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
        cout << "List - show a list of all programmer's/computer scientist's" << endl;
        cout << "Search - search the list of programmer's/computer scientist's" << endl;
        cout << "Quit - end program" << endl;


        cin >> command;
        for(unsigned int i = 0; i < command.length(); i++) // to make all lowercase, taken from c++ site
        {
            command[i] = tolower(command[i]);
        }

        cout << endl;

        if(command == "add") // Could possibly be improved upon
        {
           userMenuAdd();
        }
        else if(command == "list") // Could possibly be improved upon
        {
           userMenuList();
        }
        else if(command == "search") // Could possibly be improved upon
        {
           userMenuSearch();
        }
        else
        {
            cout << "Invalid input" << endl;
        }
    }while(command != "quit");



}
void ConsoleUI::userMenuAdd()
{
    string name;
    char gender;
    int birthYear;
    int deathYear = 0;


    cout << "Enter the programmer's/computer scientist's name: ";
    cin.ignore();
    getline(cin, name);

    bool check = true;
    do
    {
        cout << "Enter the programmer's/computer scientist's gender (m/f): ";
        cin >> gender;

        if((gender != 'm') && (gender != 'f'))
        {
            cout << "Invalid input" << endl;
        }
        else
        {
            cout << endl;
            check = false;
        }
    }while(check == true);

    bool check2 = true;
    do
    {
        cout << "Enter the programmer's/computer scientist's year of birth: ";
        cin >> birthYear;
        if(birthYear < 2016) // Just in case we find a programmer of the univers
        {
            cout << endl;
            check2 = false;
        }
        else
        {
            cout << "Invalid input" << endl;
        }
    }while(check2 == true);

    bool check3 = true;
    do
    {
        cout << "Enter the programmer's/computer scientist's year of death (type 0 if not applicable): ";
        cin >> deathYear;
        if(deathYear >= birthYear)
        {
            cout << endl;
            check3 = false;
        }
        else
        {
            cout << "Invalid input" << endl;
        }
    }while(check3 == true);

    _service.addScientist(name, gender, birthYear, deathYear);
}
void ConsoleUI::userMenuList()
{
    vector<Scientist> scientist = _service.getScientists();

    cout << "Scientist name:" << endl;
    cout << "===============" << endl;
    for (size_t i = 0; i< scientist.size(); ++i)
    {
        cout << scientist[i].getName() << endl;
    }
    cout << endl;
}
void ConsoleUI::userMenuSearch()
{
    string command;
    cout << "Select a search option: " << endl;
    cout << "Name - Search by name" << endl;
    cout << "Birth - Search by year of birth" << endl;
    cout << "Death - search by year of death" << endl;
    cin >> command;

    if(command == "name" || command == "Name" || command == "NAME")
    {
        vector<Scientist> scientist = _service.getScientists();
        string nameInputSearch;
        cout << "Enter a name to search: ";
        cin >> nameInputSearch;

        for(unsigned int i = 0; i < scientist.size(); ++i)
        {
            if(scientist[i].getName() == nameInputSearch)
            {
                cout << scientist[i].getName() << endl;
            }
        }
    }
    else if(command == "birth" || command == "Birth" || command == "BIRTH")
    {

    }
    else if(command == "death" || command == "Death" || command == "DEATH")
    {

    }


}
