#include "computerwindow.h"
#include "ui_computerwindow.h"



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

    ui->relationTable->setSortingEnabled(1);
    ui->inputAbout->setStyleSheet("background-color: rgba( 255, 255, 255, 0% );");
}

void ComputerWindow::setImage()
{
    string pixurl = "../sacr/PicCom/" + _id + ".jpg";
    QString qpixurl = QString::fromStdString(pixurl);
    QPixmap pix(qpixurl);

    ui->inputPicture->setPixmap(qpixurl);
    ui->inputPicture->setPixmap(pix.scaled(350,400,Qt::KeepAspectRatio));
}

void ComputerWindow::printRelations()
{
    ui -> relationTable -> setSortingEnabled(1);

    ui -> relationTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    _relations = _service->findRelation(2, _name);


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
        ui -> relationTable -> setColumnCount(1);

        for(unsigned int row = 0; row < _relations.size(); row++)
        {
            Relation currentRelations = _relations.at(row);

            QString scientist =  QString::fromStdString(currentRelations.getScientist());

            ui -> relationTable -> setItem(row, 0, new QTableWidgetItem(scientist));
        }
    }
}

void ComputerWindow::on_buttonInfo_clicked()
{
    QString url  = QString::fromStdString(_abouturl);
    QDesktopServices::openUrl(QUrl(url));
}
