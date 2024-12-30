#include "enemy.h"
#include "gamepage.h"

Enemy::Enemy(QWidget *parent) : QLabel(parent){
    setFixedSize(50, 50);
    //Gamepage::enimi.append(this);
}

Enemy::~Enemy() {
    //Gamepage::enimi.removeOne(this);
}

void Enemy::takeHit(int hit) {
}

void Enemy::updateAnimationSpeed()
{
    if (isAlive)
    {
        Gamepage *gamePage = qobject_cast<Gamepage *>(parentWidget());
        if (gamePage)
        {
            this->currentPosition.setX(this->x());
            this->currentPosition.setY(this->y());
            gamePage->moveObject(this);
        }
    }
}

void Enemy::restoreSpeed()
{
    speed /= 2;
    updateAnimationSpeed();
}

