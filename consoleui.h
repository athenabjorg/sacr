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


private:

    void userMenuAdd();
    void userMenuSearch();
    void userMenuSort();
    void userMenuPrint();
    void userMenuPrint(vector<Scientist> scientist);
    int  userCheckInput();
    void userMenuRemove();
    void forceLowerCase(string &command);
    void askReturnToMenu();
    void clearScreen();

private:
    ScientistService _service;
};

#endif // CONSOLEUI_H
