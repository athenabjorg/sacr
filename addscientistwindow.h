#ifndef ADDSCIENTISTWINDOW_H
#define ADDSCIENTISTWINDOW_H
#include "service.h"
#include <QDialog>

namespace Ui {
class AddScientistWindow;
}

class AddScientistWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddScientistWindow(QWidget *parent = 0);
    void set_service(service *s);
    ~AddScientistWindow();

private slots:
    void on_addButton_clicked();

private:
    Ui::AddScientistWindow *ui;
    service *_service;
};

#endif // ADDSCIENTISTWINDOW_H
