#ifndef ADDCOMPUTERWINDOW_H
#define ADDCOMPUTERWINDOW_H

#include <QDialog>

namespace Ui {
class AddComputerWindow;
}

class AddComputerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddComputerWindow(QWidget *parent = 0);
    ~AddComputerWindow();

private:
    Ui::AddComputerWindow *ui;
};

#endif // ADDCOMPUTERWINDOW_H
