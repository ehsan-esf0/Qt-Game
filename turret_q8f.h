#ifndef TURRET_Q8F_H
#define TURRET_Q8F_H

#include "bullet.h"
#include "clickablelabel.h"

class Turret_q8f : public ClickableLabel
{
    Q_OBJECT

public:
    explicit Turret_q8f(QWidget *parent = nullptr);
    ~Turret_q8f();
    QVector<QLabel*> enimi;
    void startShooting();
    void stopShooting();
    bool isActive();
    void setActive( bool x);
    void startShotBullet();
    void getLabel(QVector<QLabel *> l);
    void shotBullet();

private:
    QVector<Bullet*> bullet;
    QTimer *timer;
    QVector<QLabel*> label;
    bool active;
    int i;
};

#endif // TURRET_Q8F_H
