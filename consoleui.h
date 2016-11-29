#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "scientistservice.h"

class ConsoleUI
{
public:
    ConsoleUI();

    // Displays the main menu of the program.
    void run();
    void userMenu();
    void userMenuAdd();

private:

    void userMenuList();
    void userMenuSearch();

private:
    ScientistService _service;
};

#endif // CONSOLEUI_H
