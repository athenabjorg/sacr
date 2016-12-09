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


private:
    service _service;
// ---------------------------------- USER MENU FUNCTIONS ---------------------------------- //
public:
    void userMenuRun();
        // Displays the main menu of the program.


// ---------------------------------- USER MENU FUNCTIONS ---------------------------------- //
private:
    void userMenuSwitch(int loadType);
        // ::TODO::
    void userMenuPrint(int loadType);
        // Prints to the screen the scientist list from the text file.
    void userMenuPrint(const vector<Scientist>& scientist);
        // Prints to the screen a scientist list provided (for example a search result).
    void userMenuPrint(const vector<Computer> &computer);
        // Prints to the screen a computer list provided (for example a search result).
    void userMenuPrint(const vector<Relation> &relation);
        // Prints to the screen a relation list provided (for example a search result).


// ---------------------------------- SCIENTIST FUNCTIONS ---------------------------------- //
private:
    void addScientist();
        // Asks for information about a scientist, and then adds them to the database.
    void removeScientist();
        // Permanently removes scientists from the list, who have names containing the user input.
    void searchScientist();
        // Search scientists
    void sortScientist();
        // Sorts scientists.


// ---------------------------------- COMPUTER  FUNCTIONS ---------------------------------- //
private:
    void addComputer();
        // Asks for information about a computer, and then adds them to the database.
    void removeComputer();
        // Permanently removes scientists from the list, who have names containing the user input.
    void searchComputer();
        // Search computers
    void sortComputer();
        // Sorts computers.


// ---------------------------------- RELATION  FUNCTIONS ---------------------------------- //
private:
    void addRelation();
        // Asks for information about a scientist-computer relation, and then adds them to the database.
    void removeRelation();
        // Permanently removes scientist-computer relation from the list, who have names containing the user input.
    void searchRelation();
        // Search scientist-computer relations
    void sortRelation();
        // Sorts scientist-computer relations.

// ---------------------------------- OTHER     FUNCTIONS ---------------------------------- //
private:
    int  userCheckInput() const;
        // Asks for a yes, no, or cancel input and returns a corresponding numerical value (y = 0, n = 1, cancel = 2)
    void forceLowerCase(string &command);
        // Makes a string all lower case, to make commands eaier to read.
    void askReturnToMenu() const;
        // Halts the return to menu so the user can look at the output from other functions before returning.
    void clearScreen() const;
        // Adds 50 empty lines to the screen.
    int  whatYearIsIt() const;
        // Returns what year it is now.
    void smallLogoPrint();

    void largeLogoPrint();

    void numericLimiter();

    void numericLimiter(string comment);

};

#endif // CONSOLEUI_H
