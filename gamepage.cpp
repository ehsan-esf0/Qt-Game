#include "gamepage.h"
#include "ui_gamepage.h"

Gamepage::Gamepage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Gamepage)
{
    ui->setupUi(this);
}

Gamepage::~Gamepage()
{
    delete ui;
}
