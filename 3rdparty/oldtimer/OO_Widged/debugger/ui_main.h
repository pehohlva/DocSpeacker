/********************************************************************************
** Form generated from reading UI file 'main.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_H
#define UI_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <XML_Editor.h>

QT_BEGIN_NAMESPACE

class Ui_ZipDebugMain
{
public:
    QAction *openzip;
    QAction *actionExit;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    XMLTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menuExit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ZipDebugMain)
    {
        if (ZipDebugMain->objectName().isEmpty())
            ZipDebugMain->setObjectName(QStringLiteral("ZipDebugMain"));
        ZipDebugMain->resize(800, 600);
        openzip = new QAction(ZipDebugMain);
        openzip->setObjectName(QStringLiteral("openzip"));
        actionExit = new QAction(ZipDebugMain);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralwidget = new QWidget(ZipDebugMain);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        textEdit = new XMLTextEdit(tab);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout_2->addWidget(textEdit, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        ZipDebugMain->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ZipDebugMain);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuExit = new QMenu(menubar);
        menuExit->setObjectName(QStringLiteral("menuExit"));
        ZipDebugMain->setMenuBar(menubar);
        statusbar = new QStatusBar(ZipDebugMain);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ZipDebugMain->setStatusBar(statusbar);

        menubar->addAction(menuExit->menuAction());
        menuExit->addAction(openzip);
        menuExit->addSeparator();
        menuExit->addAction(actionExit);

        retranslateUi(ZipDebugMain);
        QObject::connect(actionExit, SIGNAL(triggered()), ZipDebugMain, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ZipDebugMain);
    } // setupUi

    void retranslateUi(QMainWindow *ZipDebugMain)
    {
        ZipDebugMain->setWindowTitle(QApplication::translate("ZipDebugMain", "MainWindow", Q_NULLPTR));
        openzip->setText(QApplication::translate("ZipDebugMain", "Open Zip OO", Q_NULLPTR));
        actionExit->setText(QApplication::translate("ZipDebugMain", "Exit", Q_NULLPTR));
        label->setText(QApplication::translate("ZipDebugMain", "Drag OpenDocument format OO file to main content...", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ZipDebugMain", "content.xml", Q_NULLPTR));
        menuExit->setTitle(QApplication::translate("ZipDebugMain", "Exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ZipDebugMain: public Ui_ZipDebugMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_H
