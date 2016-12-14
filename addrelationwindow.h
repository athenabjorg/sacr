#ifndef ADDRELATIONWINDOW_H
#define ADDRELATIONWINDOW_H
#include "service.h"
#include <QDialog>

namespace Ui {
class AddRelationWindow;
}

class AddRelationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddRelationWindow(QWidget *parent = 0);
    void set_service(service *s);
    ~AddRelationWindow();

private slots:
    void on_addButton_clicked();

private:
    Ui::AddRelationWindow *ui;
    service *_service;
};

#endif // ADDRELATIONWINDOW_H
