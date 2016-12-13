#include "consoleui.h"

using namespace std;


ConsoleUI::ConsoleUI()                                              // Constructor function
{
    /* Gets information from file so it's used from the beginning.
     */

    _service.getScientists(); // Uploads the list of scientists from file.
}

// ---------------------------------- USER MENU FUNCTIONS ---------------------------------- //
void ConsoleUI::userMenuRun()                                       // Displays the main menu
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
        largeLogoPrint();

        cout << "========================================================================================================" << endl;
        cout << "Add     -   Add a scientist or a computer" << endl;
        cout << "Remove  -   Remove a scientist or a computer" << endl;
        cout << "List    -   Show a list of all scientists or computers" << endl;
        cout << "Search  -   Search the list of scientists or computers" << endl;
        cout << "Sort    -   Sort list of scientists or computers by name, gender, year of birth, year of death or age" << endl;
        cout << "Quit    -   End program" << endl;
        cout << "========================================================================================================" << endl;
        cout << "Select one of the options above" << endl;

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

                invalidInputPrompt();
            }
        }

        if(command == "quit")
        {
            clearScreen();
            smallLogoPrint();
            textColorRed();
            if((whatYearIsIt() - 2015) == 0)
            {
                cout << setw(85) << "SACR version 2.0 will be released in December 2016" << endl << endl;
            }
            else
            {
                cout << setw(73) << "You are running an old version of SACR" << endl;
                cout << setw(105) << "Get the latest version from www.themostamazingprogrammersintheworld.ru" << endl << endl;
            }

            cout << setw(61) << "24/7 HOTLINE: +354 7707010" << endl << endl;
            textColorWhite();
            break;
        }
        clearScreen();
    }
}
void ConsoleUI::userMenuSwitch(int loadType)                        // Switch between functions
{
    /*
     * Depending on your selection here, and parametere "loadType" this function will
     * call on different functions for each case. This function is used in userMenuRun();
     */

    int selection = 0;
    string line;

    clearScreen();

    switch(loadType) // (1)add -> (2)remove -> (3)list -> (4)search -> (5)sort
    {
    case 1: line = "Would you like to add a scientist, computer or a relation to the database?";
        break;
    case 2: line = "Would you like to remove a scientist, computer or a relation from the database?";
        break;
    case 3: line = "Would you like to print a list of scientist, computer or a relation?";
        break;
    case 4: line = "Would you like to search for scientist, computer or a relation in the database?";
        break;
    case 5: line = "Would you like to sort scientist, computer or a relation?";
        break;
    }
    smallLogoPrint();
    cout << line << endl << endl
         << "(1) - Scientist" << endl
         << "(2) - Computer" << endl
         << "(3) - Relation" << endl
         << endl << "Select: ";
    cin >> selection;

    if (selection == 1) // Scientist selected
    {
        switch(loadType)
        {
        case 1: cin.ignore();
            addScientist();
            break;
        case 2: cin.ignore();
            removeScientist();
            break;
        case 3: cin.ignore();
            userMenuPrint(_service.getScientists());
            askReturnToMenu();
            break;
        case 4: cin.ignore();
            searchScientist();
            break;
        case 5: cin.ignore();
            sortScientist();
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
            removeComputer();
            break;
        case 3: cin.ignore();
            userMenuPrint(_service.getComputers());
            askReturnToMenu();
            break;
        case 4: cin.ignore();
            searchComputer();
            break;
        case 5: cin.ignore();
            sortComputer();
            break;

        }
    }
    else if (selection == 3) // Relation selected
    {
        switch(loadType)
        {
        case 1: cin.ignore();
            addRelation();
            break;
        case 2: cin.ignore();
            removeRelation();
            break;
        case 3: cin.ignore();
            userMenuPrint(_service.getRelations());
            askReturnToMenu();
            break;
        case 4: cin.ignore();
            searchRelation();
            break;
        case 5: cin.ignore();
            sortRelation();
            break;

        }
    }
    else
    {
        numericLimiter("Invalid Input!");
        userMenuSwitch(loadType);
    }

}
void ConsoleUI::userMenuPrint(int loadType)                         // Prints list depending on parameter
{
    /*
     * Prints out a list depending on parameter used for function
     * (1) - list of Scientists, (2) - list of computers and
     * (3) - list of relations.
    */

    vector<Scientist> scientist = _service.getScientists();
    vector<Computer> computer = _service.getComputers();
    vector<Relation> relation = _service.getRelations();

    switch(loadType)
    {
    case 1: userMenuPrint(scientist);
        break;
    case 2: userMenuPrint(computer);
        break;
    case 3: userMenuPrint(relation);
        break;
    default: userMenuPrint(scientist);
    }
}
void ConsoleUI::userMenuPrint(const vector<Scientist> &scientist)   // Print list provided
{
    /*
     * Prints out a partial list of scientist, depending on how
     * it was sent forward by the previous function.
     */

    clearScreen();
    smallLogoPrint();
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
     * Prints out a partial list of computers, depending on how
     * it was sent forward by the previous function.
     */


    clearScreen();
    smallLogoPrint();
    cout << left << setw(25) << "Computer name:"
         << setw(10) << right << "Year built:"
         << setw(20) << "Type:"
         << setw(15) << "Was built:"
         << setw(22) << "Years since built:" << endl;
    cout << "=============================================================================================" << endl;
    for (size_t i = 0; i< computer.size(); ++i)
    {
        cout << left << setw(25) << computer[i].getName();

        if(computer[i].getYear() == 0)
        {
            cout << setw(10) << right << "-";
        }
        else
        {
            cout << setw(10) << right << computer[i].getYear();
        }

        cout << setw(20) << computer[i].getType();

        if(computer[i].getBuilt()==true)
        {
            cout << setw(15) << "Yes";
            cout << setw(22) << computer[i].getYearsSinceBuilt() << endl; // Mætir afgangi
        }
        else
        {
            cout << setw(15) << "No";
            cout << setw (22) << "-" << endl; // Þarf að vera ef við setjum inn yearsSinceBuilt
        }
    }
    cout << "=============================================================================================" << endl;
    cout << "Total: " << computer.size() << " computers" << endl;
}
void ConsoleUI::userMenuPrint(const vector<Relation> &relation)     // Print list provided
{
    /*
     * Prints out a partial list of scientist-computer relations, depending on how
     * it was sent forward by the previous function.
     */


    clearScreen();
    smallLogoPrint();
    cout << left << setw(30) << "Scientist:"
         << setw(25) << right << "Computer:"
         << setw(15) << "Year built" << endl;
    cout << "=======================================================================" << endl;

    for (size_t i = 0; i < relation.size(); ++i)
    {
        cout << left << setw(30) << relation[i].getScientist()
             << setw(25) << right << relation[i].getComputer();

        if(relation[i].getYear() == 0)
        {
            cout << setw(15) << "-" << endl;
        }
        else
        {
            cout << setw(15) << relation[i].getYear() << endl;
        }
    }
    cout << "=======================================================================" << endl;
    cout << "Total: " << relation.size() << " relations" << endl;
}


