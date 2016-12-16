#include "addcomputerwindow.h"
#include "ui_addcomputerwindow.h"
#include "service.h"

AddComputerWindow::AddComputerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputerWindow)                   // Constructor
{
    ui->setupUi(this);
    _service = nullptr;
    setFixedSize(width(),height());
}
AddComputerWindow::~AddComputerWindow()             // Deconstructor
{
    delete ui;
}


// ---------------------------------- OTHER     FUNCTIONS ---------------------------------- //
void AddComputerWindow::set_service(service *s)     // Forwarded service
{
    _service = s;
}


// ---------------------------------- COMPUTER  FUNCTIONS ---------------------------------- //
void AddComputerWindow::on_addButton_clicked()      // To add a new computer
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

    // Check if fiels are left empty and if name is allready taken and if so print out a red error msg
    if(name.isEmpty())
    {
        valid = false;
        ui -> errorLabelName -> setText("<span style='color: #ED1C58'>Name is empty");
    }
    else if((_service->findComputer(0, name.toStdString()).size()) > 0)
    {
        valid = false;
        ui -> errorLabelName -> setText("<span style='color: #ED1C58'>Name is taken");
    }
    else
    {
        ui -> errorLabelName -> setText("<span style='color: #ED1C58'> ");
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

    // If everything checks out, add the new computer and close the addcomputerwindow
    if(valid)
    {
        Computer computer;
        string computerID, imageURL;

        _service -> addComputer(" ", name.toStdString(), year.toStdString(), type.toStdString(), built.toStdString(), " ", about.toStdString(), abouturl.toStdString());

        computer = _service->getComputer(name.toStdString());
        computerID = computer.getID();
        imageURL = "../sacr/PicCom/" + computerID + ".jpg";
        QString qImageURL = QString::fromStdString(imageURL);

        QImage image = QImage(_fileName);

        image.save(qImageURL);

        close();
    }
}
void AddComputerWindow::on_ComputerAddPic_clicked() // Opens a window to select a picture
{
    _fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home", tr("Image Files (*.png *.jpg *.bmp)"));
}
