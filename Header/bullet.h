#ifndef BULLET_H
#define BULLET_H

#include "enemy.h"
#include <QLabel>
#include <QTimer>
#include <QPropertyAnimation>
#include <QPointer>

class Bullet : public QLabel {
    Q_OBJECT

public:
    explicit Bullet(QWidget *parent = nullptr);
    void shoot(const QPoint &start, QPointer<Enemy> targetLabel);
    void updateTarget();
    void setDamage( int x );

private slots:
    void moveBullet();
    void onAnimationFinished();
    void checkTarget();


private:
    QPropertyAnimation *animation;
    QPointer<Enemy> targetLabel;
    QTimer *moveTimer;
    QTimer *checkTimer;
    int damage;
};

#endif
