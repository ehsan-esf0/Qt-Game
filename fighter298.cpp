#include "fighter298.h"
#include "gamepage.h"

Fighter298::Fighter298(QWidget *parent) : Enemy(parent) {
    setStyleSheet("background:url(:/res/image/enimi.png);");
    setFixedSize(50, 50);
    isAlive = true;
    health = 4;
    Gamepage::enimi.append(this);
}

Fighter298::~Fighter298() {
    //Gamepage::enimi.removeOne(this);
}

void Fighter298::takeHit() {
    health--;
    if (health <= 0)
    {
        isAlive = false;
        Gamepage::enimi.removeOne(this);
        //this->deleteLater();
        this->hide();
    }
}

