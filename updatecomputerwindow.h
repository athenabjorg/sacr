#ifndef UPDATECOMPUTERWINDOW_H
#define UPDATECOMPUTERWINDOW_H
#include "service.h"
#include <QDialog>
#include <QFileDialog>
#include <QImage>

namespace Ui {
class UpdateComputerWindow;
}

class UpdateComputerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateComputerWindow(QWidget *parent = 0);
    void set_service(service *s);
    void passInfo(string name);
    ~UpdateComputerWindow();

private slots:
    void on_addButton_clicked();

    void on_ComputerAddPic_clicked();

private:
    Ui::UpdateComputerWindow *ui;
    service *_service;
    Computer _computer;
    QString _fileName;

    string _name;
    string _id;
    string _year;
    string _type;
    string _built;
    string _picurl;
    string _about;
    string _abouturl;
};

#endif // UPDATECOMPUTERWINDOW_H
