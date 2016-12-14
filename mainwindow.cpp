#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "service.h"
#include <vector>

#include <QDialog>
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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui -> setupUi(this);
    printList(printSelect::scientist);
    printList(printSelect::computer);
    printList(printSelect::relation);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::printList(enum printSelect userInput)
{
    vector<Scientist> scientists = _service.getScientists();
    vector<Computer>  computers  = _service.getComputers();
    vector<Relation>  relations  = _service.getRelations();

    switch(userInput)
    {
        case printSelect::scientist:
            printScientist(scientists);
            break;
        case printSelect::computer:
            printComputer(computers);
            break;
        case printSelect::relation:
            printRelation(relations);
            break;
        default:
            break;

    }
}
void MainWindow::printScientist(const vector<Scientist> &scientists)
{
    ui -> scientistTable -> clearContents();
    ui -> scientistTable -> setRowCount(scientists.size());
    ui -> scientistTable -> setSortingEnabled(1);

    for(unsigned int row = 0; row < scientists.size(); row++)
    {
        Scientist currentScientists = scientists.at(row);

        QString name     =  QString::fromStdString(currentScientists.getName());
        QString gender   =  QString::fromStdString(currentScientists.getGender());
        QString yearBorn =  QString::number(currentScientists.getBirth());
        QString yearDied =  QString::number(currentScientists.getDeath());
        QString age      =  QString::number(currentScientists.getAge());

        ui -> scientistTable -> setItem(row, 0, new QTableWidgetItem(name));
        ui -> scientistTable -> setItem(row, 1, new QTableWidgetItem(gender));
        ui -> scientistTable -> setItem(row, 2, new QTableWidgetItem(yearBorn));
        ui -> scientistTable -> setItem(row, 3, new QTableWidgetItem(yearDied));
        ui -> scientistTable -> setItem(row, 4, new QTableWidgetItem(age));
    }
}
void MainWindow::printComputer(const vector<Computer> &computers)
{
    ui -> computerTable -> clearContents();
    ui -> computerTable -> setRowCount(computers.size());
    ui -> computerTable -> setSortingEnabled(1);

    for(unsigned int row = 0; row < computers.size(); row++)
    {
        Computer currentComputers = computers.at(row);

        QString name  =  QString::fromStdString(currentComputers.getName());
        QString year  =  QString::number(currentComputers.getYear());
        QString type  =  QString::fromStdString(currentComputers.getType());
        QString built =  QString::number(currentComputers.getBuilt());

        ui -> computerTable -> setItem(row, 0, new QTableWidgetItem(name));
        ui -> computerTable -> setItem(row, 1, new QTableWidgetItem(year));
        ui -> computerTable -> setItem(row, 2, new QTableWidgetItem(type));
        ui -> computerTable -> setItem(row, 3, new QTableWidgetItem(built));
    }
}
void MainWindow::printRelation(const vector<Relation> &relations)
{
    ui -> relationTable -> clearContents();
    ui -> relationTable -> setRowCount(relations.size());
    ui -> relationTable -> setSortingEnabled(1);

    for(unsigned int row = 0; row < relations.size(); row++)
    {
        Relation currentRelations = relations.at(row);

        QString scientistID =  QString::fromStdString(currentRelations.getScientist());
        QString computerID  =  QString::fromStdString(currentRelations.getComputer());


        ui -> relationTable -> setItem(row, 0, new QTableWidgetItem(scientistID));
        ui -> relationTable -> setItem(row, 1, new QTableWidgetItem(computerID));

    }
}


void MainWindow::on_scientistSearchInput_textEdited(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        printList(printSelect::scientist);
    }
    else
    {
        string input = ui->scientistSearchInput->text().toStdString();

        vector<Scientist> scientists = _service.findScientist(_scientistComboboxIndex + 1, arg1.toStdString());

        printScientist(scientists);
    }
}



void MainWindow::on_scientistSearchBy_currentIndexChanged(int index)
{
    _scientistComboboxIndex = index;

    QString searchBy = ui->scientistSearchInput->text();

    on_scientistSearchInput_textEdited(searchBy);
}

void MainWindow::on_scientistAddButton_clicked()
{
    AddScientistWindow addScientistWindow;

    addScientistWindow.exec();
}

void MainWindow::on_computerAddButton_clicked()
{
    AddComputerWindow addComputerWindow;

    addComputerWindow.exec();
}

void MainWindow::on_relationAddButton_clicked()
{
    AddRelationWindow addRelationWindow;

    addRelationWindow.exec();
}

void MainWindow::on_computerSearchInput_textEdited(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        printList(printSelect::computer);
    }
    else
    {
        string input = ui->computerSearchInput->text().toStdString();

        vector<Computer> computers = _service.findComputer(_computerComboboxIndex + 1, arg1.toStdString());

        printComputer(computers);
    }
}

void MainWindow::on_computerSearchBy_currentIndexChanged(int index)
{
    _computerComboboxIndex = index;

    QString searchBy = ui->computerSearchInput->text();

    on_computerSearchInput_textEdited(searchBy);
}

void MainWindow::on_relationSearchInput_textEdited(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        printList(printSelect::relation);
    }
    else
    {
        string input = ui->relationSearchInput->text().toStdString();

        vector<Relation> relations = _service.findRelation(_relationComboboxIndex + 1, arg1.toStdString());

        printRelation(relations);
    }
}

void MainWindow::on_relationSearchBy_currentIndexChanged(int index)
{
    _relationComboboxIndex = index;

    QString searchBy = ui->relationSearchInput->text();

    on_relationSearchInput_textEdited(searchBy);
}
