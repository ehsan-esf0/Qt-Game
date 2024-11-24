#include "bullet.h"

Bullet::Bullet(QWidget *parent) : QLabel(parent), animation(new QPropertyAnimation(this, "pos")), moveTimer(new QTimer(this)) {
    setStyleSheet("background-color: black;border-radius: 5%;");
    setFixedSize(10, 10);
    connect(moveTimer, &QTimer::timeout, this, &Bullet::moveBullet);
    connect(animation, &QPropertyAnimation::finished, this, &Bullet::onAnimationFinished);
}

void Bullet::shoot(const QPoint &start, QLabel *targetLabel) {
    this->targetLabel = targetLabel;
    move(start);
    show();

    animation->setDuration(2000);
    moveTimer->start(20);
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

        if ((currentPos - (targetLabel->pos() + QPoint(targetLabel->width() / 2, targetLabel->height() / 2))).manhattanLength() < 60 ) {
            moveTimer->stop();
            //targetLabel->hide();
            delete this;
        }
    }
}

void Bullet::onAnimationFinished() {

}
