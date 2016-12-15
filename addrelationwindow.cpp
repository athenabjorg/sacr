#include "addrelationwindow.h"
#include "ui_addrelationwindow.h"
#include "service.h"

AddRelationWindow::AddRelationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRelationWindow)
{
    ui->setupUi(this);
    _service = nullptr;

    ui -> errorLabel -> setText("");

    _scientistRow = -1;
    _computerRow = -1;

}

void AddRelationWindow::set_service(service *s)
{
    _service = s;

    printScientist();
    printComputer();
}

AddRelationWindow::~AddRelationWindow()
{
    delete ui;
}

void AddRelationWindow::printScientist()
{

    ui -> scientistTable -> setSortingEnabled(1);

    ui -> scientistTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


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
        ui -> scientistTable -> horizontalHeader();
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

void AddRelationWindow::printComputer()
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
        ui -> computerTable -> horizontalHeader();
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

void AddRelationWindow::on_addButton_clicked()
{
    if(_scientistRow >= 0 && _computerRow >= 0)
    {
        QString scientist = ui->scientistTable->item(_scientistRow, 0)->text();
        QString computer = ui->computerTable->item(_computerRow, 0)->text();

        if(_service->addRelation(scientist.toStdString(), computer.toStdString()))
        {
            close();
        }
        else
        {
            ui -> errorLabel -> setText("<span style='color: #ED1C58'>Relation already exists.");
        }

    }
    else if(_scientistRow < 0 && _computerRow >= 0)
    {
        ui -> errorLabel -> setText("<span style='color: #ED1C58'>Please choose a scientist");
    }
    else if(_scientistRow >= 0 && _computerRow < 0)
    {
        ui -> errorLabel -> setText("<span style='color: #ED1C58'>Please choose a computer");
    }
    else
    {
        ui -> errorLabel -> setText("<span style='color: #ED1C58'>Please choose a scientist and a computer");
    }




}

void AddRelationWindow::on_scientistTable_cellPressed(int row, int column)
{
    _scientistRow = row;
}

void AddRelationWindow::on_computerTable_cellPressed(int row, int column)
{
    _computerRow = row;
}
