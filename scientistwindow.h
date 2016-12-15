#ifndef SCIENTISTWINDOW_H
#define SCIENTISTWINDOW_H

#include <QDialog>
#include <QPixmap>
#include <vector>
#include "scientist.h"
#include "service.h"
#include "relation.h"

namespace Ui {
class ScientistWindow;
}

class ScientistWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ScientistWindow(QWidget *parent = 0);
    ~ScientistWindow();

    void set_service(service *s);

    void passInfo(string name);

private:

    void printRelations();


    Ui::ScientistWindow *ui;

    service *_service;
    Scientist _scientist;

    string _name;
    string _id;
    string _born;
    string _died;
    string _picurl;
    string _about;
    string _abouturl;
};

#endif // SCIENTISTWINDOW_H
