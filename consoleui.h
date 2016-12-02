#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <iostream>
#include <string>
#include <iomanip>
#include "scientistservice.h"

class ConsoleUI
{
public:
    ConsoleUI();

    // Displays the main menu of the program.
    void run();
    void userMenuAdd();

private:

    void userMenuList();
    void userMenuSearch();
    void userMenuSort();
    void userMenuPrint(vector<Scientist>scientist);
    int  userCheckInput();
    void userMenuRemove();
    void forceLowerCase(string &command);
    void askReturnToMenu();
    void clearScreen();
    string getInput();

private:
    ScientistService _service;
};

#endif // CONSOLEUI_H
