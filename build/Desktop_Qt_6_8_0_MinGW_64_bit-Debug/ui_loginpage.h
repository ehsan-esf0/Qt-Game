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
    QLabel *labeu;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *password_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_9;
    QWidget *Tab2;
    QLineEdit *username_2;
    QLineEdit *password_2;
    QPushButton *login;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton;

    void setupUi(QWidget *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName("LoginPage");
        LoginPage->resize(409, 484);
        LoginPage->setMaximumSize(QSize(409, 484));
        LoginPage->setStyleSheet(QString::fromUtf8("background:url(:/res/image/Untitled-3.png);\n"
""));
        tabWidget = new QTabWidget(LoginPage);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 10, 391, 461));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab = new QWidget();
        tab->setObjectName("tab");
        username = new QLineEdit(tab);
        username->setObjectName("username");
        username->setGeometry(QRect(20, 80, 221, 41));
        password = new QLineEdit(tab);
        password->setObjectName("password");
        password->setGeometry(QRect(20, 140, 221, 41));
        singin = new QPushButton(tab);
        singin->setObjectName("singin");
        singin->setGeometry(QRect(10, 370, 151, 41));
        singin->setStyleSheet(QString::fromUtf8("background-color : rgb(170, 0, 255);\n"
"font-color : 20px;\n"
"font-size : 18px;\n"
""));
        labeu = new QLabel(tab);
        labeu->setObjectName("labeu");
        labeu->setGeometry(QRect(250, 80, 121, 41));
        labeu->setStyleSheet(QString::fromUtf8("color : black;\n"
"font-size : 20px;\n"
""));
        labeu->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(250, 130, 121, 41));
        label_2->setStyleSheet(QString::fromUtf8("color : black;\n"
"font-size : 20px;\n"
""));
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(150, 10, 121, 41));
        label_3->setStyleSheet(QString::fromUtf8("color : black;\n"
"font-size : 20px;\n"
""));
        label_3->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        password_3 = new QLineEdit(tab);
        password_3->setObjectName("password_3");
        password_3->setGeometry(QRect(20, 200, 221, 41));
        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(250, 190, 121, 41));
        label_4->setStyleSheet(QString::fromUtf8("color : black;\n"
"font-size : 20px;\n"
""));
        label_4->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
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
        tabWidget->addTab(tab, QString());
        Tab2 = new QWidget();
        Tab2->setObjectName("Tab2");
        username_2 = new QLineEdit(Tab2);
        username_2->setObjectName("username_2");
        username_2->setGeometry(QRect(30, 60, 221, 41));
        password_2 = new QLineEdit(Tab2);
        password_2->setObjectName("password_2");
        password_2->setGeometry(QRect(30, 120, 221, 41));
        login = new QPushButton(Tab2);
        login->setObjectName("login");
        login->setGeometry(QRect(20, 360, 151, 41));
        login->setStyleSheet(QString::fromUtf8("background-color : rgb(170, 0, 255);\n"
"font-color : 20px;\n"
"font-size : 18px;\n"
""));
        label_6 = new QLabel(Tab2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(260, 60, 121, 41));
        label_6->setStyleSheet(QString::fromUtf8("color : black;\n"
"font-size : 20px;\n"
""));
        label_6->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_7 = new QLabel(Tab2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(260, 110, 121, 41));
        label_7->setStyleSheet(QString::fromUtf8("color : black;\n"
"font-size : 20px;\n"
""));
        label_7->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_8 = new QLabel(Tab2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(50, 180, 281, 31));
        label_8->setStyleSheet(QString::fromUtf8("color : red;\n"
"font-size : 15px;\n"
""));
        label_8->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        pushButton = new QPushButton(Tab2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(232, 368, 121, 41));
        tabWidget->addTab(Tab2, QString());

        retranslateUi(LoginPage);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QWidget *LoginPage)
    {
        LoginPage->setWindowTitle(QCoreApplication::translate("LoginPage", "Form", nullptr));
        singin->setText(QCoreApplication::translate("LoginPage", "Sign in", nullptr));
        labeu->setText(QCoreApplication::translate("LoginPage", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214", nullptr));
        label_2->setText(QCoreApplication::translate("LoginPage", "\330\261\331\205\330\262 \330\271\330\250\331\210\330\261", nullptr));
        label_3->setText(QCoreApplication::translate("LoginPage", "\331\201\330\261\331\205 \330\253\330\250\330\252 \331\206\330\247\331\205", nullptr));
        label_4->setText(QCoreApplication::translate("LoginPage", "\330\252\332\251\330\261\330\247\330\261 \330\261\331\205\330\262 \330\271\330\250\331\210\330\261", nullptr));
        label_5->setText(QString());
        label_9->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("LoginPage", "sing in", nullptr));
        login->setText(QCoreApplication::translate("LoginPage", "login", nullptr));
        label_6->setText(QCoreApplication::translate("LoginPage", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214", nullptr));
        label_7->setText(QCoreApplication::translate("LoginPage", "\330\261\331\205\330\262 \330\271\330\250\331\210\330\261", nullptr));
        label_8->setText(QString());
        pushButton->setText(QCoreApplication::translate("LoginPage", "\331\210\330\261\331\210\330\257 \330\263\330\261\333\214\330\271", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Tab2), QCoreApplication::translate("LoginPage", "login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
