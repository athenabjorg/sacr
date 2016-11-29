#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "performerservice.h"

class ConsoleUI
{
public:
    ConsoleUI();

    // Displays the main menu of the program.
    void run();

private:

    void displayListOfPerformers();

private:
    PerformerService _service;
};

#endif // CONSOLEUI_H
