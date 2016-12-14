#ifndef ADDSCIENTISTWINDOW_H
#define ADDSCIENTISTWINDOW_H

#include <QDialog>

namespace Ui {
class AddScientistWindow;
}

class AddScientistWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddScientistWindow(QWidget *parent = 0);
    ~AddScientistWindow();

private:
    Ui::AddScientistWindow *ui;
};

#endif // ADDSCIENTISTWINDOW_H
