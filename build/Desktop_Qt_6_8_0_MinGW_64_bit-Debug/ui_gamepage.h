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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gamepage
{
public:
    QLabel *label;

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
        label->setGeometry(QRect(500, 10, 231, 41));
        label->setStyleSheet(QString::fromUtf8("color : rgb(0, 0, 0);\n"
"font-size : 20px;\n"
""));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(Gamepage);

        QMetaObject::connectSlotsByName(Gamepage);
    } // setupUi

    void retranslateUi(QWidget *Gamepage)
    {
        Gamepage->setWindowTitle(QCoreApplication::translate("Gamepage", "Game", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Gamepage: public Ui_Gamepage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPAGE_H
