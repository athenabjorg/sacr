#include "scientistwindow.h"
#include "ui_scientistwindow.h"



ScientistWindow::ScientistWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScientistWindow)
{
    ui->setupUi(this);
    _service = nullptr;

    printRelations();

    ui->inputRelations->setSortingEnabled(1);
    ui->inputAbout->setStyleSheet("background-color: rgba( 255, 255, 255, 0% );");
}

ScientistWindow::~ScientistWindow()
{
    delete ui;
}

void ScientistWindow::set_service(service *s)
{
    _service = s;
}

void ScientistWindow::passInfo(string name)
{
    _name = name;

    _scientist = _service->getScientistInfo(_name);

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

void ScientistWindow::printRelations()
{
    vector<Relation> relations;

    //relations = _service->findRelation(1, _name);



    if(relations.empty())
    {
        ui->inputRelations->clearContents();
        ui -> inputRelations -> setItem(0, 0, new QTableWidgetItem("No relations have been added."));
    }
    else
    {
        ui->inputRelations->clearContents();
        ui->inputRelations->setRowCount(relations.size());

        for(unsigned int row = 0; row < relations.size(); row++)
        {
            Relation currentRelation = relations.at(row);

            QString computerName =  QString::fromStdString(currentRelation.getComputer());
            QString yearBuilt  =  QString::number(currentRelation.getYear());


            ui -> inputRelations -> setItem(row, 0, new QTableWidgetItem(computerName));
            ui -> inputRelations -> setItem(row, 1, new QTableWidgetItem(yearBuilt));
        }
    }
}

void ScientistWindow::on_pushButton_3_clicked()
{
    QString url  = QString::fromStdString(_abouturl);
    QDesktopServices::openUrl(QUrl(url));
}
