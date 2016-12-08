#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>


#include "service.h"
#include "scientist.h"
#include "computer.h"


class ConsoleUI
{
public:
    ConsoleUI();

    void userMenuRun();
        // Displays the main menu of the program.

private:

    void userMenuSwitch(int loadType);

    void userMenuAdd();
        // Enters the add menu.

    void userMenuSearch();
        // Searches for a scientist depending on the input, prints a list of the result.

    void userMenuSort();
        // Sorts the list of scientist depending on the input, prints a list of the result and saves to the text file.

    void userMenuPrint(int type);
        // Prints to the screen the scientist list from the text file.

    void userMenuPrint();

    void userMenuPrint(const vector<Scientist>& scientist);
        // Prints to the screen a scientist list provided (for example a search result).

    void userMenuPrint(const vector<Computer> &computer);
        // Prints to the screen a computer list provided (for example a search result).

    int  userCheckInput() const;
        // Asks for a yes, no, or cancel input and returns a corresponding numerical value (y = 0, n = 1, cancel = 2)

    void removeScientist();
        // Permanently removes scientists from the list, who have names containing the user input.

    void removeComputer();
        // Permanently removes scientists from the list, who have names containing the user input.

    void forceLowerCase(string &command);
        // Makes a string all lower case, to make commands eaier to read.

    void askReturnToMenu() const;
        // Halts the return to menu so the user can look at the output from other functions before returning.

    void clearScreen() const;
        // Adds 50 empty lines to the screen.

    int  whatYearIsIt() const;
        // Returns what year it is now.

    void addScientist();
        // Asks for information about a scientist, and then adds them to the database.

    void addComputer();
        // Asks for information about a computer, and then adds them to the database.


    void searchScientist();
        // Search scientists

    void searchComputer();
        // Search computers

    void sortScientist();
        // Sorts scientists.

    void sortComputer();
        // Sorts computers.


private:

    service _service;
};

#endif // CONSOLEUI_H
