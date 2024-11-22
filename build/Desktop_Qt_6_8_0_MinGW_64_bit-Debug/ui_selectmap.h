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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_selectMap
{
public:
    QPushButton *pushButton_2;

    void setupUi(QWidget *selectMap)
    {
        if (selectMap->objectName().isEmpty())
            selectMap->setObjectName("selectMap");
        selectMap->resize(259, 132);
        pushButton_2 = new QPushButton(selectMap);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 20, 221, 91));

        retranslateUi(selectMap);

        QMetaObject::connectSlotsByName(selectMap);
    } // setupUi

    void retranslateUi(QWidget *selectMap)
    {
        selectMap->setWindowTitle(QCoreApplication::translate("selectMap", "Form", nullptr));
        pushButton_2->setText(QCoreApplication::translate("selectMap", "change text", nullptr));
    } // retranslateUi

};

namespace Ui {
    class selectMap: public Ui_selectMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTMAP_H
