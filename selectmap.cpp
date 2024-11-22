#include "selectmap.h"
#include "gamepage.h"
#include "ui_selectmap.h"
#include <QPushButton>

selectMap::selectMap(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::selectMap)
{
    ui->setupUi(this);
}


void selectMap::on_pushButton_2_clicked()
{
    switch (rand() % 10) {
    case 0:
        Gamepage::label_2->setText("W");
        break;
    case 1:
        Gamepage::label_2->setText("E");
        break;
    case 2:
        Gamepage::label_2->setText("R");
        break;
    case 3:
        Gamepage::label_2->setText("T");
        break;
    case 4:
        Gamepage::label_2->setText("Y");
        break;
    case 5:
        Gamepage::label_2->setText("U");
        break;
    case 6:
        Gamepage::label_2->setText("I");
        break;
    default:
        break;
    }
}
