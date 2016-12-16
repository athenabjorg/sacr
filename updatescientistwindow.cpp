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
        _died = "";
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
    ui -> yearDiedInput -> setText(QString::fromStdString(_died));
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

    // If everything checks out, add the new scientist and close the addscientistwindow
    if(valid)
    {

        Scientist scientist;
        string scientistID, imageURL;

        _service->updateScientist(" ", name.toStdString(), gender.toStdString(), born.toStdString(), died.toStdString(), picurl.toStdString(), about.toStdString(), abouturl.toStdString());

        scientist = _service->getScientist(name.toStdString());
        scientistID = scientist.getID();
        imageURL = "../sacr/PicSci/" + scientistID + ".jpg";
        QString qImageURL = QString::fromStdString(imageURL);

        QImage image = QImage(_fileName);

        image.save(qImageURL);

        close();
    }
}

void UpdateScientistWindow::on_ScientistAddPic_clicked()
{
    _fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home", tr("Image Files (*.png *.jpg *.bmp)"));
}
