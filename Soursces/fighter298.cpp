#include "Header/fighter298.h"
#include "Header/gamepage.h"

Fighter298::Fighter298(QWidget *parent) : Enemy(parent) {
    setStyleSheet("background:url(:/res/image/enimi.png);");
    setFixedSize(50, 50);
    isAlive = true;
    health = 100;
    Gamepage::enimi.append(this);
    speed = 4000;
}

Fighter298::~Fighter298() {
    //Gamepage::enimi.removeOne(this);
}

void Fighter298::takeHit(int hit) {
    health -= hit;
    if (health <= 0)
    {
        isAlive = false;
        Gamepage::enimi.removeOne(this);
        //this->deleteLater();
        this->hide();
    }
}

