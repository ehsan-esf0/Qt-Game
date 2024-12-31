/********************************************************************************
** Form generated from reading UI file 'gamepage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEPAGE_H
#define UI_GAMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gamepage
{
public:
    QLabel *label;
    QPushButton *pushButton_2;
    QLabel *label_2;

    void setupUi(QWidget *Gamepage)
    {
        if (Gamepage->objectName().isEmpty())
            Gamepage->setObjectName("Gamepage");
        Gamepage->resize(1200, 700);
        Gamepage->setMinimumSize(QSize(1200, 700));
        Gamepage->setMaximumSize(QSize(1400, 700));
        Gamepage->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(Gamepage);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 10, 231, 41));
        label->setStyleSheet(QString::fromUtf8("color : rgb(0, 0, 0);\n"
"font-size : 20px;\n"
""));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton_2 = new QPushButton(Gamepage);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 10, 83, 29));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 0, 0);"));
        label_2 = new QLabel(Gamepage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(1200, 0, 200, 900));
        label_2->setStyleSheet(QString::fromUtf8("background : url(:/res/image/menu-lvl.png);"));

        retranslateUi(Gamepage);

        QMetaObject::connectSlotsByName(Gamepage);
    } // setupUi

    void retranslateUi(QWidget *Gamepage)
    {
        Gamepage->setWindowTitle(QCoreApplication::translate("Gamepage", "Game", nullptr));
        label->setText(QString());
        pushButton_2->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Gamepage: public Ui_Gamepage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPAGE_H
