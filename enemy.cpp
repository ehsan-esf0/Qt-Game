#include "enemy.h"
#include "gamepage.h"

Enemy::Enemy(QWidget *parent) : QLabel(parent), health(3) {
    setStyleSheet("background-color: green;");
    setFixedSize(50, 50);
    Gamepage::enimi.append(this);
}

Enemy::~Enemy() {
    Gamepage::enimi.removeOne(this);
}

void Enemy::takeHit() {
    health--;
    if (health <= 0) {
        this->hide();
    }
}

bool Enemy::isAlive() const {
    return health > 0;
}