// ---------------------------------- SCIENTIST FUNCTIONS ---------------------------------- //
void ConsoleUI::addScientist()                                      // Add scientist to database
{
    /*
     * This function gets all variables from user and makes error checks, if everything
     * checks out fine this function will call on server layer functions to then add those
     * variables to the database.
     */
    string name, genderInput;
    char gender;
    int birthYear = 0, deathYear = 0, checkInput;

    while(true)
    {
        clearScreen();
        smallLogoPrint();

        while(true)
        {
            cout << "Enter the scientist's name: ";
            cin.ignore(-1);
            getline(cin, name);

            if(name == "")
            {
                textColorRed();
                cout << endl << "\"Every rose has it's thorne, just like every scientist has a name\" -Poison"<< endl << endl;
                textColorWhite();
            }
            else if(_service.findScientist(0, name).size() > 0)
            {
                int userInput;
                cout << "This scientists is already in the database" << endl;
                cout << endl << "(1) To enter name again" << endl;
                cout << "(2) To replace scientist" << endl;
                cout << endl << "Select: ";
                cin >> userInput;

                numericLimiter();


                if(userInput == 1)
                {
                    continue;
                }
                else if(userInput == 2)
                {
                    break;
                }
                else
                {
                    invalidInputPrompt();
                }

            }
            else
            {
                break;
            }
        }

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
                invalidInputPrompt();
            }
        }

        while(true) // Check year of birth
        {
            cout << endl << "Enter the scientist's year of birth: ";
            cin >> birthYear;


            if(cin.fail())
            {
                numericLimiter("Invalid input!");
            }
            else if(birthYear <= whatYearIsIt()) // Just in case we discover a programmer of the universe
            {
                break;
            }
            else
            {
                invalidInputPrompt();
                textColorRed();
                cout << "...or you are Marty McFly" << endl;
                textColorWhite();
            }
        }

        while(true) // Check when scientist died (if dead)
        {

            cout << endl << "Enter the scientist's year of death (type 0 if not applicable): ";
            cin >> deathYear;

            if(cin.fail())
            {
                numericLimiter("Invalid input!");
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
                invalidInputPrompt();
                textColorRed();
                cout << " - You can't die before you are born!" << endl;
                textColorWhite();
                cin.clear();
            }
        }

        // Check if input is correct
        clearScreen();
        smallLogoPrint();
        cout << "Name: " << name << endl << "Gender: " << gender << endl << "Born: " << birthYear << endl;

        if(deathYear != 0)
        {
            cout << "Died: " << deathYear << endl;
        }
        else
        {
            cout << endl;
        }

        numericLimiter();
        checkInput = userCheckInput(); // A function that checks if the input is valid

        if (checkInput == 0)
        {
            if(_service.addScientist(name, gender, birthYear, deathYear))
            {
                cout << endl << name << " successfully added to the list" << endl;

            }
            else
            {
                _service.updateScientist(name, gender, birthYear, deathYear);
                cout << endl << name << " successfully replaced in the list" << endl;
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
void ConsoleUI::removeScientist()                                   // Remove scientist from database
{
    /*
     * This functions gets variables from user and checks if the user wants
     * to remove 1 scientist or all and uses functions from service layer
     * to get access to dataccess layer to alter the database depending on
     * user input.
     */

    string command;

    clearScreen();
    smallLogoPrint();
    cout << "Select one of the following options: " << endl;
    cout << "(1)     -   Remove scientists by name " << endl;
    cout << "(2)     -   Remove *ALL* scientists" << endl;
    cout << endl << "Select: ";

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
        smallLogoPrint();
        textColorRed();
        cout << "Type in \"remove\" to remove *ALL* scientists, any other input to cancel" << endl;
        textColorWhite();
        getline(cin, userInputName);
        forceLowerCase(userInputName);

        if(userInputName == "remove")
        {
            _service.removeAllScientists();
            clearScreen();
            smallLogoPrint();
            userMenuPrint(1);
        }

    }
}
void ConsoleUI::searchScientist()                                   // Search the database for scientist
{
    /*
     * A search list is printed out and user can choose from a few search commands
     * like name, gender, age, birth, death. Error checks included, this function
     * calls functions from service layer to access dataaccess layer to search
     * the database.
     */

    string command;

    clearScreen();
    smallLogoPrint();
    cout << "Select a search option: " << endl;
    cout << "===================================" << endl;
    cout << "Name    -   Search by name" << endl;
    cout << "Gender  -   Search by gender" << endl;
    cout << "Birth   -   Search by year of birth" << endl;
    cout << "Death   -   Search by year of death" << endl;
    cout << "Age     -   Search by age" << endl;

    bool inputCheck;
    do
    {
        cout << endl << "Select: ";
        getline(cin, command);

        forceLowerCase(command);

        if(command == "name" || command == "gender" || command == "birth" || command == "death" || command == "age") // check if input is int and if it ranges from 1 to 10
        {
            inputCheck = false;
        }
        else
        {
            inputCheck = true;
            invalidInputPrompt();
        }
        cin.clear();

    }while(inputCheck);

    if(command == "name") // Find scientist by name
    {
        string userInputName;

        clearScreen();
        smallLogoPrint();
        cout << "Search by name: ";
        getline(cin, userInputName);

        vector<Scientist> scientist = _service.findScientist(1, userInputName);
        userMenuPrint(scientist);
        askReturnToMenu();
    }
    else if(command == "gender") // Find scientist by gender
    {
        string userInputGender;
        clearScreen();
        smallLogoPrint();

        cout << "Search by gender" << endl;
        cout << endl << "M - Male" << endl;
        cout << "F - Female" << endl;
        while(true)
        {
            cout << endl << "Gender: ";
            cin >> userInputGender;

            userInputGender = userInputGender[0];
            forceLowerCase(userInputGender);

            if(userInputGender[0] == 'm' || userInputGender[0] == 'f')
            {
                break;
            }
            else
            {
                invalidInputPrompt();
            }
            cin.clear();
        }


        if(userInputGender == "f" || userInputGender == "m")
        {
            vector<Scientist> scientist = _service.findScientist(2, userInputGender);
            userMenuPrint(scientist);
            askReturnToMenu();
        }
        else
        {
            invalidInputPrompt();
        }


    }
    else if(command == "age") // Find scientist by age
    {
        int inputCheck;

        clearScreen();
        smallLogoPrint();
        cout << "Search by:" << endl;
        cout << endl << "(1) - Age" << endl;
        cout << "(2) - Age range" << endl << endl;

        while(true)
        {
            cout << "Select: ";
            cin >> inputCheck;

            if(cin.fail())
            {
                numericLimiter("Invalid input!");
            }
            else if(inputCheck == 1 || inputCheck == 2)
            {
                break;
            }
            else
            {
                invalidInputPrompt();
            }
        }

        if(inputCheck == 1)
        {
            int userInputAge;
            clearScreen();
            cout << endl << "Search by age: ";

            while(true)
            {
                cin >> userInputAge;

                if(cin.fail())
                {
                    numericLimiter("Enter a valid age!");
                }
                else
                {
                    break;
                }
            }

            vector<Scientist> scientist = _service.findScientist(7, to_string(userInputAge));
            userMenuPrint(scientist);
            askReturnToMenu();
        }
        else if(inputCheck == 2)
        {
            int userInputAgeFirst;
            int userInputAgeLast;
            while(true)
            {
                clearScreen();
                cout << "From age: ";
                cin >> userInputAgeFirst;

                if(cin.fail())
                {
                    numericLimiter("Enter a valid age!");
                }
                else
                {
                    break;
                }
            }
            while(true)
            {
                clearScreen();
                cout << "To age: ";
                cin >> userInputAgeLast;

                if(cin.fail())
                {
                    numericLimiter("Enter a valid age!");
                }
                else
                {
                    break;
                }
            }

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
            smallLogoPrint();
            invalidInputPrompt();
        }
    }
    else if(command == "birth")
    {
        int inputCheck;

        clearScreen();
        smallLogoPrint();
        cout << "Search by:" << endl;
        cout << endl << "(1) - Year of birth" << endl;
        cout << "(2) - Range of year of birth" << endl << endl;
        while(true)
        {
            cout << "Select: ";
            cin >> inputCheck;

            if(cin.fail())
            {
                numericLimiter("Invalid input!");
            }
            else if(inputCheck == 1 || inputCheck == 2)
            {
                break;
            }
            else
            {
                invalidInputPrompt();
            }
        }

        if(inputCheck == 1)
        {
            int userInputBirth;
            clearScreen();
            cout << "Search by year of birth: ";
            while(true)
            {
                cin >> userInputBirth;

                if(cin.fail())
                {
                    numericLimiter("Enter a valid year!");
                }
                else
                {
                    break;
                }
            }
            vector<Scientist> scientist = _service.findScientist(3, to_string(userInputBirth));
            cout << to_string(userInputBirth);
            userMenuPrint(scientist);
            askReturnToMenu();
        }
        else if(inputCheck == 2)
        {
            int userInputBirthFirst;
            int userInputBirthLast;

            while(true)
            {
                clearScreen();
                cout << "Search from year of birth: ";
                cin >> userInputBirthFirst;
                cout << endl;

                if(cin.fail())
                {
                    numericLimiter("Enter a valid year!");
                }
                else
                {
                    break;
                }
            }

            while(true)
            {
                cout << "To year of birth: ";
                cin >> userInputBirthLast;
                cout << endl;

                if(cin.fail())
                {
                    numericLimiter("Enter a valid year!");
                }
                else
                {
                    break;
                }
            }

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
            invalidInputPrompt();
        }
    }
    else if(command == "death")
    {
        int inputCheck;

        clearScreen();
        smallLogoPrint();
        cout << "Search by:" << endl;
        cout << endl << "(1) - Year scientist died" << endl;
        cout << "(2) - Year range of when scientist died" << endl << endl;

        while(true)
        {
            cout << "Select: ";
            cin >> inputCheck;

            if(cin.fail())
            {
                numericLimiter("Invalid input!");
            }
            else if(inputCheck == 1 || inputCheck == 2)
            {
                break;
            }
            else
            {
                invalidInputPrompt();
                cout << endl << endl;
            }
        }

        if(inputCheck == 1)
        {
            int userInputDeath;

            while(true)
            {
                clearScreen();
                cout << "Year scientist died (0 for still alive): ";
                cin >> userInputDeath;

                if(cin.fail())
                {
                    numericLimiter("Enter a valid year!");
                }
                else
                {
                    break;
                }
            }

            vector<Scientist> scientist = _service.findScientist(5, to_string(userInputDeath));
            userMenuPrint(scientist);
            askReturnToMenu();
        }
        else if(inputCheck == 2)
        {
            int userInputDeathFirst;
            int userInputDeathLast;

            while(true)
            {
                clearScreen();
                cout << "From year: ";
                cin >> userInputDeathFirst;

                if(cin.fail())
                {
                    numericLimiter("Enter a valid year!");
                }
                else
                {
                    break;
                }
            }
            while(true)
            {
                clearScreen();
                cout << "To year(0 for still alive): ";
                cin >> userInputDeathLast;

                if(cin.fail())
                {
                    numericLimiter("Enter a valid year!");
                }
                else
                {
                    break;
                }
            }
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
            smallLogoPrint();
            invalidInputPrompt();
        }
    }
    cout << endl;
}
void ConsoleUI::sortScientist()                                     // Get sorted list of scientist from database
{
    /*
     * A sorting function, can call function from service.cpp scientistSort().
     * The function will sort depending on int parameter "1 = name(A-Z), 2 = name(Z-A),
     * 3 = gender(f-m), 4 = gender(m-f), 5 = birth year(0-9), 6 = birth year(9-0)
     * 7 = death year(0-9), 8 = death year(9-0), 9 = age(0-9), 10 = age(9-0)".
     */


    vector<Scientist> sortedScientists;
    int userInput;
    bool inputNotValid = false;


    do
    {
        clearScreen();
        smallLogoPrint();

        cout << "Select a sort option: " << endl;
        cout << "===================================" << endl;
        cout << "(1)     -   Sort by name (A-Z)" << endl;
        cout << "(2)     -   Sort by name (Z-A)" << endl;
        cout << "(3)     -   Sort by gender (F-M)" << endl;
        cout << "(4)     -   Sort by gender (M-F)" << endl;
        cout << "(5)     -   Sort by year of birth (0-9)" << endl;
        cout << "(6)     -   Sort by year of birth (9-0)" << endl;
        cout << "(7)     -   Sort by year of death (0-9)" << endl;
        cout << "(8)     -   Sort by year of death (9-0)" << endl;
        cout << "(9)     -   Sort by age (0-9)" << endl;
        cout << "(10)    -   Sort by age (9-0)" << endl;

        if(inputNotValid)
        {
            invalidInputPrompt();

        }

        cout << endl << "Select: ";
        cin >> userInput;


        if(cin.fail())
        {
            numericLimiter("Invalid input!");
        }


        inputNotValid = true;


    }while(userInput < 1 || userInput > 10);

    cin.clear();

    clearScreen();

    sortedScientists = _service.scientistSort(userInput);

    userMenuPrint(sortedScientists);

    askReturnToMenu();
}


// ---------------------------------- COMPUTER  FUNCTIONS ---------------------------------- //
void ConsoleUI::addComputer()                                       // Add computer to database
{
    /*
     * This function gets all variables from user and makes error checks, if everything
     * checks out fine this function will call on server layer functions to then add those
     * variables to the database.
     */
    string name, type;
    int yearBuilt = 0, checkInput;
    bool built = false;

    while(true)
    {
        clearScreen();
        smallLogoPrint();

        while(true)
        {
            cout << "Enter the computer's name: ";
            cin.ignore(-1);
            getline(cin, name);

            if(name == "")
            {
                cout << "Computers have names too!" << endl;
            }
            else if(_service.findComputer(0, name).size() > 0)
            {
                int userInput;
                cout << "This computer is already in the database" << endl;
                cout << endl << "(1) To enter name again" << endl;
                cout << "(2) To replace computer" << endl;
                cout << endl << "Select: ";
                cin >> userInput;

                numericLimiter();


                if(userInput == 1)
                {
                    continue;
                }
                else if(userInput == 2)
                {
                    break;
                }
                else
                {
                    invalidInputPrompt();
                }

            }
            else
            {
                break;
            }
        }


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
                numericLimiter("Invalid input!");
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
                    invalidInputPrompt();
                }
            }
        }

        while(true) // Check if it was built
        {
            char builtInput;
            cout << endl << "Was the computer ever built? (y/n): ";
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
                invalidInputPrompt();
        }

        while(built == true) // Check when when it was built (if it was)
        {
            cout << endl << "What year was the computer built?: ";
            cin >> yearBuilt;

            if(cin.fail())
            {
                numericLimiter("Invalid input!");
            }
            else if(yearBuilt > whatYearIsIt())
            {
                cout << endl << "Predicting the future, are we? Try again" << endl;
                cin.clear();
            }
            else
                break;
        }

        // Check if input is correct
        clearScreen();
        smallLogoPrint();
        cout << "Name: " << name << endl << "Type: " << type << endl;

        if(built == true)
        {
            cout << "Built: " << yearBuilt << endl;
        }
        else
        {
            cout << "Was never built" << endl;
        }

        numericLimiter();
        checkInput = userCheckInput(); // A function that checks if the input is valid

        if (checkInput == 0)
        {
            if(_service.addComputer(name, yearBuilt, type, built))
            {
                cout << endl << name << " successfully added to the list" << endl;

            }
            else
            {
                cout << endl << name << " successfully replaced in the list" << endl;
                _service.updateComputer(name, yearBuilt, type, built);
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
void ConsoleUI::removeComputer()                                    // Remove computer from database
{
    /*
     * This functions gets variables from user and checks if the user wants
     * to remove 1 computer or all and uses functions from service layer
     * to get access to dataccess layer to alter the database depending on
     * user input.
     */
    string command;

    clearScreen();
    smallLogoPrint();
    cout << "Select one of the following options: " << endl;
    cout << "(1)     -   Remove computer by name " << endl;
    cout << "(2)     -   Remove *ALL* computers" << endl;
    cout << endl << "Select: ";

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
        smallLogoPrint();
        textColorRed();
        cout << "Type in \"remove\" to remove *ALL* computers, any other input to cancel" << endl;
        textColorWhite();
        getline(cin, userInputName);
        forceLowerCase(userInputName);

        if(userInputName == "remove")
        {
            _service.removeAllComputers(); // TODO::Needs a functin in service layer
            clearScreen();
            smallLogoPrint();
            userMenuPrint(2);
        }

    }
}
void ConsoleUI::searchComputer()                                    // Search the database for computer
{
    /*
     * A search list is printed out and user can choose from a few search commands
     * like name, year built, type, and if built. Error checks included, this function
     * calls functions from service layer to access dataaccess layer to search
     * the database.
     */
    string command;

    clearScreen();
    smallLogoPrint();
    cout << "Select a search option: " << endl;
    cout << "===================================" << endl;
    cout << "Name    -   Search by name" << endl;
    cout << "Year    -   Search by year built" << endl;
    cout << "Type    -   Search by type" << endl;
    cout << "Built   -   Search by if built or not" << endl;


    while(true)
    {
        cout << endl << "Select: ";
        getline(cin, command);

        forceLowerCase(command);

        if(command == "name" || command == "year" || command == "type" || command == "built") // check if input is int and if it ranges from 1 to 10
        {
            break;
        }
        else
        {
            invalidInputPrompt();
        }
        cin.clear();
    }



    if(command == "name") // Find computer by name
    {
        string userInputName;

        clearScreen();
        smallLogoPrint();
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
        smallLogoPrint();
        cout << "Search by year:" << endl;
        cout << endl << "(1) - Search for a computer by year it was made" << endl;
        cout << "(2) - Search for a computer by range of year it was made " << endl;

        while(true)
        {
            cout << "Select: ";
            cin >> inputCheck;

            if(cin.fail())
            {
                numericLimiter("Invalid input!");
            }
            else if(inputCheck == 1 || inputCheck == 2)
            {
                break;
            }
            else
            {
                invalidInputPrompt();
            }
        }

        switch(inputCheck)
        {
        case 1: cout << "Search by year built" << endl;

            while(true)
            {
                cout << endl << "Year: ";
                cin >> userInputYear;
                if(cin.fail())
                {
                    numericLimiter("Invalid input!");
                }
                else
                {
                    break;
                }
            }

            computer = _service.findComputer(2, to_string(userInputYear));
            userMenuPrint(computer);
            askReturnToMenu();
            break;

        case 2: cout << "Search by range of year built" << endl;

            while(true)
            {
                cout << endl << "From year: ";
                cin >> userInputYearFirst;

                if(cin.fail())
                {
                    numericLimiter("Invalid input!");
                }
                else
                {
                    break;
                }
            }
            while(true)
            {
                cout << endl << "To year: ";
                cin >> userInputYearLast;

                if(cin.fail())
                {
                    numericLimiter("Invalid input!");
                }
                else
                {
                    break;
                }
            }
            computer = _service.findComputer(3, to_string(userInputYearFirst), to_string(userInputYearLast));
            userMenuPrint(computer);
            askReturnToMenu();
            break;
        }
    }
    else if(command == "type") // Find computer by type
    {
        int inputCheck;
        vector<Computer> computer;

        clearScreen();
        smallLogoPrint();
        cout << "Search by type:" << endl;
        cout << endl << "(1) - Electromechanical" << endl;
        cout << "(2) - Electronic" << endl;
        cout << "(3) - Mechanical" << endl;
        cout << "(4) - Transistor" << endl;

        while(true)
        {
            cout << "Select: ";
            cin >> inputCheck;

            if(cin.fail())
            {
                numericLimiter("Invalid input!");
            }
            else if(inputCheck == 1 || inputCheck == 2 || inputCheck == 3 || inputCheck == 4)
            {
                break;
            }
            else
            {
                invalidInputPrompt();
            }
        }

        switch(inputCheck)
        {
        case 1: computer = _service.findComputer(4,"Electromechanical");
            userMenuPrint(computer);
            askReturnToMenu();
            break;
        case 2: computer = _service.findComputer(4,"Electronic");
            userMenuPrint(computer);
            askReturnToMenu();
            break;
        case 3: computer = _service.findComputer(4,"Mechanical");
            userMenuPrint(computer);
            askReturnToMenu();
            break;
        case 4: computer = _service.findComputer(4,"Transistor");
            userMenuPrint(computer);
            askReturnToMenu();
            break;
        }
    }
    else if(command == "built") // Find computer if built or not
    {
        int inputCheck;
        vector<Computer> computers;

        clearScreen();
        smallLogoPrint();
        cout << "Search by:" << endl;
        cout << endl << "(1) - Was built" << endl;
        cout << "(2) - Was not built" << endl << endl;

        while(true)
        {
            cout << "Select: ";
            cin >> inputCheck;

            if(cin.fail())
            {
                numericLimiter("Invalid input!");
            }
            else if(inputCheck == 1 || inputCheck == 2)
            {
                break;
            }
            else
            {
                invalidInputPrompt();
            }
        }


        switch(inputCheck)
        {
        case 1: computers = _service.findComputer(5,"1");
            userMenuPrint(computers);
            askReturnToMenu();
            break;
        case 2: computers = _service.findComputer(5,"0");
            userMenuPrint(computers);
            askReturnToMenu();
            break;
        }
    }
    cout << endl;
}
void ConsoleUI::sortComputer()                                      // Get sorted list of computers from database
{
    /*
         * A sorting function, can call function from service.cpp computerSort().
         * The function will sort depending on int parameter "Sort by sortType:
         *  1 = name(A-Z), 2 = name(Z-A), 3 = year(0-9), 4 = year(9-0) 5 = type(A-Z),
         *  6 = type(Z-A), 7 = was built(N-Y),  8 = year made(Y-N), 9 = years since built(0-9)
         *  10 = years sine built(9-0)".
         */

    vector<Computer> sortedComputers;
    int userInput;
    bool inputNotValid = false;

    clearScreen();
    smallLogoPrint();

    do
    {
        clearScreen();
        smallLogoPrint();

        cout << "Select a sort option: " << endl;
        cout << "===================================" << endl;
        cout << "(1)     -   Sort by name (A-Z)" << endl;
        cout << "(2)     -   Sort by name (Z-A)" << endl;
        cout << "(3)     -   Sort by year (0-9)" << endl;
        cout << "(4)     -   Sort by year (9-0)" << endl;
        cout << "(5)     -   Sort by type (A-Z)" << endl;
        cout << "(6)     -   Sort by type (Z-A)" << endl;
        cout << "(7)     -   Sort by if built (N-Y)" << endl;
        cout << "(8)     -   Sort by if built (Y-N)" << endl;
        cout << "(9)     -   Sort by years since built (0-9))" << endl;
        cout << "(10)    -   Sort by years since built (9-0))" << endl;


        if(inputNotValid)
        {
            invalidInputPrompt();

        }

        cout << endl << "Select: ";
        cin >> userInput;

        if(cin.fail())
        {
            numericLimiter("Invalid input!");
        }


        inputNotValid = true;


    }while(userInput < 1 || userInput > 10);


    cin.clear();

    clearScreen();

    sortedComputers = _service.computerSort(userInput);

    userMenuPrint(sortedComputers);

    askReturnToMenu();

}


// ---------------------------------- RELATION  FUNCTIONS ---------------------------------- //
void ConsoleUI::addRelation()                                       // Add relation to database
{
    /*
     * This function gets all variables from user and makes error checks, if everything
     * checks out fine this function will call on server layer functions to then add those
     * variables to the database.
     */
    string name, computer;
    int checkInput;

    while(true)
    {
        smallLogoPrint();

        userMenuPrint(1);
        while(true)
        {


            cout << endl << "Enter the scientist's name: ";

            cin.ignore(-1);
            getline(cin, name);

            if(name == "")
            {
                userMenuPrint(1);
                textColorRed();
                cout << endl << "\"Every rose has it's thorne, just like every scientist has a name\" -Poison"<< endl;
                textColorWhite();
            }
            else if(_service.doesScientistExist(name) == false)
            {
                userMenuPrint(1);
                cout << endl << "This scientist does not exist in the database, try again!" << endl;

            }
            else
            {
                break;
            }
        }
        userMenuPrint(2);
        while(true)
        {
            cout << endl << "Enter the computer's name: ";

            cin.ignore(-1);
            getline(cin, computer);

            if(computer == "")
            {
                userMenuPrint(2);
                textColorRed();
                cout << endl << "\"Every rose has it's thorne, just like every computer has a name\" -Poison"<< endl;
                textColorWhite();
            }
            else if(_service.doesComputerExist(computer) == false)
            {
                userMenuPrint(2);
                cout << "This computer does not exist in the database, try again!" << endl;
            }
            else
            {
                break;
            }
        }

        // Check if input is correct
        clearScreen();
        smallLogoPrint();
        cout << "Name: " << name << endl << "Computer: " << computer << endl;

        checkInput = userCheckInput(); // A function that checks if the input is valid

        if (checkInput == 0)
        {
            if(_service.doesRelationExist(name, computer) == false)
            {
                _service.addRelation(name, computer);
                cout << "Relation between " << name << " and " << computer << " successfully added to the list" << endl;
            }
            else
            {
                int userInput;
                cout << endl << "This relation is already in the database" << endl;
                cout << endl << "(1) To make another relation" << endl;
                cout << "(2) To go back to menu" << endl;
                cout << endl << "Select: ";
                cin >> userInput;

                numericLimiter();


                if(userInput == 1)
                {
                    continue;
                }
                else if(userInput == 2)
                {
                    break;
                }
                else
                {
                    cout << "Invalid input!";
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
void ConsoleUI::removeRelation()                                    // Remove relation from database
{
    /*
     * This functions gets variables from user and checks if the user wants
     * to remove 1 scientist or all and uses functions from service layer
     * to get access to dataccess layer to alter the database depending on
     * user input.
     */
    string command;

    clearScreen();
    smallLogoPrint();
    cout << "Select one of the following options: " << endl;
    cout << "(1)     -   Remove Relation by Scientist Name " << endl;
    cout << "(2)     -   Remove Relation by Computer Name" << endl;
    cout << "(3)     -   Remove Relation by Scientist and computer name" << endl;
    cout << "(4)     -   Remove *ALL* relations" << endl << endl;
    cout << endl << "Select: ";

    getline(cin, command);
    cout << endl;

    if(command[0] == '1')
    {
        vector<Relation> relation = _service.getRelations();
        userMenuPrint(relation);

        string userInputName, confirm;
        vector<Relation> relationsToRemove;

        cout << endl << "Remove relations with Scientist names containing: ";

        getline(cin, userInputName);
        relationsToRemove = _service.findRelation(1, userInputName);

        if(relationsToRemove.size() > 0)
        {
            userMenuPrint(relationsToRemove);
            cout << endl << "Are you sure you want to remove these relations from the list?" << endl;
            cout << "Y     -   Yes, remove them " << endl;
            cout << "N     -   No, do not remove them" << endl << endl;
            cout << endl << "Select: ";

            getline(cin, confirm);

            if (confirm[0] == 'y' || confirm[0] == 'Y')
            {
                _service.removeRelation(1, userInputName);
                cout << endl << "Relations with Scientist names containing '" << userInputName << "' have been removed from the list." << endl;
                askReturnToMenu();
            }
            else
            {
                cout << endl << "No relations were removed" << endl;
                askReturnToMenu();
            }

        }
        else
        {
            cout << endl << "There are no relations with names containing '" << userInputName << "'" << endl;
            askReturnToMenu();
        }
    }
    if(command[0] == '2') // Remove Relation/s by input.
    {
        vector<Relation> relation = _service.getRelations();
        userMenuPrint(relation);

        string userInputName, confirm;
        vector<Relation> relationsToRemove;


        cout << endl << "Remove relations with Computer names containing: ";


        getline(cin, userInputName);
        relationsToRemove = _service.findRelation(3, userInputName);

        if(relationsToRemove.size() > 0)
        {
            userMenuPrint(relationsToRemove);
            cout << endl << "Are you sure you want to remove these computers from the list?" << endl;
            cout << "Y     -   Yes, remove them " << endl;
            cout << "N     -   No, do not remove them" << endl << endl;
            cout << endl << "Select: ";

            getline(cin, confirm);

            if (confirm[0] == 'y' || confirm[0] == 'Y')
            {
                _service.removeRelation(2, userInputName); // TODO::Needs a functin in service layer
                cout << endl << "Relations with Computer names containing '" << userInputName << "' have been removed from the list." << endl;
                askReturnToMenu();
            }
            else
            {
                cout << endl << "No relations were removed" << endl;
                askReturnToMenu();
            }

        }
        else
        {
            cout << endl << "There are no relations with names containing '" << userInputName << "'" << endl;
            askReturnToMenu();
        }
    }
    if(command[0] == '3') // Remove Relation/s by input.
    {
        vector<Relation> relation = _service.getRelations();
        userMenuPrint(relation);

        string userInputScientist, userInputComputer, confirm;
        vector<Relation> relationsToRemove;

        cout << endl << "Remove relations where scientist name is: ";
        getline(cin, userInputScientist);

        cout << endl << "Remove relations where computer name is: ";
        getline(cin, userInputComputer);

        relationsToRemove = _service.findRelation(6, userInputScientist, userInputComputer);

        if(relationsToRemove.size() > 0)
        {
            userMenuPrint(relationsToRemove);
            cout << endl << "Are you sure you want to remove this relation between scientist and computer from the list?" << endl;
            cout << "Y     -   Yes, remove it " << endl;
            cout << "N     -   No, do not remove it" << endl << endl;
            cout << endl << "Select: ";

            getline(cin, confirm);

            if (confirm[0] == 'y' || confirm[0] == 'Y')
            {
                _service.removeRelation(userInputScientist, userInputComputer);
                cout << endl << "Relation between '" << userInputScientist << "' and '" << userInputComputer << "' has been removed from the list." << endl;
                askReturnToMenu();
            }
            else
            {
                cout << endl << "No relations were removed" << endl;
                askReturnToMenu();
            }

        }
        else
        {
            cout << endl << "There is no relation between '" << userInputScientist << "' and '" << userInputComputer << "'" << endl;
            askReturnToMenu();
        }
    }
    else if(command[0] == '4') // Remove all relations
    {
        string userInputName;

        clearScreen();
        smallLogoPrint();
        textColorRed();
        cout << "Type in \"remove\" to remove *ALL* relations, any other input to cancel" << endl;
        textColorWhite();
        getline(cin, userInputName);
        forceLowerCase(userInputName);

        if(userInputName == "remove")
        {
            _service.removeAllRelations(); // TODO::Needs a functin in service layer
            clearScreen();
            smallLogoPrint();
            cout << "All relations have been removed successfully!" << endl;
            askReturnToMenu();
        }

    }
}
void ConsoleUI::searchRelation()                                    // Search the database for relations
{
    /*
     * A search list is printed out and user can choose from a few search commands
     * like name and computer. Error checks included, this function
     * calls functions from service layer to access dataaccess layer to search
     * the database.
     */
    string command;

    clearScreen();
    smallLogoPrint();
    cout << "Select a search option: " << endl;
    cout << "===================================" << endl;
    cout << "(1)     -   Search by Scientist Name" << endl;
    cout << "(2)     -   Search by Computer Name" << endl;
    cout << "(3)     -   Search by Year Built" << endl;


    while(true)
    {
        cout << endl << "Select: ";
        getline(cin, command);

        if(command[0] == '1' || command[0] == '2' || command[0] == '3')
        {
            break;
        }
        else
        {
            invalidInputPrompt();
        }
    }

    if(command[0] == '1') // Find relation by Scientist
    {
        string userInputName;

        clearScreen();
        smallLogoPrint();
        cout << "Search by name: ";
        getline(cin, userInputName);

        vector<Relation> relation = _service.findRelation(1, userInputName);
        userMenuPrint(relation);
        askReturnToMenu();
    }
    if(command[0] == '2') // Find relation by Computer
    {
        string userInputName;

        clearScreen();
        smallLogoPrint();
        cout << "Search by name: ";
        getline(cin, userInputName);

        vector<Relation> relation = _service.findRelation(3, userInputName);
        userMenuPrint(relation);
        askReturnToMenu();
    }
    else if(command[0] == '3') // Find relation by year
    {
        int userInputYear;
        int userInputYearFirst;
        int userInputYearLast;
        int inputCheck;
        vector<Relation> relation;

        clearScreen();
        smallLogoPrint();
        cout << "Search by year:" << endl;
        cout << endl << "(1) - Search for a relation by year it was made" << endl;
        cout << "(2) - Search for a relation by range of year it was made " << endl;


        while(true)
        {
            cout << endl << "Select: ";
            cin >> inputCheck;

            if(cin.fail())
            {
                numericLimiter("Invalid input");
            }
            else if(inputCheck == 1 || inputCheck == 2)
            {
                break;
            }
            else
            {
                invalidInputPrompt();
                cin.clear();
            }
        }


        switch(inputCheck)
        {
        case 1: cout << "Search by year built" << endl;


            while(true)
            {
                cout << endl << "Year: ";
                cin >> userInputYear;

                if(cin.fail())
                {
                    numericLimiter("Invalid input");
                }
                else
                {
                    break;
                }
            }
            relation = _service.findRelation(4, to_string(userInputYear));
            userMenuPrint(relation);
            askReturnToMenu();
            break;

        case 2: cout << "Search by range of year built" << endl;

            while(true)
            {
                cout << endl << "Starting year: ";
                cin >> userInputYearFirst;

                if(cin.fail())
                {
                    numericLimiter("Invalid input");
                }
                else
                {
                    break;
                }
            }
            while(true)
            {
                cout << endl << "Ending year: ";
                cin >> userInputYearLast;

                if(cin.fail())
                {
                    numericLimiter("Invalid input");
                }
                else
                {
                    break;
                }
            }
            relation = _service.findRelation(5, to_string(userInputYearFirst), to_string(userInputYearLast));
            userMenuPrint(relation);
            askReturnToMenu();
            break;
        default: invalidInputPrompt();
        }
        cout << endl;
    }
}
void ConsoleUI::sortRelation()                                      // Get sorted list of relations
{
    /*
     * A sorting function, can call function from service.cpp computerSort().
     * The function will sort depending on int parameter "Sort by sortType:
     *  1 = name(A-Z), 2 = name(Z-A), 3 = year(0-9), 4 = year(9-0) 5 = type(A-Z),
     *  6 = type(Z-A), 7 = was built(N-Y),  8 = year made(Y-N)".
     */

    vector<Relation> sortedRelations;
    int userInput;
    bool inputNotValid = false;

    clearScreen();
    smallLogoPrint();



    do
    {
        clearScreen();
        smallLogoPrint();

        cout << "Select a sort option: " << endl;
        cout << "===================================" << endl;
        cout << "(1)     -   Sort by Scientist Name (A-Z)" << endl;
        cout << "(2)     -   Sort by Scientist Name (Z-A)" << endl;
        cout << "(3)     -   Sort by Computer Name (A-Z)" << endl;
        cout << "(4)     -   Sort by Computer Name (Z-A)" << endl;
        cout << "(5)     -   Sort by Year Built (0-9)" << endl;
        cout << "(6)     -   Sort by Year Built (9-0)" << endl;

        if(inputNotValid)
        {
            invalidInputPrompt();

        }

        cout << endl << "Select: ";
        cin >> userInput;

        if(cin.fail())
        {
            numericLimiter("Invalid input!");
        }


        inputNotValid = true;


    }while(userInput < 1 || userInput > 6);


    cin.clear();

    clearScreen();

    sortedRelations = _service.relationSort(userInput);

    userMenuPrint(sortedRelations);

    askReturnToMenu();

}

// ---------------------------------- OTHER     FUNCTIONS ---------------------------------- //
void ConsoleUI::askReturnToMenu() const                             // Asks if user wants to move back to the menu
{
    cout << endl;
    cout << "To return to the menu press 'm'" << endl;
    cout << endl << "Select: ";

    string userInput = " ";
    while (userInput[0] != 'm' && userInput[0] != 'M')
    {
        getline(cin, userInput);
    }
}
int  ConsoleUI::userCheckInput()                                    // Checks input from userMenuAdd
{
    /*
     * Check if all data is correct and return a int depending on what user selected.
     * (0) yes, (1) no, (2) cancel and if nothing selected or invalid input the loop will
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
            invalidInputPrompt();
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
void ConsoleUI::clearScreen()                                 // Clears console screen
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
void ConsoleUI::smallLogoPrint()                                    // Prints a small logo to screen
{
    textColorRed();

    int w = 65;
    cout << setw(w-1) << "  _____   ___    ______ ____" << endl;
    cout << setw(w) << " / ___/  /   |  / ____// __ \\" << endl;
    cout << setw(w) << " \\__  \\ / /| | / /    / /_/ /"  << endl;
    cout << setw(w) << " ___/ // ___ |/ /___ / _, _/ " << endl;
    cout << setw(w) << "/____//_/  |_|\\____//_/ |_|  " << endl;

    textColorGray();
    cout << setw(w+4) << "Scientist and computer realtions." << endl;
    cout << setw(w-18) << "Version 1.0" << endl << endl << endl << endl;

    textColorWhite();
}
void ConsoleUI::largeLogoPrint()                                    // Prints a large logo to screen
{
    if(true)
    {
        textColorRed();

        cout << "            _____                    _____                    _____                    _____          " << endl;
        cout << "           /\\    \\                  /\\    \\                  /\\    \\                  /\\    \\          " << endl;
        cout << "          /::\\    \\                /::\\    \\                /::\\    \\                /::\\    \\         " << endl;
        cout << "         /::::\\    \\              /::::\\    \\              /::::\\    \\              /::::\\    \\        " << endl;
        cout << "        /::::::\\    \\            /::::::\\    \\            /::::::\\    \\            /::::::\\    \\       " << endl;
        cout << "       /:::/\\:::\\    \\          /:::/\\:::\\    \\          /:::/\\:::\\    \\          /:::/\\:::\\    \\      " << endl;
        cout << "      /:::/__\\:::\\    \\        /:::/__\\:::\\    \\        /:::/  \\:::\\    \\        /:::/__\\:::\\    \\     " << endl;
        cout << "      \\:::\\   \\:::\\    \\      /::::\\   \\:::\\    \\      /:::/    \\:::\\    \\      /::::\\   \\:::\\    \\    " << endl;
        cout << "    ___\\:::\\   \\:::\\    \\    /::::::\\   \\:::\\    \\    /:::/    / \\:::\\    \\    /::::::\\   \\:::\\    \\   " << endl;
        cout << "   /\\   \\:::\\   \\:::\\    \\  /:::/\\:::\\   \\:::\\    \\  /:::/    /   \\:::\\    \\  /:::/\\:::\\   \\:::\\____\\  " << endl;
        cout << "  /::\\   \\:::\\   \\:::\\____\\/:::/  \\:::\\   \\:::\\____\\/:::/____/     \\:::\\____\\/:::/  \\:::\\   \\:::|    |" << endl;
        cout << "  \\:::\\   \\:::\\   \\::/    /\\::/    \\:::\\  /:::/    /\\:::\\    \\      \\::/    /\\::/   |::::\\  /:::|____|" << endl;
        cout << "   \\:::\\   \\:::\\   \\/____/  \\/____/ \\:::\\/:::/    /  \\:::\\    \\      \\/____/  \\/____|:::::\\/:::/    /  " << endl;
        cout << "    \\:::\\   \\:::\\    \\               \\::::::/    /    \\:::\\    \\                    |:::::::::/    /   " << endl;
        cout << "     \\:::\\   \\:::\\____\\               \\::::/    /      \\:::\\    \\                   |::|\\::::/    /    " << endl;
        cout << "      \\:::\\  /:::/    /               /:::/    /        \\:::\\    \\                  |::| \\::/____/     " << endl;
        cout << "       \\:::\\/:::/    /               /:::/    /          \\:::\\    \\                 |::|  ~|           " << endl;
        cout << "        \\::::::/    /";
        textColorGray();
        cout <<"  Scientist";
        textColorRed();
        cout << "    /:::/    /            \\:::\\    \\                |::|   |           " << endl;
        cout << "         \\::::/    /  ";
        textColorGray();
        cout << "And";
        textColorRed();
        cout << "          /:::/    /              \\:::\\____\\               \\::|   |           " << endl;
        cout << "          \\::/    /  ";
        textColorGray();
        cout << "Computer";
        textColorRed();
        cout << "      \\::/    /                \\::/    /                \\:|   |           " << endl;
        cout << "           \\/____/  ";
        textColorGray();
        cout << "Relations";
        textColorRed();
        cout << "       \\/____/  ";
        textColorGray();
        cout << "Version 1.0";

        textColorRed();
        cout << "     \\/____/                  \\|___|           " << endl;

        textColorWhite();

    }
}
void ConsoleUI::numericLimiter()                                    // Limits input to just numbers
{
    /*
     * Limits input of numbers to just 1, used for selections like (1), (2) etc..
     * this way you can only input 1 number, this will help with not getting errors.
     */
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void ConsoleUI::numericLimiter(string comment)                      // Limits input to just numbers, parameter for print out msg
{
    /*
     * Limits input of numbers to just 1, used for selections like (1), (2) etc..
     * this way you can only input 1 number, this will help with not getting errors.
     * The parameter is used to print out a msg before the limiter.
     */
    cout << comment << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void ConsoleUI::invalidInputPrompt()                                // Promt for error msg, "Invalid Input!"
{
    /*
     * Promt for error msg, "Invalid Input!", used in many places in the code
     * so best to keep as function even though it is small.
     */
    textColorRed();
    cout << endl << "Invalid input!" << endl;
    textColorWhite();
}


// ---------------------------------- OS         FUNCTIONS ---------------------------------- //
#ifdef _WIN32                                                       // Windows user will run this
void ConsoleUI::textColorWhite()                                    // Function for white text
{
    HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hstdout, 0x0F );
}
void ConsoleUI::textColorRed()                                      // Function for red text
{
    HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hstdout, 0x0C );
}
void ConsoleUI::textColorGray()                                     // Function for gray text
{
    HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hstdout, 0x08 );
}
#else                                                               // If not a windows user, run these functions which dont change the color.
void ConsoleUI::textColorWhite()
{
    // Nothing happening! Absolutely nothing to see here!
}
void ConsoleUI::textColorRed()
{
    // Nothing happening! Absolutely nothing to see here!
}

void ConsoleUI::textColorGray()
{
    // Nothing happening! Absolutely nothing to see here!
}
#endif