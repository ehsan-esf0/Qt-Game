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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginPage
{
public:
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;
    QLineEdit *usernameLineEdit_2;
    QPushButton *loginButton_2;
    QLineEdit *passwordLineEdit_2;

    void setupUi(QWidget *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName("LoginPage");
        LoginPage->resize(400, 300);
        usernameLineEdit = new QLineEdit(LoginPage);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setGeometry(QRect(40, 70, 113, 28));
        passwordLineEdit = new QLineEdit(LoginPage);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(40, 120, 113, 28));
        loginButton = new QPushButton(LoginPage);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(60, 180, 83, 29));
        usernameLineEdit_2 = new QLineEdit(LoginPage);
        usernameLineEdit_2->setObjectName("usernameLineEdit_2");
        usernameLineEdit_2->setGeometry(QRect(230, 70, 113, 28));
        loginButton_2 = new QPushButton(LoginPage);
        loginButton_2->setObjectName("loginButton_2");
        loginButton_2->setGeometry(QRect(250, 180, 83, 29));
        passwordLineEdit_2 = new QLineEdit(LoginPage);
        passwordLineEdit_2->setObjectName("passwordLineEdit_2");
        passwordLineEdit_2->setGeometry(QRect(230, 120, 113, 28));

        retranslateUi(LoginPage);

        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QWidget *LoginPage)
    {
        LoginPage->setWindowTitle(QCoreApplication::translate("LoginPage", "Form", nullptr));
        usernameLineEdit->setText(QString());
        passwordLineEdit->setText(QString());
        loginButton->setText(QCoreApplication::translate("LoginPage", "login", nullptr));
        usernameLineEdit_2->setText(QString());
        loginButton_2->setText(QCoreApplication::translate("LoginPage", "sign in", nullptr));
        passwordLineEdit_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
