#include "gamepage.h"
#include "mainwindow.h"
#include "qpropertyanimation.h"
#include "ui_gamepage.h"
#include <QThread>
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>


void Gamepage::addMatrix()
{
    int startX = 100;
    int endX = 600;
    int startY = 200;
    int endY = 1100;
    int step = 100;
    int i , j;
    i = 1;
    for (int x = startX; x <= endX; x += step)
    {
        j = 1;
        for (int y = startY; y <= endY; y += step)
        {
            matrix[{i, j}] = {y, x};
            j++;
        }
        i++;
    }
}

Gamepage::Gamepage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gamepage)
{
    ui->setupUi(this);
    addMatrix();

    QSequentialAnimationGroup *animationGroup;
    animationGroup = new QSequentialAnimationGroup(this);
    QPropertyAnimation *animation1 = new QPropertyAnimation(ui->label, "geometry");
    animation1->setDuration(2000);
    animation1->setStartValue(QRect(matrix[{1,1}].first, matrix[{1,1}].second, ui->label->width(), ui->label->height()));
    animation1->setEndValue(QRect(matrix[{1,2}].first, matrix[{1,2}].second, ui->label->width(), ui->label->height()));
    QPropertyAnimation *animation2 = new QPropertyAnimation(ui->label, "geometry");
    animation2->setDuration(2000);
    animation2->setStartValue(QRect(matrix[{1,2}].first, matrix[{1,2}].second, ui->label->width(), ui->label->height()));
    animation2->setEndValue(QRect(matrix[{1,3}].first, matrix[{1,3}].second, ui->label->width(), ui->label->height()));
    QPropertyAnimation *animation3 = new QPropertyAnimation(ui->label, "geometry");
    animation3->setDuration(2000);
    animation3->setStartValue(QRect(matrix[{1,3}].first, matrix[{1,3}].second, ui->label->width(), ui->label->height()));
    animation3->setEndValue(QRect(matrix[{1,4}].first, matrix[{1,4}].second, ui->label->width(), ui->label->height()));
    QPropertyAnimation *animation4 = new QPropertyAnimation(ui->label, "geometry");
    animation4->setDuration(2000);
    animation4->setStartValue(QRect(matrix[{1,4}].first, matrix[{1,4}].second, ui->label->width(), ui->label->height()));
    animation4->setEndValue(QRect(matrix[{1,5}].first, matrix[{1,5}].second, ui->label->width(), ui->label->height()));

    QPropertyAnimation *animation5 = new QPropertyAnimation(ui->label, "geometry");
    animation5->setDuration(2000);
    animation5->setStartValue(QRect(matrix[{1,5}].first, matrix[{1,5}].second, ui->label->width(), ui->label->height()));
    animation5->setEndValue(QRect(matrix[{1,6}].first, matrix[{1,6}].second, ui->label->width(), ui->label->height()));

    animationGroup->addAnimation(animation1);
    animationGroup->addAnimation(animation2);
    animationGroup->addAnimation(animation3);
    animationGroup->addAnimation(animation4);
    animationGroup->addAnimation(animation5);


    animationGroup->start();
}


Gamepage::~Gamepage()
{
    delete ui;
}

void Gamepage::on_pushButton_clicked()
{
    MainWindow *m = new MainWindow();
    m->show();
    this->close();
}


