#ifndef ComputerWindow_H
#define ComputerWindow_H

#include <QDialog>
#include <QPixmap>
#include <vector>
#include "computer.h"
#include "service.h"
#include "relation.h"
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

#endif // ComputerWindow_H
