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

void AddScientistWindow::on_addButton_clicked() // FIXME::BETTER_SOLUTION_?
{
    QString name = ui -> nameInput -> text();
    QString birthYear = ui -> yearBornInput -> text();
    QString deathYear = ui -> yearDiedInput -> text();
    char gender;
    ui -> errorLabelName -> setText(" ");

    // Check for what buttom is selected
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
    else
    {
        gender = ' ';
    }


    // Check if fiels are left emty and if name is allready taken and if so print out a red error msg
    if(name.isEmpty())
    {
        ui -> errorLabelName -> setText("<span style='color: #ED1C58'>Name is empty");
    }
    else if(_service->addScientist(name.toStdString(), gender, birthYear.toInt(), deathYear.toInt()) == false)
    {
        ui -> errorLabelName -> setText("<span style='color: #ED1C58'>Name is taken");
    }
    else
    {
        ui -> errorLabelName -> setText("<span style='color: #ED1C58'> ");
    }

    if(gender == 'e')
    {
        ui -> errorLabelGender -> setText("<span style='color: #ED1C58'>Gender is empty");
    }
    else
    {
        ui -> errorLabelGender -> setText("<span style='color: #ED1C58'> ");
    }

    if(birthYear.isEmpty())
    {
        ui -> errorLabelBorn -> setText("<span style='color: #ED1C58'>Birth year is empty");
    }
    else
    {
        ui -> errorLabelBorn -> setText("<span style='color: #ED1C58'> ");
    }







    // If everything chekcs out, add the new scientist and close the addscientistwindow
    if(name.isEmpty() || gender == 'e' || birthYear.isEmpty())
    {
        // TODO::ERROR_MSG_?
    }
    else
    {
        _service->addScientist(name.toStdString(), gender, birthYear.toInt(), deathYear.toInt());
        close();
    }





}
