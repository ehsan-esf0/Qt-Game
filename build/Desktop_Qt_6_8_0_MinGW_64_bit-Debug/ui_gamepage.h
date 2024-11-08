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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gamepage
{
public:
    QLabel *label;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QWidget *Gamepage)
    {
        if (Gamepage->objectName().isEmpty())
            Gamepage->setObjectName("Gamepage");
        Gamepage->resize(1200, 700);
        Gamepage->setMinimumSize(QSize(1200, 700));
        Gamepage->setMaximumSize(QSize(1200, 700));
        Gamepage->setStyleSheet(QString::fromUtf8("background-color : rgb(105, 210, 255);"));
        label = new QLabel(Gamepage);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 590, 71, 71));
        label->setStyleSheet(QString::fromUtf8("background-color : rgb(30, 45, 127);"));
        groupBox = new QGroupBox(Gamepage);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 50, 100, 600));
        groupBox->setMinimumSize(QSize(100, 600));
        groupBox->setMaximumSize(QSize(100, 600));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 90, 81, 81));
        label_2->setStyleSheet(QString::fromUtf8("background-color :rgb(0, 85, 127);"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 190, 81, 81));
        label_3->setStyleSheet(QString::fromUtf8("background-color :rgb(0, 85, 127);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 290, 81, 81));
        label_4->setStyleSheet(QString::fromUtf8("background-color :rgb(0, 85, 127);"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 390, 81, 81));
        label_5->setStyleSheet(QString::fromUtf8("background-color :rgb(0, 85, 127);"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 490, 81, 81));
        label_6->setStyleSheet(QString::fromUtf8("background-color :rgb(0, 85, 127);"));
        pushButton = new QPushButton(Gamepage);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 10, 83, 29));
        label_7 = new QLabel(Gamepage);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 660, 31, 31));
        label_7->setStyleSheet(QString::fromUtf8("background-color : rgb(30, 45, 127);"));
        label_8 = new QLabel(Gamepage);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(50, 660, 61, 31));
        label_8->setStyleSheet(QString::fromUtf8("background-color : rgb(30, 45, 127);"));

        retranslateUi(Gamepage);

        QMetaObject::connectSlotsByName(Gamepage);
    } // setupUi

    void retranslateUi(QWidget *Gamepage)
    {
        Gamepage->setWindowTitle(QCoreApplication::translate("Gamepage", "Game", nullptr));
        label->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("Gamepage", "GroupBox", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        pushButton->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Gamepage: public Ui_Gamepage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPAGE_H
