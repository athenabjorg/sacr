#include "ComputerWindow.h"
#include "ui_ComputerWindow.h"



ComputerWindow::ComputerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComputerWindow)
{
    ui->setupUi(this);
    _service = nullptr;
}

ComputerWindow::~ComputerWindow()
{
    delete ui;
}

void ComputerWindow::set_service(service *s)
{
    _service = s;
}

void ComputerWindow::passInfo(string name)
{
    _name = name;

    _computer = _service->getComputerInfo(_name);

    _id = _computer.getInfoID();
    _year = _computer.getInfoYear();
    _type = _computer.getInfoType();

    if(_year == "0")
    {
        _year = "-";
    }

    _picurl = _computer.getInfoPicurl();
    _about = _computer.getInfoAbout();
    _abouturl = _computer.getInfoAbouturl();

    ui->inputName->setText(QString::fromStdString(_name));
    ui->inputYear->setText(QString::fromStdString(_year));
    ui->inputType->setText(QString::fromStdString(_type));
    ui->inputAbout->setText(QString::fromStdString(_about));

    setImage();

    printRelations();

    ui->inputRelations->setSortingEnabled(1);
    ui->inputAbout->setStyleSheet("background-color: rgba( 255, 255, 255, 0% );");
}

void ComputerWindow::setImage()
{
    string pixurl = "../sacr/PicSci/" + _id + ".jpg";
    QString qpixurl = QString::fromStdString(pixurl);
    QPixmap pix(qpixurl);

    ui->inputPicture->setPixmap(qpixurl);
    ui->inputPicture->setPixmap(pix.scaled(400,400,Qt::KeepAspectRatio));
}

void ComputerWindow::printRelations()
{
    vector<Relation> relations;

    relations = _service->findRelation(1, _name);


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

void ComputerWindow::on_buttonInfo_clicked()
{
    QString url  = QString::fromStdString(_abouturl);
    QDesktopServices::openUrl(QUrl(url));
}
