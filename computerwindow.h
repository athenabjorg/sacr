#ifndef COMPUTERWINDOW_H
#define COMPUTERWINDOW_H

#include <QDialog>
#include <string>

using namespace std;

namespace Ui {
class ComputerWindow;
}

class ComputerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ComputerWindow(QWidget *parent = 0);
    ~ComputerWindow();

    void passInfo(string name);

private:
    Ui::ComputerWindow *ui;
};

#endif // COMPUTERWINDOW_H
