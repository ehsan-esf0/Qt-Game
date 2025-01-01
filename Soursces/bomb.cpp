#include "qnamespace.h"
#include "qtimer.h"
#include "Header/bomb.h"
#include "Header/gamepage.h"

Bomb::Bomb(QWidget *parent) : ClickableLabel(parent) {
    connect(this, &Bomb::bombExploded, this, &Bomb::handleBombExplosion);

    setStyleSheet("background: url(:/res/image/bomb.png);");
    setFixedSize(50, 50);


    QTimer *collisionTimer = new QTimer(this);
    connect(collisionTimer, &QTimer::timeout, this, &Bomb::checkCollision);
    collisionTimer->start(100);
    isActive = true;
    damage = 2000;
}

void Bomb::checkCollision() {
    if ( isActive == true )
    {
        QList<Enemy*> collidedEnemies;

        for (Enemy *enemy : Gamepage::enimi) {
            if (this->geometry().adjusted(-50, -50, 50, 50).intersects(enemy->geometry())) {
                collidedEnemies.append(enemy);
            }
        }

        if (!collidedEnemies.isEmpty()) {
            for (Enemy *enemy : collidedEnemies) {
                enemy->takeHit(damage);
            }

            emit bombExploded();
        }
    }
}

void Bomb::handleBombExplosion() {

    qDebug() << "Bomb exploded and removed enemies!";
    isActive = false;
    this->hide();
    this->move(2000 ,1000);
}
