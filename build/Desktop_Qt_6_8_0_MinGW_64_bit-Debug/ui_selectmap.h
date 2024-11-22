/********************************************************************************
** Form generated from reading UI file 'selectmap.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTMAP_H
#define UI_SELECTMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_selectMap
{
public:
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QWidget *selectMap)
    {
        if (selectMap->objectName().isEmpty())
            selectMap->setObjectName("selectMap");
        selectMap->resize(1200, 700);
        selectMap->setMaximumSize(QSize(1200, 700));
        selectMap->setSizeIncrement(QSize(1200, 700));
        selectMap->setStyleSheet(QString::fromUtf8("background-color : rgb(105, 210, 255);"));
        pushButton_2 = new QPushButton(selectMap);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(1080, 660, 111, 31));
        pushButton_2->setMaximumSize(QSize(1200, 700));
        label = new QLabel(selectMap);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 100, 291, 261));
        label->setStyleSheet(QString::fromUtf8("background-color : rgb(255, 237, 202);"));
        label_2 = new QLabel(selectMap);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(450, 100, 291, 261));
        label_2->setStyleSheet(QString::fromUtf8("background-color : rgb(255, 237, 202);"));
        label_3 = new QLabel(selectMap);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(810, 100, 291, 261));
        label_3->setStyleSheet(QString::fromUtf8("background-color : rgb(255, 237, 202);"));
        pushButton = new QPushButton(selectMap);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 10, 83, 29));
        pushButton->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 0, 0);"));

        retranslateUi(selectMap);

        QMetaObject::connectSlotsByName(selectMap);
    } // setupUi

    void retranslateUi(QWidget *selectMap)
    {
        selectMap->setWindowTitle(QCoreApplication::translate("selectMap", "Form", nullptr));
        pushButton_2->setText(QCoreApplication::translate("selectMap", "change text", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class selectMap: public Ui_selectMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTMAP_H
