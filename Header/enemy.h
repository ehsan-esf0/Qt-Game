#ifndef ENEMY_H
#define ENEMY_H

#include <QLabel>
#include "Header/BaseEnemy.h"

class Enemy : public BaseEnemy {
    Q_OBJECT

public:
    explicit Enemy(QWidget *parent = nullptr);
    ~Enemy();

    virtual void takeHit( int hit );
    void updateAnimationSpeed();
    void restoreSpeed();
    bool isAlive;
    int speed;
    QPoint currentPosition;
    void setHealth( float x );
    float getHealth();
    void setRotationAngle(int angle);
    void setPixmap(const QPixmap &pixmap);
    void paintEvent(QPaintEvent *event) override;

protected:
    float health;

signals:
    void animationFinished();
private:
    int rotationAngle;
    QPixmap enemyPixmap;
};

#endif // ENEMY_H
