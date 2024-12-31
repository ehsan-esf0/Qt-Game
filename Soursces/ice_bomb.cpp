#include "ice_bomb.h"
#include "gamepage.h"
#include <QDebug>

Ice_Bomb::Ice_Bomb(QWidget *parent) : ClickableLabel(parent), isActive(true) {
    connect(this, &Ice_Bomb::bombExploded, this, &Ice_Bomb::handleBombExplosion);

    setStyleSheet("background: url(:/res/image/bomb.png);");
    setFixedSize(50, 50);

    QTimer *collisionTimer = new QTimer(this);
    connect(collisionTimer, &QTimer::timeout, this, &Ice_Bomb::checkCollision);
    collisionTimer->start(100);
}

void Ice_Bomb::checkCollision() {
    if (isActive) {
        QList<Enemy*> collidedEnemies;

        for (Enemy *enemy : Gamepage::enimi) {
            if (this->geometry().adjusted(-50, -50, 50, 50).intersects(enemy->geometry())) {
                collidedEnemies.append(enemy);
            }
        }

        if (!collidedEnemies.isEmpty()) {
            for (Enemy *enemy : collidedEnemies) {
                enemy->speed *= 2;
                enemy->updateAnimationSpeed();


                QTimer::singleShot(3000, enemy, &Enemy::restoreSpeed);
            }

            emit bombExploded();
        }
    }
}

void Ice_Bomb::handleBombExplosion() {
    qDebug() << "Bomb exploded and slowed down enemies!";
    isActive = false;
    this->hide();
}
