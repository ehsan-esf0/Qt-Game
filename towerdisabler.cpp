#include "towerdisabler.h"
#include "gamepage.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include "turret_q8.h"
#include "turret_q8f.h"
#include "turret_q8r.h"

TowerDisabler::TowerDisabler(QWidget *parent) : Enemy(parent) {
    setStyleSheet("background:url(:/res/image/enimi4.png);");
    setFixedSize(50, 50);
    isAlive = true;
    health = 5;
    speed = 3000;

    Gamepage::enimi.append(this);


    disableTimer = new QTimer(this);
    connect(disableTimer, &QTimer::timeout, this, &TowerDisabler::attemptToDisableTower);
    disableTimer->start(5000);


    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

TowerDisabler::~TowerDisabler() {
    //Gamepage::enimi.removeOne(this);
}

void TowerDisabler::attemptToDisableTower() {
    if (!isAlive) {
        return;
    }

    if (Gamepage::turrets.isEmpty()) {
        return;
    }


    int randomIndex = std::rand() % Gamepage::turrets.size();
    ClickableLabel *tower = Gamepage::turrets[randomIndex];

    if (auto turret1 = dynamic_cast<Turret_Q8*>(tower)) {
        if (turret1->isActive()) {
            turret1->stopShooting();
            turret1->setActive(false);
            disabledTowers.append(turret1);
            qDebug() << "Random turret1 disabled!";
        }
    } else if (auto turret2 = dynamic_cast<Turret_q8f*>(tower)) {
        if (turret2->isActive()) {
            turret2->stopShooting();
            turret2->setActive(false);
            disabledTowers.append(turret2);
            qDebug() << "Random turret2 disabled!";
        }
    } else if (auto turret3 = dynamic_cast<Turret_q8r*>(tower)) {
        if (turret3->isActive()) {
            turret3->stopShooting();
            turret3->setActive(false);
            disabledTowers.append(turret3);
            qDebug() << "Random turret3 disabled!";
        }
    }
}

void TowerDisabler::takeHit(int hit) {
    health -= hit;
    if (health <= 0) {
        isAlive = false;
        Gamepage::enimi.removeOne(this);
        this->hide();

        for (ClickableLabel *tower : disabledTowers) {
            if (auto turret1 = dynamic_cast<Turret_Q8*>(tower)) {
                turret1->setActive(true);
                turret1->startShotBullet();
                qDebug() << "Turret1 re-enabled!";
            } else if (auto turret2 = dynamic_cast<Turret_q8f*>(tower)) {
                turret2->setActive(true);
                turret2->startShotBullet();
                qDebug() << "Turret2 re-enabled!";
            } else if (auto turret3 = dynamic_cast<Turret_q8r*>(tower)) {
                turret3->setActive(true);
                turret3->startShotBullet();
                qDebug() << "Turret3 re-enabled!";
            }
        }
        qDebug() << "TowerDisabler died and re-enabled turrets!";
    }
}
