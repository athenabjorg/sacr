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
    ui -> scientistTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui -> computerTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui -> relationTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
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
    ui -> scientistTable -> horizontalHeader() -> show();


    for(unsigned int row = 0; row < scientists.size(); row++)
    {
        Scientist currentScientists = scientists.at(row);

        QString name     =  QString::fromStdString(currentScientists.getName());
        QString gender   =  QString::fromStdString(currentScientists.getGender());
        QString yearBorn =  QString::fromStdString(currentScientists.getBorn());
        QString yearDied =  QString::fromStdString(currentScientists.getDied());
        QString age      =  QString::number(currentScientists.getAge());

        if(gender == "m")
        {
            gender = "male";
        }
        else if(gender == "f")
        {
            gender = "female";
        }
        else if(gender == "o")
        {
            gender = "other";
        }

        if(yearDied == "0")
        {
            yearDied = "-";
        }


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
        QString year  =  QString::fromStdString(currentComputers.getYear());
        QString type  =  QString::fromStdString(currentComputers.getType());
        QString built =  QString::fromStdString(currentComputers.getBuilt());

        if(year == "0")
        {
            year = "-";
        }
        if(built == "1")
        {
            built = "Yes";
        }
        else if(built == "0")
        {
            built = "No";
        }

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
        QString computerYear  =  QString::number(currentRelations.getYear());

        if(computerYear == "0")
        {
            computerYear = "-";
        }

        ui -> relationTable -> setItem(row, 0, new QTableWidgetItem(scientistID));
        ui -> relationTable -> setItem(row, 1, new QTableWidgetItem(computerID));
        ui -> relationTable -> setItem(row, 2, new QTableWidgetItem(computerYear));
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
    else if ((_scientistComboboxIndex + 1) == 8 ||
             (_scientistComboboxIndex + 1) == 6 ||
             (_scientistComboboxIndex + 1) == 4)
    {
        if(arg1.isEmpty())
        {
            vector<Scientist> scientists = _service.findScientist(_scientistComboboxIndex + 1, "0" , ui->scientistSearchRange->text().toStdString());

            printScientist(scientists);
        }

        else if(ui->scientistSearchRange->text().isEmpty())
        {
            vector<Scientist> scientists = _service.findScientist(_scientistComboboxIndex + 1, arg1.toStdString(), "2016");

            printScientist(scientists);
        }
        else
        {
            vector<Scientist> scientists = _service.findScientist(_scientistComboboxIndex + 1, arg1.toStdString(), ui->scientistSearchRange->text().toStdString());

            printScientist(scientists);
        }
    }
    else
    {
        vector<Scientist> scientists = _service.findScientist(_scientistComboboxIndex + 1, arg1.toStdString());

        printScientist(scientists);
    }

    ui -> scientistTable -> setSortingEnabled(1);
}
void MainWindow::on_scientistSearchRange_textEdited(const QString &arg1)
{
    on_scientistSearchInput_textEdited(ui->scientistSearchInput->text());
}
void MainWindow::on_scientistSearchBy_currentIndexChanged(int index)
{
    ui->scientistSearchInput->setText("");
    ui->scientistSearchRange->setText("");

    _scientistComboboxIndex = index;

    QString searchBy = ui->scientistSearchInput->text();

    on_scientistSearchInput_textEdited(searchBy);

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
    ui -> scientistTable -> setSortingEnabled(0);
    AddScientistWindow addScientistWindow;
    addScientistWindow.set_service(&_service);
    addScientistWindow.exec();
    printList(printSelect::scientist);
    ui -> scientistTable -> setSortingEnabled(1);
}
void MainWindow::on_scientistTable_cellDoubleClicked(int row, int column)
{
    ScientistWindow scientistWindow;
    QString name = ui->scientistTable->item(row, 0)->text();

    scientistWindow.set_service(&_service);
    scientistWindow.passInfo(name.toStdString());
    scientistWindow.exec();
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

        ui -> errorLabelRemoveScientist -> setText("<span style='color: #ED1C58'>Nothing selected");
    }
    else if(_currentRow >= 0)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Remove", "Are you sure you want to remove this scientist",
        QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            QString name = ui -> scientistTable -> item(_currentRow, 0) -> text();
            _service.removeScientist(name.toStdString());
            ui -> errorLabelRemoveScientist -> setText("<span style='color: #ED1C58'>");
            printList(printSelect::scientist);
        }
        else
        {
            //Do nothing
        }

    }

    ui -> scientistTable -> setSortingEnabled(1);

    _currentRow = -1;
}
void MainWindow::on_scientistRemoveAllButton_clicked()
{
    ui -> scientistTable -> setSortingEnabled(0);

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Remove all", "Are you sure you want to remove all scientists",
    QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        _service.removeAllScientists();
        printList(printSelect::scientist);
    }
    else
    {
        //Do nothing
    }


    ui -> scientistTable -> setSortingEnabled(1);
}


