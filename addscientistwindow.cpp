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

    char yearWrong = 'F';

    QRegExp re("\\d*");

    //Error check birthYearInput
    if(birthYear.isEmpty())
    {
        ui -> errorLabelBorn -> setText("<span style='color: #ED1C58'>Birth year is empty");
        yearWrong = 'T';
    }
    else if(!re.exactMatch(birthYear))
    {
        ui -> errorLabelBorn -> setText("<span style='color: #ED1C58'>Birth year is invalid");
        yearWrong = 'T';
    }
    else if(birthYear.toInt() > _service-> whatYearIsIt())
    {
        ui -> errorLabelBorn -> setText("<span style='color: #ED1C58'>Birth year is invalid");
        yearWrong = 'T';
    }
    else
    {
        ui -> errorLabelBorn -> setText("<span style='color: #ED1C58'> ");
    }

    if(deathYear.toInt() < birthYear.toInt() && deathYear.toInt() != 0)
    {
        ui -> errorLabelDeath -> setText("<span style='color: #ED1C58'>Death year is invalid");
        yearWrong = 'T';    }
    else if(deathYear.toInt() > _service->whatYearIsIt())
    {
        ui -> errorLabelDeath -> setText("<span style='color: #ED1C58'>Death year is invalid");
        yearWrong = 'T';    }
    else
    {
        ui -> errorLabelDeath -> setText("<span style='color: #ED1C58'> ");
    }

    // If everything chekcs out, add the new scientist and close the addscientistwindow
    if(!name.isEmpty() && gender != 'e' && !birthYear.isEmpty() && !(_service->findScientist(0, name.toStdString()).size() > 0) && (re.exactMatch(birthYear)) && yearWrong == 'F')
    {
        Scientist scientist;
        string scientistID, imageURL;

        _service->addScientist(name.toStdString(), gender, birthYear.toInt(), deathYear.toInt());

        scientist = _service->getScientistInfo(name.toStdString());
        scientistID = scientist.getInfoID();
        imageURL = "../sacr/PicSci/" + scientistID + ".jpg";
        QString qImageURL = QString::fromStdString(imageURL);

        QImage image = QImage(_fileName);

        image.save(qImageURL);

        close();
    }
    else
    {
        //Do Nothing
    }
}

void AddScientistWindow::on_ScientistAddPic_clicked()
{
    _fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home", tr("Image Files (*.png *.jpg *.bmp)"));
}
