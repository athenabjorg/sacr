#include "addrelationwindow.h"
#include "ui_addrelationwindow.h"
#include "service.h"

AddRelationWindow::AddRelationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRelationWindow)
{
    ui->setupUi(this);
    _service = nullptr; //---
}

void AddRelationWindow::set_service(service *s)//---
{
    _service = s;
}

AddRelationWindow::~AddRelationWindow()
{
    delete ui;
}

void AddRelationWindow::on_addButton_clicked()
{
//    QString name = ui -> nameInput -> text();
//    QString birthYear = ui -> yearBornInput -> text();
//    QString deathYear = ui -> yearDiedInput_2 -> text();
//    char gender;


//    if(ui -> genderMaleButton -> isChecked())
//    {
//        gender = 'm';
//    }
//    else if(ui -> genderFemaleButton -> isChecked())
//    {
//        gender = 'f';
//    }
//    else if(ui -> genderOtherButton -> isChecked())
//    {
//        gender = 'o';
//    }

//    _service->addScientist(name.toStdString(), gender, birthYear.toInt(), deathYear.toInt());//---
//    close();
}
