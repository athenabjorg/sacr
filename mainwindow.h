#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "addscientistwindow.h"
#include "addcomputerwindow.h"
#include "addrelationwindow.h"
#include "scientistwindow.h"
#include "computerwindow.h"


#include <QMainWindow>
#include <QObject>
#include <string>
#include "service.h"
#include <vector>
#include <QDialog>
#include <QMainWindow>
#include <QLabel>
#include <QMessageBox>
#include <QTableView>
#include <QTableWidget>
#include <QItemDelegate>
#include <QStandardItemModel>
#include <QTableWidgetItem>
#include <QTableWidgetSelectionRange>
#include <QAbstractItemView>
#include <QObject>

using namespace std;

enum printSelect
{
    scientist,
    computer,
    relation,
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


// ---------------------------------- OTHER     FUNCTIONS ---------------------------------- //
    void printLogo();
    void printList(enum printSelect userInput);
    void printScientist(const vector<Scientist> &scientists);
    void printComputer(const vector<Computer> &computers);
    void printRelation(const vector<Relation> &relations);


// ---------------------------------- SCIENTIST FUNCTIONS ---------------------------------- //
    void on_scientistSearchInput_textEdited(const QString &arg1);
    void on_scientistSearchBy_currentIndexChanged(int index);
    void on_scientistSearchBy_currentIndexChanged(const QString &arg1);
    void on_scientistAddButton_clicked();
    void on_scientistTable_cellDoubleClicked(int row, int column);
    void on_scientistTable_cellPressed(int row, int column);
    void on_scientistRemoveButton_clicked();


// ---------------------------------- COMPUTER  FUNCTIONS ---------------------------------- //
    void on_computerSearchInput_textEdited(const QString &arg1);
    void on_computerSearchBy_currentIndexChanged(int index);
    //TODO::currentIndexChanged ?
    void on_computerAddButton_clicked();
    void on_computerTable_cellDoubleClicked(int row, int column);
    void on_computerTable_cellPressed(int row, int column);
    void on_computerRemoveButton_clicked();


// ---------------------------------- RELATION  FUNCTIONS ---------------------------------- //
    void on_relationSearchInput_textEdited(const QString &arg1);
    void on_relationSearchBy_currentIndexChanged(int index);
    //TODO::currentIndexChanged ?
    void on_relationAddButton_clicked();
    //TODO::cellDoubleClicked ?
    void on_relationTable_cellPressed(int row, int column);
    void on_relationRemoveButton_clicked();



private:
    Ui::MainWindow *ui;
    service _service;

    int _scientistComboboxIndex = 0;
    int _computerComboboxIndex = 0;
    int _relationComboboxIndex = 0;
    int _currentRow = 0;
    int _currentColumn = 0;
};

#endif // MAINWINDOW_H
