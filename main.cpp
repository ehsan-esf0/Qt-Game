#include "loginpage.h"
#include "mainwindow.h"
#include "selectmap.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();

    LoginPage l;
    l.show();


    return a.exec();
}
