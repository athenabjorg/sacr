#include "mainwindow.h"
#include "ui_mainwindow.h"
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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui -> setupUi(this);
    printList(printSelect::relation);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_removeScientistButton_clicked()
{

}
void MainWindow::printList(enum printSelect userInput)
{
    vector<Scientist> scientists = _service.getScientists();
    vector<Computer>  computers  = _service.getComputers();
    vector<Relation>  relations  = _service.getRelations();

    switch(userInput)
    {
        case printSelect::scientist:
            printScientist(scientists);
            break;
        case printSelect::computer:
            printComputer(computers);
            break;
        case printSelect::relation:
            printRelation(relations);
            break;
        default:
            break;

    }
}
void MainWindow::printScientist(const vector<Scientist> &scientists)
{
//    ui -> scientistTable -> clearContents();
//    ui -> scientistTable -> scientists.size();

//    for(unsigned int row = 0; row < scientists.size(); row++)
//    {
//        Scientist currentScientists = scientists.at(row);

//        QString name =  QString::fromStdString(currentScientists.getName());<

//        ui -> scientistList -> setItem(row, 0, new QTableWidgetItem(name));
//    }


}
void MainWindow::printComputer(const vector<Computer> &computers)
{
//    ui -> scientistList -> clearContents();;
//    for(unsigned int i = 0; i < computers.size(); i++)
//    {
//        ui -> scientistList -> addItem(QString::fromStdString(computers[i].getName()));
//    }
//    ui -> scientistList->update();
}
void MainWindow::printRelation(const vector<Relation> &relations)
{
//    ui -> scientistList -> clearContents();
//    for(unsigned int i = 0; i < relations.size(); i++)
//    {
//        ui -> scientistList -> addItem(QString::fromStdString(relations[i].getScientist()));
//        ui -> scientistList -> addItem(QString::fromStdString(relations[i].getComputer()));
//    }
//    ui -> scientistList->update();
}



void MainWindow::on_scientistList_activated(const QModelIndex &index)
{

}
