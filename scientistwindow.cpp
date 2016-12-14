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

    _id = _scientist.getInfoID();
    _born = _scientist.getInfoBorn();
    _died = _scientist.getInfoDied();

    if(_died == "0")
    {
        _died = "-";
    }

    _picurl = _scientist.getInfoPicurl();
    _about = _scientist.getInfoAbout();
    _abouturl = _scientist.getInfoAbouturl();

    ui->inputName->setText(QString::fromStdString(_name));
    ui->inputBorn->setText(QString::fromStdString(_born));
    ui->inputDied->setText(QString::fromStdString(_died));
    ui->inputAbout->setText(QString::fromStdString(_about));

}

