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

        if(yearBuilt.isEmpty())
        {
            built = false;
        }
        else
        {
            built = true;
        }



        // Check if fiels are left empty and if name is allready taken and if so print out a red error msg
        if(name.isEmpty())
        {
            ui -> errorLabelName -> setText("<span style='color: #ED1C58'>Name is empty");
        }
        else if(_service -> addComputer(name.toStdString(), yearBuilt.toInt(), type.toStdString(), built) == false)
        {
            ui -> errorLabelName -> setText("<span style='color: #ED1C58'>Name is taken");
        }
        else
        {
            ui -> errorLabelName -> setText("<span style='color: #ED1C58'> ");
        }




        // If everything chekcs out, add the new scientist and close the addscientistwindow
        if(!name.isEmpty() &&_service -> addComputer(name.toStdString(), yearBuilt.toInt(), type.toStdString(), built))
            {
                _service -> addComputer(name.toStdString(), yearBuilt.toInt(), type.toStdString(), built);
                close();
            }
            else
            {
                //do nothing
            }
        }

