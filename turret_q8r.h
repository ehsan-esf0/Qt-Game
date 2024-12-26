#ifndef TURRET_Q8R_H
#define TURRET_Q8R_H

#include "bullet.h"
#include "clickablelabel.h"

class Turret_q8r : public ClickableLabel
{
    Q_OBJECT

public:
    explicit Turret_q8r(QWidget *parent = nullptr);
    ~Turret_q8r();
    QVector<QLabel*> enimi;
    void startShooting();
    void stopShooting();
    bool isActive();
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
