#include "addscientistwindow.h"
#include "ui_addscientistwindow.h"
#include "service.h"

AddScientistWindow::AddScientistWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientistWindow)
{
    ui->setupUi(this);
    _service = nullptr;
    setFixedSize(width(),height());
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
    QString born = ui -> yearBornInput -> text();
    QString died = ui -> yearDiedInput -> text();
    QString picurl = " ";
    QString about = ui -> ScientistsAddInfo -> toPlainText();
    QString abouturl = ui -> inputInfoUrl -> text();
    QString gender;
    bool valid = true;
    ui -> errorLabelName -> setText(" ");

    // Check for what button is selected
    ui -> errorLabelGender -> setText("<span style='color: #ED1C58'> ");

    if(ui -> genderMaleButton -> isChecked())
    {
        gender = "m";
    }
    else if(ui -> genderFemaleButton -> isChecked())
    {
        gender = "f";
    }
    else if(ui -> genderOtherButton -> isChecked())
    {
        gender = "o";
    }
    else
    {
        valid = false;
        ui -> errorLabelGender -> setText("<span style='color: #ED1C58'>Gender is empty");
    }


    // Check if fiels are left emty and if name is allready taken and if so print out a red error msg
    if(name.isEmpty())
    {
        valid = false;
        ui -> errorLabelName -> setText("<span style='color: #ED1C58'>Name is empty");
    }
    else if(_service->findScientist(1, name.toStdString()).size() > 0)
    {
        valid = false;
        ui -> errorLabelName -> setText("<span style='color: #ED1C58'>Name is taken");
    }
    else
    {
        ui -> errorLabelName -> setText("<span style='color: #ED1C58'> ");
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
    else if(born.toInt() > _service-> whatYearIsIt())
    {
        ui -> errorLabelBorn -> setText("<span style='color: #ED1C58'>Birth year is in the future");
        valid = false;
    }
    else
    {
        ui -> errorLabelBorn -> setText("<span style='color: #ED1C58'> ");
    }

    if(died.toInt() < born.toInt() && died.toInt() != 0)
    {
        ui -> errorLabelDeath -> setText("<span style='color: #ED1C58'>Death year is invalid");
        valid = false;
    }
    else if(!died.isEmpty() && !re.exactMatch(died))
    {
        ui -> errorLabelDeath -> setText("<span style='color: #ED1C58'>Death year is invalid");
        valid = false;
    }
    else if(died.toInt() > _service->whatYearIsIt())
    {
        ui -> errorLabelDeath -> setText("<span style='color: #ED1C58'>Death year is in the future");
        valid = false;
    }
    else if(died.isEmpty())
    {
        died = "0";
    }
    else
    {
        ui -> errorLabelDeath -> setText("<span style='color: #ED1C58'> ");
    }

    // If everything chekcs out, add the new scientist and close the addscientistwindow
    if(valid)
    {
        Scientist scientist;
        string scientistID, imageURL;

        _service->addScientist(" ", name.toStdString(), gender.toStdString(), born.toStdString(), died.toStdString(), picurl.toStdString(), about.toStdString(), abouturl.toStdString());

        scientist = _service->getScientist(name.toStdString());
        scientistID = scientist.getID();
        imageURL = "../sacr/PicSci/" + scientistID + ".jpg";
        QString qImageURL = QString::fromStdString(imageURL);

        QImage image = QImage(_fileName);

        image.save(qImageURL);

        close();
    }

}

void AddScientistWindow::on_ScientistAddPic_clicked()
{
    _fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home", tr("Image Files (*.png *.jpg *.bmp)"));
}
