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
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Gamepage)
    {
        if (Gamepage->objectName().isEmpty())
            Gamepage->setObjectName("Gamepage");
        Gamepage->resize(1200, 700);
        Gamepage->setMinimumSize(QSize(1200, 700));
        Gamepage->setMaximumSize(QSize(1350, 700));
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
        label_3 = new QLabel(Gamepage);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(480, 0, 401, 111));
        label_3->setStyleSheet(QString::fromUtf8("background: url(:/res/image/End-1.png);"));
        pushButton = new QPushButton(Gamepage);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(540, 110, 141, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background: url(:/res/image/End-3.png);"));
        pushButton_3 = new QPushButton(Gamepage);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(690, 110, 141, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("background: url(:/res/image/End-2.png);"));

        retranslateUi(Gamepage);

        QMetaObject::connectSlotsByName(Gamepage);
    } // setupUi

    void retranslateUi(QWidget *Gamepage)
    {
        Gamepage->setWindowTitle(QCoreApplication::translate("Gamepage", "Game", nullptr));
        label->setText(QString());
        pushButton_2->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        pushButton->setText(QString());
        pushButton_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Gamepage: public Ui_Gamepage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPAGE_H
