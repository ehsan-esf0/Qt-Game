#ifndef ENEMY_H
#define ENEMY_H

#include <QLabel>

class Enemy : public QLabel {
    Q_OBJECT

public:
    explicit Enemy(QWidget *parent = nullptr);
    ~Enemy();

    virtual void takeHit();
    void updateAnimationSpeed();
    void restoreSpeed();
    bool isAlive;
    int speed;
    QPoint currentPosition;

protected:
    int health;

signals:
    void animationFinished();
};

#endif // ENEMY_H
