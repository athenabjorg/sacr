#include "addrelationwindow.h"
#include "ui_addrelationwindow.h"

AddRelationWindow::AddRelationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRelationWindow)
{
    ui->setupUi(this);
}

AddRelationWindow::~AddRelationWindow()
{
    delete ui;
}
