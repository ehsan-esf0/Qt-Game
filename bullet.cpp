#include "bullet.h"
#include "gamepage.h"

Bullet::Bullet(QWidget *parent) : QLabel(parent), animation(new QPropertyAnimation(this, "pos")), moveTimer(new QTimer(this)), checkTimer(new QTimer(this)) {
    setStyleSheet("background-color: black;border-radius: 5%;");
    setFixedSize(10, 10);
    connect(moveTimer, &QTimer::timeout, this, &Bullet::moveBullet);
    connect(animation, &QPropertyAnimation::finished, this, &Bullet::onAnimationFinished);
    connect(checkTimer, &QTimer::timeout, this, &Bullet::checkTarget);
}

void Bullet::shoot(const QPoint &start, QPointer<Enemy> targetLabel) {
    this->targetLabel = targetLabel;
    int x = start.x() + 85;
    int y = start.y() + 25;
    move(x , y);
    show();

    animation->setDuration(2000);
    moveTimer->start(20);
    checkTimer->start(50);
}

void Bullet::moveBullet() {
    if (targetLabel) {
        QPoint targetPos = targetLabel->pos() + QPoint(targetLabel->width() / 2, targetLabel->height() / 2);
        QPoint currentPos = pos() + QPoint(width() / 2, height() / 2);

        int dx = targetPos.x() - currentPos.x();
        int dy = targetPos.y() - currentPos.y();

        currentPos.setX(currentPos.x() + dx / 10);
        currentPos.setY(currentPos.y() + dy / 10);

        move(currentPos - QPoint(width() / 2, height() / 2));

        if ((currentPos - targetPos).manhattanLength() < 60) {
            moveTimer->stop();
            if (targetLabel) {
                targetLabel->takeHit(1);
            }
            qDebug() << "Bullet hit target!";
            this->deleteLater();
            hide();
        }
    }
}

void Bullet::checkTarget() {
    if (!targetLabel || !targetLabel->isAlive) {
        updateTarget();
        checkTimer->stop();
        hide();
        qDebug() << "Bullet target lost, deleting bullet";
        //delete this;
    }
}


void Bullet::onAnimationFinished() {
    hide();
    //delete this;
}

void Bullet::updateTarget() {

    checkTimer->stop();
        for (Enemy *enemy : Gamepage::enimi ) {

            if (enemy->isAlive) {

                targetLabel = enemy;
                animation->setEndValue(targetLabel->pos() + QPoint(targetLabel->width() / 2, targetLabel->height() / 2));
                animation->start();
                checkTimer->start(1);

                return;
            }
        }
        hide();
        //delete this;
}

