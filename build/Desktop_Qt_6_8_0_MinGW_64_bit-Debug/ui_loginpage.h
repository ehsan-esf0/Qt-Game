/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginPage
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *singin;
    QLineEdit *password_3;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *Tab2;
    QLineEdit *username_2;
    QLineEdit *password_2;
    QPushButton *login;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton;
    QLabel *label_13;

    void setupUi(QWidget *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName("LoginPage");
        LoginPage->resize(409, 484);
        LoginPage->setMaximumSize(QSize(409, 484));
        LoginPage->setStyleSheet(QString::fromUtf8("background-color:rgb(245,245,207);\n"
""));
        tabWidget = new QTabWidget(LoginPage);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 10, 391, 481));
        tabWidget->setStyleSheet(QString::fromUtf8("font: 20pt \"Tw Cen MT Condensed Extra Bold\";\n"
"font-color:black;\n"
""));
        tab = new QWidget();
        tab->setObjectName("tab");
        username = new QLineEdit(tab);
        username->setObjectName("username");
        username->setGeometry(QRect(150, 80, 221, 41));
        password = new QLineEdit(tab);
        password->setObjectName("password");
        password->setGeometry(QRect(150, 140, 221, 41));
        singin = new QPushButton(tab);
        singin->setObjectName("singin");
        singin->setGeometry(QRect(10, 370, 151, 41));
        singin->setStyleSheet(QString::fromUtf8("background-color : rgb(170, 0, 255);\n"
"font: 20pt \"Tw Cen MT Condensed Extra Bold\";\n"
"font-color:black;\n"
"border-radius:20%;\n"
"\n"
""));
        password_3 = new QLineEdit(tab);
        password_3->setObjectName("password_3");
        password_3->setGeometry(QRect(150, 200, 221, 41));
        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 260, 301, 81));
        label_5->setStyleSheet(QString::fromUtf8("color : red;\n"
"font-size : 15px;\n"
""));
        label_5->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_9 = new QLabel(tab);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(180, 370, 181, 31));
        label_9->setStyleSheet(QString::fromUtf8("color : red;\n"
"font-size : 15px;\n"
""));
        label_9->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_10 = new QLabel(tab);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 80, 131, 51));
        label_10->setStyleSheet(QString::fromUtf8("\n"
"font: 20pt \"Tw Cen MT Condensed Extra Bold\";\n"
"\n"
""));
        label_10->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_11 = new QLabel(tab);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 140, 131, 41));
        label_11->setStyleSheet(QString::fromUtf8("font: 20pt \"Tw Cen MT Condensed Extra Bold\";\n"
"font-color:rgb(170, 0, 255);\n"
""));
        label_11->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_12 = new QLabel(tab);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(80, 10, 191, 51));
        label_12->setStyleSheet(QString::fromUtf8("font: 30pt \"Tw Cen MT Condensed Extra Bold\";\n"
"font-color:black;\n"
""));
        label_12->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        tabWidget->addTab(tab, QString());
        Tab2 = new QWidget();
        Tab2->setObjectName("Tab2");
        username_2 = new QLineEdit(Tab2);
        username_2->setObjectName("username_2");
        username_2->setGeometry(QRect(150, 100, 221, 41));
        password_2 = new QLineEdit(Tab2);
        password_2->setObjectName("password_2");
        password_2->setGeometry(QRect(150, 150, 221, 41));
        login = new QPushButton(Tab2);
        login->setObjectName("login");
        login->setGeometry(QRect(20, 360, 151, 41));
        login->setStyleSheet(QString::fromUtf8("background-color : rgb(170, 0, 255);\n"
"font: 20pt \"Tw Cen MT Condensed Extra Bold\";\n"
"font-color:black;\n"
"border-radius:20%;\n"
"\n"
""));
        label_6 = new QLabel(Tab2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 90, 131, 51));
        label_6->setStyleSheet(QString::fromUtf8("font: 20pt \"Tw Cen MT Condensed Extra Bold\";\n"
"font-color:black;\n"
""));
        label_6->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_7 = new QLabel(Tab2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 150, 131, 41));
        label_7->setStyleSheet(QString::fromUtf8("font: 20pt \"Tw Cen MT Condensed Extra Bold\";\n"
"font-color:black;\n"
""));
        label_7->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_8 = new QLabel(Tab2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(50, 220, 281, 121));
        label_8->setStyleSheet(QString::fromUtf8("color : red;\n"
"font-size : 15px;\n"
""));
        label_8->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        pushButton = new QPushButton(Tab2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(232, 368, 121, 41));
        label_13 = new QLabel(Tab2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(70, 10, 211, 51));
        label_13->setStyleSheet(QString::fromUtf8("font: 30pt \"Tw Cen MT Condensed Extra Bold\";\n"
"font-color:black;\n"
""));
        label_13->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        tabWidget->addTab(Tab2, QString());

        retranslateUi(LoginPage);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QWidget *LoginPage)
    {
        LoginPage->setWindowTitle(QCoreApplication::translate("LoginPage", "Form", nullptr));
        singin->setText(QCoreApplication::translate("LoginPage", "Sign in", nullptr));
        label_5->setText(QString());
        label_9->setText(QString());
        label_10->setText(QCoreApplication::translate("LoginPage", "Username", nullptr));
        label_11->setText(QCoreApplication::translate("LoginPage", "Password", nullptr));
        label_12->setText(QCoreApplication::translate("LoginPage", "Sign page", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("LoginPage", "sing in", nullptr));
        login->setText(QCoreApplication::translate("LoginPage", "login", nullptr));
        label_6->setText(QCoreApplication::translate("LoginPage", "Username", nullptr));
        label_7->setText(QCoreApplication::translate("LoginPage", "Password", nullptr));
        label_8->setText(QString());
        pushButton->setText(QCoreApplication::translate("LoginPage", "\331\210\330\261\331\210\330\257 \330\263\330\261\333\214\330\271", nullptr));
        label_13->setText(QCoreApplication::translate("LoginPage", "Login page", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Tab2), QCoreApplication::translate("LoginPage", "login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
