#include "loginpage.h"
#include "QMessageBox"
#include "mainwindow.h"
#include "ui_loginpage.h"

LoginPage::LoginPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/Computer engineering/Qt/project/Battle-of-ships/DataGame.db");

    if ( db.open() )
    {
        ui->label_9->setText("وصل است");
    }

}

LoginPage::~LoginPage()
{
    delete ui;
}

bool checkUsername(const QString &username) {
    QSqlQuery query;
    query.prepare("SELECT * FROM user WHERE username = :username");
    query.bindValue(":username", username);


    if (query.exec() && query.next())
    {
        return true;
    }
    return false;
}


void LoginPage::on_singin_clicked()
{

    QString username = ui->username->text();
    QString password = ui->password->text();
    QString password2 = ui->password_3->text();
    QString eror = "";

    if ( !checkUsername(username) && username.size() > 6 )
    {
        if ( password == password2 )
        {
            if ( password.size() > 8 )
            {
                QSqlQuery query;
                query.prepare("INSERT INTO user (username, password) VALUES (:username, :password)");
                query.bindValue(":username", username);
                query.bindValue(":password", password);

                if (query.exec()) {
                    ui->label_5->setText("ثبت نام موفق امیز بود");
                } else {
                    ui->label_5->setText("ثبت نام ناموفق بود");
                }
            }
            else
            {
                eror =+ "رمز عبور باید طولانی تر باشه \n";
            }
        }
        else
        {
            eror =+ "رمز عبور های وارد شده مشابه هم نیستند \n";
        }
    }
    else
    {
        eror =+ "نام کاربری تکراری است \n";
    }
    ui->label_5->setText(eror);
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
        MainWindow *m = new MainWindow();
        m->show();
        this->close();
    } else {
        ui->label_8->setText("نام کاربری یا رمز عبور نادرست است");
    }

}

