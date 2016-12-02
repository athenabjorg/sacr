#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

#include "scientistservice.h"

class ConsoleUI
{
public:
    ConsoleUI();

    void run();
        // Displays the main menu of the program.

private:

    void userMenuAdd();
    void userMenuSearch();
    void userMenuSort();
    void userMenuPrint();
    void userMenuPrint(const vector<Scientist>& scientist);
    int  userCheckInput() const;
    void userMenuRemove();
    void forceLowerCase(string &command);
    void askReturnToMenu() const;
    void clearScreen() const;
    int whatYearIsIt() const;

private:
    ScientistService _service;
};

#endif // CONSOLEUI_H
