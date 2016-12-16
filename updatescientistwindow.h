#ifndef UPDATESCIENTISTWINDOW_H
#define UPDATESCIENTISTWINDOW_H
#include "service.h"
#include <QDialog>

namespace Ui {
class UpdateScientistWindow;
}

class UpdateScientistWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateScientistWindow(QWidget *parent = 0);
    void set_service(service *s);
    ~UpdateScientistWindow();

private slots:
    void on_updateButton_clicked();

private:
    Ui::UpdateScientistWindow *ui;
    service *_service;
};

#endif // UPDATESCIENTISTWINDOW_H
