#include "usermanual.h"
#include "ui_usermanual.h"

UserManual::UserManual(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserManual)
{
    ui->setupUi(this);
}

UserManual::~UserManual()
{
    delete ui;
}
