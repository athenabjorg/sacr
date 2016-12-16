#include "updatecomputerwindow.h"
#include "ui_updatecomputerwindow.h"

UpdateComputerWindow::UpdateComputerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateComputerWindow)
{
    ui->setupUi(this);
}

UpdateComputerWindow::~UpdateComputerWindow()
{
    delete ui;
}
