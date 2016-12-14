#ifndef SCIENTISTWINDOW_H
#define SCIENTISTWINDOW_H

#include <QDialog>
#include "scientist.h"
#include "service.h"


namespace Ui {
class ScientistWindow;
}

class ScientistWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ScientistWindow(QWidget *parent = 0);
    ~ScientistWindow();

    void passName(string name);

private:
    Ui::ScientistWindow *ui;

    service _service;
    Scientist _scientist;

    string _name;
};

#endif // SCIENTISTWINDOW_H
