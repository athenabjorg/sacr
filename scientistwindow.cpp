#include "scientistwindow.h"
#include "ui_scientistwindow.h"

ScientistWindow::ScientistWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScientistWindow)
{
    ui->setupUi(this);
}

ScientistWindow::~ScientistWindow()
{
    delete ui;
}
