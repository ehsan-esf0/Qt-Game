#include "mainwindow.h"
#include "gamepage.h"
#include "selectmap.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Gamepage *game = new Gamepage();
    game->show();
    this->close();
}


void MainWindow::on_pushButton_3_clicked()
{
    selectMap *s = new selectMap();
    s->show();
    this->close();
}

