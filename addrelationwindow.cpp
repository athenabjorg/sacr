#include "addrelationwindow.h"
#include "ui_addrelationwindow.h"
#include "service.h"

AddRelationWindow::AddRelationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRelationWindow)                                           // Constructor
{
    ui->setupUi(this);
    _service = nullptr;
    //setFixedSize(width(),height());

    ui -> errorLabel -> setText("");

    _scientist = "";
    _computer = "";

    _scientistSet = false;
    _computerSet = false;

    _scientistRow = -1;
    _computerRow = -1;

}
AddRelationWindow::~AddRelationWindow()                                     // Deconstructor
{
    delete ui;
}


// ---------------------------------- OTHER     FUNCTIONS ---------------------------------- //
void AddRelationWindow::set_service(service *s)                             // Forwarded service
{
    _service = s;

    printScientist();
    printComputer();
}


// ---------------------------------- SCIENTIST FUNCTIONS ---------------------------------- //
void AddRelationWindow::setScientist(QString scientist)                     // Only prints selected scientist
{
    _scientist = scientist;

    ui -> scientistTable -> horizontalHeader() -> hide();
    ui -> scientistTable -> clearContents();
    ui -> scientistTable -> setRowCount(1);
    ui -> scientistTable -> setColumnCount(1);
    ui -> scientistTable -> setItem(0, 0, new QTableWidgetItem(_scientist));
    ui -> scientistTable -> selectRow(0);

    printComputer();

    _scientistSet = true;
}
void AddRelationWindow::printScientist()       // Prints a list of scientists
{

    ui -> scientistTable -> setSortingEnabled(1);

    ui -> scientistTable -> horizontalHeader() -> setSectionResizeMode(QHeaderView::Stretch);


    _scientists = _service->getScientists();


    if(_scientists.empty())
    {
        ui -> scientistTable -> horizontalHeader() -> hide();
        ui -> scientistTable -> clearContents();
        ui -> scientistTable -> setRowCount(1);
        ui -> scientistTable -> setColumnCount(1);
        ui -> scientistTable -> setItem(0, 0, new QTableWidgetItem("No scientists to show."));
    }
    else
    {
        ui -> scientistTable -> horizontalHeader() -> show();
        ui -> scientistTable -> clearContents();
        ui -> scientistTable -> setRowCount(_scientists.size());
        ui -> scientistTable -> setColumnCount(1);

        for(unsigned int row = 0; row < _scientists.size(); row++)
        {
            Scientist currentScientist = _scientists.at(row);

            QString name =  QString::fromStdString(currentScientist.getName());

            ui -> scientistTable -> setItem(row, 0, new QTableWidgetItem(name));
        }
    }
}
void AddRelationWindow::on_scientistTable_cellPressed(int row, int column)  // Stores currently selected row
{
    _scientistRow = row;
}


// ---------------------------------- COMPUTER  FUNCTIONS ---------------------------------- //
void AddRelationWindow::setComputer(QString computer)                       // Only prints selected computer
{
    _computer = computer;

    ui -> computerTable -> horizontalHeader() -> hide();
    ui -> computerTable -> clearContents();
    ui -> computerTable -> setRowCount(1);
    ui -> computerTable -> setColumnCount(1);
    ui -> computerTable -> setItem(0, 0, new QTableWidgetItem(_computer));
    ui -> computerTable -> selectRow(0);

    printScientist();

    _computerSet = true;
}
void AddRelationWindow::printComputer()          // Prints a list of computers
{
    ui -> computerTable -> setSortingEnabled(1);

    ui -> computerTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    _computers = _service->getComputers();


    if(_computers.empty())
    {
        ui -> computerTable -> horizontalHeader() -> hide();
        ui -> computerTable -> clearContents();
        ui -> computerTable -> setRowCount(1);
        ui -> computerTable -> setColumnCount(1);
        ui -> computerTable -> setItem(0, 0, new QTableWidgetItem("No scientists to show."));
    }
    else
    {
        ui -> computerTable -> horizontalHeader() -> show();
        ui -> computerTable -> clearContents();
        ui -> computerTable -> setRowCount(_computers.size());
        ui -> computerTable -> setColumnCount(1);

        for(unsigned int row = 0; row < _computers.size(); row++)
        {
            Computer currentComputer = _computers.at(row);

            QString name =  QString::fromStdString(currentComputer.getName());

            ui -> computerTable -> setItem(row, 0, new QTableWidgetItem(name));
        }
    }
}
void AddRelationWindow::on_computerTable_cellPressed(int row, int column)   // Stores currently selected row
{
    _computerRow = row;
}


// ---------------------------------- RELATION  FUNCTIONS ---------------------------------- //
void AddRelationWindow::on_addButton_clicked()                              // To add a new relation
{
    if((_scientistRow >= 0 || _scientistSet) && (_computerRow >= 0 || _computerSet))
    {
        QString scientist;
        QString computer;

        if(_scientistSet)
        {
            scientist = _scientist;
            computer = ui->computerTable->item(_computerRow, 0)->text();
        }
        else if (_computerSet)
        {
            computer = _computer;
            scientist = ui->scientistTable->item(_scientistRow, 0)->text();
        }
        else
        {
            scientist = ui->scientistTable->item(_scientistRow, 0)->text();
            computer = ui->computerTable->item(_computerRow, 0)->text();
        }

        if(_service->addRelation(scientist.toStdString(), computer.toStdString()))
        {
            close();
        }
        else
        {
            ui -> errorLabel -> setText("<span style='color: #ED1C58'>Relation already exists.");
        }

    }
    else if(_scientistRow < 0 && (_computerRow >= 0 || _computerSet))
    {
        ui -> errorLabel -> setText("<span style='color: #ED1C58'>Please choose a scientist");
    }
    else if((_scientistRow >= 0 || _scientistSet) && _computerRow < 0)
    {
        ui -> errorLabel -> setText("<span style='color: #ED1C58'>Please choose a computer");
    }
    else
    {
        ui -> errorLabel -> setText("<span style='color: #ED1C58'>Please choose a scientist and a computer");
    }

}
