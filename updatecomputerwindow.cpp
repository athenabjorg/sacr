#include "updatecomputerwindow.h"
#include "ui_updatecomputerwindow.h"
#include "service.h"

UpdateComputerWindow::UpdateComputerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateComputerWindow)
{
    ui->setupUi(this);
    _service = nullptr;
}
void UpdateComputerWindow::set_service(service *s)
{
    _service = s;
}

void UpdateComputerWindow::passInfo(string name)
{
    _name = name;
    _computer = _service->getComputer(_name);
    _id = _computer.getID();
    _year = _computer.getYear();
    _type = _computer.getType();
    _built = _computer.getBuilt();
    _picurl = _computer.getPicurl();
    _about = _computer.getAbout();
    _abouturl = _computer.getAbouturl();


    if(_year == "0")
    {
        _year = "";
    }

    ui -> nameInput -> setText(QString::fromStdString(_name));
    ui -> yearBuiltInput -> setText(QString::fromStdString(_year));
    ui -> ComputerAddInfo -> setText(QString::fromStdString(_about));
    ui -> inputInfoUrl -> setText(QString::fromStdString(_abouturl));
}

UpdateComputerWindow::~UpdateComputerWindow()
{
    delete ui;
}

void UpdateComputerWindow::on_addButton_clicked()
{
    QString name = ui -> nameInput -> text();
    QString year = ui -> yearBuiltInput -> text();
    QString built;
    QString type = ui -> typeInput -> currentText();
    QString about = ui -> ComputerAddInfo -> toPlainText();
    QString abouturl = ui -> inputInfoUrl -> text();
    bool valid = true;

    if(year.isEmpty())
    {
        built = "0";
    }
    else
    {
        built = "1";
    }

    QRegExp re("\\d*");

    //Error check year built
    if(year.toInt() > _service->whatYearIsIt())
    {
        ui -> errorLabelYear -> setText("<span style='color: #ED1C58'>Year is in the future");
        valid = false;
    }
    else if(!year.isEmpty() && !re.exactMatch(year))
    {
        ui -> errorLabelYear -> setText("<span style='color: #ED1C58'>Year is invalid");
        valid = false;
    }
    else
    {
        ui -> errorLabelYear -> setText("<span style='color: #ED1C58'> ");
    }

    // If everything checks out, add the new computer and close the UpdateComputerWindow
    if(valid)
    {
        Computer computer;
        string computerID, imageURL;

        _service -> updateComputer(" ", name.toStdString(), year.toStdString(), type.toStdString(), built.toStdString(), " ", about.toStdString(), abouturl.toStdString());

        computer = _service->getComputer(name.toStdString());
        computerID = computer.getID();
        imageURL = "../sacr/PicCom/" + computerID + ".jpg";
        QString qImageURL = QString::fromStdString(imageURL);

        QImage image = QImage(_fileName);

        image.save(qImageURL);

        close();
    }
}

void UpdateComputerWindow::on_ComputerAddPic_clicked()
{
    _fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home", tr("Image Files (*.png *.jpg *.bmp)"));
}
