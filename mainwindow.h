#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <string>
#include "service.h"
#include <vector>

using namespace std;

namespace Ui {
class MainWindow;
}

enum printSelect
{
    scientist,
    computer,
    relation,
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:



    void on_removeScientistButton_clicked();
    void printList(enum printSelect userInput);
    void printScientist(const vector<Scientist> &scientists);
    void printComputer(const vector<Computer> &computers);
    void printRelation(const vector<Relation> &relations);


private:
    Ui::MainWindow *ui;
    service _service;
};

#endif // MAINWINDOW_H
