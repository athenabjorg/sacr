#ifndef ADDSCIENTISTWINDOW_H
#define ADDSCIENTISTWINDOW_H
#include "service.h"
#include <QDialog>
#include <QFileDialog>
#include <QImage>

namespace Ui {
class AddScientistWindow;
}

class AddScientistWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddScientistWindow(QWidget *parent = 0);
    void set_service(service *s);
    ~AddScientistWindow();

private slots:
    void on_addButton_clicked();
    void on_ScientistAddPic_clicked();

private:
    Ui::AddScientistWindow *ui;
    service *_service;
    QString _fileName;
};

#endif // ADDSCIENTISTWINDOW_H
