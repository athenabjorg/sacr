/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabs;
    QWidget *scientistsTab;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *userOptionsLayout;
    QSpacerItem *picturePlaceholder;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *searchLayout;
    QSpacerItem *horizontalSpacer;
    QLineEdit *searchInput;
    QToolButton *toolButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *addRemoveLayout;
    QSpacerItem *addScientistRemoveSpacer;
    QPushButton *removeScientistButton;
    QPushButton *addButton;
    QListWidget *scientistList;
    QWidget *computersTab;
    QWidget *relationsTab;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(772, 607);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabs = new QTabWidget(centralWidget);
        tabs->setObjectName(QStringLiteral("tabs"));
        tabs->setEnabled(true);
        QFont font;
        font.setPointSize(12);
        tabs->setFont(font);
        tabs->setLayoutDirection(Qt::LeftToRight);
        tabs->setTabPosition(QTabWidget::North);
        tabs->setTabShape(QTabWidget::Triangular);
        tabs->setIconSize(QSize(16, 16));
        scientistsTab = new QWidget();
        scientistsTab->setObjectName(QStringLiteral("scientistsTab"));
        verticalLayout_2 = new QVBoxLayout(scientistsTab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        userOptionsLayout = new QHBoxLayout();
        userOptionsLayout->setSpacing(6);
        userOptionsLayout->setObjectName(QStringLiteral("userOptionsLayout"));
        picturePlaceholder = new QSpacerItem(120, 160, QSizePolicy::Fixed, QSizePolicy::Minimum);

        userOptionsLayout->addItem(picturePlaceholder);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        searchLayout = new QHBoxLayout();
        searchLayout->setSpacing(6);
        searchLayout->setObjectName(QStringLiteral("searchLayout"));
        horizontalSpacer = new QSpacerItem(120, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        searchLayout->addItem(horizontalSpacer);

        searchInput = new QLineEdit(scientistsTab);
        searchInput->setObjectName(QStringLiteral("searchInput"));

        searchLayout->addWidget(searchInput);

        toolButton = new QToolButton(scientistsTab);
        toolButton->setObjectName(QStringLiteral("toolButton"));

        searchLayout->addWidget(toolButton);


        verticalLayout->addLayout(searchLayout);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        addRemoveLayout = new QHBoxLayout();
        addRemoveLayout->setSpacing(6);
        addRemoveLayout->setObjectName(QStringLiteral("addRemoveLayout"));
        addScientistRemoveSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        addRemoveLayout->addItem(addScientistRemoveSpacer);

        removeScientistButton = new QPushButton(scientistsTab);
        removeScientistButton->setObjectName(QStringLiteral("removeScientistButton"));

        addRemoveLayout->addWidget(removeScientistButton, 0, Qt::AlignRight);

        addButton = new QPushButton(scientistsTab);
        addButton->setObjectName(QStringLiteral("addButton"));

        addRemoveLayout->addWidget(addButton, 0, Qt::AlignRight);


        verticalLayout->addLayout(addRemoveLayout);


        userOptionsLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(userOptionsLayout);

        scientistList = new QListWidget(scientistsTab);
        scientistList->setObjectName(QStringLiteral("scientistList"));

        verticalLayout_2->addWidget(scientistList);

        tabs->addTab(scientistsTab, QString());
        computersTab = new QWidget();
        computersTab->setObjectName(QStringLiteral("computersTab"));
        tabs->addTab(computersTab, QString());
        relationsTab = new QWidget();
        relationsTab->setObjectName(QStringLiteral("relationsTab"));
        tabs->addTab(relationsTab, QString());

        horizontalLayout->addWidget(tabs);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 772, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        searchInput->setPlaceholderText(QApplication::translate("MainWindow", "Search", 0));
        toolButton->setText(QApplication::translate("MainWindow", "...", 0));
        removeScientistButton->setText(QApplication::translate("MainWindow", "Add", 0));
        addButton->setText(QApplication::translate("MainWindow", "Remove", 0));
        tabs->setTabText(tabs->indexOf(scientistsTab), QApplication::translate("MainWindow", "Scientists", 0));
        tabs->setTabText(tabs->indexOf(computersTab), QApplication::translate("MainWindow", "Computers", 0));
        tabs->setTabText(tabs->indexOf(relationsTab), QApplication::translate("MainWindow", "Relations", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
