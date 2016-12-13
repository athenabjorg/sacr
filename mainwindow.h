#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <string>
#include "service.h"
#include <vector>
#include <QDialog>
#include <QMainWindow>
#include <QLabel>
#include <QMessageBox>
#include <QTableView>
#include <QTableWidget>
#include <QItemDelegate>
#include <QStandardItemModel>
#include <QTableWidgetItem>
#include <QTableWidgetSelectionRange>
#include <QAbstractItemView>
#include <QObject>

using namespace std;

enum printSelect
{
    scientist,
    computer,
    relation,
};

namespace Ui {
class MainWindow;
}

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


    void on_scientistList_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    service _service;
};

#endif // MAINWINDOW_H
