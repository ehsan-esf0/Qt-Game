#include "fighter111.h"
#include "gamepage.h"


fighter111::fighter111(QWidget *parent) : Enemy(parent) {
    setStyleSheet("background:url(:/res/image/enimi1.png);");
    setFixedSize(50, 50);
    isAlive = true;
    health = 6;
    Gamepage::enimi.append(this);
    speed = 3000;
}

fighter111::~fighter111() {
    //Gamepage::enimi.removeOne(this);
}

void fighter111::takeHit() {
    health--;
    if (health <= 0)
    {
        isAlive = false;
        Gamepage::enimi.removeOne(this);
        //this->deleteLater();
        this->hide();
    }
}


