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

void ScientistWindow::passName(string name)
{
    _name = name;

    _scientist = _service.getScientistInfo(_name);

    ui->inputName->setText(QString::fromStdString(_name));

}
