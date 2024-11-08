/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setWindowModality(Qt::WindowModality::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(400, 500);
        MainWindow->setMinimumSize(QSize(400, 500));
        MainWindow->setMaximumSize(QSize(400, 500));
        MainWindow->setStyleSheet(QString::fromUtf8("background : rgb(117, 225, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 30, 301, 131));
        label->setStyleSheet(QString::fromUtf8("font-family: 'Vazir';\n"
"font-size: 50px;\n"
"font-weight: bold;\n"
"color: black;\n"
"text-align: center;\n"
"text-shadow: 5px 5px 10px rgba(100, 0, 0, 0.5);\n"
"background:none;\n"
""));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(90, 180, 201, 61));
        pushButton->setStyleSheet(QString::fromUtf8("font-size: 26px;\n"
"font-weight: bold;\n"
"color: black;\n"
"background-color: white;\n"
"border: 2px solid black;\n"
"border-radius: 15px;\n"
"padding: 10px 20px;\n"
"box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3);"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(130, 260, 201, 61));
        pushButton_2->setStyleSheet(QString::fromUtf8("font-size: 26px;\n"
"font-weight: bold;\n"
"color: black;\n"
"background-color: white;\n"
"border: 2px solid black;\n"
"border-radius: 15px;\n"
"padding: 10px 20px;\n"
"box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3);"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(90, 340, 201, 61));
        pushButton_3->setStyleSheet(QString::fromUtf8("font-size: 26px;\n"
"font-weight: bold;\n"
"color: black;\n"
"background-color: white;\n"
"border: 2px solid black;\n"
"border-radius: 15px;\n"
"padding: 10px 20px;\n"
"box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3);"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\331\205\331\206\331\210\333\214 \330\250\330\247\330\262\333\214", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\331\210\330\261\331\210\330\257 \330\250\331\207 \330\250\330\247\330\262\333\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\331\276\330\261\331\210\331\201\330\247\333\214\331\204", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\330\252\331\206\330\270\333\214\331\205\330\247\330\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
