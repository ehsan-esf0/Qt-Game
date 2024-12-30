#include "gamepage.h"
#include "bomb.h"
#include "fighter298.h"
#include "fighter111.h"
#include "ice_bomb.h"
#include "mainwindow.h"
#include "qpropertyanimation.h"
#include "savegamedata.h"
#include "selectmap.h"
#include "towerdestroyer.h"
#include "bombdisabler.h"
#include "towerdisabler.h"
#include "turret_q8.h"
#include "turret_q8f.h"
#include "turret_q8r.h"
#include "ui_gamepage.h"
#include <QThread>
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>
#include <QLabel>
#include <QTabWidget>
#include <QVBoxLayout>
#include "clickablelabel.h"

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
    labelCount = 1;
    wCount = 10;
    timeCount = 10000;
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

    createLabelsInGroupBox(4);

    label_2 = new QLabel(saveGameData::str, this);
    label_2->setFixedSize(200, 50);
    int x = 100;
    int y = 50;
    label_2->move(x, y);
    label_2->show();

    timer3 = new QTimer(this);
    connect(timer3, &QTimer::timeout, this, &Gamepage::countIron);
    timer3->start(1000);
    iron = 2000;
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

}

void Gamepage::countIron()
{
    iron += 100;
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
    int rands = std::rand() % 4 + 1;

    switch (rands) {
    case 1:
        label = new Fighter298(this);
        break;
    case 2:
        label = new fighter111(this);
        break;
    // case 3:
    //     label = new TowerDestroyer(this);
    //     break;
    case 4:
        label = new BombDisabler(this);
        break;
    default:
        label = new Fighter298(this);
        break;
    }
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
        timeCount += 5000;
        icount = (timeCount / 1000);
        timer->setInterval(timeCount);
        timer2->start(1000);
        labelCount = 1;
        wCount += 10;
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


        label->status = true;

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
    label->status = true;

    connect(label, &ClickableLabel::clicked, this, &Gamepage::labelClicked);

    label->move(position);
    label->show();

    labels.append(label);
}

void Gamepage::labelClicked()
{
    selectedLabel = qobject_cast<ClickableLabel*>(sender());
    if (selectedLabel) {
        if ( selectedLabel->status == true )
        {
            selectedLabel->setStyleSheet("background-color: red;");
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
    if (selectedLabel && event->button() == Qt::LeftButton) {
        QPoint previousPosition = selectedLabel->pos();
        QRect newRect(event->pos() - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2), selectedLabel->size());

        if ( selectedLabel->status == true )
        {
            if ( checkMap(event) )
            {
                if (!isPositionOccupied(newRect))
                {

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

                    if (auto turret1 = dynamic_cast<Turret_Q8 *>(selectedLabel))
                    {
                        if ( iron - 500 < 0 ){}
                        else {
                            selectedLabel->move(event->pos() - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2));
                            iron -= 500;
                            turret1->startShotBullet();
                            selectedLabel->setFixedSize(90, 60);
                            selectedLabel->setStyleSheet("background: url(:/res/image/T.png);");
                            selectedLabel->status = false;
                            Gamepage::turrets.append(selectedLabel);
                            selectedLabel = nullptr;
                            createNewLabel(previousPosition);
                            labels.removeOne(selectedLabel);
                        }
                    } else if (auto turret2 = dynamic_cast<Turret_q8f *>(selectedLabel))
                    {
                        if ( iron - 700 < 0 ){}
                        else {
                            selectedLabel->move(event->pos() - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2));
                            iron -= 700;
                            turret2->startShotBullet();
                            selectedLabel->setStyleSheet("background: url(:/res/image/T1.png);");
                            selectedLabel->setFixedSize(90, 60);
                            selectedLabel->status = false;
                            Gamepage::turrets.append(selectedLabel);
                            selectedLabel = nullptr;
                            createNewLabel(previousPosition);
                            labels.removeOne(selectedLabel);
                        }
                    } else if (auto turret3 = dynamic_cast<Turret_q8r *>(selectedLabel))
                    {
                        if ( iron - 1000 < 0 ){}
                        else {
                            selectedLabel->move(event->pos() - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2));
                            iron -= 1000;
                            turret3->startShotBullet();
                            selectedLabel->setStyleSheet("background: url(:/res/image/T2.png);");
                            selectedLabel->setFixedSize(90, 60);
                            selectedLabel->status = false;
                            Gamepage::turrets.append(selectedLabel);
                            selectedLabel = nullptr;
                            createNewLabel(previousPosition);
                            labels.removeOne(selectedLabel);
                        }
                    }
                }
            }
            else {
                if (!isPositionOccupied(newRect))
                {
                    if (auto turret1 = dynamic_cast<Bomb *>(selectedLabel))
                    {
                        if ( iron - 500 < 0 ){}
                        else {
                            selectedLabel->move(event->pos() - QPoint(selectedLabel->width() / 2 - 20, selectedLabel->height() / 2 - 20));
                            iron -= 500;
                            //connect(selectedLabel, &Bomb::clicked, selectedLabel, &Bomb::checkCollision);
                            selectedLabel->setStyleSheet("background: url(:/res/image/Bomb.png);");
                            selectedLabel->setFixedSize(50, 50);
                            selectedLabel->status = false;
                            Gamepage::bombs.append(selectedLabel);
                            selectedLabel = nullptr;
                            createNewLabel(previousPosition);
                            labels.removeOne(selectedLabel);
                        }
                    }
                    else if (auto turret2 = dynamic_cast<Ice_Bomb *>(selectedLabel)) {
                        if ( iron - 300 < 0 ){}
                        else {
                            selectedLabel->move(event->pos() - QPoint(selectedLabel->width() / 2 - 20, selectedLabel->height() / 2 - 20));
                            iron -= 300;
                            //connect(selectedLabel, &Bomb::clicked, selectedLabel, &Bomb::checkCollision);
                            selectedLabel->setStyleSheet("background: url(:/res/image/Bomb2.png);");
                            selectedLabel->setFixedSize(50, 50);
                            selectedLabel->status = false;
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


