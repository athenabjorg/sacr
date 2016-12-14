#include "addscientistwindow.h"
#include "ui_addscientistwindow.h"
#include "service.h"

AddScientistWindow::AddScientistWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientistWindow)
{
    ui->setupUi(this);
    _service = nullptr;
}

void AddScientistWindow::set_service(service *s)
{
    _service = s;
}

AddScientistWindow::~AddScientistWindow()
{
    delete ui;
}

void AddScientistWindow::on_addButton_clicked()
{
    QString name = ui -> nameInput -> text();
    QString birthYear = ui -> yearBornInput -> text();
    QString deathYear = ui -> yearDiedInput_2 -> text();
    char gender;
    ui -> errorLabelName -> setText(" ");

    if(name.isEmpty())
    {
        ui -> errorLabelName -> setText("<span style='color: #ED1C58'>Name is empty");
    }

    if(ui -> genderMaleButton -> isChecked())
    {
        gender = 'm';
    }
    else if(ui -> genderFemaleButton -> isChecked())
    {
        gender = 'f';
    }
    else if(ui -> genderOtherButton -> isChecked())
    {
        gender = 'o';
    }


    _service->addScientist(name.toStdString(), gender, birthYear.toInt(), deathYear.toInt());
    //close();
}
