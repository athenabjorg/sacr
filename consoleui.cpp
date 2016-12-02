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
void ConsoleUI::run()                                       // DIsplays the main menu
{
    /*
     * This is the main function body, that is run at the start of the program every time
     * and gives the user the option to run a few functions like, userMenuAdd(), userMenuList()
     * userMenuSearch(), userMenuSort(), userMenuPrint(). User can also end the program from here.
     */

    string command;
    bool invalidInput = true;

    clearScreen();

    while(true)
    {

        cout << "Select one of the following options: " << endl;
        cout << "==========================================================================" << endl;
        cout << "Add     -   Add a scientist" << endl;
        cout << "Remove  -   Remove a scientist" << endl;
        cout << "List    -   Show a list of all scientists" << endl;
        cout << "Search  -   Search the list of scientists" << endl;
        cout << "Sort    -   Sort list by name, gender, year of birth, year of death or age" << endl;
        cout << "Quit    -   End program" << endl;
        cout << "==========================================================================" << endl;

        invalidInput = true;

        while(invalidInput)
        {
            invalidInput = false;

            cin.clear();
            cout << endl << "Select: ";

            getline(cin, command);

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
               userMenuPrint();
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
                break;
            }
            else
            {
                invalidInput = true;

                cout << "Invalid input" << endl;
            }
        }

        clearScreen();
    }
}
void ConsoleUI::userMenuAdd()                               // Adds a new programmer
{
    /*
     * The function used to add a new scientist. The user enters
     * name, gender, birth year and year of death. Error checks included.
     */

    string name, genderInput;
    char gender;
    int birthYear = 0, deathYear = 0, age = 0, checkInput;


    clearScreen();

    cout << "Enter the scientist's name: ";
    cin.ignore(-1);
    getline(cin, name);

    while(true) // Check for gender
    {
        cout << endl;
        cout << "Enter the scientist's gender" << endl;
        cout << endl << "F - Female" << endl;
        cout << "M - Male" << endl;
        cout << endl << "Gender: ";
        cin >> genderInput;
        forceLowerCase(genderInput);
        gender = genderInput[0];

        if((gender == 'm') || (gender == 'f'))
        {
            break;
        }
        else
        {
            cout << "Invalid input" << endl;
        }
    }

    while(true) // Check year of birth
        {
           cout << endl << "Enter the scientist's year of birth: ";
           cin >> birthYear;


            if(cin.fail())
            {
                cout << "Invalid input!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if(birthYear <= whatYearIsIt()) // Just in case we discover a programmer of the universe
            {
                break;
            }
            else
            {
                cout << "Invalid input...or you are Marty McFly" << endl;
            }
        }

        while(true) // Check when scientist died (if dead)
        {

            cout << endl << "Enter the scientist's year of death (type 0 if not applicable): ";
            cin >> deathYear;

            if(cin.fail())
            {
                cout << "Invalid input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (deathYear == 0)
            {
                break;
            }
            else if(deathYear > whatYearIsIt())
            {
                cout << "Predicting the future, are we? Try again" << endl;
                cin.clear();
            }
            else if(deathYear >= birthYear)
            {
                break;
            }
            else if(deathYear < birthYear)
            {
                cout << "Invalid input - You can't die before you are born!" << endl;
                cin.clear();
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

    checkInput = userCheckInput(); // A function that checks if the input is valid

    if (checkInput == 0)
    {
        if(_service.addScientist(name, gender, birthYear, deathYear, age))
        {
            cout << endl << name << " successfully added to the list" << endl;

        }
        else
        {
            int userInput;

            cout << "This name is already in the database." << endl;
            cout << endl << "1 - Replace existing name" << endl;
            cout << "2 - Start over" << endl;
            cout << endl << "Select: ";
            cin >> userInput;

            if(userInput == 1)
            {
                _service.removeScientist(name);
                _service.addScientist(name, gender, birthYear, deathYear, age);
            }

        }
    }
    else if (checkInput == 1)
    {
        cout << name << " not added to the list" << endl << endl;
    }

    askReturnToMenu();
}
void ConsoleUI::userMenuSearch()                            // Searches the list
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
    cout << "Birth   -   Search by year of birth" << endl;
    cout << "Death   -   Search by year of death" << endl;
    cout << "Age     -   Search by age" << endl << endl;
    cout << "Select: ";

    getline(cin, command);

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

        cout << "Search by gender" << endl;
        cout << endl << "M - Male" << endl;
        cout << "F - Female" << endl;
        cout << endl << "Gender: ";
        cin >> userInputGender;

        vector<Scientist> scientist = _service.findScientistByGender(userInputGender);
        userMenuPrint(scientist);
        askReturnToMenu();
    }
    else if(command == "age") // Find scientist by age
    {
        int inputCheck;

        clearScreen();
        cout << "Search by:" << endl;
        cout << endl << "(1) - Age" << endl;
        cout << "(2) - Age range" << endl;
        cout << endl << "Select: ";

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

        clearScreen();
        cout << "Search by:" << endl;
        cout << endl << "(1) - Year of birth" << endl;
        cout << "(2) - Range of year of birth" << endl << endl;
        cout << "Select: ";

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
            cout << endl << "Wrong Input" << endl;
        }
    }
    else if(command == "death")
    {
        int inputCheck;

        clearScreen();
        cout << "Search by:" << endl;
        cout << endl << "(1) - Year scientist died" << endl;
        cout << "(2) - Year range of when scientist died" << endl << endl;
        cout << "Select: ";

        cin >> inputCheck;

        if(inputCheck == 1)
        {
            int userInputDeath;

            cout << "Search by year scientist died (0 for still alive): ";
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
            cout << "to year of death: ";
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
void ConsoleUI::userMenuSort()                              // Sorts list
{ 
    /*
     * A sorting function, can call function from scientistservice.cpp scientistSort().
     * The function will sort depending on int parameter "Sort list by Name A-Z(1), Name Z-A(2),
     * Gender(3), Year of Birth(4), Year of Death(5) or Age (6)".
     */

    bool inputCheck = true;
    int userInput;

    do
    {
        clearScreen();

        cout << "Select a sort option: " << endl;
        cout << "===================================" << endl;
        cout << "(1)     -   Sort by name (A-Z)" << endl;
        cout << "(2)     -   Sort by name (Z-A)" << endl;
        cout << "(3)     -   Sort by gender" << endl;
        cout << "(4)     -   Sort by year of birth" << endl;
        cout << "(5)     -   Sort by year of death" << endl;
        cout << "(6)     -   Sort by age" << endl;
        cout << endl << "Select: ";
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
     userMenuPrint();
}
void ConsoleUI::userMenuPrint()                             // Prints whole list
{
    /*
     * Prints out a partial list of scientist, depending on how
     * it was sent forward by the previous function.
     */

    vector<Scientist> scientist = _service.getScientists();

    clearScreen();
    cout << left << setw(30) << "Scientist name:"
         << setw(10) << right << "gender:"
         << setw(10) << "born:"
         << setw(10) << "died:"
         << setw(10) << "age:" << endl;
    cout << "======================================================================" << endl;
    for (size_t i = 0; i < scientist.size(); ++i)
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
    cout << "Total: " << scientist.size() << " scientists" << endl;

    askReturnToMenu();
}
void ConsoleUI::userMenuPrint(const vector<Scientist> &scientist)   // Print list provided
{
    /*
     * Prints out a partial list of scientist, depending on how
     * it was sent forward by the previous function.
     */

    clearScreen();
    cout << left << setw(30) << "Scientist name:"
         << setw(10) << right << "Gender:"
         << setw(10) << "Born:"
         << setw(10) << "Died:"
         << setw(10) << "Age:" << endl;
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
    cout << "Total: " << scientist.size() << " scientists" << endl;

}
int  ConsoleUI::userCheckInput() const                      // Checks input from userMenuAdd
{
    /*
     * Check if all data is correct and return a int depending on what user selected.
     * (0) yes, (1) no, (2) cancel and if nothing selected or wrong input the loop will
     * keep running until one of the 3 is selected.
     */

    while(true)
    {
        string answer;
        cout << endl << "Is this data correct?" << endl;
        cout << endl << "Y - Yes, add the name to the list" << endl;
        cout << "N - No, let me try again" << endl;
        cout << "C - Cancel add and return to the menu" << endl;
        cout << endl << "Select: ";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, answer);


        if(answer[0] == 'y' || answer[0] == 'Y')
        {
            return 0;
        }
        else if (answer[0] == 'n' || answer[0] == 'N')
        {
            return 1;
        }
        else if (answer[0] == 'c' || answer[0] == 'C')
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
     * A function to remove a scientist.
     */

    string command;

    clearScreen();
    cout << "Select one of the following options: " << endl;
    cout << "======================================================================" << endl;
    cout << "(1)     -   Remove scientists by name " << endl;
    cout << "(2)     -   Remove *ALL* scientists" << endl << endl;
    cout << "Select: ";

    getline(cin, command);
    cout << endl;

    if(command[0] == '1') // Remove scientist/s by input.
    {
        vector<Scientist> scientist = _service.getScientists();
        userMenuPrint(scientist);

        string userInputName, confirm;
        vector<Scientist> scientistsToRemove;


        cout << endl << "Remove scientists with names containing: ";


        getline(cin, userInputName);
        scientistsToRemove = _service.findScientistByName(userInputName);

        if(scientistsToRemove.size() > 0)
        {
            userMenuPrint(scientistsToRemove);
            cout << endl << "Are you sure you want to remove these scientists from the list? (y/n)" << endl;
            cout << endl << "Select: ";

            getline(cin, confirm);

            if (confirm[0] == 'y' || confirm[0] == 'Y')
            {
                _service.removeScientist(userInputName);
                cout << endl << "Scientists with names containing '" << userInputName << "' have been removed from the list." << endl;
                askReturnToMenu();
            }

        }
        else
        {
            cout << endl << "There are no scientists with names containing '" << userInputName << "'" << endl;
            askReturnToMenu();
        }
    }
    else if(command[0] == '2') // Remove all scientists
    {
        string userInputName;

        clearScreen();

        cout << "Type in \"remove\" to remove *ALL* scientists, any other input to cancel" << endl;
        cin.ignore();
        getline(cin, userInputName);
        forceLowerCase(userInputName);

        if(userInputName == "remove")
        {
            _service.removeAllScientists();
            clearScreen();
            userMenuPrint();
        }

    }

}
void ConsoleUI::forceLowerCase(string &command)             // Forces input to lower case
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
void ConsoleUI::askReturnToMenu() const                     // Asks if user wants to move back to the menu
{
    cout << endl;
    cout << "To return to the menu press m" << endl;
    cout << "Select: ";

   string userInput = " ";
   while (userInput[0] != 'm' && userInput[0] != 'M')
   {
       getline(cin, userInput);
   }
}
void ConsoleUI::clearScreen() const                         // Clears console screen
{
    const int spaceLength = 50;
    cout << string( spaceLength, '\n' );
}
int  ConsoleUI::whatYearIsIt() const                        // Returns the current year.
{
    time_t     currentTime;
    struct tm* timeinfo;

    time(&currentTime);
    timeinfo = localtime(&currentTime);

    int currentYear = (timeinfo->tm_year + 1900);
    return currentYear;
}
