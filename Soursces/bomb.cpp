#include "qnamespace.h"
#include "qtimer.h"
#include "qpropertyanimation.h"
#include "qsequentialanimationgroup.h"
#include "Header/bomb.h"
#include "Header/gamepage.h"

Bomb::Bomb(QWidget *parent) : ClickableLabel(parent) {
    connect(this, &Bomb::bombExploded, this, &Bomb::handleBombExplosion);
    connect(this, &Bomb::Release, this, &Bomb::ReleaseTheBomb);

    setStyleSheet("background: url(:/res/image/bomb.png);");
    setFixedSize(50, 50);

    QTimer *collisionTimer = new QTimer(this);
    connect(collisionTimer, &QTimer::timeout, this, &Bomb::checkCollision);
    collisionTimer->start(100);
    isActive = true;
    damage = 2000;
    bombLabel = new QLabel(qobject_cast<Gamepage*>(parentWidget()));

    range = 50;
}

void Bomb::ReleaseTheBomb()
{
    bombLabel->setStyleSheet("background: url(:/res/image/BombR1.png);");
    bombLabel->setFixedSize(50, 70);
    bombLabel->move(this->x(), this->y() - 300);
    bombLabel->show();
    animateBombLabel();
}

void Bomb::animateBombLabel() {
    QPropertyAnimation *animation = new QPropertyAnimation(bombLabel, "geometry");
    animation->setDuration(150);
    animation->setStartValue(QRect(bombLabel->x(), bombLabel->y(), bombLabel->width(), bombLabel->height()));
    animation->setEndValue(QRect(this->x(), this->y() + 10, bombLabel->width(), bombLabel->height()));
    animation->start();
    connect(animation , &QPropertyAnimation::finished , this , &Bomb::deleteBomb);
}

void Bomb::deleteBomb()
{
    bombLabel->hide();
    bombLabel->move(1000,2000);
}

void Bomb::checkCollision() {
    if (isActive == true) {

        QList<Enemy*> collidedEnemies;

        for (Enemy *enemy : Gamepage::enimi) {
            if (this->geometry().adjusted(-range, -range, range, range).intersects(enemy->geometry())) {
                emit Release();
                collidedEnemies.append(enemy);
            }
        }

        if (!collidedEnemies.isEmpty()) {
            for (Enemy *enemy : collidedEnemies) {
                enemy->takeHit(damage);
            }

            emit bombExploded();

        }

        // Check collision with bombLabel
        if (bombLabel->geometry().adjusted(-50, -50, 50, 50).intersects(this->geometry())) {
            qDebug() << "Bomb collided with bombLabel!";
            bombLabel->hide();
        }
    }
}

void Bomb::handleBombExplosion() {
    qDebug() << "Bomb exploded and removed enemies!";
    isActive = false;
    this->hide();
    this->move(2000, 1000);
}

void Bomb::setRange( int x){
    range = x;
}
int Bomb::getRange(){
    return range;
}
