#include "Header/gamepage.h"
#include "Header/bomb.h"
#include "Header/fighter298.h"
#include "Header/fighter111.h"
#include "Header/ice_bomb.h"
#include "Header/mainwindow.h"
#include "Header/turret_q8m.h"
#include "qpropertyanimation.h"
#include "Header/savegamedata.h"
#include "Header/selectmap.h"
#include "Header/towerdestroyer.h"
#include "Header/bombdisabler.h"
#include "Header/towerdisabler.h"
#include "Header/turret_q8.h"
#include "Header/turret_q8f.h"
#include "Header/turret_q8r.h"
#include "ui_gamepage.h"
#include <QThread>
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>
#include <QLabel>
#include <QTabWidget>
#include <QVBoxLayout>
#include "Header/clickablelabel.h"
#include "QGraphicsOpacityEffect"
#include "QTransform"

QVector<Enemy*> Gamepage::enimi;
QVector<ClickableLabel*> Gamepage::turrets;
QVector<ClickableLabel*> Gamepage::bombs;
 int Gamepage::numberEemey = 0;
 int Gamepage::Score = 0;

void Gamepage::addMatrix()
{
    switch (saveGameData::mapNumber) {
    case 1:
        matrix[{1,1}] = {200 ,700};
        matrix[{1,2}] = {200 ,100};
        matrix[{2,1}] = {1100 ,100};
        matrix[{2,2}] = {1100 ,600};
        break;
    case 2:
        matrix[{1,1}] = {600 ,700};
        matrix[{1,2}] = {600 ,500};
        matrix[{2,1}] = {600 ,200};
        matrix[{2,2}] = {600 ,-10};
        break;
    case 3:
        matrix[{1,1}] = {0 ,600};
        matrix[{1,2}] = {600 ,600};
        matrix[{2,1}] = {600 ,50};
        matrix[{2,2}] = {1200 ,50};
        break;
    default:
        matrix[{1,1}] = {200 ,700};
        matrix[{1,2}] = {200 ,100};
        matrix[{2,1}] = {1100 ,100};
        matrix[{2,2}] = {1100 ,600};
        break;
    }

    matrix2[{0,0}] = {500 ,300};
    matrix2[{0,1}] = {500 ,410};
    matrix2[{0,2}] = {500 ,520};
    matrix2[{0,3}] = {500 ,630};
    matrix2[{1,0}] = {610 ,300};
    matrix2[{1,1}] = {610 ,410};
    matrix2[{1,2}] = {610 ,520};
    matrix2[{1,3}] = {610 ,630};
    matrix2[{2,0}] = {720 ,300};
    matrix2[{2,1}] = {720 ,410};
    matrix2[{2,2}] = {720 ,520};
    matrix2[{2,3}] = {720 ,630};
    matrix2[{3,0}] = {830 ,300};
    matrix2[{3,1}] = {830 ,410};
    matrix2[{3,2}] = {830 ,520};
    matrix2[{3,3}] = {830 ,630};
}

Gamepage::Gamepage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gamepage)
    ,   selectedLabel(nullptr)
{
    enimi.clear();
    turrets.clear();
    bombs.clear();
    numberEemey = 0;
    //enimi.clear();
    enemiesExited = 0;
    ui->setupUi(this);
    addMatrix();
    countWave = 1;
    bossCount = 0;
    labelCount = 1;
    wCount = 20;
    timeCount = 10000;
    icount = 10;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Gamepage::createBlueSquareLabel);
    timer2 = new QTimer(this);
    connect(timer2, &QTimer::timeout, this, &Gamepage::timeLabelText);
    timer->start(500);
    timer4 = new QTimer(this);
    connect(timer4, &QTimer::timeout, this, &Gamepage::ironLabelshow);
    timer->start(10);


    switch (saveGameData::mapNumber) {
    case 1:
        Gamepage::setStyleSheet("background-color : rgb(28, 181, 222);");

        for (int i = 450 ; i <= 850 ; i += 100 ) {

            for (int j = 250 ; j <= 600 ; j += 100 ) {

                createLabelMap( i , j );
                j += 10;
            }
            i += 10;
        }

        labelInMap( 330 , 400 , 100 , 140 , "background: url(:/res/image/tree2.png);" );

        labelInMap( 900 , 500 , 100 , 140 , "background: url(:/res/image/tree2.png);" );

        labelInMap( 900 , 170 , 100 , 140 , "background: url(:/res/image/tree3.png);" );

        labelInMap( 890 , 340 , 60 , 50 , "background: url(:/res/image/shark.png);" );

        labelInMap( 340 , 315 , 60 , 50 , "background: url(:/res/image/shark.png);" );

        labelInMap( 320 , 615 , 70 , 70 , "background: url(:/res/image/stone.png);" );

        labelInMap( 460 , 160 , 70 , 70 , "background: url(:/res/image/stone.png);" );

        labelInMap( 550 , 180 , 70 , 70 , "background: url(:/res/image/stone.png);" );

        break;
    case 2:
        Gamepage::setStyleSheet("background-color : rgb(110, 203, 146);");
        for (int i = 250 ; i <= 450 ; i += 100 ) {

            for (int j = 150 ; j <= 500 ; j += 100 ) {

                createLabelMap( i , j );
                j += 10;
            }
            i += 10;
        }
        for (int i = 800 ; i <= 950 ; i += 100 ) {

            for (int j = 150 ; j <= 500 ; j += 100 ) {
                createLabelMap( i , j );
                j += 10;
            }
            i += 10;
        }
        labelInMap( 1030 , 400 , 150 , 150 , "background: url(:/res/image/tree4.png);" );

        labelInMap( 1030 , 150 , 150 , 150 , "background: url(:/res/image/tree4.png);" );

        labelInMap( 800 , -10 , 150 , 150 , "background: url(:/res/image/tree4.png);" );

        labelInMap( 120 , 550 , 150 , 150 , "background: url(:/res/image/tree4.png);" );

        break;
    case 3:
        for (int i = 250 ; i <= 450 ; i += 100 ) {

            for (int j = 100 ; j <= 450 ; j += 100 ) {

                createLabelMap( i , j );
                j += 10;
            }
            i += 10;
        }
        for (int i = 800 ; i <= 950 ; i += 100 ) {

            for (int j = 200 ; j <= 550 ; j += 100 ) {

                createLabelMap( i , j );
                j += 10;
            }
            i += 10;
        }
        break;
    default:
        Gamepage::setStyleSheet("background-color : rgb(28, 181, 222);");

        for (int i = 450 ; i <= 850 ; i += 100 ) {

            for (int j = 250 ; j <= 600 ; j += 100 ) {

                createLabelMap( i , j );
                j += 10;
            }
            i += 10;
        }
        for (int i = 450 ; i <= 850 ; i += 100 ) {

            for (int j = 250 ; j <= 600 ; j += 100 ) {

                createLabelMapUpdate( i + 20 , j + 85 );
                j += 10;
            }
            i += 10;
        }
        labelInMap( 330 , 400 , 100 , 140 , "background: url(:/res/image/tree2.png);" );

        labelInMap( 900 , 500 , 100 , 140 , "background: url(:/res/image/tree2.png);" );

        labelInMap( 900 , 170 , 100 , 140 , "background: url(:/res/image/tree3.png);" );

        labelInMap( 890 , 340 , 60 , 50 , "background: url(:/res/image/shark.png);" );

        labelInMap( 340 , 315 , 60 , 50 , "background: url(:/res/image/shark.png);" );

        labelInMap( 320 , 615 , 70 , 70 , "background: url(:/res/image/stone.png);" );

        labelInMap( 460 , 160 , 70 , 70 , "background: url(:/res/image/stone.png);" );

        labelInMap( 550 , 180 , 70 , 70 , "background: url(:/res/image/stone.png);" );


        break;
    }

    createLabelsInGroupBox(5);

    label_2 = new QLabel(saveGameData::str, this);
    label_2->setFixedSize(200, 50);
    int x = 100;
    int y = 50;
    label_2->move(x, y);
    label_2->show();

    timer3 = new QTimer(this);
    connect(timer3, &QTimer::timeout, this, &Gamepage::countIron);
    timer3->start(100);
    iron = 500;
    ironLabel = new QLabel(this);
    QLabel *iconIron = new QLabel(this);
    iconIron->setStyleSheet("background: url(:/res/image/iron.png);");
    iconIron->move(1037,12);
    iconIron->setFixedSize(60,40);
    iconIron->show();
    ironLabel->setText(QString("%1").arg(iron));
    ironLabel->setStyleSheet("font-size : 20px; font-weight : bold;");
    ironLabel->move(1100, 7);
    ironLabel->setFixedSize(100 , 50);
    ironLabel->show();

    heart1 = new QLabel(this);
    heart1->setFixedSize(30,29);
    heart1->move(1000, 20);
    heart1->setStyleSheet("background: url(:/res/image/heart.png);");

    heart2 = new QLabel(this);
    heart2->setFixedSize(30,29);
    heart2->move(965, 20);
    heart2->setStyleSheet("background: url(:/res/image/heart.png);");

    heart3 = new QLabel(this);
    heart3->setFixedSize(30,29);
    heart3->move(930, 20);
    heart3->setStyleSheet("background: url(:/res/image/heart.png);");


    exitCounterLabel = new QLabel(this);
    exitCounterLabel->setText(QString("Enemies exited: %1").arg(enemiesExited));
    exitCounterLabel->setFixedSize(100,40);
    exitCounterLabel->move(1060, 70);
    exitCounterLabel->show();

    speedWave = 0;
    healthWave = 1.1;

    level = QVector<int>(6, 1);
    level2 = QVector<int>(6, 1);

    ui->label_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->label_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_3->hide();
    ui->label_5->hide();

    createToolbar();
}

