#include "usermanual.h"
#include "ui_usermanual.h"

using namespace std;

UserManual::UserManual(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserManual)
{
    ui->setupUi(this);

    printLogo();

    ui->userManualText->setStyleSheet("background-color: rgba( 255, 255, 255, 0% );");
}

UserManual::~UserManual()
{
    delete ui;
}
void UserManual::printLogo()
{
    string logourl = "../sacr/logos/SACR_Logo_red.png";
    QString qlogourl = QString::fromStdString(logourl);
    QPixmap logo(qlogourl);

    ui->inputLogoUM->setPixmap(qlogourl);
    ui->inputLogoUM->setPixmap(logo.scaled(194,61,Qt::KeepAspectRatio));
}
