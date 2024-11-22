#include "selectmap.h"
#include "gamepage.h"
#include "mainwindow.h"
#include "savegamedata.h"
#include "ui_selectmap.h"
#include <QPushButton>

selectMap::selectMap(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::selectMap)
{
    ui->setupUi(this);
    switch (saveGameData::mapNumber) {
    case 1:
        ui->checkBox->setChecked(true);
        break;
    case 2:
        ui->checkBox_2->setChecked(true);
        break;
    case 3:
        ui->checkBox_3->setChecked(true);
        break;
    default:
        ui->checkBox->setChecked(true);
        break;
    }

    if ( saveGameData::speed != 0 )
    {
        ui->progressBar->setValue(saveGameData::speed);
        ui->horizontalScrollBar->setValue(saveGameData::speed);
    }
    else {
        saveGameData::speed = ui->progressBar->value();
    }
}


void selectMap::on_pushButton_2_clicked()
{
    saveGameData::str = "sad";
}

void selectMap::on_pushButton_clicked()
{
    MainWindow *menu = new MainWindow();
    menu->show();
    this->close();
}


void selectMap::on_checkBox_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    saveGameData::mapNumber = 1;
}


void selectMap::on_checkBox_2_clicked()
{
    ui->checkBox->setChecked(false);
    ui->checkBox_3->setChecked(false);
    saveGameData::mapNumber = 2;
}


void selectMap::on_checkBox_3_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox->setChecked(false);
    saveGameData::mapNumber = 3;
}


void selectMap::on_horizontalScrollBar_actionTriggered(int action)
{

}


void selectMap::on_progressBar_valueChanged(int value)
{
    saveGameData::speed = value;
    QString number = QString::number(saveGameData::speed);
    ui->label_4->setText(number);

}