void Gamepage::createToolbar()
{
    labellvl1 = new QLabel(this);
    labellvl1->setStyleSheet("background: url(:/res/image/card1-lvl1.png);");
    labellvl1->setFixedSize(90, 90);
    int x = 1236;
    int y = 10 + 0 * 115;
    labellvl1->move(x, y);
    labellvl1->show();
    QPushButton *button = new QPushButton("Lvl up", this);
    button->setGeometry(x, y + 90, 90, 20);
    connect(button, &QPushButton::clicked, this, &Gamepage::buttonClicked1);
    button->show();

    labellvl2 = new QLabel(this);
    labellvl2->setStyleSheet("background: url(:/res/image/card2-lvl1.png);");
    labellvl2->setFixedSize(90, 90);
    x = 1236;
    y = 10 + 1 * 115;
    labellvl2->move(x, y);
    labellvl2->show();
    QPushButton *button2 = new QPushButton("Lvl up", this);
    button2->setGeometry(x, y + 90, 90, 20);
    connect(button2, &QPushButton::clicked, this, &Gamepage::buttonClicked2);
    button2->show();

    labellvl3 = new QLabel(this);
    labellvl3->setStyleSheet("background: url(:/res/image/card3-lvl1.png);");
    labellvl3->setFixedSize(90, 90);
    x = 1236;
    y = 10 + 2 * 115;
    labellvl3->move(x, y);
    labellvl3->show();
    QPushButton *button3 = new QPushButton("Lvl up", this);
    button3->setGeometry(x, y + 90, 90, 20);
    connect(button3, &QPushButton::clicked, this, &Gamepage::buttonClicked3);
    button3->show();

    labellvl4 = new QLabel(this);
    labellvl4->setStyleSheet("background: url(:/res/image/card4-lvl1.png);");
    labellvl4->setFixedSize(90, 90);
    x = 1236;
    y = 10 + 3 * 115;
    labellvl4->move(x, y);
    labellvl4->show();
    QPushButton *button4 = new QPushButton("Lvl up", this);
    button4->setGeometry(x, y + 90, 90, 20);
    connect(button4, &QPushButton::clicked, this, &Gamepage::buttonClicked4);
    button4->show();

    labellvl5 = new QLabel(this);
    labellvl5->setStyleSheet("background: url(:/res/image/card5-lvl1.png);");
    labellvl5->setFixedSize(90, 90);
    x = 1236;
    y = 10 + 4 * 115;
    labellvl5->move(x, y);
    labellvl5->show();
    QPushButton *button5 = new QPushButton("Lvl up", this);
    button5->setGeometry(x, y + 90, 90, 20);
    connect(button5, &QPushButton::clicked, this, &Gamepage::buttonClicked5);
    button5->show();

    labellvl6 = new QLabel(this);
    labellvl6->setStyleSheet("background: url(:/res/image/card6-lvl1.png);");
    labellvl6->setFixedSize(90, 90);
    x = 1236;
    y = 10 + 5 * 115;
    labellvl6->move(x, y);
    labellvl6->show();
    QPushButton *button6 = new QPushButton("Lvl up", this);
    button6->setGeometry(x, y + 90, 90, 20);
    connect(button6, &QPushButton::clicked, this, &Gamepage::buttonClicked6);
    button6->show();
}

