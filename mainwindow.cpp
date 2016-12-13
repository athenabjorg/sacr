#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_inputWindow_textEdited(const QString &arg1)
{
    string input = ui->inputWindow->text().toStdString();

    ui->outputWindow->setText(QString::fromStdString(input));
}
