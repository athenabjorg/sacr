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

void AddComputerWindow::on_addButton_clicked()
{
        QString name = ui -> nameInput -> text();
        QString yearBuilt = ui -> yearBuiltInput -> text();
        QString type = ui -> typeInput -> currentText();
        bool built = true;

        if(yearBuilt.isEmpty())
        {
            built = false;
        }
        else
        {
            built = true;
        }

        _service -> addComputer(name.toStdString(), yearBuilt.toInt(), type.toStdString(), built);
        close();
}
