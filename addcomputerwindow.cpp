#include "addcomputerwindow.h"
#include "ui_addcomputerwindow.h"

AddComputerWindow::AddComputerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputerWindow)
{
    ui->setupUi(this);
}

AddComputerWindow::~AddComputerWindow()
{
    delete ui;
}
