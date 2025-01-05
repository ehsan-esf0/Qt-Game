#include "Header/fighter111.h"
#include "Header/gamepage.h"


fighter111::fighter111(QWidget *parent) : Enemy(parent) {
    setPixmap(QPixmap(":/res/image/enimi1.png"));
    setFixedSize(50, 50);
    isAlive = true;
    health = 50;
    Gamepage::enimi.append(this);
    speed = 3000;
}

fighter111::~fighter111() {
    //Gamepage::enimi.removeOne(this);
}

void fighter111::takeHit(int hit) {
    health -= hit;
    if (health <= 0)
    {
        isAlive = false;
        Gamepage::enimi.removeOne(this);
        playDeathAnimation();

        QTimer::singleShot(300, this, &fighter111::hide);
    }
}

void fighter111::playDeathAnimation() {
    QLabel *label = new QLabel(this);
    label->setFixedSize(50,50);
    label->setStyleSheet("background:url(:/res/image/boom2.png);");
    label->show();
}
