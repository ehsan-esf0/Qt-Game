#include "Header/enemy.h"
#include "Header/gamepage.h"
#include <QPainter>

Enemy::Enemy(QWidget *parent) : BaseEnemy(parent){
    setFixedSize(50, 50);
    //Gamepage::enimi.append(this);
}

Enemy::~Enemy() {
    //Gamepage::enimi.removeOne(this);
}

void Enemy::takeHit(int hit) {
}

void Enemy::setRotationAngle(int angle) {
    rotationAngle = angle;
    update(); // نقاشی مجدد ویجت
}

void Enemy::setPixmap(const QPixmap &pixmap) {
    enemyPixmap = pixmap;
    update(); // نقاشی مجدد ویجت
}

void Enemy::paintEvent(QPaintEvent *event) {
    BaseEnemy::paintEvent(event);

    if (!enemyPixmap.isNull()) {
        QPainter painter(this);
        QTransform transform;
        transform.translate(width() / 2, height() / 2); // انتقال مرکز چرخش به مرکز ویجت
        transform.rotate(rotationAngle);
        transform.translate(-width() / 2, -height() / 2); // بازگرداندن مرکز چرخش
        painter.setTransform(transform);

        painter.drawPixmap(0, 0, enemyPixmap.scaled(width(), height())); // تصویر چرخیده شده
    }
}

void Enemy::updateAnimationSpeed()
{
    if (isAlive)
    {
        Gamepage *gamePage = qobject_cast<Gamepage *>(parentWidget());
        if (gamePage)
        {
            this->currentPosition.setX(this->x());
            this->currentPosition.setY(this->y());
            gamePage->moveObject(this);
        }
    }
}

void Enemy::restoreSpeed()
{
    speed /= 2;
    updateAnimationSpeed();
}

void Enemy::setHealth( float x )
{
    health = x;
}

float Enemy::getHealth()
{
    return health;
}