void  Gamepage::buttonClicked1()
{
    if ( iron - (200 * level[0]) < 0 ){}
    else {
        if ( level[0] < 5 )
        {
            iron -= (200 * level[0]);
            level[0] += 1;
        }
        labellvl1->setStyleSheet(QString("background: url(:/res/image/card1-lvl%1.png);").arg(level[0]));
        for (ClickableLabel *t : Gamepage::turrets) {
            if (auto turret_Q8 = dynamic_cast<Turret_Q8*>(t)) {
                turret_Q8->setLvlDamage(level[0]);
                turret_Q8->setDamage(turret_Q8->getDamage() * pow(2,(level[0] - 1)));
            }
        }
    }
}
void  Gamepage::buttonClicked2()
{
    if ( iron - (200 * level[1] ) < 0 ){}
    else {
        if ( level[1] < 5 )
        {
            iron -= (200 * level[1]);
            level[1] += 1;
        }
        labellvl2->setStyleSheet(QString("background: url(:/res/image/card2-lvl%1.png);").arg(level[1]));
        for (ClickableLabel *t : Gamepage::turrets) {
            if (auto turret_q8f = dynamic_cast<Turret_q8f*>(t)) {
                turret_q8f->setLvlDamage(level[1]);
                turret_q8f->setDamage(turret_q8f->getDamage() * pow(2,(level[1] - 1)));
            }
        }
    }
}

void Gamepage::buttonClicked3()
{
    if ( iron - ( 200 * level[2]  )< 0){}
    else {
        if ( level[2] < 5 )
        {
            iron -= (200 * level[2]);
            level[2] += 1;
        }
        labellvl3->setStyleSheet(QString("background: url(:/res/image/card3-lvl%1.png);").arg(level[2]));
        for (ClickableLabel *t : Gamepage::turrets) {
            if (auto turret_q8r = dynamic_cast<Turret_q8r*>(t)) {
                turret_q8r->setLvlDamage(level[2]);
                turret_q8r->setDamage(turret_q8r->getDamage() * pow(2,(level[2] - 1)));
            }
        }
    }
}

void  Gamepage::buttonClicked4()
{
    if ( level[3] < 5 )
    {
        iron -= (200 * level[3]);
        level[3] += 1;
    }
    labellvl4->setStyleSheet(QString("background: url(:/res/image/card4-lvl%1.png);").arg(level[3]));
    for (ClickableLabel *t : Gamepage::bombs) {
        if (auto bomb = dynamic_cast<Bomb*>(t)) {
            bomb->setRange(level[3] * 25 + 40);
        }
    }
}

void  Gamepage::buttonClicked5()
{
    if ( level[4] < 5 )
    {
        iron -= (200 * level[4]);
        level[4] += 1;
    }
    labellvl5->setStyleSheet(QString("background: url(:/res/image/card5-lvl%1.png);").arg(level[4]));
    for (ClickableLabel *t : Gamepage::bombs) {
        if (auto bomb = dynamic_cast<Ice_Bomb*>(t)) {
            bomb->setRange(level[4] * 25 + 40);
        }
    }
}

void Gamepage::buttonClicked6()
{
    if ( iron - ( 200 * level[5]  )< 0){}
    else {
        if ( level[5] < 5 )
        {
            iron -= (200 * level[5]);
            level[5] += 1;
        }
        labellvl6->setStyleSheet(QString("background: url(:/res/image/card6-lvl%1.png);").arg(level[5]));
        for (ClickableLabel *t : Gamepage::turrets) {
            qDebug() << "hi";
            if (auto turret_q8m = dynamic_cast<Turret_q8m*>(t)) {
                turret_q8m->setLvlDamage(level[5]);
                turret_q8m->setDamage(turret_q8m->getDamage() * pow(2,(level[5] - 1)));
            }
        }
    }
}

void Gamepage::countIron()
{
    iron += 50;
    ironLabel->setText(QString("%1").arg(iron));
}
void Gamepage::ironLabelshow()
{
    ironLabel->setText(QString("%1").arg(iron));
}

void Gamepage::labelInMap( int x , int y , int z , int k , QString s )
{
    QLabel *labelpanel = new QLabel(this);
    labelpanel->move( x , y );
    labelpanel->setFixedSize( z , k );
    labelpanel->setStyleSheet(s);
    labelpanel->show();
}

void Gamepage::createLabelMapUpdate( int startx , int starty)
{
    QLabel *labelpanelUp = new QLabel(this);
    labelpanelUp->move( startx , starty );
    labelpanelUp->setFixedSize( 50 , 15 );
    labelpanelUp->setStyleSheet("background-color:rgb(255, 185, 20);border-radius:5px");
    labelpanelUp->show();
}

