#ifndef UPDATECOMPUTERWINDOW_H
#define UPDATECOMPUTERWINDOW_H

#include <QDialog>

namespace Ui {
class UpdateComputerWindow;
}

class UpdateComputerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateComputerWindow(QWidget *parent = 0);
    ~UpdateComputerWindow();

private:
    Ui::UpdateComputerWindow *ui;
};

#endif // UPDATECOMPUTERWINDOW_H
