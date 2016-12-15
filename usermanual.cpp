#include "usermanual.h"
#include "ui_usermanual.h"

UserManual::UserManual(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserManual)
{
    ui->setupUi(this);
    ui->userManualText->setStyleSheet("background-color: rgba( 255, 255, 255, 0% );");
}

UserManual::~UserManual()
{
    delete ui;
}