void Gamepage::createLabelMap( int startx , int starty)
{
    QLabel *labelpanel = new QLabel(this);
    labelpanel->move( startx , starty );
    labelpanel->setFixedSize( 100 , 100 );
    if ( saveGameData::mapNumber == 1 )
    {
        switch (rand() % 5 + 1) {
        case 1:
            labelpanel->setStyleSheet("background: url(:/res/image/Map3.png);");
            break;
        case 2:
            labelpanel->setStyleSheet("background: url(:/res/image/Map4.png);");
            break;
        case 3:
            labelpanel->setStyleSheet("background: url(:/res/image/Map5.png);");
            break;
        case 4:
            labelpanel->setStyleSheet("background: url(:/res/image/Map6.png);");
            break;
        case 5:
            labelpanel->setStyleSheet("background: url(:/res/image/Map7.png);");
            break;
        default:
            break;
        }
    }else if ( saveGameData::mapNumber == 2 ) {
        switch (rand() % 5 + 1) {
        case 1:
            labelpanel->setStyleSheet("background: url(:/res/image/map2_1.png);");
            break;
        case 2:
            labelpanel->setStyleSheet("background: url(:/res/image/map2_2.png);");
            break;
        case 3:
            labelpanel->setStyleSheet("background: url(:/res/image/map2_3.png);");
            break;
        case 4:
            labelpanel->setStyleSheet("background: url(:/res/image/map2_4.png);");
            break;
        case 5:
            labelpanel->setStyleSheet("background: url(:/res/image/map2_5.png);");
            break;
        default:
            break;
        }
    }else {
        switch (rand() % 5 + 1) {
        case 1:
            labelpanel->setStyleSheet("background: url(:/res/image/Map3.png);");
            break;
        case 2:
            labelpanel->setStyleSheet("background: url(:/res/image/Map4.png);");
            break;
        case 3:
            labelpanel->setStyleSheet("background: url(:/res/image/Map5.png);");
            break;
        case 4:
            labelpanel->setStyleSheet("background: url(:/res/image/Map6.png);");
            break;
        case 5:
            labelpanel->setStyleSheet("background: url(:/res/image/Map7.png);");
            break;
        default:
            break;
        }
    }
    labelpanel->show();

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

void Gamepage::createBlueSquareLabel()
{
    Enemy *label;
    int rands = std::rand() % 2 + 1;

    switch (rands) {
    case 1:
        label = new Fighter298(this);
        break;
    case 2:
        label = new fighter111(this);
        break;
    default:
        label = new Fighter298(this);
        break;
    }


    if ( countWave % 2 == 0 && bossCount == 0 ){
        int rands2 = std::rand() % 3 + 1;

        switch (rands2) {
        case 1:
            label = new TowerDestroyer(this);
            bossCount = 1;
            break;
        case 2:
            label = new TowerDisabler(this);
            bossCount = 1;
            break;
        case 3:
            label = new BombDisabler(this);
            bossCount = 1;
            break;
        default:
            label = new BombDisabler(this);
            bossCount = 1;
            break;
        }
    }

    float temp =  label->getHealth();
    temp *= healthWave;
    label->setHealth(temp);
    label->speed -= speedWave;
    label->setFixedSize(47, 47);

    //label->setText(QString("%1").arg(labelCount++));
    labelCount++;
    int x = matrix[{1,1}].first;
    int y = matrix[{1,1}].second;
    label->move(x, y);
    label->currentPosition.setX(x);
    label->currentPosition.setY(y);
    Gamepage::enimi.append(label);
    label->show();


    if ( labelCount  == wCount + 1 )
    {
        timer->setInterval(timeCount);
        timer2->start(1000);
        icount = 10;
        labelCount = 1;
        bossCount = 0;
        countWave += 1;
        speedWave += 100;
        healthWave += 0.1;
    }
    else {

        timer->setInterval(rand() % 600 + 400);
        ui->label->setText("fight");
    }

    connect(label, &Enemy::animationFinished, this , &Gamepage::onEnemyExited);

    moveObject( label );
}

void Gamepage::timeLabelText()
{
    ui->label->setText(QString("Until the next wave %1 ").arg( icount-- ));

    if ( icount ==  0 )
    {
        timer2->stop();
    }
}

void Gamepage::moveObject( Enemy *label )
{
    animationGroup = new QSequentialAnimationGroup(this);
    QPropertyAnimation *animation0 = new QPropertyAnimation(label, "geometry");
    QPropertyAnimation *animation1 = new QPropertyAnimation(label, "geometry");
    QPropertyAnimation *animation6 = new QPropertyAnimation(label, "geometry");


    if ( label->y() == 100 )
    {

        animation1->setDuration(label->speed * 2);
        animation1->setStartValue(QRect(label->x(), label->y(), label->width(), label->height()));
        animation1->setEndValue(QRect(matrix[{2,1}].first, matrix[{2,1}].second, label->width(), label->height()));

        animation1->start();


        animation6->setDuration(label->speed);
        animation6->setStartValue(QRect(matrix[{2,1}].first, matrix[{2,1}].second, label->width(), label->height()));
        animation6->setEndValue(QRect(matrix[{2,2}].first, matrix[{2,2}].second, label->width(), label->height()));


        connect(animation1, &QPropertyAnimation::finished, this, [animation6, label](){
            label->setRotationAngle(180);
            animation6->start();
        });

    }
    else if ( label->x() == 1100 ) {


        animation6->setDuration(label->speed);
        animation6->setStartValue(QRect(label->x(), label->y(), label->width(), label->height()));
        animation6->setEndValue(QRect(matrix[{2,2}].first, matrix[{2,2}].second, label->width(), label->height()));

        animation6->start();

    }else {
        animation0->setDuration(label->speed);
        animation0->setStartValue(QRect(label->currentPosition.x(), label->currentPosition.y(), label->width(), label->height()));
        animation0->setEndValue(QRect(matrix[{1,2}].first, matrix[{1,2}].second, label->width(), label->height()));
        animation0->start();
        label->setRotationAngle(0);

        animation1->setDuration(label->speed * 2);
        animation1->setStartValue(QRect(matrix[{1,2}].first, matrix[{1,2}].second, label->width(), label->height()));
        animation1->setEndValue(QRect(matrix[{2,1}].first, matrix[{2,1}].second, label->width(), label->height()));

        connect(animation0, &QPropertyAnimation::finished, this, [animation1, label](){
            label->setRotationAngle(90);
            animation1->start();
        });


        animation6->setDuration(label->speed);
        animation6->setStartValue(QRect(matrix[{2,1}].first, matrix[{2,1}].second, label->width(), label->height()));
        animation6->setEndValue(QRect(matrix[{2,2}].first, matrix[{2,2}].second, label->width(), label->height()));


        connect(animation1, &QPropertyAnimation::finished, this, [animation6, label](){
            label->setRotationAngle(180);
            animation6->start();
        });
    }


    connect(animation6, &QPropertyAnimation::finished, this, [ label]()
            {
                //label->deleteLater();
                if ( label->isAlive == true ){
                    emit label->animationFinished();
                }
                Gamepage::enimi.removeOne(label);
                label->hide();
                label->isAlive = false;
            });
}

void Gamepage::onEnemyExited() {
    enemiesExited++;
    if ( enemiesExited == 1 )
    {
        heart1->hide();
    }
    if ( enemiesExited == 2 )
    {
        heart2->hide();
    }
    if ( enemiesExited == 3 )
    {
        heart3->hide();
        ui->label_3->show();
        ui->label_5->show();
        ui->pushButton_4->show();
        ui->pushButton_3->show();
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        timer->stop();
        timer2->stop();
        timer3->stop();
        timer4->stop();

        QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
        opacityEffect->setOpacity(0.7);
        ui->label_4->setStyleSheet("background-color:black;");
        ui->label_4->raise();
        ui->pushButton_4->raise();
        ui->pushButton_3->raise();
        ui->label_3->raise();
        ui->label_4->setGraphicsEffect(opacityEffect);
        ui->label_5->raise();
        QLabel *numberEnemyLabel = new QLabel(this);
        numberEnemyLabel->move(490,460);
        numberEnemyLabel->setText(QString("The number of kill %1").arg(numberEemey));
        numberEnemyLabel->setStyleSheet("background:transparent; font-size:25px;font-weight: bold; color: black; text-shadow: 1px 1px 2px white;");
        numberEnemyLabel->show();
        numberEnemyLabel->raise();


        iron = 0;
        for ( Enemy *e : Gamepage::enimi ) {
            e->takeHit(10000);
        }

        for ( ClickableLabel *a : Gamepage::turrets ) {
            a->setSpeedshoot(0);
        }
    }
    exitCounterLabel->setText(QString("Enemies exited: %1").arg(enemiesExited));
}


void Gamepage::createLabelsInGroupBox(int initialCount)
{
    for (int i = 0; i < initialCount; ++i) {
        ClickableLabel *label;
        int rands = std::rand() % 6 + 1;

        switch (rands) {
        case 1:
            label = new Turret_Q8(this);
            label->setStyleSheet("background: url(:/res/image/card1.png);");
            break;
        case 2:
            label = new Turret_q8f(this);
            label->setStyleSheet("background: url(:/res/image/card2.png);");
            break;
        case 3:
            label = new Turret_q8r(this);
            label->setStyleSheet("background: url(:/res/image/card3.png);");
            break;
        case 4:
            label = new Bomb(this);
            label->setStyleSheet("background: url(:/res/image/card4.png);");
            break;
        case 5:
            label = new Ice_Bomb(this);
            label->setStyleSheet("background: url(:/res/image/card5.png);");
            break;
        case 6:
            label = new Turret_q8m(this);
            label->setStyleSheet("background: url(:/res/image/card6.png);");
            break;
        default:
            label = new Turret_Q8(this);
            label->setStyleSheet("background: url(:/res/image/card1.png);");
            break;
        }

        label->setFixedSize(90, 90);
        label->select = false;

        label->status = 0;

        connect(label, &ClickableLabel::clicked, this, &Gamepage::labelClicked);

        int x = 50;
        int y = 100 + i * 100;
        label->move(x, y);
        label->show();

        labels.append(label);
    }
}

void Gamepage::createNewLabel(QPoint position)
{
    ClickableLabel *label;
    int rands = std::rand() % 6 + 1;

    switch (rands) {
    case 1:
        label = new Turret_Q8(this);
        label->setStyleSheet("background: url(:/res/image/card1.png);");
        break;
    case 2:
        label = new Turret_q8f(this);
        label->setStyleSheet("background: url(:/res/image/card2.png);");
        break;
    case 3:
        label = new Turret_q8r(this);
        label->setStyleSheet("background: url(:/res/image/card3.png);");
        break;
    case 4:
        label = new Bomb(this);
        label->setStyleSheet("background: url(:/res/image/card4.png);");
        break;
    case 5:
        label = new Ice_Bomb(this);
        label->setStyleSheet("background: url(:/res/image/card5.png);");
        break;
    case 6:
        label = new Turret_q8m(this);
        label->setStyleSheet("background: url(:/res/image/card6.png);");
        break;
    default:
        label = new Turret_Q8(this);
        label->setStyleSheet("background: url(:/res/image/card1.png);");
        break;
    }


    label->setFixedSize(90, 90);
    label->status = 0;

    connect(label, &ClickableLabel::clicked, this, &Gamepage::labelClicked);

    label->move(position);
    label->show();

    labels.append(label);
}

void Gamepage::labelClicked()
{

    selectedLabel = qobject_cast<ClickableLabel*>(sender());
    if ( selectedLabel )
    {
        if ( selectedLabel->status != -1 )
        {
            for ( ClickableLabel *t : Gamepage::turrets )
            {
                if ( t->select == true )
                {
                    t->select = false;
                    QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
                    opacityEffect->setOpacity(1);
                    t->setGraphicsEffect(opacityEffect);
                }
            }
            for ( ClickableLabel *t : Gamepage::bombs )
            {
                if ( t->select == true )
                {
                    t->select = false;
                    QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
                    opacityEffect->setOpacity(1);
                    t->setGraphicsEffect(opacityEffect);
                }
            }
            for ( ClickableLabel *t : labels )
            {
                if ( t->select == true )
                {
                    t->select = false;
                    QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
                    opacityEffect->setOpacity(1);
                    t->setGraphicsEffect(opacityEffect);
                }
            }
            QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
            opacityEffect->setOpacity(0.5);
            selectedLabel->setGraphicsEffect(opacityEffect);
            selectedLabel->select = true;
        }
    }
}


bool Gamepage::isPositionOccupied(QRect rec) {
    for (ClickableLabel *label : labels) {
        if (label->geometry().intersects(rec)) {
            return true;
        }
    }
    return false;
}

bool Gamepage::isPositionOccupied2(QRect rec , int x , int lvl , int code ) {
    for (ClickableLabel *t : Gamepage::turrets) {
        if (t->geometry().adjusted(-2, -2, 2, 2).intersects(rec)) {
            if (auto turret_q8 = dynamic_cast<Turret_Q8*>(t)) {
                if ( x == 1 ){
                    if ( lvl == turret_q8->getLvl() )
                    {
                        if ( code == turret_q8->getCode() )
                        {
                            return false;
                        }
                        turret_q8->setActive(false);
                        turret_q8->stopShooting();
                        Gamepage::turrets.removeOne(turret_q8);
                        turret_q8->move(2000,2000);
                        return true;
                    }
                }
            }else if (auto turret_q8f = dynamic_cast<Turret_q8f*>(t)) {
                if ( x == 2 ){
                    if ( lvl == turret_q8f->getLvl() )
                    {
                        if ( code == turret_q8f->getCode() )
                        {
                            return false;
                        }
                        turret_q8f->setActive(false);
                        turret_q8f->stopShooting();
                        Gamepage::turrets.removeOne(turret_q8f);
                        turret_q8f->move(2000,2000);
                        return true;
                    }
                }
            }else if (auto turret_q8r = dynamic_cast<Turret_q8r*>(t)) {
                if ( x == 3 ){
                    if ( lvl == turret_q8r->getLvl() )
                    {
                        if ( code == turret_q8r->getCode() )
                        {
                            return false;
                        }
                        turret_q8r->setActive(false);
                        turret_q8r->stopShooting();
                        Gamepage::turrets.removeOne(turret_q8r);
                        turret_q8r->move(2000,2000);
                        return true;
                    }
                }
            }
            else if (auto turret_q8m = dynamic_cast<Turret_q8m*>(t)) {
                if ( x == 3 ){
                    if ( lvl == turret_q8m->getLvl() )
                    {
                        if ( code == turret_q8m->getCode() )
                        {
                            return false;
                        }
                        turret_q8m->setActive(false);
                        turret_q8m->stopShooting();
                        Gamepage::turrets.removeOne(turret_q8m);
                        turret_q8m->move(2000,2000);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}


void Gamepage::labelClicked2()
{
    selectedLabel2 = qobject_cast<ClickableLabel2*>(sender());
    if (selectedLabel2) {
        if ( selectedLabel2->mod == 1 )
        {
            QLabel *parentLabel = qobject_cast<QLabel*>(selectedLabel2->parent());
            if (parentLabel) {
                parentLabel->move(1000,1000);
            }
        }
        if ( selectedLabel2->mod == 2)
        {
            QLabel *parentLabel = qobject_cast<QLabel*>(selectedLabel2->parent());
            if (parentLabel) {
                parentLabel->setStyleSheet("background-color: red;");
            }
        }
    }
}

bool Gamepage::checkMap ( QMouseEvent *event )
{
    switch (saveGameData::mapNumber) {
    case 1:
        for (int i = 450 ; i <= 850 ; i += 100 ) {

            for (int j = 250 ; j <= 600 ; j += 100 ) {

                if ((i + 20 < event->pos().rx() && event->pos().rx()  < i + 80) && (j + 20  < event->pos().ry() && event->pos().ry()  < j + 80))
                {
                    return true;
                }
                j += 10;
            }
            i += 10;
        }
        return false;
        break;
    case 2:
        for (int i = 250 ; i <= 450 ; i += 100 ) {

            for (int j = 150 ; j <= 500 ; j += 100 ) {

                if ((i + 30 < event->pos().rx() && event->pos().rx()  < i + 70) && (j + 30  < event->pos().ry() && event->pos().ry()  < j + 70))
                {
                    return true;
                }
                j += 10;
            }
            i += 10;
        }
        for (int i = 800 ; i <= 950 ; i += 100 ) {

            for (int j = 150 ; j <= 500 ; j += 100 ) {

                if ((i + 30 < event->pos().rx() && event->pos().rx()  < i + 70) && (j + 30  < event->pos().ry() && event->pos().ry()  < j + 70))
                {
                    return true;
                }
                j += 10;
            }
            i += 10;
        }
        return false;
    case 3:
        for (int i = 250 ; i <= 450 ; i += 100 ) {

            for (int j = 100 ; j <= 450 ; j += 100 ) {

                if ((i + 30 < event->pos().rx() && event->pos().rx()  < i + 70) && (j + 30  < event->pos().ry() && event->pos().ry()  < j + 70))
                {
                    return true;
                }
                j += 10;
            }
            i += 10;
        }
        for (int i = 800 ; i <= 950 ; i += 100 ) {

            for (int j = 200 ; j <= 550 ; j += 100 ) {

                if ((i + 30 < event->pos().rx() && event->pos().rx()  < i + 70) && (j + 30  < event->pos().ry() && event->pos().ry()  < j + 70))
                {
                    return true;
                }
                j += 10;
            }
            i += 10;
        }
        break;
    default:
        for (int i = 450 ; i <= 850 ; i += 100 ) {

            for (int j = 250 ; j <= 600 ; j += 100 ) {

                if ((i < event->pos().rx() && event->pos().rx()  < i + 100) && (j < event->pos().ry() && event->pos().ry()  < j + 80))
                {
                    return true;
                }
                j += 10;
            }
            i += 10;
        }
        return false;
        break;
    }
    return false;
}


bool Gamepage::checkMap2 ( QMouseEvent *event )
{
    switch (saveGameData::mapNumber)
    {
    case 1:
        if ( (200 < event->pos().rx() && event->pos().rx()  < 450 )  && (200 < event->pos().ry() && event->pos().ry()  < 600)
            && (850 < event->pos().rx() && event->pos().rx()  < 1050 ))
        {
            return true;
        }
        return false;
        break;
    }
    return false;
}

bool Gamepage::checkMap3 ( QMouseEvent *event )
{
    for (int i = 450 ; i <= 850 ; i += 100 ) {

        for (int j = 250 ; j <= 600 ; j += 100 ) {

            if ((i + 25 < event->pos().rx() && event->pos().rx()  < i + 75) && (j + 85  < event->pos().ry() && event->pos().ry()  < j + 100))
            {
                return true;
            }
            j += 10;
        }
        i += 10;
    }
    return false;
}

QPoint Gamepage::checkEvent( QMouseEvent *event )
{
    if ( event->pos().rx() <= 550  )
    {
        if ( event->pos().ry() <= 350 )
        {
            return QPoint(matrix2[{0,0}].first , matrix2[{0,0}].second);
        }
        else if ( event->pos().ry() <= 460 )
        {
            return QPoint(matrix2[{0,1}].first , matrix2[{0,1}].second);
        }
        else if ( event->pos().ry() <= 570 )
        {
            return QPoint(matrix2[{0,2}].first , matrix2[{0,2}].second);
        }
        else if ( event->pos().ry() <= 680 )
        {
            return QPoint(matrix2[{0,3}].first , matrix2[{0,3}].second);
        }
    }else if (event->pos().rx() <= 660) {

        if ( event->pos().ry() <= 350 )
        {
            return QPoint(matrix2[{1,0}].first , matrix2[{1,0}].second);
        }
        else if ( event->pos().ry() <= 460 )
        {
            return QPoint(matrix2[{1,1}].first , matrix2[{1,1}].second);
        }
        else if ( event->pos().ry() <= 570 )
        {
            return QPoint(matrix2[{1,2}].first , matrix2[{1,2}].second);
        }
        else if ( event->pos().ry() <= 680 )
        {
            return QPoint(matrix2[{1,3}].first , matrix2[{1,3}].second);
        }
    }else if (event->pos().rx() <= 770) {

        if ( event->pos().ry() <= 350 )
        {
            return QPoint(matrix2[{2,0}].first , matrix2[{2,0}].second);
        }
        else if ( event->pos().ry() <= 460 )
        {
            return QPoint(matrix2[{2,1}].first , matrix2[{2,1}].second);
        }
        else if ( event->pos().ry() <= 570 )
        {
            return QPoint(matrix2[{2,2}].first , matrix2[{2,2}].second);
        }
        else if ( event->pos().ry() <= 680 )
        {
            return QPoint(matrix2[{2,3}].first , matrix2[{2,3}].second);
        }
    }else if (event->pos().rx() <= 880) {

        if ( event->pos().ry() <= 350 )
        {
            return QPoint(matrix2[{3,0}].first , matrix2[{3,0}].second);
        }
        else if ( event->pos().ry() <= 460 )
        {
            return QPoint(matrix2[{3,1}].first , matrix2[{3,1}].second);
        }
        else if ( event->pos().ry() <= 570 )
        {
            return QPoint(matrix2[{3,2}].first , matrix2[{3,2}].second);
        }
        else if ( event->pos().ry() <= 680 )
        {
            return QPoint(matrix2[{3,3}].first , matrix2[{3,3}].second);
        }
    }
}


void Gamepage::mousePressEvent(QMouseEvent *event)
{
    if (selectedLabel && event->button() == Qt::LeftButton) {
        QPoint previousPosition = selectedLabel->pos();
        QRect newRect(event->pos() - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2), selectedLabel->size());

        if ( selectedLabel->status != -1 )
        {
            if ( checkMap3(event) )
            {
                if (auto turret1 = dynamic_cast<Turret_Q8*>(selectedLabel))
                {
                    if ( selectedLabel->status > 0 ){
                        if ( isPositionOccupied2(newRect , 1 , turret1->getLvl() , turret1->getCode() ))
                        {
                            int lvl = turret1->getLvl() + 1;
                            turret1->setLvl( lvl );
                            selectedLabel->move(checkEvent(event) - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2 + 7));
                            selectedLabel->setStyleSheet(QString("background: url(:/res/image/T-%1.png);").arg(turret1->getLvl()));
                            int speed = selectedLabel->getSpeedshoot() - 100;
                            selectedLabel->setSpeedshoot(speed);
                            QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
                            opacityEffect->setOpacity(1);
                            selectedLabel->setGraphicsEffect(opacityEffect);
                            turret1->startShotBullet();
                        }
                    }
                }else if (auto turret2 = dynamic_cast<Turret_q8f*>(selectedLabel))
                {
                    if ( selectedLabel->status > 0 ){
                        if ( isPositionOccupied2(newRect , 2 , turret2->getLvl() , turret2->getCode() ) )
                        {
                            int lvl = turret2->getLvl() + 1;
                            turret2->setLvl( lvl );
                            selectedLabel->move(checkEvent(event) - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2+ 7));
                            selectedLabel->setStyleSheet(QString("background: url(:/res/image/T1-%1.png);").arg(turret2->getLvl()));
                            if ( turret2->getLvl() == 5 )
                            {
                                selectedLabel->setStyleSheet("background: url(:/res/image/T-5.png);");
                            }
                            int speed = selectedLabel->getSpeedshoot() - 100;
                            selectedLabel->setSpeedshoot(speed);
                            QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
                            opacityEffect->setOpacity(1);
                            selectedLabel->setGraphicsEffect(opacityEffect);
                            turret2->startShotBullet();
                        }
                    }
                }else if (auto turret3 = dynamic_cast<Turret_q8r*>(selectedLabel))
                {

                    if ( selectedLabel->status > 0 ){
                        if ( isPositionOccupied2(newRect , 3 , turret3->getLvl() , turret3->getCode() ) )
                        {
                            int lvl = turret3->getLvl() + 1;
                            turret3->setLvl( lvl );
                            selectedLabel->move(checkEvent(event) - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2+ 7));
                            selectedLabel->setStyleSheet(QString("background: url(:/res/image/T2-%1.png);").arg(turret3->getLvl()));
                            if ( turret3->getLvl() == 5 )
                            {
                                selectedLabel->setStyleSheet("background: url(:/res/image/T-5.png);");
                            }
                            int speed = selectedLabel->getSpeedshoot() - 200;
                            selectedLabel->setSpeedshoot(speed);
                            QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
                            opacityEffect->setOpacity(1);
                            selectedLabel->setGraphicsEffect(opacityEffect);
                            turret3->startShotBullet();
                        }
                    }
                }
                else if (auto turret4 = dynamic_cast<Turret_q8m*>(selectedLabel))
                {

                    if ( selectedLabel->status > 0 ){
                        if ( isPositionOccupied2(newRect , 3 , turret4->getLvl() , turret4->getCode() ) )
                        {
                            int lvl = turret4->getLvl() + 1;
                            turret4->setLvl( lvl );
                            selectedLabel->move(checkEvent(event) - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2+ 7));
                            selectedLabel->setStyleSheet(QString("background: url(:/res/image/T3-%1.png);").arg(turret4->getLvl()));
                            if ( turret4->getLvl() == 5 )
                            {
                                selectedLabel->setStyleSheet("background: url(:/res/image/T-5.png);");
                            }
                            int speed = selectedLabel->getSpeedshoot() - 100;
                            selectedLabel->setSpeedshoot(speed);
                            QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
                            opacityEffect->setOpacity(1);
                            selectedLabel->setGraphicsEffect(opacityEffect);
                            turret4->startShotBullet();
                        }
                    }
                }
            }else if ( checkMap(event) )
            {
                if (!isPositionOccupied(newRect) || selectedLabel->status != 0)
                {

                    if (auto turret1 = dynamic_cast<Turret_Q8 *>(selectedLabel))
                    {
                        if ( iron - 200 < 0 ){}
                        else {
                            if ( selectedLabel->status == 0 )
                            {
                                createNewLabel(previousPosition);
                                Gamepage::turrets.append(selectedLabel);
                                labels.removeOne(selectedLabel);
                                iron -= 200;

                                selectedLabel->move(checkEvent(event) - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2));

                                turret1->startShotBullet();
                                turret1->setDamage(turret1->getDamage() * pow(2,(level[0] - 1)));
                                selectedLabel->setFixedSize(90, 60);
                                selectedLabel->setStyleSheet("background: url(:/res/image/T.png);");
                                QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
                                opacityEffect->setOpacity(1);
                                selectedLabel->setGraphicsEffect(opacityEffect);
                                selectedLabel->status = 1;
                                selectedLabel = nullptr;
                            }
                        }

                    } else if (auto turret2 = dynamic_cast<Turret_q8f *>(selectedLabel))
                    {
                        if ( iron - 200 < 0 ){}
                        else {
                            if ( selectedLabel->status == 0 )
                            {
                                createNewLabel(previousPosition);
                                Gamepage::turrets.append(selectedLabel);
                                labels.removeOne(selectedLabel);
                                iron -= 200;
                                selectedLabel->move(checkEvent(event) - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2));
                                turret2->startShotBullet();
                                turret2->setDamage(turret2->getDamage() * pow(2,(level[1] - 1)));
                                selectedLabel->setStyleSheet("background: url(:/res/image/T1.png);");
                                QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
                                opacityEffect->setOpacity(1);
                                selectedLabel->setGraphicsEffect(opacityEffect);
                                selectedLabel->setFixedSize(90, 60);
                                selectedLabel->status = 1;
                                selectedLabel = nullptr;

                            }
                        }

                    } else if (auto turret3 = dynamic_cast<Turret_q8r *>(selectedLabel))
                    {
                        if ( iron - 400 < 0 ){}
                        else {
                            if ( selectedLabel->status == 0 )
                            {
                                createNewLabel(previousPosition);
                                Gamepage::turrets.append(selectedLabel);
                                labels.removeOne(selectedLabel);
                                iron -= 400;
                                selectedLabel->move(checkEvent(event) - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2));
                                turret3->startShotBullet();
                                turret3->setDamage(turret3->getDamage() * pow(2,(level[2] - 1)));
                                selectedLabel->setStyleSheet("background: url(:/res/image/T2.png);");
                                QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
                                opacityEffect->setOpacity(1);
                                selectedLabel->setGraphicsEffect(opacityEffect);
                                selectedLabel->setFixedSize(90, 60);
                                selectedLabel->status = 1;
                                selectedLabel = nullptr;
                            }
                        }
                    }
                    else if (auto turret4 = dynamic_cast<Turret_q8m *>(selectedLabel))
                    {
                        if ( iron - 300 < 0 ){}
                        else {
                            if ( selectedLabel->status == 0 )
                            {
                                createNewLabel(previousPosition);
                                Gamepage::turrets.append(selectedLabel);
                                labels.removeOne(selectedLabel);
                                iron -= 300;
                                selectedLabel->move(checkEvent(event) - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2));
                                turret4->startShotBullet();
                                turret4->setDamage(turret4->getDamage() * pow(2,(level[2] - 1)));
                                selectedLabel->setStyleSheet("background: url(:/res/image/T3.png);");
                                QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
                                opacityEffect->setOpacity(1);
                                selectedLabel->setGraphicsEffect(opacityEffect);
                                selectedLabel->setFixedSize(90, 60);
                                selectedLabel->status = 1;
                                selectedLabel = nullptr;
                            }
                        }
                    }
                }
            }
            else {
                if (!isPositionOccupied(newRect))
                {
                    if (auto turret1 = dynamic_cast<Bomb *>(selectedLabel))
                    {
                        if ( iron - 200 < 0 ){}
                        else {
                            selectedLabel->move(event->pos() - QPoint(selectedLabel->width() / 2 - 20, selectedLabel->height() / 2 - 20));
                            iron -= 200;
                            //connect(selectedLabel, &Bomb::clicked, selectedLabel, &Bomb::checkCollision);
                            selectedLabel->setStyleSheet("background: url(:/res/image/Bomb.png);");
                            QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
                            opacityEffect->setOpacity(1);
                            selectedLabel->setGraphicsEffect(opacityEffect);
                            selectedLabel->setFixedSize(50, 50);
                            turret1->setRange(level[3] * 25 + 40);
                            selectedLabel->status = 1;
                            Gamepage::bombs.append(selectedLabel);
                            selectedLabel = nullptr;
                            createNewLabel(previousPosition);
                            labels.removeOne(selectedLabel);
                        }
                    }
                    else if (auto turret2 = dynamic_cast<Ice_Bomb *>(selectedLabel)) {
                        if ( iron - 200 < 0 ){}
                        else {
                            selectedLabel->move(event->pos() - QPoint(selectedLabel->width() / 2 - 20, selectedLabel->height() / 2 - 20));
                            iron -= 200;
                            //connect(selectedLabel, &Bomb::clicked, selectedLabel, &Bomb::checkCollision);
                            selectedLabel->setStyleSheet("background: url(:/res/image/Bomb2.png);");
                            QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
                            opacityEffect->setOpacity(1);
                            selectedLabel->setGraphicsEffect(opacityEffect);
                            selectedLabel->setFixedSize(50, 50);
                            turret2->setRange(level[4] * 25 + 40);
                            selectedLabel->status = 1;
                            Gamepage::bombs.append(selectedLabel);
                            selectedLabel = nullptr;
                            createNewLabel(previousPosition);
                            labels.removeOne(selectedLabel);
                        }
                    }
                }
            }
        }
    }
}


