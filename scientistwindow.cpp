#include "scientistwindow.h"
#include "ui_scientistwindow.h"
#include "updatescientistwindow.h"



ScientistWindow::ScientistWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScientistWindow)
{
    ui->setupUi(this);
    _service = nullptr;

    ui->relationTable->setSortingEnabled(1);
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

    _scientist = _service->getScientist(_name);

    _id = _scientist.getID();
    _born = _scientist.getBorn();
    _died = _scientist.getDied();

    if(_died == "0")
    {
        _died = "-";
    }

    _picurl = _scientist.getPicurl();
    _about = _scientist.getAbout();
    _abouturl = _scientist.getAbouturl();

    ui->inputName->setText(QString::fromStdString(_name));
    ui->inputBorn->setText(QString::fromStdString(_born));
    ui->inputDied->setText(QString::fromStdString(_died));
    ui->inputAbout->setText(QString::fromStdString(_about));

    setImage();

    printRelations();



}

void ScientistWindow::setImage()
{
    string pixurl = "../sacr/PicSci/" + _id + ".jpg";
    QString qpixurl = QString::fromStdString(pixurl);
    QPixmap pix(qpixurl);

    ui->inputPicture->setPixmap(qpixurl);
    ui->inputPicture->setPixmap(pix.scaled(400,400,Qt::KeepAspectRatio));
}

void ScientistWindow::printRelations()
{

    ui -> relationTable -> setSortingEnabled(1);

    ui -> relationTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    _relations = _service->findRelation(1, _name);


    if(_relations.empty())
    {
        ui -> relationTable -> horizontalHeader() -> hide();
        ui -> relationTable -> clearContents();
        ui -> relationTable -> setRowCount(1);
        ui -> relationTable -> setColumnCount(1);
        ui -> relationTable -> setItem(0, 0, new QTableWidgetItem("No relations have been added."));
    }
    else
    {
        ui -> relationTable -> horizontalHeader();
        ui -> relationTable -> clearContents();
        ui -> relationTable -> setRowCount(_relations.size());
        ui -> relationTable -> setColumnCount(2);

        for(unsigned int row = 0; row < _relations.size(); row++)
        {
            Relation currentRelations = _relations.at(row);

            QString computer =  QString::fromStdString(currentRelations.getComputer());
            QString year  =  QString::number(currentRelations.getYear());

            if(year.toInt() == 0)
            {
                year = "-";
            }

            ui -> relationTable -> setItem(row, 0, new QTableWidgetItem(computer));
            ui -> relationTable -> setItem(row, 1, new QTableWidgetItem(year));
        }
    }
}

void ScientistWindow::on_buttonInfo_clicked()
{
    QString url  = QString::fromStdString(_abouturl);
    QDesktopServices::openUrl(QUrl(url));
}

void ScientistWindow::on_buttonUpdate_2_clicked()
{
    UpdateScientistWindow updateScientistWindow;
    updateScientistWindow.set_service(_service);
    updateScientistWindow.passInfo(_name);
    updateScientistWindow.exec();
    passInfo(_name);

}

void ScientistWindow::on_buttonAddRelation_clicked()
{
    AddRelationWindow addRelationWindow;
    addRelationWindow.set_service(_service);
    addRelationWindow.setScientist(QString::fromStdString(_name));
    addRelationWindow.exec();

    printRelations();
}
