#include "consoleui.h"
#include "scientist.h"
#include "computer.h"

#include <QtSql>



using namespace std;

ConsoleUI::ConsoleUI()                                              // Constructor function
{
    /*
     * Gets information from file so it's used from the beginning.
     */

    _service.getScientists(); // Uploads the list of scientists from file.
}
void ConsoleUI::run()                                               // DIsplays the main menu
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
        cout << "=====================================================================================================" << endl;
        cout << "Add     -   Add a scientist or a computer" << endl;
        cout << "Remove  -   Remove a scientist or a computer" << endl;
        cout << "List    -   Show a list of all scientists or computers" << endl;
        cout << "Search  -   Search the list of scientists or computers" << endl;
        cout << "Sort    -   Sort list of scientists or computers by name, gender, year of birth, year of death or age" << endl;
        cout << "Quit    -   End program" << endl;
        cout << "=====================================================================================================" << endl;

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
                userMenuSwitch(1);
            }
            else if(command == "remove")
            {
                userMenuSwitch(2);
            }
            else if(command == "list")
            {
                userMenuSwitch(3);
            }
            else if(command == "search")
            {
                userMenuSwitch(4);
            }
            else if(command == "sort")
            {
                userMenuSwitch(5);
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

        if(command == "quit")
        {
            break;
        }
        clearScreen();
    }
}
void ConsoleUI::userMenuSwitch(int loadType)
{
    int selection = 0;
    string line;


    switch(loadType) // (1)add -> (2)remove -> (3)list -> (4)search -> (5)sort
    {
        case 1: line = "Would you like to add a scientist or a computer to the database?";
                break;
        case 2: line = "Would you like to remove a scientist or a computer from the database?";
                break;
        case 3: line = "Would you like to print a list of scientists or a computers?";
                break;
        case 4: line = "Would you like to search for scientist or a computer in the database?";
                break;
        case 5: line = "Would you like to sort scientists or a computers?";
                break;
    }

    cout << line << endl
         << "1 - Scientist" << endl
         << "2 - Computer" << endl;
    cin >> selection;

    if (selection == 1) // Scientist selected
    {
        switch(loadType)
        {
            case 1: cin.ignore();
                    addScientist();
                    break;
            case 2: cin.ignore();
                    userMenuRemove();// TODO::change name and seprate; removeScientist(), removeComputer().
                    break;
            case 3: cin.ignore();
                    userMenuPrint(_service.getScientists());
                    askReturnToMenu();
                    break;
            case 4: cin.ignore();
                    searchScientist();
                    break;
            case 5: cin.ignore();
                    //sortScientist();
                    break;

        }
    }
    else if (selection == 2) // Computer selected
    {
        switch(loadType)
        {
            case 1: cin.ignore();
                    addComputer();
                    break;
            case 2: cin.ignore();
                    userMenuRemove();// TODO::change name and seprate; removeScientist(), removeComputer().
                    break;
            case 3: cin.ignore();
                    userMenuPrint(_service.getComputers());
                    break;
            case 4: cin.ignore();
                    searchComputer();
                    break;
            case 5: cin.ignore();
                    //sortComputer();
                    break;

        }
    }
    else
        cout << "Invalid input" << endl;

}
void ConsoleUI::userMenuAdd()                                       // Adds a new programmer
{
    int selection = 0;
    cout << "Would you like to add a scientist or a computer to the database?" << endl
         << "1 - Scientist" << endl
         << "2 - Computer" << endl;
    cin >> selection;

    if (selection == 1)
    {
        cin.ignore();
        addScientist();
    }
    else if (selection == 2)
    {
        cin.ignore();
        addComputer();
    }
    else
        cout << "Invalid input" << endl;
}
void ConsoleUI::userMenuSearch()                                    // Searches the list
{
    int selection = 0;
    cout << "Would you like to search for scientist or a computer in the database?" << endl
         << "1 - Scientist" << endl
         << "2 - Computer" << endl;
    cin >> selection;

    if (selection == 1)
    {
        cin.ignore();
        addScientist();
    }
    else if (selection == 2)
    {
        cin.ignore();
        addComputer();
    }
    else
        cout << "Invalid input" << endl;
}
void ConsoleUI::userMenuSort()                                      // Sorts list
{
    int selection = 0;
    cout << "Would you like to sort the list of scientists or the computers" << endl
         << "1 - Scientists" << endl
         << "2 - Computers" << endl;
    cin >> selection;

    if (selection == 1)
    {
        cin.ignore();
        sortScientist();
    }
    else if (selection == 2)
    {
        cin.ignore();
        sortComputer();
    }
    else
        cout << "Invalid input" << endl;
}
void ConsoleUI::userMenuPrint()                                     // Prints whole list
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
void ConsoleUI::userMenuPrint(const vector<Computer> &computer)     // Print list provided
{
    /*
     * Prints out a partial list of scientist, depending on how
     * it was sent forward by the previous function.
     */


    clearScreen();
    cout << left << setw(30) << "Computer name:"
         << setw(10) << right << "Year built:"
         << setw(10) << "Type:"
         << setw(10) << "Was built:" << endl;
    cout << "======================================================================" << endl;
    for (size_t i = 0; i< computer.size(); ++i)
    {
        cout << left << setw(30) << computer[i].getName()
             << setw(10) << right << computer[i].getYear()
             << setw(10) << computer[i].getType()
             << setw(10) << computer[i].getBuilt() << endl;
    }
    cout << "======================================================================" << endl;
    cout << "Total: " << computer.size() << " computers" << endl;

}
int  ConsoleUI::userCheckInput() const                              // Checks input from userMenuAdd
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
        cout << endl << "Y - Yes, add this to the list" << endl;
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
void ConsoleUI::userMenuRemove()                                    // Removes a programmer
{



}
void ConsoleUI::removeScientist()
{
    /*
     * A function to remove a scientist.
     */

    string command;

    clearScreen();
    cout << "Select one of the following options: " << endl;
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
        scientistsToRemove = _service.findScientist(1, userInputName);

        if(scientistsToRemove.size() > 0)
        {
            userMenuPrint(scientistsToRemove);
            cout << endl << "Are you sure you want to remove these scientists from the list?" << endl;
            cout << "Y     -   Yes, remove them " << endl;
            cout << "N     -   No, do not remove them" << endl << endl;
            cout << endl << "Select: ";

            getline(cin, confirm);

            if (confirm[0] == 'y' || confirm[0] == 'Y')
            {
                _service.removeScientist(userInputName);
                cout << endl << "Scientists with names containing '" << userInputName << "' have been removed from the list." << endl;
                askReturnToMenu();
            }
            else
            {
                cout << endl << "No scientists were removed" << endl;
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
void ConsoleUI::removeComputer()
{
    /*
     * A function to remove a computer.
     */

    string command;

    clearScreen();
    cout << "Select one of the following options: " << endl;
    cout << "(1)     -   Remove computer by name " << endl;
    cout << "(2)     -   Remove *ALL* computers" << endl << endl;
    cout << "Select: ";

    getline(cin, command);
    cout << endl;

    if(command[0] == '1') // Remove computer/s by input.
    {
        vector<Computer> computer = _service.getComputers();
        userMenuPrint(computer);

        string userInputName, confirm;
        vector<Computer> computersToRemove;


        cout << endl << "Remove computers with names containing: ";


        getline(cin, userInputName);
        computersToRemove = _service.findComputer(1, userInputName);

        if(computersToRemove.size() > 0)
        {
            userMenuPrint(computersToRemove);
            cout << endl << "Are you sure you want to remove these computers from the list?" << endl;
            cout << "Y     -   Yes, remove them " << endl;
            cout << "N     -   No, do not remove them" << endl << endl;
            cout << endl << "Select: ";

            getline(cin, confirm);

            if (confirm[0] == 'y' || confirm[0] == 'Y')
            {
                _service.removeComputer(userInputName); // TODO::Needs a functin in service layer
                cout << endl << "Computers with names containing '" << userInputName << "' have been removed from the list." << endl;
                askReturnToMenu();
            }
            else
            {
                cout << endl << "No computers were removed" << endl;
                askReturnToMenu();
            }

        }
        else
        {
            cout << endl << "There are no computers with names containing '" << userInputName << "'" << endl;
            askReturnToMenu();
        }
    }
    else if(command[0] == '2') // Remove all computers
    {
        string userInputName;

        clearScreen();

        cout << "Type in \"remove\" to remove *ALL* computers, any other input to cancel" << endl;

        getline(cin, userInputName);
        forceLowerCase(userInputName);

        if(userInputName == "remove")
        {
            _service.removeAllComputers(); // TODO::Needs a functin in service layer
            clearScreen();
            userMenuPrint();
        }

    }
}
void ConsoleUI::forceLowerCase(string &command)                     // Forces input to lower case
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
void ConsoleUI::askReturnToMenu() const                             // Asks if user wants to move back to the menu
{
    cout << endl;
    cout << "To return to the menu input 'm'" << endl;
    cout << "Select: ";

   string userInput = " ";
   while (userInput[0] != 'm' && userInput[0] != 'M')
   {
       getline(cin, userInput);
   }
}
void ConsoleUI::clearScreen() const                                 // Clears console screen
{
    const int spaceLength = 50;
    cout << string( spaceLength, '\n' );
}
int  ConsoleUI::whatYearIsIt() const                                // Returns the current year.
{
    time_t     currentTime;
    struct tm* timeinfo;

    time(&currentTime);
    timeinfo = localtime(&currentTime);

    int currentYear = (timeinfo->tm_year + 1900);
    return currentYear;
}
void ConsoleUI::addScientist()
{
    string name, genderInput;
    char gender;
    int birthYear = 0, deathYear = 0, checkInput;

    while(true)
    {
        clearScreen();

        cout << "Enter the scientist's name: ";
        cin.ignore();
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
            if(_service.addScientist(name, gender, birthYear, deathYear))
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
                    _service.addScientist(name, gender, birthYear, deathYear);
                }

            }
            askReturnToMenu();
            break;
        }
        else if (checkInput == 1)
        {

        }
        else
        {
            break;
        }
    }
}
void ConsoleUI::addComputer()
{
    string name, type;
    int yearBuilt = 0, checkInput;
    bool built = false;

        while(true)
        {
        clearScreen();

        cout << "Enter the computer's name: ";
        cin.ignore(-1);
        getline(cin, name);

        while(true) // Check for type
        {
            int inputType;
            cout << endl;
            cout << "What type of computer is this?" << endl;
            cout << endl << "1 - ElectroMechanical" << endl;
            cout << "2 - Electronic" << endl;
            cout << "3 - Mechanical" << endl;
            cout << "4 - Transistor" << endl;
            cout << endl << "Type: ";
            cin >> inputType;

            if(cin.fail())
            {
                cout << "Invalid input!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                switch(inputType)
                {
                    case 1:
                        type = "ElectroMechanical";
                        break;
                    case 2:
                        type = "Electronic";
                        break;
                    case 3:
                        type = "Mechanical";
                        break;
                    case 4:
                        type = "Transistor";
                        break;
                }
                if(inputType == 1 || inputType == 2 || inputType == 3 || inputType == 4)
                {
                    break;
                }
                else
                {
                    cout << "Invalid input" << endl;
                }
            }
        }

        while(true) // Check if it was built
        {
            char builtInput;
            cout << endl << "Was the computer ever built? (y/n)"<< endl;
            cin >> builtInput;

            if (builtInput == 'y')
            {
                built = true;
                break;
            }
            else if (builtInput == 'n')
            {
                built = false;
                break;
            }

            else
                cout << "Invalid Input" << endl;
        }

        while(built == true) // Check when when it was built (if it was)
        {
            cout << endl << "What year was the computer built?" << endl;
            cin >> yearBuilt;

            if(cin.fail())
            {
                cout << "Invalid input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if(yearBuilt > whatYearIsIt())
            {
                cout << "Predicting the future, are we? Try again" << endl;
                cin.clear();
            }
            else
                break;
        }

        // Check if input is correct
        clearScreen();
        cout << "Name: " << name << endl << "Type: " << type << endl;

        if(built == true)
        {
            cout << "Built: " << yearBuilt << endl;
        }
        else
        {
            cout << "Was never built" << endl;
        }

        checkInput = userCheckInput(); // A function that checks if the input is valid

        if (checkInput == 0)
        {
            /*if(_service.addScientist(name, gender, birthYear, deathYear))
            {
                cout << endl << name << " successfully added to the list" << endl;

            }
            else
            {
                int userInput;

                cout << "This name is already in the database." << endl;
                cout << endl << "1 - Replace existing data" << endl;
                cout << "2 - Start over" << endl;
                cout << endl << "Select: ";
                cin >> userInput;

                if(userInput == 1)
                {
                    _service.removeScientist(name);
                    _service.addScientist(name, gender, birthYear, deathYear);
                }

            }
            askReturnToMenu();
            break;
            */
        }
        else if (checkInput == 1)
        {

        }
        else
        {
            break;
        }
    }
}
void ConsoleUI::searchScientist()
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

        vector<Scientist> scientist = _service.findScientist(1, userInputName);
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

        vector<Scientist> scientist = _service.findScientist(2, to_string(userInputGender));
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

            vector<Scientist> scientist = _service.findScientist(7, to_string(userInputAge));
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

            if(userInputAgeFirst > userInputAgeLast)
            {
                int temp = userInputAgeFirst;
                userInputAgeFirst = userInputAgeLast;
                userInputAgeLast = temp;
            }

            vector<Scientist> scientist = _service.findScientist(8, to_string(userInputAgeFirst), to_string(userInputAgeLast));
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

            vector<Scientist> scientist = _service.findScientist(3, to_string(userInputBirth));
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

            if(userInputBirthFirst > userInputBirthLast)
            {
                int temp = userInputBirthFirst;
                userInputBirthFirst = userInputBirthLast;
                userInputBirthLast = temp;
            }

            vector<Scientist> scientist = _service.findScientist(4, to_string(userInputBirthFirst), to_string(userInputBirthLast));
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

            vector<Scientist> scientist = _service.findScientist(5, to_string(userInputDeath));
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

            if(userInputDeathFirst > userInputDeathLast)
            {
                int temp = userInputDeathFirst;
                userInputDeathFirst = userInputDeathLast;
                userInputDeathLast = temp;
            }

            vector<Scientist> scientist = _service.findScientist(6, to_string(userInputDeathFirst), to_string(userInputDeathLast));
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
void ConsoleUI::searchComputer()
{
    /*
     * A search list is printed out and user can choose from a few search commands
     * like name, year built, type, and if built. Error checks included
     */

    string command;

    clearScreen();
    cout << "Select a search option: " << endl;
    cout << "===================================" << endl;
    cout << "Name    -   Search by name" << endl;
    cout << "Year    -   Search by year built" << endl;
    cout << "Type    -   Search by type" << endl;
    cout << "Built   -   Search by if built or not" << endl;
    cout << "Select: ";

    getline(cin, command);
    forceLowerCase(command);


    if(command == "name") // Find computer by name
    {
        string userInputName;

        clearScreen();
        cout << "Search by name: ";
        getline(cin, userInputName);

        vector<Computer> computer = _service.findComputer(1, userInputName);
        userMenuPrint(computer);
        askReturnToMenu();
    }
    else if(command == "year") // Find computer by year
    {
        int userInputYear;
        int userInputYearFirst;
        int userInputYearLast;
        int inputCheck;
        vector<Computer> computer;

        clearScreen();
        cout << "Search by year:" << endl;
        cout << endl << "(1) - Search for a computer by year it was made" << endl;
        cout << "(2) - Search for a computer by range of year it was made " << endl;
        cout << endl << "Select: ";

        cin >> inputCheck;

        switch(inputCheck)
        {
            case 1: cout << "Search by year built" << endl;
                    cout << endl << "Year: ";
                    cin >> userInputYear;
                    computer = _service.findComputer(2, to_string(userInputYear)); // TODO:: right type input etc.
                    userMenuPrint(computer);
                    askReturnToMenu();
                    break;

            case 2: cout << "Search by range of year built" << endl;
                    cout << endl << "Starting year: ";
                    cin >> userInputYearFirst;
                    cout << endl << "Ending year: ";
                    cin >> userInputYearLast;
                    computer = _service.findComputer(2, to_string(userInputYearFirst), to_string(userInputYearLast)); // TODO:: right type input etc.
                    userMenuPrint(computer);
                    askReturnToMenu();
                    break;
            default: cout << "Wrong Input" << endl;
        }



        computer = _service.findComputer(2, to_string(userInputYear)); // TODO:: right type input etc.
        userMenuPrint(computer);
        askReturnToMenu();
    }
    else if(command == "type") // Find computer by type
    {
        int inputCheck;
        vector<Computer> computer;

        clearScreen();
        cout << "Search by type:" << endl;
        cout << endl << "(1) - ElectroMechanical" << endl;
        cout << "(2) - Electronic" << endl;
        cout << "(3) - Mechanical" << endl;
        cout << "(4) - Transistor" << endl;
        cout << endl << "Select: ";

        cin >> inputCheck;

        switch(inputCheck)
        {
            case 1: computer = _service.findComputer(7,"ElectroMechanical"); // TODO:: right type input etc.
                    userMenuPrint(computer);
                    askReturnToMenu();
                    break;
            case 2: computer = _service.findComputer(7,"Electronic"); // TODO:: right type input etc.
                    userMenuPrint(computer);
                    askReturnToMenu();
                    break;
            case 3: computer = _service.findComputer(7,"Mechanical"); // TODO:: right type input etc.
                    userMenuPrint(computer);
                    askReturnToMenu();
                    break;
            case 4: computer = _service.findComputer(7,"Transistor"); // TODO:: right type input etc.
                    userMenuPrint(computer);
                    askReturnToMenu();
                    break;
            default: cout << "Wrong Input" << endl;
        }
    }
    else if(command == "built") // Find computer if built or not
    {
        int inputCheck;
        vector<Computer> computers;

        clearScreen();
        cout << "Search by:" << endl;
        cout << endl << "(1) - Was built" << endl;
        cout << "(2) - Was not built" << endl << endl;
        cout << "Select: ";

        cin >> inputCheck;

        switch(inputCheck)
        {
            case 1: computers = _service.findComputer(7,"0"); // TODO:: right type input etc.
                    userMenuPrint(computers);
                    askReturnToMenu();
                    break;
            case 2: computers = _service.findComputer(7,"1"); // TODO:: right type input etc.
                    userMenuPrint(computers);
                    askReturnToMenu();
                    break;
            default: cout << "Wrong Input" << endl;
        }
    }
    cout << endl;
}
void ConsoleUI::sortScientist()
{
    /*
     * A sorting function, can call function from scientistservice.cpp scientistSort().
     * The function will sort depending on int parameter "Sort list by Name A-Z(1), Name Z-A(2),
     * Gender(3), Year of Birth(4), Year of Death(5) or Age (6)".
     */


    vector<Scientist> sortedScientists;
    bool inputCheck = true;
    int userInput;

    clearScreen();

        cout << "Select a sort option: " << endl;
        cout << "===================================" << endl;
        cout << "(1)     -   Sort by name (A-Z)" << endl;
        cout << "(2)     -   Sort by name (Z-A)" << endl;
        cout << "(3)     -   Sort by gender" << endl;
        cout << "(4)     -   Sort by year of birth (First to last)" << endl;
        cout << "(5)     -   Sort by year of death (Alive scientists first. Then first to last)" << endl;
        cout << "(6)     -   Sort by age (Youngest to oldest)" << endl;

    do
    {
        cout << endl << "Select: ";
        cin >> userInput;

        if(userInput < 0 || userInput > 10) // check if input is int and if it ranges from 1 to 10
        {
            inputCheck = true;
            cout << "Invalid input" << endl;
        }
        else
        {
            inputCheck = false;
        }
        cin.clear();

        clearScreen();

    }while(inputCheck);

     sortedScientists = _service.scientistSort(userInput);

     userMenuPrint(sortedScientists);

     askReturnToMenu();
}
void ConsoleUI::sortComputer()
{
    /*
     * A sorting function, can call function from scientistservice.cpp scientistSort().
     * The function will sort depending on int parameter "Sort list by Name A-Z(1), Name Z-A(2),
     * Gender(3), Year of Birth(4), Year of Death(5) or Age (6)".
     */


    vector<Computer> sortedComputers;
    bool inputCheck = true;
    int userInput;

    clearScreen();

        cout << "Select a sort option: " << endl;
        cout << "===================================" << endl;
        cout << "(1)     -   Sort by name (A-Z)" << endl;
        cout << "(2)     -   Sort by name (Z-A)" << endl;
        cout << "(3)     -   Sort by type" << endl;
        cout << "(4)     -   Sort by year built (First to last)" << endl;

    do
    {
        cout << endl << "Select: ";
        cin >> userInput;

        if(userInput < 0 || userInput > 10) // check if input is int and if it ranges from 1 to 10
        {
            inputCheck = true;
            cout << "Invalid input" << endl;
        }
        else
        {
            inputCheck = false;
        }
        cin.clear();

        clearScreen();

    }while(inputCheck);

     sortedComputers = _service.computerSort(userInput);

     //userMenuPrint(sortedComputers); ############### Laga þegar print er orðið klárt #########

     askReturnToMenu();

}
