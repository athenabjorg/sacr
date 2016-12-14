#ifndef SCIENTISTWINDOW_H
#define SCIENTISTWINDOW_H

#include <QDialog>

namespace Ui {
class ScientistWindow;
}

class ScientistWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ScientistWindow(QWidget *parent = 0);
    ~ScientistWindow();

private:
    Ui::ScientistWindow *ui;
};

#endif // SCIENTISTWINDOW_H