// ---------------------------------- COMPUTER  FUNCTIONS ---------------------------------- //
void MainWindow::on_computerSearchInput_textEdited(const QString &arg1)
{
    ui -> computerTable -> setSortingEnabled(0);


    if(arg1.isEmpty())
    {
        printList(printSelect::computer);
    }
    else if ((_computerComboboxIndex + 1) == 3)
    {
        if(arg1.isEmpty())
        {
            vector<Computer> computers = _service.findComputer(_computerComboboxIndex + 1, "0" , ui->computerSearchRange->text().toStdString());

            printComputer(computers);
        }

        else if(ui->computerSearchRange->text().isEmpty())
        {
            vector<Computer> computers = _service.findComputer(_computerComboboxIndex + 1, arg1.toStdString(), "2016");

            printComputer(computers);
        }
        else
        {
            vector<Computer> computers = _service.findComputer(_computerComboboxIndex + 1, arg1.toStdString(), ui->computerSearchRange->text().toStdString());

            printComputer(computers);
        }
    }
    else
    {
        vector<Computer> computers = _service.findComputer(_computerComboboxIndex + 1, arg1.toStdString());

        printComputer(computers);
    }

    ui -> computerTable -> setSortingEnabled(1);
}

void MainWindow::on_computerSearchRange_textEdited(const QString &arg1)
{
    on_computerSearchInput_textEdited(ui->computerSearchInput->text());
}

void MainWindow::on_computerSearchBy_currentIndexChanged(int index)
{
    ui->computerSearchInput->setText("");
    ui->computerSearchRange->setText("");

    _computerComboboxIndex = index;

    QString searchBy = ui->computerSearchInput->text();

    on_computerSearchInput_textEdited(searchBy);

    if( ui->computerSearchBy->currentText().toStdString() == "by Year Built Range")
    {
        ui->computerSearchRange->setEnabled(true);
    }
    else
    {
        ui->computerSearchRange->setEnabled(false);
    }

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
        ui -> errorLabelRemoveComputer -> setText("<span style='color: #ED1C58'>Nothing selected");
    }
    else if(_currentRow >= 0)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Remove", "Are you sure you want to remove this computer",
        QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            QString name = ui -> computerTable -> item(_currentRow, 0) -> text();
            _service.removeComputer(name.toStdString());
            ui -> errorLabelRemoveComputer -> setText("<span style='color: #ED1C58'>");
            printList(printSelect::computer);
        }
        else
        {
            //Do nothing
        }

    }

    ui -> computerTable -> setSortingEnabled(1);

    _currentRow = -1;
}
void MainWindow::on_computerRemoveAllButton_clicked()
{
    ui -> computerTable -> setSortingEnabled(0);

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Remove all", "Are you sure you want to remove all computers",
    QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        _service.removeAllComputers();
        printList(printSelect::computer);
    }
    else
    {
        //Do nothing
    }

    ui -> computerTable -> setSortingEnabled(1);
}

// ---------------------------------- RELATION  FUNCTIONS ---------------------------------- //

void MainWindow::on_relationSearchInput_textEdited(const QString &arg1)
{
    ui -> relationTable -> setSortingEnabled(0);


    if(arg1.isEmpty())
    {
        printList(printSelect::relation);
    }
    else if ((_relationComboboxIndex + 1) == 4)
    {
        if(ui->relationSearchRange->text().isEmpty())
        {
            vector<Relation> relations = _service.findRelation(_relationComboboxIndex + 2, arg1.toStdString(), "2016");

            printRelation(relations);
        }
        else
        {
            vector<Relation> relations = _service.findRelation(_relationComboboxIndex + 2, arg1.toStdString(), ui->relationSearchRange->text().toStdString());

            printRelation(relations);
        }
    }
    else
    {
        vector<Relation> relations = _service.findRelation(_relationComboboxIndex + 1, arg1.toStdString());

        printRelation(relations);
    }

    ui -> relationTable -> setSortingEnabled(1);
}
void MainWindow::on_relationSearchRange_textEdited(const QString &arg1)
{
    on_relationSearchInput_textEdited(ui->relationSearchInput->text());
}
void MainWindow::on_relationSearchBy_currentIndexChanged(int index)
{
    ui->relationSearchInput->setText("");
    ui->relationSearchRange->setText("");

    _relationComboboxIndex = index;

    QString searchBy = ui->relationSearchInput->text();

    on_relationSearchInput_textEdited(searchBy);

    if( ui->relationSearchBy->currentText().toStdString() == "by Year Built Range")
    {
        ui->relationSearchRange->setEnabled(true);
    }
    else
    {
        ui->relationSearchRange->setEnabled(false);
    }

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
        ui -> errorLabelRemoveRelation -> setText("<span style='color: #ED1C58'>Nothing selected");
    }
    else if(_currentRow >= 0)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Remove", "Are you sure you want to remove this relation",
        QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            QString scientist = ui -> relationTable -> item(_currentRow, 0) -> text();
            QString computer = ui -> relationTable -> item(_currentRow, 1) -> text();
            _service.removeRelation(scientist.toStdString(), computer.toStdString());
            ui -> errorLabelRemoveRelation -> setText("<span style='color: #ED1C58'>");
            printList(printSelect::relation);
        }
        else
        {
            //Do nothing
        }

    }

    ui -> relationTable -> setSortingEnabled(1);

    _currentRow = -1;
}
void MainWindow::on_relationRemoveAllButton_clicked()
{
    ui -> relationTable -> setSortingEnabled(0);

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Remove all", "Are you sure you want to remove all relations",
    QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        _service.removeAllRelations();
        printList(printSelect::relation);
    }

    ui -> relationTable -> setSortingEnabled(1);
}

void MainWindow::on_userManualButton_clicked()
{
    UserManual userManual;
    userManual.exec();
}

void MainWindow::on_userManualButton2_clicked()
{
    UserManual userManual;
    userManual.exec();
}

void MainWindow::on_userManualButton3_clicked()
{
    UserManual userManual;
    userManual.exec();
}








