#ifndef COMPUTERWINDOW_H
#define COMPUTERWINDOW_H

#include <QDialog>
#include <QPixmap>
#include <vector>
#include "computer.h"
#include "service.h"
#include "relation.h"
#include "addrelationwindow.h"
#include "updatecomputerwindow.h"
#include <QDesktopServices>

namespace Ui {
class ComputerWindow;
}

class ComputerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ComputerWindow(QWidget *parent = 0);
    ~ComputerWindow();

    void set_service(service *s);

    void passInfo(string name);

private slots:
    void on_buttonInfo_clicked();

    void on_buttonAddRelation_clicked();

    void on_buttonUpdate_2_clicked();

private:

    void printRelations();
    void setImage();

    Ui::ComputerWindow *ui;

    service *_service;
    Computer _computer;
    vector<Relation> _relations;

    string _name;
    string _id;
    string _year;
    string _type;
    string _picurl;
    string _about;
    string _abouturl;
};

#endif // COMPUTERWINDOW_H
