#include "Header/gamepage.h"
#include "Header/bomb.h"
#include "Header/fighter298.h"
#include "Header/fighter111.h"
#include "Header/ice_bomb.h"
#include "Header/mainwindow.h"
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

QVector<Enemy*> Gamepage::enimi;
QVector<ClickableLabel*> Gamepage::turrets;
QVector<ClickableLabel*> Gamepage::bombs;

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
}

Gamepage::Gamepage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gamepage)
    ,   selectedLabel(nullptr)
{
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
    iconIron->move(1037,27);
    iconIron->setFixedSize(60,40);
    iconIron->show();
    ironLabel->setText(QString("%1").arg(iron));
    ironLabel->setStyleSheet("font-size : 20px; font-weight : bold;");
    ironLabel->move(1100, 20);
    ironLabel->setFixedSize(100 , 50);
    ironLabel->show();


    exitCounterLabel = new QLabel(this);
    exitCounterLabel->setText(QString("Enemies exited: %1").arg(enemiesExited));
    exitCounterLabel->setFixedSize(100,40);
    exitCounterLabel->move(1060, 70);
    exitCounterLabel->show();

    speedWave = 0;
    healthWave = 1.1;

    createToolbar(5);

    level = QVector<int>(5, 1);

}

void Gamepage::createToolbar(int initialCount)
{
    labellvl1 = new QLabel(this);
    labellvl1->setStyleSheet("background: url(:/res/image/card1-lvl1.png);");
    labellvl1->setFixedSize(90, 90);
    int x = 1236;
    int y = 30 + 0 * 135;
    labellvl1->move(x, y);
    labellvl1->show();
    QPushButton *button = new QPushButton("Action", this);
    button->setGeometry(x, y + 90, 90, 30);
    connect(button, &QPushButton::clicked, this, &Gamepage::buttonClicked1);
    button->show();

    labellvl2 = new QLabel(this);
    labellvl2->setStyleSheet("background: url(:/res/image/card2-lvl1.png);");
    labellvl2->setFixedSize(90, 90);
    x = 1236;
    y = 30 + 1 * 135;
    labellvl2->move(x, y);
    labellvl2->show();
    QPushButton *button2 = new QPushButton("Action", this);
    button2->setGeometry(x, y + 90, 90, 30);
    connect(button2, &QPushButton::clicked, this, &Gamepage::buttonClicked2);
    button2->show();

    labellvl3 = new QLabel(this);
    labellvl3->setStyleSheet("background: url(:/res/image/card3-lvl1.png);");
    labellvl3->setFixedSize(90, 90);
    x = 1236;
    y = 30 + 2 * 135;
    labellvl3->move(x, y);
    labellvl3->show();
    QPushButton *button3 = new QPushButton("Action", this);
    button3->setGeometry(x, y + 90, 90, 30);
    connect(button3, &QPushButton::clicked, this, &Gamepage::buttonClicked3);
    button3->show();

    labellvl4 = new QLabel(this);
    labellvl4->setStyleSheet("background: url(:/res/image/card4-lvl1.png);");
    labellvl4->setFixedSize(90, 90);
    x = 1236;
    y = 30 + 3 * 135;
    labellvl4->move(x, y);
    labellvl4->show();
    QPushButton *button4 = new QPushButton("Action", this);
    button4->setGeometry(x, y + 90, 90, 30);
    connect(button4, &QPushButton::clicked, this, &Gamepage::buttonClicked4);
    button4->show();

    labellvl5 = new QLabel(this);
    labellvl5->setStyleSheet("background: url(:/res/image/card5-lvl1.png);");
    labellvl5->setFixedSize(90, 90);
    x = 1236;
    y = 30 + 4 * 135;
    labellvl5->move(x, y);
    labellvl5->show();
    QPushButton *button5 = new QPushButton("Action", this);
    button5->setGeometry(x, y + 90, 90, 30);
    connect(button5, &QPushButton::clicked, this, &Gamepage::buttonClicked5);
    button5->show();
}

void  Gamepage::buttonClicked1()
{
    if ( iron - (200 * level[0]) < 0 ){}
    else {
        if ( level[0] <= 5 )
        {
            iron -= (200 * level[0]);
            level[0] += 1;
        }
        labellvl1->setStyleSheet(QString("background: url(:/res/image/card1-lvl%1.png);").arg(level[0]));
        for (ClickableLabel *t : Gamepage::turrets) {
            if (auto turret_Q8 = dynamic_cast<Turret_Q8*>(t)) {
                turret_Q8->setDamage(turret_Q8->getDamage() * pow(2,(level[0] - 1)));
            }
        }
    }
}
void  Gamepage::buttonClicked2()
{
    if ( iron - (200 * level[1] ) < 0 ){}
    else {
        if ( level[1] <= 5 )
        {
            iron -= (200 * level[1]);
            level[1] += 1;
        }
        labellvl2->setStyleSheet(QString("background: url(:/res/image/card2-lvl%1.png);").arg(level[1]));
        for (ClickableLabel *t : Gamepage::turrets) {
            if (auto turret_q8f = dynamic_cast<Turret_q8f*>(t)) {
                turret_q8f->setDamage(turret_q8f->getDamage() * pow(2,(level[1] - 1)));
            }
        }
    }
}

