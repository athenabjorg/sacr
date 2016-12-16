#include "updatescientistwindow.h"
#include "ui_updatescientistwindow.h"
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
    _scientist = _service->getScientist(_name);
    _id = _scientist.getID();
    _born = _scientist.getBorn();
    _died = _scientist.getDied();
    _gender = _scientist.getGender();
    _about = _scientist.getAbout();
    _abouturl = _scientist.getAbouturl();


    if(_died == "0")
    {
        _died = "-";
    }

    if(_gender == "f")
    {
        ui -> genderFemaleButton -> setChecked(true);
    }
    else if(_gender == "m")
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
    QString born = ui -> yearBornInput -> text();
    QString died = ui -> yearDiedInput -> text();
    QString picurl;
    QString about;
    QString abouturl;
    QString gender;
    bool valid = true;
    ui -> errorLabelName -> setText(" ");


    // Check for what buttom is selected
    ui -> errorLabelGender -> setText("<span style='color: #ED1C58'> ");
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
        ui -> errorLabelGender -> setText("<span style='color: #ED1C58'>Gender is empty");
        valid = false;
    }

    QRegExp re("\\d*");

    //Error check birthYearInput
    if(born.isEmpty())
    {
        ui -> errorLabelBorn -> setText("<span style='color: #ED1C58'>Birth year is empty");
        valid = false;
    }
    else if(!re.exactMatch(born))
    {
        ui -> errorLabelBorn -> setText("<span style='color: #ED1C58'>Birth year is invalid");
        valid = false;
    }
    else
    {
        ui -> errorLabelBorn -> setText("<span style='color: #ED1C58'> ");
    }

    // If everything checks out, add the new scientist and close the UpdateScientistWindow
    if(valid)
    {
        _service->addScientist(" ", name.toStdString(), gender.toStdString(), born.toStdString(), died.toStdString(), picurl.toStdString(), about.toStdString(), abouturl.toStdString());
        close();
        //printList(printSelect::scientist);
    }
}
