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
    cout << "Please enter one of the following commands:" << endl;
    cout << "list - This will list all performers in the system" << endl;
    cout << "add - This will add a new performer" << endl;
    cout << "delete - This removes an entry" << endl;
    cout << "update - Updates an entry" << endl;
    cout << "search - Searches for a given performer" << endl;

    // Test

    string command;
    cin >> command;

    if (command == "list")
    {
        displayListOfPerformers();
    }
    else if (command == "add")
    {
        string name;
        int age;
        cin >> name;
        cin >> age;

        Performer newPerformer(name, age);

        // TODO:
        //_service.addPerformer(newPerformer);
    }
    else if (command == "search")
    {
        // TODO
    }
    else
    {

    }

}

void ConsoleUI::displayListOfPerformers()
{
    vector<Performer> performers = _service.getPerformers();

    cout << "Performer name:" << endl;
    cout << "===============" << endl;
    for (size_t i = 0; i< performers.size(); ++i)
    {
        cout << performers[i].getName() << endl;
    }
}

