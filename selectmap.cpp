#include "selectmap.h"
#include "gamepage.h"
#include "mainwindow.h"
#include "savegamedata.h"
#include "ui_selectmap.h"
#include <QPushButton>

QString saveGameData::str = nullptr;

selectMap::selectMap(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::selectMap)
{
    ui->setupUi(this);
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

