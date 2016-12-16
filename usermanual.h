#ifndef USERMANUAL_H
#define USERMANUAL_H

#include <QDialog>
#include <string>

namespace Ui {
class UserManual;
}

class UserManual : public QDialog
{
    Q_OBJECT

public:
    explicit UserManual(QWidget *parent = 0);
    ~UserManual();

private:
    Ui::UserManual *ui;
    void printLogo();
};

#endif // USERMANUAL_H
