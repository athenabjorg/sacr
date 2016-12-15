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

    _currentRow = -1;
    _currentColumn = -1;

    printLogo();
    printList(printSelect::scientist);
    printList(printSelect::computer);
    printList(printSelect::relation);

    ui -> scientistTable -> setSortingEnabled(1);
    ui -> computerTable  -> setSortingEnabled(1);
    ui -> relationTable  -> setSortingEnabled(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// ---------------------------------- OTHER     FUNCTIONS ---------------------------------- //
void MainWindow::printLogo()
{
    string pixurl = "../sacr/logos/SACR_Logo_red.png";
    QString qpixurl = QString::fromStdString(pixurl);
    QPixmap pix(qpixurl);

    ui->inputLogoSci->setPixmap(qpixurl);
    ui->inputLogoSci->setPixmap(pix.scaled(203,62,Qt::KeepAspectRatio));
    ui->inputLogoCom->setPixmap(qpixurl);
    ui->inputLogoCom->setPixmap(pix.scaled(203,62,Qt::KeepAspectRatio));
    ui->inputLogoRel->setPixmap(qpixurl);
    ui->inputLogoRel->setPixmap(pix.scaled(203,62,Qt::KeepAspectRatio));
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

    for(unsigned int row = 0; row < relations.size(); row++)
    {
        Relation currentRelations = relations.at(row);

        QString scientistID =  QString::fromStdString(currentRelations.getScientist());
        QString computerID  =  QString::fromStdString(currentRelations.getComputer());


        ui -> relationTable -> setItem(row, 0, new QTableWidgetItem(scientistID));
        ui -> relationTable -> setItem(row, 1, new QTableWidgetItem(computerID));

    }
}


// ---------------------------------- SCIENTIST FUNCTIONS ---------------------------------- //
void MainWindow::on_scientistSearchInput_textEdited(const QString &arg1)
{
    ui -> scientistTable -> setSortingEnabled(0);

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

    ui -> scientistTable -> setSortingEnabled(1);
}
void MainWindow::on_scientistSearchBy_currentIndexChanged(int index)
{
    _scientistComboboxIndex = index;

    QString searchBy = ui->scientistSearchInput->text();

    on_scientistSearchInput_textEdited(searchBy);
}
void MainWindow::on_scientistSearchBy_currentIndexChanged(const QString &arg1) //FIXME::?
{
    if( ui->scientistSearchBy->currentText().toStdString() == "by Age Range" ||
        ui->scientistSearchBy->currentText().toStdString() == "by Birth Year Range" ||
        ui->scientistSearchBy->currentText().toStdString() == "by Death Year Range")
    {
        ui->scientistSearchRange->setEnabled(true);
    }
    else
    {
        ui->scientistSearchRange->setEnabled(false);
    }
}
void MainWindow::on_scientistAddButton_clicked()
{
    AddScientistWindow addScientistWindow;
    addScientistWindow.set_service(&_service);//---
    addScientistWindow.exec();
    printList(printSelect::scientist);

}
void MainWindow::on_scientistTable_cellDoubleClicked(int row, int column)
{
    ScientistWindow scientistWindow;
    QString name = ui->scientistTable->item(row, 0)->text();

    scientistWindow.set_service(&_service);
    scientistWindow.passInfo(name.toStdString());
    scientistWindow.exec();
    printList(printSelect::scientist);
}
void MainWindow::on_scientistTable_cellPressed(int row, int column)
{
    _currentRow = row;
    _currentColumn = column;
}
void MainWindow::on_scientistRemoveButton_clicked()
{
    ui -> scientistTable -> setSortingEnabled(0);

    if(_currentRow == -1)
    {
        //ui -> errorLableRemoveScientist -> setText("<span style='color: #ED1C58'>Nothing selected");
    }
    else if(_currentRow >= 0)
    {
        QString name = ui -> scientistTable -> item(_currentRow, 0) -> text();
        _service.removeScientist(name.toStdString());
        //ui -> errorLableRemoveScientist -> setText("<span style='color: #ED1C58'>");
        printList(printSelect::scientist);
    }

    ui -> scientistTable -> setSortingEnabled(1);

    _currentRow = -1;
}


// ---------------------------------- COMPUTER  FUNCTIONS ---------------------------------- //
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
//TODO::currentIndexChanged
void MainWindow::on_computerAddButton_clicked()
{
    AddComputerWindow addComputerWindow;
    addComputerWindow.set_service(&_service);//---
    addComputerWindow.exec();
    printList(printSelect::computer);
}
void MainWindow::on_computerTable_cellDoubleClicked(int row, int column)
{
    ComputerWindow computerWindow;
    QString name = ui->computerTable->item(row, 0)->text();

    computerWindow.set_service(&_service);
    computerWindow.passInfo(name.toStdString());
    computerWindow.exec();
    printList(printSelect::computer);
}
void MainWindow::on_computerTable_cellPressed(int row, int column)
{
    _currentRow = row;
    _currentColumn = column;
}
void MainWindow::on_computerRemoveButton_clicked()
{
    ui -> computerTable -> setSortingEnabled(0);

    if(_currentRow == -1)
    {
        //ui -> errorLabelRemoveComputer -> setText("<span style='color: #ED1C58'>Nothing selected");
    }
    else if(_currentRow >= 0)
    {
        QString name = ui -> computerTable -> item(_currentRow, 0) -> text();
        _service.removeComputer(name.toStdString());
        //ui -> errorLabelRemoveComputer -> setText("<span style='color: #ED1C58'>");
        printList(printSelect::computer);
    }

    ui -> computerTable -> setSortingEnabled(1);

    _currentRow = -1;
}


// ---------------------------------- RELATION  FUNCTIONS ---------------------------------- //
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
//TODO::currentIndexChanged
void MainWindow::on_relationAddButton_clicked()
{
    AddRelationWindow addRelationWindow;
    addRelationWindow.set_service(&_service);//---
    addRelationWindow.exec();
    printList(printSelect::relation);
}
//TODO::cellDoubleClicked ?
void MainWindow::on_relationTable_cellPressed(int row, int column)
{
    _currentRow = row;
    _currentColumn = column;
}
void MainWindow::on_relationRemoveButton_clicked()
{
    ui -> relationTable -> setSortingEnabled(0);

    if(_currentRow == -1)
    {
        //ui -> errorLabelRemoveRelation -> setText("<span style='color: #ED1C58'>Nothing selected");
    }
    else if(_currentRow >= 0)
    {
        QString scientist = ui -> relationTable -> item(_currentRow, 0) -> text();
        QString computer = ui -> relationTable -> item(_currentRow, 1) -> text();
        _service.removeRelation(scientist.toStdString(), computer.toStdString());
        //ui -> errorLabelRemoveRelation -> setText("<span style='color: #ED1C58'>");
        printList(printSelect::relation);
    }

    ui -> relationTable -> setSortingEnabled(1);

    _currentRow = -1;
}


void MainWindow::on_userManualButton_clicked()
{
    UserManual userManual;
    userManual.exec();
}
