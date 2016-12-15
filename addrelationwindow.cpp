#include "addrelationwindow.h"
#include "ui_addrelationwindow.h"
#include "service.h"

AddRelationWindow::AddRelationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRelationWindow)
{
    ui->setupUi(this);
    _service = nullptr;
}

void AddRelationWindow::set_service(service *s)
{
    _service = s;
}

AddRelationWindow::~AddRelationWindow()
{
    delete ui;
}

void AddRelationWindow::on_addButton_clicked()
{
    QString scientist = ui -> scientistNameInput -> text();
    QString computer = ui -> computerNameInput_2 -> text();



    // Check if fiels are left empty and if name is allready taken and if so print out a red error msg
    if(scientist.isEmpty())
    {
        ui -> errorLabelScientist -> setText("<span style='color: #ED1C58'>Name is empty");
    }
    else
    {
        ui -> errorLabelScientist -> setText("<span style='color: #ED1C58'> ");
    }

    // Check if fiels are left empty and if name is allready taken and if so print out a red error msg
    if(computer.isEmpty())
    {
        ui -> errorLabelComputer -> setText("<span style='color: #ED1C58'>Name is empty");
    }
    else
    {
        ui -> errorLabelComputer -> setText("<span style='color: #ED1C58'> ");
    }




    // If everything chekcs out, add the new scientist and close the addscientistwindow
    if(scientist.isEmpty() || computer.isEmpty())
    {
        // TODO::ERROR_MSG_?
    }
    else if(_service -> addRelation(scientist.toStdString(), computer.toStdString()) == false)
    {
        ui -> errorLabelRelation -> setText("<span style='color: #ED1C58'>Relation allready exists");
    }
    else
    {
        _service -> addRelation(scientist.toStdString(), computer.toStdString());
        close();
    }


}
