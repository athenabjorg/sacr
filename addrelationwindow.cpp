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

    _service -> addRelation(scientist.toStdString(), computer.toStdString());
    close();
}
