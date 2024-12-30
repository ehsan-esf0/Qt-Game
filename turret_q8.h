#ifndef TURRET_Q8_H
#define TURRET_Q8_H

#include "bullet.h"
#include "clickablelabel.h"

class Turret_Q8 : public ClickableLabel
{
private:
    QVector<Bullet*> bullet;
    QTimer *timer;
    QVector<QLabel*> label;
    bool active;
    int i;
public:
    void shotBullet();
    explicit Turret_Q8(QWidget *parent = nullptr);
    QVector<QLabel*> enimi;
    void startShooting();
    void stopShooting();
    bool isActive();
    void setActive( bool x);
    void startShotBullet();
    void getLabel(QVector<QLabel *> l);
};

#endif // TURRET_Q8_H
