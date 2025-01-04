#ifndef TURRET_Q8M_H
#define TURRET_Q8M_H

#include "Header/bullet.h"
#include "Header/clickablelabel.h"

class Turret_q8m : public ClickableLabel
{
    Q_OBJECT
private:
    QVector<Bullet*> bullet;
    QTimer *timer;
    QVector<QLabel*> label;
    bool active;
    int i;
public:
    void shotBullet();
    explicit Turret_q8m(QWidget *parent = nullptr);
    QVector<QLabel*> enimi;
    void startShooting();
    void stopShooting();
    bool isActive();
    void setActive( bool x);
    void startShotBullet();
    void getLabel(QVector<QLabel *> l);
};

#endif // TURRET_Q8_H
