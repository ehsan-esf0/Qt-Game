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
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setWindowModality(Qt::WindowModality::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(400, 500);
        MainWindow->setMinimumSize(QSize(400, 500));
        MainWindow->setMaximumSize(QSize(400, 500));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color : rgb(255, 255, 255);\n"
"background :url(:/res/image/Untitled-3.png);\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("background-color : rgb(255, 255, 255);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(100, 130, 231, 71));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setStyleSheet(QString::fromUtf8("font-size: 26px;\n"
"font-weight: bold;\n"
"color: black;\n"
"background-color:rgb(255, 255, 255);\n"
"border: 2px solid black;\n"
"border-radius: 15px;\n"
"padding: 10px 20px;\n"
"box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3);"));
        pushButton->setAutoExclusive(false);
        pushButton->setAutoDefault(false);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(220, 240, 171, 61));
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
        pushButton_3->setGeometry(QRect(220, 310, 171, 61));
        pushButton_3->setStyleSheet(QString::fromUtf8("font-size: 26px;\n"
"font-weight: bold;\n"
"color: black;\n"
"background-color: white;\n"
"border: 2px solid black;\n"
"border-radius: 15px;\n"
"padding: 10px 20px;\n"
"box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.3);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(-10, 0, 351, 121));
        label->setStyleSheet(QString::fromUtf8("background : url(:/res/image/Untitled-5.png);"));
        MainWindow->setCentralWidget(centralwidget);
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton->raise();
        label->raise();

        retranslateUi(MainWindow);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\331\210\330\261\331\210\330\257 \330\250\331\207 \330\250\330\247\330\262\333\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\331\276\330\261\331\210\331\201\330\247\333\214\331\204", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\330\252\331\206\330\270\333\214\331\205\330\247\330\252", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
