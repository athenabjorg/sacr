#include "computerwindow.h"
#include "ui_computerwindow.h"

ComputerWindow::ComputerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComputerWindow)
{
    ui->setupUi(this);
}

ComputerWindow::~ComputerWindow()
{
    delete ui;
}

void ComputerWindow::passInfo(vector<string> name)
{
    //ui->lineEdit->setText(QString::fromStdString(name));
}
