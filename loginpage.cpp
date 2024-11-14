#include "loginpage.h"
#include "ui_loginpage.h"

LoginPage::LoginPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/Computer engineering/Qt/project/Battle-of-ships/DataGame.db");

    if (db.open())
    {
        ui->label->setText("connect");
    }
    else {
        ui->label->setText("dis connect");
    }
}

LoginPage::~LoginPage()
{
    delete ui;
}
