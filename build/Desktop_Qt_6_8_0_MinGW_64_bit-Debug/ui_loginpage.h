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
    QWidget *tab_2;
    QLineEdit *username_2;
    QLineEdit *password_2;
    QPushButton *login;
    QLabel *label;

    void setupUi(QWidget *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName("LoginPage");
        LoginPage->resize(409, 484);
        LoginPage->setMaximumSize(QSize(409, 484));
        LoginPage->setStyleSheet(QString::fromUtf8("background : rgb(117, 225, 255);"));
        tabWidget = new QTabWidget(LoginPage);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 20, 361, 391));
        tab = new QWidget();
        tab->setObjectName("tab");
        username = new QLineEdit(tab);
        username->setObjectName("username");
        username->setGeometry(QRect(20, 30, 221, 41));
        password = new QLineEdit(tab);
        password->setObjectName("password");
        password->setGeometry(QRect(20, 80, 221, 41));
        singin = new QPushButton(tab);
        singin->setObjectName("singin");
        singin->setGeometry(QRect(100, 150, 151, 41));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        username_2 = new QLineEdit(tab_2);
        username_2->setObjectName("username_2");
        username_2->setGeometry(QRect(40, 30, 221, 41));
        password_2 = new QLineEdit(tab_2);
        password_2->setObjectName("password_2");
        password_2->setGeometry(QRect(40, 90, 221, 41));
        login = new QPushButton(tab_2);
        login->setObjectName("login");
        login->setGeometry(QRect(100, 160, 151, 41));
        tabWidget->addTab(tab_2, QString());
        label = new QLabel(LoginPage);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 430, 141, 31));

        retranslateUi(LoginPage);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QWidget *LoginPage)
    {
        LoginPage->setWindowTitle(QCoreApplication::translate("LoginPage", "Form", nullptr));
        singin->setText(QCoreApplication::translate("LoginPage", "PushButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("LoginPage", "Tab 1", nullptr));
        login->setText(QCoreApplication::translate("LoginPage", "PushButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("LoginPage", "Tab 2", nullptr));
        label->setText(QCoreApplication::translate("LoginPage", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
