#ifndef ADDRELATIONWINDOW_H
#define ADDRELATIONWINDOW_H
#include "service.h"
#include <QDialog>
#include <vector>
#include <string>
#include "scientist.h"
#include "computer.h"


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
    void setScientist(QString scientist);
    void setComputer(QString copmuter);

private slots:
    void on_addButton_clicked();
    void on_scientistTable_cellPressed(int row, int column);
    void on_computerTable_cellPressed(int row, int column);

private:
    Ui::AddRelationWindow *ui;
    service *_service;
    vector<Scientist> _scientists;
    vector<Computer> _computers;
    QString _scientist;
    QString _computer;
    bool _scientistSet;
    bool _computerSet;
    int _scientistRow;
    int _computerRow;
    void printScientist(vector<Scientist> &scientists);
    void printComputer(vector<Computer> &computers);
};

#endif // ADDRELATIONWINDOW_H
