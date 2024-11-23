#ifndef TURRET_Q8_H
#define TURRET_Q8_H

#include "bullet.h"
#include "clickablelabel.h"

class Turret_Q8 : public ClickableLabel
{
private:
    QVector<Bullet*> bullet;
    QTimer *timer;
    QLabel *label;
public:
    void shotBullet( );
    explicit Turret_Q8(QWidget *parent = nullptr);
    QVector<QLabel*> enimi;
    void startShotBullet();
    void getLabel(QLabel *l);
};

#endif // TURRET_Q8_H