void Gamepage::buttonClicked3()
{
    if ( iron - ( 200 * level[2]  )< 0){}
    else {
        if ( level[2] <= 5 )
        {
            iron -= (200 * level[2]);
            level[2] += 1;
        }
        labellvl3->setStyleSheet(QString("background: url(:/res/image/card3-lvl%1.png);").arg(level[2]));
        for (ClickableLabel *t : Gamepage::turrets) {
            if (auto turret_q8r = dynamic_cast<Turret_q8r*>(t)) {
                turret_q8r->setDamage(turret_q8r->getDamage() * pow(2,(level[2] - 1)));
            }
        }
    }
}

void  Gamepage::buttonClicked4()
{
    if ( level[3] <= 5 )
    {
        level[3] += 1;
    }
    labellvl4->setStyleSheet(QString("background: url(:/res/image/card4-lvl%1.png);").arg(level[3]));
}

void  Gamepage::buttonClicked5()
{
    if ( level[4] <= 5 )
    {
        level[4] += 1;
    }
    labellvl5->setStyleSheet(QString("background: url(:/res/image/card5-lvl%1.png);").arg(level[4]));
}


void Gamepage::countIron()
{
    iron += 5;
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

    label->setText(QString("%1").arg(labelCount++));
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
        speedWave += 200;
        healthWave += 0.1;
    }
    else {

        timer->setInterval(rand() % 600 + 400);
        ui->label->setText("مبارزه");
    }

    connect(label, &Enemy::animationFinished, this , &Gamepage::onEnemyExited);

    moveObject( label );
}

void Gamepage::timeLabelText()
{
    ui->label->setText(QString(" %1 تا موج بعدی حمله ").arg( icount-- ));

    if ( icount ==  0 )
    {
        timer2->stop();
    }
}

void Gamepage::moveObject( Enemy *label )
{
    animationGroup = new QSequentialAnimationGroup(this);
    QPropertyAnimation *animation0 = new QPropertyAnimation(label, "geometry");
    animation0->setDuration(label->speed);
    animation0->setStartValue(QRect(label->currentPosition.x(), label->currentPosition.y(), label->width(), label->height()));
    animation0->setEndValue(QRect(matrix[{1,2}].first, matrix[{1,2}].second, label->width(), label->height()));
    QPropertyAnimation *animation1 = new QPropertyAnimation(label, "geometry");
    animation1->setDuration(label->speed * 2);
    animation1->setStartValue(QRect(matrix[{1,2}].first, matrix[{1,2}].second, label->width(), label->height()));
    animation1->setEndValue(QRect(matrix[{2,1}].first, matrix[{2,1}].second, label->width(), label->height()));
    QPropertyAnimation *animation6 = new QPropertyAnimation(label, "geometry");
    animation6->setDuration(label->speed);
    animation6->setStartValue(QRect(matrix[{2,1}].first, matrix[{2,1}].second, label->width(), label->height()));
    animation6->setEndValue(QRect(matrix[{2,2}].first, matrix[{2,2}].second, label->width(), label->height()));

    animationGroup->addAnimation(animation0);
    animationGroup->addAnimation(animation1);
    animationGroup->addAnimation(animation6);

    connect(animationGroup, &QSequentialAnimationGroup::finished, this, [ label]()
            {
                //label->deleteLater();
                if ( label->isAlive == true ){
                    emit label->animationFinished();
                }
                Gamepage::enimi.removeOne(label);
                label->hide();
                label->isAlive = false;
            });

    animationGroup->start();
}

void Gamepage::onEnemyExited() {
    enemiesExited++;
    exitCounterLabel->setText(QString("Enemies exited: %1").arg(enemiesExited));
}


