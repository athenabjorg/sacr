#include "consoleui.h"

using namespace std;


ConsoleUI::ConsoleUI()                                              // Constructor function
{
     /* Gets information from file so it's used from the beginning.
     */

    _service.getScientists(); // Uploads the list of scientists from file.
}

// ---------------------------------- USER MENU FUNCTIONS ---------------------------------- //
void ConsoleUI::userMenuRun()                                       // DIsplays the main menu
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

                cout << "Invalid input" << endl;
            }
        }

        if(command == "quit")
        {
            clearScreen();
            smallLogoPrint();
            textColorLogo();
            cout << setw(85) << "SACR version 2.0 will be released on midnight, December 16th 2016" << endl << endl;
            cout << setw(46) << "24/7 HOTLINE: +354 7707010" << endl << endl;
            textColorMain();
            break;
        }
        clearScreen();
    }
}
void ConsoleUI::userMenuSwitch(int loadType)
{
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
    cout << line << endl
         << "1 - Scientist" << endl
         << "2 - Computer" << endl
         << "3 - Relation" << endl << endl
         << "Select: ";
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
void ConsoleUI::userMenuPrint(int loadType)  //remove þetta, nota bara vecor prentin?                                   // Prints whole list
{
    /*
     * Prints out a partial list of scientist, depending on how
     * it was sent forward by the previous function.
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
void ConsoleUI::userMenuPrint(const vector<Relation> &relation)    // Print list provided
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
void ConsoleUI::addScientist()
{
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
                cout << "\"Every rose has it's thorne, just like every scientist has a name\" -Poison"<< endl;
            }
            else if(_service.findScientist(0, name).size() > 0)
            {
                int userInput;
                cout << "This scientists is allready in the database" << endl;
                cout << "(1) To enter name again" << endl;
                cout << "(2) To replace scientist" << endl;
                cout << "Select: ";
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
                    cout << "Wrong input!";
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
                cout << "Invalid input" << endl;
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
                    cout << "Invalid input...or you are Marty McFly" << endl;
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
                    cout << "Invalid input - You can't die before you are born!" << endl;
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
void ConsoleUI::removeScientist()
{
    /*
     * A function to remove a scientist.
     */

    string command;

    clearScreen();
    smallLogoPrint();
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
        smallLogoPrint();

        cout << "Type in \"remove\" to remove *ALL* scientists, any other input to cancel" << endl;

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
void ConsoleUI::searchScientist()
{
    /*
     * A search list is printed out and user can choose from a few search commands
     * like name, gender, age, birth, death. Error checks included
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
    cout << "Age     -   Search by age" << endl << endl;

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
                cout << "Invalid input!" << endl;
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
                cout << "Invalid input!" << endl;
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
            cout << "Wrong Input" << endl;
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
                cout << "Invalid input!" << endl;
            }
        }

        if(inputCheck == 1)
        {
            int userInputAge;
            cout << endl << "Search by age: " << endl;

            while(true)
            {
                cout << "Select: ";
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
            cout << "Wrong Input" << endl;
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
                cout << "Invalid input!" << endl << endl;
            }
        }

        if(inputCheck == 1)
        {
            int userInputBirth;

            cout << "Search by year of birth: ";
            while(true)
            {
                cout << "Select: ";
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
                cout << "to year of birth: ";
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
            cout << endl << "Wrong Input" << endl;
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
                cout << "Invalid input!" << endl << endl;
            }
        }

        if(inputCheck == 1)
        {
            int userInputDeath;

            while(true)
            {
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
            cout << "Wrong Input" << endl;
        }
    }
    cout << endl;
}
void ConsoleUI::sortScientist()
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
            cout << endl << "Invalid input!" << endl;

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
void ConsoleUI::addComputer()
{
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
                cout << "This computer is allready in the database" << endl;
                cout << "(1) To enter name again" << endl;
                cout << "(2) To replace computer" << endl;
                cout << "Select: ";
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
                    cout << "Wrong input!";
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
                    cout << "Invalid input" << endl;
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
                cout << "Invalid Input" << endl;
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
void ConsoleUI::removeComputer()
{
    /*
     * A function to remove a computer.
     */

    string command;

    clearScreen();
    smallLogoPrint();
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
        smallLogoPrint();

        cout << "Type in \"remove\" to remove *ALL* computers, any other input to cancel" << endl;

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
void ConsoleUI::searchComputer()
{
    /*
     * A search list is printed out and user can choose from a few search commands
     * like name, year built, type, and if built. Error checks included
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
            cout << "Invalid input!" << endl;
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
                cout << "Invalid input!" << endl;
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
                cout << "Invalid input!" << endl << endl;
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
                cout << "Invalid input!" << endl << endl;
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
void ConsoleUI::sortComputer()
{
    /*
     * A sorting function, can call function from service.cpp computerSort().
     * The function will sort depending on int parameter "Sort by sortType:
     *  1 = name(A-Z), 2 = name(Z-A), 3 = year(0-9), 4 = year(9-0) 5 = type(A-Z),
     *  6 = type(Z-A), 7 = was built(N-Y),  8 = year made(Y-N)".
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

        if(inputNotValid)
        {
            cout << endl << "Invalid input!" << endl;

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
void ConsoleUI::addRelation()
{
    string scientist, computer;
    int checkInput;

        while(true)
        {
        clearScreen();
        userMenuPrint(1);
        cout << "Enter the scientist's name: ";

        while(true)
        {
            cin.ignore(-1);
            getline(cin, scientist);

            if(scientist == "")
            {
                userMenuPrint(1);
                cout << "No name no fame!" << endl;
                cout << "Enter the scientist's name: ";
            }
            else if(_service.doesScientistExist(scientist) == false)
            {
                userMenuPrint(1);
                cout << "There are no scientists by that name." << endl;
                cout << "Enter the scientist's name: ";
            }
            else
            {
                break;
            }
        }

        userMenuPrint(2);
        cout << "Enter the computer's name: ";

        while(true)
        {
            cin.ignore(-1);
            getline(cin, computer);

            if(computer == "")
            {
                userMenuPrint(2);
                cout << "Computers have names too!" << endl;
                cout << "Enter the computer's name: ";
            }
            else if(_service.doesComputerExist(computer) == false)
            {
                userMenuPrint(2);
                cout << "There are no computers by that name." << endl;
                cout << "Enter the computer's name: ";
            }
            else
            {
                break;
            }
        }

        // Check if input is correct
        clearScreen();
        smallLogoPrint();
        cout << "Scientist: " << scientist << endl << "Computer: " << computer << endl;

        checkInput = userCheckInput(); // A function that checks if the input is valid

        if (checkInput == 0)
        {
            if(_service.addRelation(scientist, computer))
            {
                cout << endl << scientist << "-" << computer << " relation successfully added to the list" << endl;
                askReturnToMenu();
                break;

            }
            else
            {
                int userInput;

                cout << "This relation is already in the database." << endl;
                cout << endl << "1 - Start over" << endl;
                cout << "2 - Cancel" << endl;
                while(true)
                {
                    cout << endl << "Select: ";
                    cin >> userInput;

                    if(cin.fail())
                    {
                        numericLimiter("Invalid input!");
                    }
                    else if(userInput == 2 || userInput == 1)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Invalid input!" << endl;
                    }

                }


                if(userInput == 2)
                {
                    break;
                }

            }

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
void ConsoleUI::removeRelation()
{
    /*
     * A function to remove a computer.
     */

    string command;

    clearScreen();
    smallLogoPrint();
    cout << "Select one of the following options: " << endl;
    cout << "(1)     -   Remove Relation by Scientist Name " << endl;
    cout << "(2)     -   Remove Relation by Computer Name" << endl;
    cout << "(3)     -   Remove *ALL* relations" << endl << endl;
    cout << "Select: ";

    getline(cin, command);
    cout << endl;

    if(command[0] == '1') // Remove computer/s by input.
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
                _service.removeRelation(1, userInputName); // TODO::Needs a functin in service layer
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
    else if(command[0] == '3') // Remove all relations
    {
        string userInputName;

        clearScreen();
        smallLogoPrint();

        cout << "Type in \"remove\" to remove *ALL* relations, any other input to cancel" << endl;

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
void ConsoleUI::searchRelation()
{
    /*
     * A search list is printed out and user can choose from a few search commands
     * like name, year built, type, and if built. Error checks included
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
        cout << "Select: ";
        getline(cin, command);

        if(command[0] == '1' || command[0] == '2' || command[0] == '3')
        {
            break;
        }
        else
        {
            cout << "Invalid input!" << endl;
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
                cout << "Invalid input!" << endl << endl;
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
            default: cout << "Wrong Input" << endl;
        }
    cout << endl;
    }
}

void ConsoleUI::sortRelation()
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
            cout << endl << "Invalid input!" << endl;

        }

        cout << endl << "Select: ";
        cin >> userInput;

        if(cin.fail())
        {
            numericLimiter("Invalid input!");
        }


        inputNotValid = true;


    }while(userInput < 1 || userInput > 8);


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
void ConsoleUI::smallLogoPrint()                                    // Prints a small logo to screen
{
    textColorLogo();

    int w = 65;
    cout << setw(w-1) << "  _____   ___    ______ ____" << endl;
    cout << setw(w) << " / ___/  /   |  / ____// __ \\" << endl;
    cout << setw(w) << " \\__  \\ / /| | / /    / /_/ /"  << endl;
    cout << setw(w) << " ___/ // ___ |/ /___ / _, _/ " << endl;
    cout << setw(w) << "/____//_/  |_|\\____//_/ |_|  " << endl;

    textColorSubLogo();
    cout << setw(w+4) << "Scientist and computer realtions." << endl;
    cout << setw(w-18) << "Version 1.0" << endl << endl << endl << endl;

    textColorMain();
}
void ConsoleUI::largeLogoPrint()                                    // Prints a large logo to screen
{
    if(true)
    {
    textColorLogo();

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
    textColorSubLogo();
    cout <<"  Scientist";
    textColorLogo();
    cout << "    /:::/    /            \\:::\\    \\                |::|   |           " << endl;
    cout << "         \\::::/    /  ";
    textColorSubLogo();
    cout << "And";
    textColorLogo();
    cout << "          /:::/    /              \\:::\\____\\               \\::|   |           " << endl;
    cout << "          \\::/    /  ";
    textColorSubLogo();
    cout << "Computer";
    textColorLogo();
    cout << "      \\::/    /                \\::/    /                \\:|   |           " << endl;
    cout << "           \\/____/  ";
    textColorSubLogo();
    cout << "Relations";
    textColorLogo();
    cout << "       \\/____/  ";
    textColorSubLogo();
    cout << "Version 1.0";

    textColorLogo();
    cout << "     \\/____/                  \\|___|           " << endl;

    textColorMain();

    }
}
void ConsoleUI::numericLimiter()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void ConsoleUI::numericLimiter(string comment)
{
    cout << comment << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

#ifdef _WIN32
void ConsoleUI::textColorMain()
{
    HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hstdout, 0x0F );
}
void ConsoleUI::textColorLogo()
{
    HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hstdout, 0x0C );
}
void ConsoleUI::textColorSubLogo()
{
    HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hstdout, 0x08 );
}
#else
void ConsoleUI::textColorMain()
{
    // Nothing happening! absolutely nothing to see here!
}
void ConsoleUI::textColorLogo()
{
    // Nothing happening! absolutely nothing to see here!
}

void ConsoleUI::textColorSubLogo()
{
    // Nothing happening! absolutely nothing to see here!
}
#endif
