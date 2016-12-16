#ifndef UPDATESCIENTISTWINDOW_H
#define UPDATESCIENTISTWINDOW_H
#include "service.h"
#include <QDialog>

namespace Ui {
class UpdateScientistWindow;
}

class UpdateScientistWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateScientistWindow(QWidget *parent = 0);
    ~UpdateScientistWindow();
    void set_service(service *s);
    void passInfo(string name);

private slots:
    void on_updateButton_clicked();

private:
    Ui::UpdateScientistWindow *ui;
    service *_service;
    Scientist _scientist;

    string _name;
    string _id;
    string _born;
    string _died;
    string _picurl;
    string _about;
    string _abouturl;
    string _gender;
};

#endif // UPDATESCIENTISTWINDOW_H
