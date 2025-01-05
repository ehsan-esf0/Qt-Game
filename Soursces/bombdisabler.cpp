#include "Header/bombdisabler.h"
#include "Header/bomb.h"
#include "Header/gamepage.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include "Header/bomb.h"
#include "Header/ice_bomb.h"

BombDisabler::BombDisabler(QWidget *parent) : Enemy(parent) {
    setPixmap(QPixmap(":/res/image/enimi2.png"));
    setFixedSize(50, 50);
    isAlive = true;
    health = 2000;
    speed = 3000;

    Gamepage::enimi.append(this);


    disableTimer = new QTimer(this);
    connect(disableTimer, &QTimer::timeout, this, &BombDisabler::disableNearbyBombs);
    disableTimer->start(10);
}

BombDisabler::~BombDisabler() {
    //Gamepage::enimi.removeOne(this);
}

void BombDisabler::disableNearbyBombs() {
    if (!isAlive) {
        return;
    }

    for (ClickableLabel *bomb : Gamepage::bombs) {
        QRect bombArea = bomb->geometry().adjusted(-100, -100, 100, 100);
        if (bombArea.intersects(this->geometry())) {
            if (auto bomb1 = dynamic_cast<Bomb*>(bomb)) {
                if (bomb1->isActive) {
                    bomb1->isActive = false;
                    bomb1->hide();
                    Gamepage::bombs.removeOne(bomb1);
                    qDebug() << "Bomb destroyed!";
                }
            } else if (auto bomb2 = dynamic_cast<Ice_Bomb*>(bomb)) {
                if (bomb2->isActive) {
                    bomb2->isActive = false;
                    bomb2->hide();
                    Gamepage::bombs.removeOne(bomb2);
                    qDebug() << "Ice bomb destroyed!";
                }
            }
        }
    }
}

void BombDisabler::takeHit(int hit) {
    health -= hit;
    if (health <= 0)
    {
        isAlive = false;
        Gamepage::enimi.removeOne(this);
        playDeathAnimation();

        QTimer::singleShot(300, this, &BombDisabler::hide);
    }
}

void BombDisabler::playDeathAnimation() {
    QLabel *label = new QLabel(this);
    label->setFixedSize(50,50);
    label->setStyleSheet("background:url(:/res/image/boom3.png);");
    label->show();
}

