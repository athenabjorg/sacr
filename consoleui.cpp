#include "consoleui.h"
#include "scientist.h"


using namespace std;

ConsoleUI::ConsoleUI()                                      // Constructor function
{
    /*
     * Gets information from file so it's used from the beginning.
     */

    _service.getScientists(); // Uploads the list of scientists from file.
}
void ConsoleUI::run()                                       // The main function
{
    /*
     * This is the main function body, that is run at the start of the program every time
     * and gives the user the option to run a few functions like, userMenuAdd(), userMenuList()
     * userMenuSearch(), userMenuSort(), userMenuPrint(). User can also end the program from here.
     */

    string command;

    while(true)
    {
        clearScreen(); // Clears every run.

        cout << "Select one of the following options: " << endl;
        cout << "======================================================================" << endl;
        cout << "Add     -   add a programmer/computer scientist" << endl;
        cout << "Remove  -   remove a programmer/computer scientist" << endl;
        cout << "List    -   show a list of all programmer's/computer scientist's" << endl;
        cout << "Search  -   search the list of programmer's/computer scientist's" << endl;
        cout << "Sort    -   sort list by name, gender, age or year of death" << endl;
        cout << "Quit    -   end program" << endl;

        cout << "Select: ";
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
            clearScreen();
            break;
        }
        else
        {
            clearScreen();
            cout << "Invalid input" << endl;
            cout << endl;
        }
    }
}
void ConsoleUI::userMenuAdd()                               // Adds a new programmer
{
    /*
     * The function used to add a new programmer / computer scientist, user gets
     * to enter name, gender, birth, death. Error checks included.
     */

    string name;
    string genderInput;
    char gender;
    int birthYear;
    int deathYear = 0;
    int age = 0;
    int a;

    while(true)
    {
        clearScreen();

        cout << "Enter the programmer's/computer scientist's name: ";
        cin.ignore();
        getline(cin, name);

        clearScreen();

        while(true) // Check for gender
        {
            cout << "Enter the programmer's/computer scientist's gender (m/f): ";
            cin >> genderInput;
            forceLowerCase(genderInput);

            if((genderInput == "m") || (genderInput == "f"))
            {
                gender = genderInput[0];
                cin.clear();
                break;
            }
            else
            {
                clearScreen();
                cout << "Invalid input" << endl;
            }
        }

        clearScreen();

        while(true) // Check year of birth
        {
            bool inputCheck;
            do
            {
                cout << "Enter the programmer's/computer scientist's year of birth: ";
                cin >> birthYear;
                inputCheck = cin.fail();
                if(inputCheck)
                {
                    clearScreen();
                    cout << "Invalid input" << endl;
                }
                cin.clear();
            }
            while(inputCheck);


            if(birthYear < 2016) // Just in case we discover a programmer of the universe
            {
                break;
            }
            else
            {
                clearScreen();
                cout << "Invalid input - You can't be born in the future!" << endl;
            }
        }

        clearScreen();


        while(true) // Check when year of death (if dead)
        {    
            bool inputCheck;
            do
            {
                cout << "Enter the programmer's/computer scientist's year of death (type 0 if not applicable): ";
                cin >> deathYear;
                inputCheck = cin.fail();
                if(inputCheck)
                {
                    clearScreen();
                    cout << "Invalid input" << endl;
                }
                cin.clear();
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
                clearScreen();
                cout << "Invalid input" << endl;
            }
        }

        // Check if input is correct
        clearScreen();
        cout << "Name: " << name << endl << "Gender: " << gender << endl << "Born: " << birthYear << endl;

        if(deathYear != 0)
        {
            cout << "Died: " << deathYear << endl;
        }
        else
        {
            cout << endl;
        }

        a = userCheckInput(); // A function that lets user select if the input that was selected is right or not

        if (a == 0)
        {
            // false sama nafn
            if(_service.addScientist(name, gender, birthYear, deathYear, age))
            {
                cout << name << " has been successfully added to the list" << endl;
                clearScreen();
            }
            else
            {
                int userInput;
                clearScreen();

                cout << "This name is allready taken, replace existing name(1), start over(2)" << endl;
                cout << "Select: ";
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
void ConsoleUI::userMenuList()                              // List of commands
{
    /*
     * A menu list as a vector is loaded into the print function userMenuPrint()
     *
     */

    vector<Scientist> scientist = _service.getScientists();
    userMenuPrint(scientist);
    askReturnToMenu();

}
void ConsoleUI::userMenuSearch()                            // Search list
{
    /*
     * A search list is printed out and user can choose from a few search commands
     * like name, gender, age, birth, death. Error checks included
     */

    string command;

    clearScreen();
    cout << "Select a search option: " << endl;
    cout << "===================================" << endl;
    cout << "Name    -   Search by name" << endl;
    cout << "Gender  -   Search by gender" << endl;   
    cout << "Birth   -   search by year of birth" << endl;
    cout << "Death   -   search by year of death" << endl;
    cout << "Age     -   Search by age" << endl;
    cout << "Select: ";
    cin >> command;
    cin.clear();
    //cin.ignore(INT_MAX, '\n');
    cout << endl;

    forceLowerCase(command);


    if(command == "name") // Find scientist by name
    {
        string userInputName;

        clearScreen();
        cout << "Search by name: ";
        getline(cin, userInputName);

        vector<Scientist> scientist = _service.findScientistByName(userInputName);
        userMenuPrint(scientist);
        askReturnToMenu();
    }
    else if(command == "gender") // Find scientist by gender
    {
        char userInputGender;
        clearScreen();

        cout << "Search by gender: ";
        cin >> userInputGender;

        vector<Scientist> scientist = _service.findScientistByGender(userInputGender);
        userMenuPrint(scientist);
        askReturnToMenu();
    }
    else if(command == "age") // Find scientist by age
    {
        int inputCheck;

        cout << "To search by age(1), to search by range of age(2)" << endl;
        cin >> inputCheck;
        if(inputCheck == 1)
        {
            int userInputAge;
            cout << "Search by age: ";
            cout << "Select: ";
            cin >> userInputAge;

            vector<Scientist> scientist = _service.findScientistByAge(userInputAge);
            userMenuPrint(scientist);
            askReturnToMenu();
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
            askReturnToMenu();
        }
        else
        {
            clearScreen();
            cout << "Wrong Input" << endl;
        }
    }
    else if(command == "birth")
    {
        int inputCheck;

        cout << "To search by year of birth(1), to search by range of year of birth(2)" << endl;
        cin >> inputCheck;

        if(inputCheck == 1)
        {
            int userInputBirth;

            cout << "Search by year of birth: ";
            cin >> userInputBirth;

            vector<Scientist> scientist = _service.findScientistByBirth(userInputBirth);
            userMenuPrint(scientist);
            askReturnToMenu();
        }
        else if(inputCheck == 2)
        {
            int userInputBirthFirst;
            int userInputBirthLast;

            cout << "Search from year of birth: ";
            cin >> userInputBirthFirst;
            cout << endl;
            cout << "to year of birth: ";
            cin >> userInputBirthLast;
            cout << endl;

            vector<Scientist> scientist = _service.findScientistByBirthRange(userInputBirthFirst, userInputBirthLast);
            userMenuPrint(scientist);
            askReturnToMenu();
        }
        else
        {
            clearScreen();
            cout << "Wrong Input" << endl;
        }
    }
    else if(command == "death")
    {
        int inputCheck;

        cout << "To search by year of death(1), to search by range of year of death(2)" << endl;
        cin >> inputCheck;

        if(inputCheck == 1)
        {
            int userInputDeath;

            cout << "Search by year of death (0 for still alive): ";
            cin >> userInputDeath;

            vector<Scientist> scientist = _service.findScientistByDeath(userInputDeath);
            userMenuPrint(scientist);
            askReturnToMenu();
        }
        else if(inputCheck == 2)
        {
            int userInputDeathFirst;
            int userInputDeathLast;

            cout << "Search from year of death (0 for still alive): ";
            cin >> userInputDeathFirst;
            cout << endl;
            cout << "to year of death (0 for still alive): ";
            cin >> userInputDeathLast;
            cout << endl;

            vector<Scientist> scientist = _service.findScientistByDeathRange(userInputDeathFirst, userInputDeathLast);
            userMenuPrint(scientist);
            askReturnToMenu();
        }
        else
        {
            clearScreen();
            cout << "Wrong Input" << endl;
        }
    }
    cout << endl;
}
void ConsoleUI::userMenuSort()                              // Sort list
{ 
    /*
     * A sorting function, can call function from scientistservice.cpp scientistSort().
     * Depending on int parameter "Sort list by Name A-Z(1), Name Z-A(2),Gender(3),
     * Year of Birth(4), Year of Death(5) or Age (6)" the function will sort differently.
     */

    bool inputCheck = true;
    int userInput;

    do
    {
        clearScreen();

        cout << "Sort list by Name A-Z(1), Name Z-A(2), Gender(3), Year of Birth(4), Year of Death(5) or Age (6)" << endl;
        cout << "Select: ";
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

    }while(inputCheck);

     _service.scientistSort(userInput);
     userMenuList();
}
void ConsoleUI::userMenuPrint(vector<Scientist>scientist)   // Print list
{
    /*
     * This is the function that prints out the menu for user to navigate the program
     * and make changes or add programmers / computer scientists.
     */

    clearScreen();
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
}
int  ConsoleUI::userCheckInput()                            // Check input from userMenuAdd
{
    /*
     * Check if all data is correct and return a int depending on what user selected.
     * (0) yes, (1) no, (2) quit and if nothing selected or wrong input the loop will
     * keep running untill one of the 3 is selected.
     */

    while(true)
    {
        char answear;
        cout << "Is this data correct? (input y/n) or press q to quit" << endl;
        cout << "Select: ";
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
void ConsoleUI::userMenuRemove()                            // Removes a programmer
{
    /*
     * A function to remove a programmer / computer scientist.
     */

    int command;

    clearScreen();
    cout << "Select one of the following options: " << endl;
    cout << "======================================================================" << endl;
    cout << "(1)     -   Remove a single programmer / computer scientist " << endl;
    cout << "(2)     -   Remove *ALL* programmers / computer scientists (2)" << endl;
    cout << "Select: ";

    cin >> command;
    cin.clear();
    cout << endl;

    if(command == 1) // Remove programmer/s by input.
    {

        string userInputName, confirm;
        vector<Scientist> scientistsToRemove;
        clearScreen();

        cout << "Remove programmers/computer scientists with names containing: ";

        cin.ignore();
        getline(cin, userInputName);
        scientistsToRemove = _service.findScientistByName(userInputName);
        userMenuPrint(scientistsToRemove);
        cout << endl << "Are you sure you want to remove these computer scientists from the list (y/n)" << endl;
        cout << "Select: ";
        cin.ignore();
        getline(cin, confirm);

        if (confirm[0] == 'y' || confirm[0] == 'Y')
        {
            _service.removeScientist(userInputName);
            cout << "Scientists with names containing " << userInputName << " have been removed from the list." << endl;
        }

        clearScreen();

    }
    else if(command == 2) // Remove all programmers
    {
        string userInputName;

        clearScreen();

        cout << "Confirm remove *ALL* programmers / computer scientists (y), any other letter to cancel" << endl;
        cin.ignore();
        getline(cin, userInputName);
        forceLowerCase(userInputName);

        if(userInputName == "y")
        {
            _service.removeAllScientists();
            clearScreen();
            userMenuList();
        }
        else
        {
            clearScreen();
            cout << "Wrong Input" << endl;
        }

    }
    else
    {
        clearScreen();
        cout << "Wrong Input" << endl;
    }
}
void ConsoleUI::forceLowerCase(string &command)             // Force input to lower case
{
    /*
     * A function that takes a string parameter as refrence and forces the string
     * to be only lowercase. Code taken from c++ site
     */

    for(unsigned int i = 0; i < command.length(); i++)
    {
        command[i] = tolower(command[i]);
    }
}

void ConsoleUI::askReturnToMenu()
{
    cout << "======================================================================" << endl;
    cout << "To return to menu press m" << endl;
    cout << "Select: ";

   string userInput = " ";
   while (userInput != "m")
   {
       cin >> userInput;
   }
   cout << string( 2, '\n' );
}

void ConsoleUI::clearScreen()
{
    const int spaceLength = 100;
    cout << string( spaceLength, '\n' );
}
