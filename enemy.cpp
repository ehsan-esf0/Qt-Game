#include "enemy.h"
#include "gamepage.h"

Enemy::Enemy(QWidget *parent) : QLabel(parent){
    setFixedSize(50, 50);
    //Gamepage::enimi.append(this);
}

Enemy::~Enemy() {
    //Gamepage::enimi.removeOne(this);
}

void Enemy::takeHit() {
}


