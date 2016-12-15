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
#include <QPixmap>

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


    void printLogo();
    void printList(enum printSelect userInput);
    void printScientist(const vector<Scientist> &scientists);
    void printComputer(const vector<Computer> &computers);
    void printRelation(const vector<Relation> &relations);


    void on_scientistSearchInput_textEdited(const QString &arg1);


    void on_scientistSearchBy_currentIndexChanged(int index);

    void on_scientistAddButton_clicked();

    void on_computerAddButton_clicked();

    void on_relationAddButton_clicked();

    void on_computerSearchInput_textEdited(const QString &arg1);

    void on_computerSearchBy_currentIndexChanged(int index);

    void on_relationSearchInput_textEdited(const QString &arg1);

    void on_relationSearchBy_currentIndexChanged(int index);

    void on_scientistTable_cellDoubleClicked(int row, int column);

    void on_computerTable_cellDoubleClicked(int row, int column);

    void on_scientistSearchBy_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    service _service;

    int _scientistComboboxIndex = 0;
    int _computerComboboxIndex = 0;
    int _relationComboboxIndex = 0;
};

#endif // MAINWINDOW_H
