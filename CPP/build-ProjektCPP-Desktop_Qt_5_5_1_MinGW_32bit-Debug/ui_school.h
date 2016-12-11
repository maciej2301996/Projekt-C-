/********************************************************************************
** Form generated from reading UI file 'school.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHOOL_H
#define UI_SCHOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_School
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *School)
    {
        if (School->objectName().isEmpty())
            School->setObjectName(QStringLiteral("School"));
        School->resize(1905, 1000);
        School->setMinimumSize(QSize(1905, 1000));
        centralWidget = new QWidget(School);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(1905, 1000));
        centralWidget->setMaximumSize(QSize(16777215, 16777215));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(885, 300, 133, 20));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(885, 340, 133, 20));
        School->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(School);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1905, 21));
        School->setMenuBar(menuBar);
        mainToolBar = new QToolBar(School);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        School->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(School);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        School->setStatusBar(statusBar);

        retranslateUi(School);

        QMetaObject::connectSlotsByName(School);
    } // setupUi

    void retranslateUi(QMainWindow *School)
    {
        School->setWindowTitle(QApplication::translate("School", "School", 0));
    } // retranslateUi

};

namespace Ui {
    class School: public Ui_School {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHOOL_H
