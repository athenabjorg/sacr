#ifndef ADDRELATIONWINDOW_H
#define ADDRELATIONWINDOW_H

#include <QDialog>

namespace Ui {
class AddRelationWindow;
}

class AddRelationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddRelationWindow(QWidget *parent = 0);
    ~AddRelationWindow();

private:
    Ui::AddRelationWindow *ui;
};

#endif // ADDRELATIONWINDOW_H
