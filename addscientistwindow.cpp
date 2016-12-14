#include "addscientistwindow.h"
#include "ui_addscientistwindow.h"

AddScientistWindow::AddScientistWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientistWindow)
{
    ui->setupUi(this);
}

AddScientistWindow::~AddScientistWindow()
{
    delete ui;
}
