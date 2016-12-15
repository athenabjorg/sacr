#ifndef USERMANUAL_H
#define USERMANUAL_H

#include <QDialog>

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
};

#endif // USERMANUAL_H
