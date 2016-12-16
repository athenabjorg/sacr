#ifndef ADDCOMPUTERWINDOW_H
#define ADDCOMPUTERWINDOW_H
#include "service.h"
#include <QDialog>
#include <QFileDialog>
#include <QImage>

namespace Ui {
class AddComputerWindow;
}

class AddComputerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddComputerWindow(QWidget *parent = 0);
    void set_service(service *s);
    ~AddComputerWindow();

private slots:
    void on_addButton_clicked();
    void on_ComputerAddPic_clicked();

private:
    Ui::AddComputerWindow *ui;
    service *_service;
    QString _fileName;
};

#endif // ADDCOMPUTERWINDOW_H
