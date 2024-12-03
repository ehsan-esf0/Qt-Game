#ifndef BULLET_H
#define BULLET_H

#include "enemy.h"
#include <QLabel>
#include <QTimer>
#include <QPropertyAnimation>

class Bullet : public QLabel {
    Q_OBJECT

public:
    explicit Bullet(QWidget *parent = nullptr);
    void shoot(const QPoint &start, Enemy *targetLabel);

private slots:
    void moveBullet();
    void onAnimationFinished();
    void checkTarget();

private:
    QPropertyAnimation *animation;
    Enemy *targetLabel;
    QTimer *moveTimer;
    QTimer *checkTimer;
};

#endif