void Gamepage::createLabelsInGroupBox(int initialCount)
{
    for (int i = 0; i < initialCount; ++i) {
        ClickableLabel *label;
        int rands = std::rand() % 5 + 1;

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
        default:
            label = new Turret_Q8(this);
            label->setStyleSheet("background: url(:/res/image/card1.png);");
            break;
        }

        label->setFixedSize(90, 90);


        label->status = 0;
        label->select = false;

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
    int rands = std::rand() % 5 + 1;

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
    if (selectedLabel) {
        for (ClickableLabel *t : Gamepage::turrets ) {
            if ( t->select == true )
            {
                if ( t == selectedLabel )
                {

                }
                else {
                    return;
                }
            }
        }
        for (ClickableLabel *t : labels ) {
            if ( t->select == true )
            {
                if ( t == selectedLabel )
                {

                }
                else {
                    return;
                }
            }
        }
        if ( selectedLabel->status != -1 )
        {
            selectedLabel->select = true;
            QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
            opacityEffect->setOpacity(0.5);
            selectedLabel->setGraphicsEffect(opacityEffect);
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

bool Gamepage::isPositionOccupied2(QRect rec , int x ) {
    qDebug()<<"gi";
    for (ClickableLabel *t : Gamepage::turrets) {
        if (t->geometry().intersects(rec)) {
            if (auto turret_q8 = dynamic_cast<Turret_Q8*>(t)) {
                if ( x == 1 ){
                    turret_q8->setActive(false);
                    turret_q8->stopShooting();
                    Gamepage::turrets.removeOne(turret_q8);
                    turret_q8->move(2000,2000);
                    return true;
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

                if ((i + 30 < event->pos().rx() && event->pos().rx()  < i + 70) && (j + 30  < event->pos().ry() && event->pos().ry()  < j + 70))
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

                if ((i + 30 < event->pos().rx() && event->pos().rx()  < i + 70) && (j + 30  < event->pos().ry() && event->pos().ry()  < j + 70))
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



void Gamepage::mousePressEvent(QMouseEvent *event)
{
    if (selectedLabel && event->button() == Qt::LeftButton && selectedLabel->select == true) {
        QPoint previousPosition = selectedLabel->pos();
        QRect newRect(event->pos() - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2), selectedLabel->size());

        if ( selectedLabel->status != -1 )
        {
            if ( checkMap(event) )
            {
                if (!isPositionOccupied(newRect) || selectedLabel->status != 0)
                {

                    if (auto turret1 = dynamic_cast<Turret_Q8 *>(selectedLabel))
                    {
                        if ( selectedLabel->status > 0 ){
                            if ( isPositionOccupied2(newRect , 1) )
                            {
                                selectedLabel->move(event->pos() - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2));
                                selectedLabel->setStyleSheet("background: url(:/res/image/T-2.png);");
                                QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
                                opacityEffect->setOpacity(1);
                                selectedLabel->setGraphicsEffect(opacityEffect);
                                selectedLabel->select = false;
                                turret1->startShotBullet();
                            }
                        }

                        if ( iron - 200 < 0 ){}
                        else {
                            if ( selectedLabel->status == 0 )
                            {
                                createNewLabel(previousPosition);
                                Gamepage::turrets.append(selectedLabel);
                                labels.removeOne(selectedLabel);
                                iron -= 200;
                                selectedLabel->move(event->pos() - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2));
                                selectedLabel->select = false;
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

                        if ( selectedLabel->status > 0 ){
                            if ( isPositionOccupied2(newRect , 1) )
                            {
                                selectedLabel->move(event->pos() - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2));
                                selectedLabel->setStyleSheet("background: url(:/res/image/T-2.png);");
                                QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
                                opacityEffect->setOpacity(1);
                                selectedLabel->setGraphicsEffect(opacityEffect);
                                selectedLabel->select = false;
                                turret2->startShotBullet();
                            }
                        }

                        if ( iron - 200 < 0 ){}
                        else {
                            if ( selectedLabel->status == 0 )
                            {
                                createNewLabel(previousPosition);
                                Gamepage::turrets.append(selectedLabel);
                                labels.removeOne(selectedLabel);
                                iron -= 200;
                                selectedLabel->move(event->pos() - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2));
                                selectedLabel->select = false;
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

                        if ( selectedLabel->status > 0 ){
                            if ( isPositionOccupied2(newRect , 1) )
                            {
                                selectedLabel->move(event->pos() - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2));
                                selectedLabel->setStyleSheet("background: url(:/res/image/T-2.png);");
                                QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
                                opacityEffect->setOpacity(1);
                                selectedLabel->setGraphicsEffect(opacityEffect);
                                selectedLabel->select = false;
                                turret3->startShotBullet();
                            }
                        }

                        if ( iron - 400 < 0 ){}
                        else {
                            if ( selectedLabel->status == 0 )
                            {
                                createNewLabel(previousPosition);
                                Gamepage::turrets.append(selectedLabel);
                                labels.removeOne(selectedLabel);
                                iron -= 400;
                                selectedLabel->move(event->pos() - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2));
                                selectedLabel->select = false;
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
                            selectedLabel->select = false;
                            iron -= 200;
                            //connect(selectedLabel, &Bomb::clicked, selectedLabel, &Bomb::checkCollision);
                            selectedLabel->setStyleSheet("background: url(:/res/image/Bomb.png);");
                            QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
                            opacityEffect->setOpacity(1);
                            selectedLabel->setGraphicsEffect(opacityEffect);
                            selectedLabel->setFixedSize(50, 50);
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
                            selectedLabel->select = false;
                            iron -= 200;
                            //connect(selectedLabel, &Bomb::clicked, selectedLabel, &Bomb::checkCollision);
                            selectedLabel->setStyleSheet("background: url(:/res/image/Bomb2.png);");
                            QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
                            opacityEffect->setOpacity(1);
                            selectedLabel->setGraphicsEffect(opacityEffect);
                            selectedLabel->setFixedSize(50, 50);
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
