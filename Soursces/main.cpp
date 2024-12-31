#include "Header/loginpage.h"
#include "Header/mainwindow.h"
#include "Header/selectmap.h"
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
