#include "Header/fighter298.h"
#include "Header/gamepage.h"
#include <QMovie>

Fighter298::Fighter298(QWidget *parent) : Enemy(parent) {
    setPixmap(QPixmap(":/res/image/enimi.png"));
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
        playDeathAnimation();

        QTimer::singleShot(300, this, &Fighter298::hide);
    }
}

void Fighter298::playDeathAnimation() {
    QLabel *label = new QLabel(this);
    label->setFixedSize(50,50);
    label->setStyleSheet("background:url(:/res/image/boom.png);");
    label->show();
}

