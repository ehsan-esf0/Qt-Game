#include "towerdestroyer.h"
#include "gamepage.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>

TowerDestroyer::TowerDestroyer(QWidget *parent) : Enemy(parent) {
    setStyleSheet("background:url(:/res/image/enimi3.png);");
    setFixedSize(50, 50);
    isAlive = true;
    health = 6;
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
        tower->deleteLater();
        qDebug() << "Random tower destroyed!";
    }
}

void TowerDestroyer::takeHit() {
    health--;
    if (health <= 0)
    {
        isAlive = false;
        Gamepage::enimi.removeOne(this);
        //this->deleteLater();
        this->hide();
    }
}

