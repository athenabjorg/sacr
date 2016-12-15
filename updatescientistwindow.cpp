#include "UpdateScientistWindow.h"
#include "ui_UpdateScientistWindow.h"
#include "service.h"

UpdateScientistWindow::UpdateScientistWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateScientistWindow)
{
    ui->setupUi(this);
    _service = nullptr;
}

void UpdateScientistWindow::set_service(service *s)
{
    _service = s;
}

UpdateScientistWindow::~UpdateScientistWindow()
{
    delete ui;
}

void UpdateScientistWindow::on_addButton_clicked() // FIXME::BETTER_SOLUTION_?
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
        gender = 'e';
    }








    // Check if fiels are left emty and if name is allready taken and if so print out a red error msg
    if(name.isEmpty())
    {
        ui -> errorLabelName -> setText("<span style='color: #ED1C58'>Name is empty");
    }
    else if(_service->findScientist(1, name.toStdString()).size() > 0)
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

    QRegExp re("\\d*");

    //Error check birthYearInput
    if(birthYear.isEmpty())
    {
        ui -> errorLabelBorn -> setText("<span style='color: #ED1C58'>Birth year is empty");
    }
    else if(!re.exactMatch(birthYear))
    {
        ui -> errorLabelBorn -> setText("<span style='color: #ED1C58'>Birth year is invalid");
    }
    else
    {
        ui -> errorLabelBorn -> setText("<span style='color: #ED1C58'> ");
    }

    // If everything chekcs out, add the new scientist and close the UpdateScientistWindow
    if(!name.isEmpty() && gender != 'e' && !birthYear.isEmpty() && !(_service->findScientist(1, name.toStdString()).size() > 0) && (re.exactMatch(birthYear)))
    {
        _service->addScientist(name.toStdString(), gender, birthYear.toInt(), deathYear.toInt());
        close();
    }
    else
    {
        //Do Nothing
    }
}
