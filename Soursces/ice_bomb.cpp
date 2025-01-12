#include "Header/ice_bomb.h"
#include "Header/gamepage.h"
#include <QDebug>

Ice_Bomb::Ice_Bomb(QWidget *parent) : ClickableLabel(parent), isActive(true) {
    connect(this, &Ice_Bomb::bombExploded, this, &Ice_Bomb::handleBombExplosion);
    connect(this, &Ice_Bomb::Release, this, &Ice_Bomb::ReleaseTheBomb);

    setStyleSheet("background: url(:/res/image/bomb.png);");
    setFixedSize(50, 50);

    QTimer *collisionTimer = new QTimer(this);
    connect(collisionTimer, &QTimer::timeout, this, &Ice_Bomb::checkCollision);
    collisionTimer->start(100);
    bombLabel = new QLabel(qobject_cast<Gamepage*>(parentWidget()));
}

void Ice_Bomb::ReleaseTheBomb()
{
    bombLabel->setStyleSheet("background: url(:/res/image/BombR1-ice.png);");
    bombLabel->setFixedSize(50, 70);
    bombLabel->move(this->x(), this->y() - 300);
    bombLabel->show();
    animateBombLabel();
}

void Ice_Bomb::animateBombLabel() {
    QPropertyAnimation *animation = new QPropertyAnimation(bombLabel, "geometry");
    animation->setDuration(150);
    animation->setStartValue(QRect(bombLabel->x(), bombLabel->y(), bombLabel->width(), bombLabel->height()));
    animation->setEndValue(QRect(this->x(), this->y() + 10, bombLabel->width(), bombLabel->height()));
    animation->start();
    connect(animation , &QPropertyAnimation::finished , this , &Ice_Bomb::deleteBomb);
}

void Ice_Bomb::deleteBomb()
{
    bombLabel->hide();
    bombLabel->move(1000,2000);
}

void Ice_Bomb::checkCollision() {
    if (isActive) {
        QList<Enemy*> collidedEnemies;

        for (Enemy *enemy : Gamepage::enimi) {
            if (this->geometry().adjusted(-range, -range, range, range).intersects(enemy->geometry())) {
                emit Release();
                collidedEnemies.append(enemy);
            }
        }

        if (!collidedEnemies.isEmpty()) {
            for (Enemy *enemy : collidedEnemies) {
                enemy->speed *= 2;
                enemy->updateAnimationSpeed();


                QTimer::singleShot(3000, enemy, &Enemy::restoreSpeed);

                QLabel *label = new QLabel(enemy);
                label->setFixedSize(50,50);
                label->setStyleSheet("background:url(:/res/image/ice3.png);");
                label->show();

                QTimer::singleShot(3000, enemy, [label]() {
                    label->hide();
                });
            }
            emit bombExploded();
        }
    }
}

void Ice_Bomb::handleBombExplosion() {
    qDebug() << "Bomb exploded and slowed down enemies!";
    isActive = false;
    this->hide();
    this->move(2000 ,1000);
}

void Ice_Bomb::setRange( int x){
    range = x;
}
int Ice_Bomb::getRange(){
    return range;
}
