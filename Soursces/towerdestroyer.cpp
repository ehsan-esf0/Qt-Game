#include "Header/towerdestroyer.h"
#include "Header/gamepage.h"
#include "Header/turret_q8f.h"
#include "Header/turret_q8r.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>

TowerDestroyer::TowerDestroyer(QWidget *parent) : Enemy(parent) {
    setStyleSheet("background:url(:/res/image/enimi3.png);");
    setFixedSize(50, 50);
    isAlive = true;
    health = 2000;
    speed = 3000;

    Gamepage::enimi.append(this);

    destructionTimer = new QTimer(this);
    connect(destructionTimer, &QTimer::timeout, this, &TowerDestroyer::attemptToDestroyTower);
    destructionTimer->start(5000);

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

TowerDestroyer::~TowerDestroyer() {
    //Gamepage::enimi.removeOne(this);
}

void TowerDestroyer::attemptToDestroyTower() {
    if (!isAlive) {
        return;
    }

    if (Gamepage::turrets.isEmpty()) {
        return;
    }


    int randomIndex = std::rand() % Gamepage::turrets.size();
    ClickableLabel *tower = Gamepage::turrets[randomIndex];

    if (tower) {
        Gamepage::turrets.removeAt(randomIndex);
        if ( auto turret1 = dynamic_cast<Turret_Q8*>(tower) )
        {
            turret1->stopShooting();
            turret1->setActive(false);
            turret1->hide();
            turret1->move(2000,1000);
        }
        if ( auto turret2 = dynamic_cast<Turret_q8f*>(tower) )
        {
            turret2->stopShooting();
            turret2->setActive(false);
            turret2->hide();
            turret2->move(2000,1000);
        }
        if ( auto turret3 = dynamic_cast<Turret_q8r*>(tower) )
        {
            turret3->stopShooting();
            turret3->setActive(false);
            turret3->hide();
            turret3->move(2000,1000);
        }
        tower->deleteLater();
        qDebug() << "Random tower destroyed!";
    }
}

void TowerDestroyer::takeHit(int hit) {
    health -= hit;
    if (health <= 0)
    {
        isAlive = false;
        Gamepage::enimi.removeOne(this);
        playDeathAnimation();

        QTimer::singleShot(3000, this, &TowerDestroyer::hide);
    }
}

void TowerDestroyer::playDeathAnimation() {
    QLabel *label = new QLabel(this);
    label->setFixedSize(50,50);
    label->setStyleSheet("background:url(:/res/image/boom3.png);");
    label->show();
}