void Gamepage::on_pushButton_2_clicked()
{
    this->deleteLater();
    MainWindow *menu = new MainWindow();
    menu->show();
    this->close();
}


// ClickableLabel2 *deletelabel = new ClickableLabel2(selectedLabel);
// deletelabel->setStyleSheet("background-color: red;border-radius : 5px;");
// deletelabel->setFixedSize(20, 20);
// deletelabel->mod = 1;
// //deletelabel->move(selectedLabel->pos().rx() , selectedLabel->pos().ry());

// deletelabel->show();

// connect(deletelabel, &ClickableLabel2::clicked, this, &Gamepage::labelClicked2);

// ClickableLabel2 *editlabel = new ClickableLabel2(selectedLabel);
// editlabel->setStyleSheet("background-color: green;border-radius : 5px;");
// editlabel->setFixedSize(10, 10);
// editlabel->mod = 2;
// //deletelabel->move(selectedLabel->pos().rx() , selectedLabel->pos().ry());

// editlabel->show();

// connect(editlabel, &ClickableLabel2::clicked, this, &Gamepage::labelClicked2);

//selectedLabel->setEnabled(false);


//dynamic_cast<Turret_Q8*>(selectedLabel)->getLabel(enimi);
//dynamic_cast<Turret_Q8*>(selectedLabel)->startShotBullet();

void Gamepage::on_pushButton_4_clicked()
{
    this->deleteLater();
    MainWindow *m = new MainWindow();
    m->show();
    this->close();
}


void Gamepage::on_pushButton_3_clicked()
{
    this->deleteLater();
    Gamepage *m = new Gamepage();
    m->show();
    this->close();
}

