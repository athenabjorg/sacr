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

void UpdateScientistWindow::passInfo(string name)
{
    _name = name;
    _scientist = _service->getScientistInfo(_name);
    _id = _scientist.getInfoID();
    _born = _scientist.getInfoBorn();
    _died = _scientist.getInfoDied();
    _gender = _scientist.getGender();
    _about = _scientist.getInfoAbout();
    _abouturl = _scientist.getInfoAbouturl();


    if(_died == "0")
    {
        _died = "-";
    }

    if(_gender[0] == 'f')
    {
        ui -> genderFemaleButton -> setChecked(true);
    }
    else if(_gender[0] == 'm')
    {
        ui -> genderMaleButton -> setChecked(true);
    }
    else
    {
        ui -> genderOtherButton -> setChecked(true);
    }



    ui -> nameInput -> setText(QString::fromStdString(_name));
    ui -> yearBornInput -> setText(QString::fromStdString(_born));
    ui -> yearDiedInput_2 -> setText(QString::fromStdString(_died));
    ui -> ScientistsAddInfo -> setText(QString::fromStdString(_about));
    ui -> inputInfoUrl -> setText(QString::fromStdString(_abouturl));

}

UpdateScientistWindow::~UpdateScientistWindow()
{
    delete ui;
}

void UpdateScientistWindow::on_updateButton_clicked() // FIXME::BETTER_SOLUTION_?
{
    QString name = ui -> nameInput -> text();
    QString birthYear = ui -> yearBornInput -> text();
    QString deathYear = ui -> yearDiedInput -> text();
    char gender;
    ui -> errorLabelName -> setText(" ");
    //ui -> nameInput -> setText(QString::fromStdString(_name));

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
    if(gender != 'e' && !birthYear.isEmpty())
    {
        _service->updateScientist(_name, gender, birthYear.toInt(), deathYear.toInt());
        close();
        //printList(printSelect::scientist);
    }
    else
    {
        //Do Nothing
    }
}
