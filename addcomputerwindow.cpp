#include "addcomputerwindow.h"
#include "ui_addcomputerwindow.h"
#include "service.h"

AddComputerWindow::AddComputerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputerWindow)
{
    ui->setupUi(this);
    _service = nullptr;
}
void AddComputerWindow::set_service(service *s)
{
    _service = s;
}

AddComputerWindow::~AddComputerWindow()
{
    delete ui;
}

void AddComputerWindow::on_addButton_clicked() // FIXME::BETTER_SOLUTION_?
{
    QString name = ui -> nameInput -> text();
    QString yearBuilt = ui -> yearBuiltInput -> text();
    QString type = ui -> typeInput -> currentText();
    bool built = true;
    bool valid = true;

    if(yearBuilt.isEmpty())
    {
        built = false;
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
    if(yearBuilt.toInt() > _service->whatYearIsIt())
    {
        ui -> errorLabelYear -> setText("<span style='color: #ED1C58'>Year is in the future");
        valid = false;
    }
    else if(!yearBuilt.isEmpty() && !re.exactMatch(yearBuilt))
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

        _service -> addComputer(name.toStdString(), yearBuilt.toInt(), type.toStdString(), built);

        computer = _service->getComputerInfo(name.toStdString());
        computerID = computer.getInfoID();
        imageURL = "../sacr/PicCom/" + computerID + ".jpg";
        QString qImageURL = QString::fromStdString(imageURL);

        QImage image = QImage(_fileName);

        image.save(qImageURL);

        close();
    }
}


void AddComputerWindow::on_ComputerAddPic_clicked()
{
    _fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home", tr("Image Files (*.png *.jpg *.bmp)"));
}
