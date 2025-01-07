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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_selectMap
{
public:
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *selectMap)
    {
        if (selectMap->objectName().isEmpty())
            selectMap->setObjectName("selectMap");
        selectMap->resize(1200, 700);
        selectMap->setMinimumSize(QSize(1200, 700));
        selectMap->setMaximumSize(QSize(1210, 710));
        selectMap->setSizeIncrement(QSize(1200, 700));
        selectMap->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(selectMap);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 10, 83, 29));
        pushButton->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 0, 0);"));
        checkBox = new QCheckBox(selectMap);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(380, 0, 201, 101));
        checkBox->setStyleSheet(QString::fromUtf8("font: 700 30pt \"Script MT Bold\";"));
        checkBox->setCheckable(true);
        checkBox->setChecked(false);
        checkBox_2 = new QCheckBox(selectMap);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(930, 260, 171, 51));
        checkBox_2->setStyleSheet(QString::fromUtf8("font: 700 30pt \"Script MT Bold\";"));
        checkBox_3 = new QCheckBox(selectMap);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setGeometry(QRect(1000, 570, 171, 51));
        checkBox_3->setStyleSheet(QString::fromUtf8("font: 700 30pt \"Script MT Bold\";"));
        pushButton_2 = new QPushButton(selectMap);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(1070, 660, 111, 31));
        pushButton_2->setMaximumSize(QSize(1200, 700));
        label = new QLabel(selectMap);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1200, 700));
        label->setMinimumSize(QSize(1200, 700));
        label->setMaximumSize(QSize(1200, 16777215));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/res/image/S-map.png);"));
        label_2 = new QLabel(selectMap);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 640, 461, 111));
        label_2->setStyleSheet(QString::fromUtf8("font: 700 30pt \"Script MT Bold\";"));
        label->raise();
        pushButton->raise();
        checkBox->raise();
        checkBox_2->raise();
        checkBox_3->raise();
        pushButton_2->raise();
        label_2->raise();

        retranslateUi(selectMap);

        QMetaObject::connectSlotsByName(selectMap);
    } // setupUi

    void retranslateUi(QWidget *selectMap)
    {
        selectMap->setWindowTitle(QCoreApplication::translate("selectMap", "Form", nullptr));
        pushButton->setText(QString());
        checkBox->setText(QCoreApplication::translate("selectMap", " map 1", nullptr));
        checkBox_2->setText(QCoreApplication::translate("selectMap", " map 2", nullptr));
        checkBox_3->setText(QCoreApplication::translate("selectMap", " map 3", nullptr));
        pushButton_2->setText(QCoreApplication::translate("selectMap", "change text", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("selectMap", "In the next updates\n"
"", nullptr));
    } // retranslateUi

};

namespace Ui {
    class selectMap: public Ui_selectMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTMAP_H
