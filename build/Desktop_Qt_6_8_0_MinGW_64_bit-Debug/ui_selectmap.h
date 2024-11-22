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
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_selectMap
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QScrollBar *horizontalScrollBar;
    QProgressBar *progressBar;
    QLabel *label_4;
    QPushButton *pushButton_2;

    void setupUi(QWidget *selectMap)
    {
        if (selectMap->objectName().isEmpty())
            selectMap->setObjectName("selectMap");
        selectMap->resize(1200, 700);
        selectMap->setMaximumSize(QSize(1200, 700));
        selectMap->setSizeIncrement(QSize(1200, 700));
        selectMap->setStyleSheet(QString::fromUtf8("background-color : rgb(105, 210, 255);"));
        label = new QLabel(selectMap);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 100, 291, 261));
        label->setStyleSheet(QString::fromUtf8("background-color : rgb(255, 237, 202);\n"
"color : rgb(0, 0, 0);"));
        label_2 = new QLabel(selectMap);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(450, 100, 291, 261));
        label_2->setStyleSheet(QString::fromUtf8("background-color : rgb(255, 237, 202);\n"
"color : rgb(0, 0, 0);"));
        label_3 = new QLabel(selectMap);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(810, 100, 291, 261));
        label_3->setStyleSheet(QString::fromUtf8("background-color : rgb(255, 237, 202);\n"
"color : rgb(0, 0, 0);"));
        pushButton = new QPushButton(selectMap);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 10, 83, 29));
        pushButton->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 0, 0);"));
        checkBox = new QCheckBox(selectMap);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(200, 370, 93, 26));
        checkBox->setCheckable(true);
        checkBox->setChecked(false);
        checkBox_2 = new QCheckBox(selectMap);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(550, 370, 93, 26));
        checkBox_3 = new QCheckBox(selectMap);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setGeometry(QRect(920, 370, 93, 26));
        horizontalScrollBar = new QScrollBar(selectMap);
        horizontalScrollBar->setObjectName("horizontalScrollBar");
        horizontalScrollBar->setGeometry(QRect(100, 630, 611, 31));
        horizontalScrollBar->setMaximum(100);
        horizontalScrollBar->setValue(60);
        horizontalScrollBar->setOrientation(Qt::Orientation::Horizontal);
        progressBar = new QProgressBar(selectMap);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(100, 570, 171, 41));
        progressBar->setValue(60);
        label_4 = new QLabel(selectMap);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(340, 530, 63, 20));
        pushButton_2 = new QPushButton(selectMap);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(1060, 640, 111, 31));
        pushButton_2->setMaximumSize(QSize(1200, 700));

        retranslateUi(selectMap);
        QObject::connect(horizontalScrollBar, &QScrollBar::sliderMoved, progressBar, &QProgressBar::setValue);

        QMetaObject::connectSlotsByName(selectMap);
    } // setupUi

    void retranslateUi(QWidget *selectMap)
    {
        selectMap->setWindowTitle(QCoreApplication::translate("selectMap", "Form", nullptr));
        label->setText(QCoreApplication::translate("selectMap", "                  1", nullptr));
        label_2->setText(QCoreApplication::translate("selectMap", "                  2", nullptr));
        label_3->setText(QCoreApplication::translate("selectMap", "                    3", nullptr));
        pushButton->setText(QString());
        checkBox->setText(QCoreApplication::translate("selectMap", "map 1", nullptr));
        checkBox_2->setText(QCoreApplication::translate("selectMap", "map 2", nullptr));
        checkBox_3->setText(QCoreApplication::translate("selectMap", "map 3", nullptr));
        label_4->setText(QCoreApplication::translate("selectMap", "TextLabel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("selectMap", "change text", nullptr));
    } // retranslateUi

};

namespace Ui {
    class selectMap: public Ui_selectMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTMAP_H
