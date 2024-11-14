#include "loginpage.h"
#include "QMessageBox"
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

void LoginPage::on_singin_clicked()
{

    QString username = ui->username->text();
    QString password = ui->password->text();

    QSqlQuery query;
    query.prepare("INSERT INTO user (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec()) {
        QMessageBox::information(nullptr,"موفقیت", "اطلاعات با موفقیت ذخیره شد");
    } else {
        QMessageBox::critical(nullptr, "خطا", query.lastError().text());
    }
}


void LoginPage::on_login_clicked()
{
    QString username = ui->username_2->text();
    QString password = ui->password_2->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM user WHERE username = :u AND password = :p ");
    query.bindValue(":u", username);
    query.bindValue(":p", password);

    if (query.exec() && query.next()) {
        QMessageBox::information(nullptr,"موفقیت", "ورود");
    } else {
        QMessageBox::critical(nullptr, "خطا", query.lastError().text());
    }

}

