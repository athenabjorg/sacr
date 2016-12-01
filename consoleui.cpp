#include <iostream>
#include <string>
#include "consoleui.h"
#include "scientist.h"
#include <iomanip>


using namespace std;

ConsoleUI::ConsoleUI()
{
    _service.getScientists();  // gets information from file so it's used from the beginning.
}

// Should not contain logic for individual commands, that should be in separate functions!
void ConsoleUI::run()
{


    string command;

    while(true)
    {
        cout << string( 100, '\n' ); // Clears screen

        cout << "Select one of the following options: " << endl;
        cout << "======================================================================" << endl;
        cout << "Add     -   add a programmer/computer scientist" << endl;
        cout << "Remove  -   remove a programmer/computer scientist" << endl;
        cout << "List    -   show a list of all programmer's/computer scientist's" << endl;
        cout << "Search  -   search the list of programmer's/computer scientist's" << endl;
        cout << "Sort    -   sort list by name, gender, age or year of death" << endl;
        cout << "Quit    -   end program" << endl;

        cin >> command;
        forceLowerCase(command);

        if(command == "add")
        {
           userMenuAdd();
        }
        else if(command == "remove")
        {
           userMenuRemove();
        }
        else if(command == "list")
        {
           userMenuList();
        }
        else if(command == "search")
        {
           userMenuSearch();
        }
        else if(command == "sort")
        {
            userMenuSort();
        }
        else if(command == "quit")
        {
            cout << string( 100, '\n' ); // Clears screen

            break;
        }
        else
        {
            cout << "Invalid input" << endl;
        }
    }
}
void ConsoleUI::userMenuAdd()
{
    string name;
    string genderInput;
    char gender;
    int birthYear;
    int deathYear = 0;
    int age = 0;
    int a;

    while(true)
    {
        cout << string( 100, '\n' ); // Clears screen

        cout << "Enter the programmer's/computer scientist's name: ";
        cin.ignore();
        getline(cin, name);

        cout << string( 100, '\n' ); // Clears screen
        // Check for gender
        while(true)
        {
            cout << "Enter the programmer's/computer scientist's gender (m/f): ";
            cin >> genderInput;
            forceLowerCase(genderInput);

            if((genderInput == "m") || (genderInput == "f"))
            {
                gender = genderInput[0];
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                break;

            }
            else
            {
                cout << string( 100, '\n' ); // Clears screen
                cout << "Invalid input" << endl;

            }

        }

        cout << string( 100, '\n' ); // Clears screen
        // Check year of birth
        while(true)
        {
            bool inputCheck;
            do
            {
                cout << "Enter the programmer's/computer scientist's year of birth: ";
                cin >> birthYear;
                inputCheck = cin.fail();
                if(inputCheck)
                {
                    cout << string( 100, '\n' ); // Clears screen
                    cout << "Invalid input" << endl;
                }
                cin.clear();
                cin.ignore(INT_MAX, '\n');

            }while(inputCheck);

            if(birthYear < 2016) // Just in case we find a programmer of the univers
            {
                break;
            }
            else
            {
                cout << string( 100, '\n' ); // Clears screen
                cout << "Invalid input" << endl;
            }
        }

        cout << string( 100, '\n' ); // Clears screen
        // Check when year of death (if dead)
        while(true)
        {    
            bool inputCheck;
            do
            {


                cout << "Enter the programmer's/computer scientist's year of death (type 0 if not applicable): ";
                cin >> deathYear;
                inputCheck = cin.fail();
                if(inputCheck)
                {
                    cout << string( 100, '\n' ); // Clears screen
                    cout << "Invalid input" << endl;
                }
                cin.clear();
                cin.ignore(INT_MAX, '\n');

            }while(inputCheck);


            if (deathYear == 0)
            {
                break;
            }
            else if(deathYear >= birthYear)
            {
                break;
            }
            else
            {
                cout << string( 100, '\n' ); // Clears screen
                cout << "Invalid input" << endl;
            }
        }


        // Check if input is correct
        cout << string( 100, '\n' ); // Clears screen

        cout << "Name: " << name << endl << "Gender: " << gender << endl << "Born: " << birthYear << endl;

        if(deathYear != 0)
        {
            cout << "Died: " << deathYear << endl;
        }
        else
        {
            cout << endl;
        }



        a = userCheckInput();

        if (a == 0)
        {
            // false sama nafn
            if(_service.addScientist(name, gender, birthYear, deathYear, age))
            {
                break;
            }
            else
            {
                int userInput;
                cout << string( 100, '\n' ); // Clears screen

                cout << "This name is allready taken, replace existing name(1), start over(2)" << endl;
                cin >> userInput;
                if(userInput == 1)
                {
                    _service.removeScientist(name);
                    _service.addScientist(name, gender, birthYear, deathYear, age);
                    break;
                }

            }
        }
        else if (a == 2)
        {
            break;
        }

    }
    cout << endl;

}
void ConsoleUI::userMenuList()
{
    vector<Scientist> scientist = _service.getScientists();
    userMenuPrint(scientist);
}
void ConsoleUI::userMenuSearch()
{
    string command;

    cout << string( 100, '\n' ); // Clears screen
    cout << "Select a search option: " << endl;
    cout << "======================================================================" << endl;
    cout << "Name    -   Search by name" << endl;
    cout << "Gender  -   Search by gender" << endl;
    cout << "Age     -   Search by age" << endl;
    cout << "Birth   -   search by year of birth" << endl;
    cout << "Death   -   search by year of death" << endl;
    cout << "Select: ";
    cin >> command;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << endl;


    forceLowerCase(command);


    if(command == "name")
    {
        string userInputName;
        cout << string( 100, '\n' ); // Clears screen

        cout << "Search by name: ";
        getline(cin, userInputName);

        vector<Scientist> scientist = _service.findScientistByName(userInputName);
        userMenuPrint(scientist);

    }
    else if(command == "gender") // findScientistByGender
    {
        char userInputGender;
        cout << string( 100, '\n' ); // Clears screen

        cout << "Search by gender: ";
        cin >> userInputGender;

        vector<Scientist> scientist = _service.findScientistByGender(userInputGender);
        userMenuPrint(scientist);
    }
    else if(command == "age") // findScientistByGender
    {
        int inputCheck;

        cout << "To search by age(1), to search by range of age(2)" << endl;
        cin >> inputCheck;
        if(inputCheck == 1)
        {
            int userInputAge;
            cout << "Search by age: ";
            cin >> userInputAge;

            vector<Scientist> scientist = _service.findScientistByAge(userInputAge);
            userMenuPrint(scientist);
        }
        else if(inputCheck == 2)
        {
            int userInputAgeFirst;
            int userInputAgeLast;
            cout << "Search from age: ";
            cin >> userInputAgeFirst;
            cout << endl;
            cout << "to age: ";
            cin >> userInputAgeLast;
            cout << endl;

            vector<Scientist> scientist = _service.findScientistByAgeRange(userInputAgeFirst, userInputAgeLast);
            userMenuPrint(scientist);
        }
        else
        {
            cout << "Wrong Input" << endl;
        }


      //  cout << string( 100, '\n' ); // Clears screen


    }
    else if(command == "birth")
    {
        int userInputBirth;
        cout << string( 100, '\n' ); // Clears screen

        cout << "Search by year of birth: ";
        cin >> userInputBirth;

        vector<Scientist> scientist = _service.findScientistByBirth(userInputBirth);
        userMenuPrint(scientist);
    }
    else if(command == "death")
    {
        int userInputDeath;
        cout << string( 100, '\n' ); // Clears screen

        cout << "Search by year of death (0 for still alive): ";
        cin >> userInputDeath;

        vector<Scientist> scientist = _service.findScientistByDeath(userInputDeath);
        userMenuPrint(scientist);
    }
    cout << endl;

}
void ConsoleUI::userMenuSort()
{ 
    bool inputCheck = true;
    int userInput;

    do
    {
        cout << string( 100, '\n' ); // Clears screen

        cout << "Sort list by Name A-Z(1), Name Z-A(2), Gender(3), Year of Birth(4), Year of Death(5) or Age (6)" << endl;
        cin >> userInput;

        if(userInput > 0 && userInput < 7) // check if input is int and if it ranges from 1 to 6
        {
            inputCheck = false;
        }
        else if(cin.fail())
        {
            cout << "Invalid input" << endl;
        }
        else
        {
            cout << "Invalid input" << endl;
        }
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }while(inputCheck);


     _service.scientistSort(userInput);
     userMenuList();
}
void ConsoleUI::userMenuPrint(vector<Scientist>scientist)
{
    cout << string( 100, '\n' );
    cout << left << setw(30) << "Scientist name:"
         << setw(10) << right << "gender:"
         << setw(10) << "born:"
         << setw(10) << "died:"
         << setw(10) << "age:" << endl;
    cout << "======================================================================" << endl;
    for (size_t i = 0; i< scientist.size(); ++i)
    {
        cout << left << setw(30) << scientist[i].getName()
             << setw(10) << right << scientist[i].getGender()
             << setw(10) << scientist[i].getBirth();


             if(scientist[i].getDeath() == 0)
             {
                 cout << setw(10) << "-";
             }
             else
             {
                 cout << setw(10) << scientist[i].getDeath();
             }
             cout << setw(10) << scientist[i].getAge() << endl;


    }
    cout << "======================================================================" << endl;
    cout << "To return to menu press m" << endl;

   string userInput = " ";
   while (userInput != "m")
   {
       cin >> userInput;
   }
}
int  ConsoleUI::userCheckInput()
{
    // Check if all data is correct
    while(true)
    {
        char answear;
        cout << "Is this data correct? (input y/n) or press q to quit" << endl;
        cin >> answear;

        if(answear == 'y')
        {
            return 0;
        }
        else if (answear == 'n')
        {
            return 1;
        }
        else if (answear == 'q')
        {
            return 2;
        }
        else
        {
            cout << "Invalid input!";
        }

    }
}
void ConsoleUI::userMenuRemove()
{
    string userInputName;
    cout << string( 100, '\n' ); // Clears screen

    cout << "Remove a programmer/computer scientist: ";
    cin.ignore();
    getline(cin, userInputName);

    _service.removeScientist(userInputName);
}
void ConsoleUI::forceLowerCase(string &command)
{
    for(unsigned int i = 0; i < command.length(); i++) // to make all lowercase, taken from c++ site
    {
        command[i] = tolower(command[i]);
    }
}
