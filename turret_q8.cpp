#include "turret_q8.h"
#include "gamepage.h"

Turret_Q8::Turret_Q8(QWidget *parent) : ClickableLabel(parent) {
    setStyleSheet("background-color: red;");
    setText("Label 1");
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Turret_Q8::shotBullet);
    active = true;
}

void Turret_Q8::shotBullet() {
    if (!isActive()) {
        return;
    }
    if (Gamepage::enimi.isEmpty()) {
       // stopShooting();
        return;
    } else if ( Gamepage::enimi.isEmpty() == false ) {
        for (Enemy *e : Gamepage::enimi) {
            if (e->isAlive()) {
                Bullet *b = new Bullet(parentWidget());
                b->shoot(this->pos(), QPointer<Enemy>(e));
                bullet.append(b);
                return;
            }
        }
    }
}

void Turret_Q8::startShooting() {

    active = true;
    shotBullet();
    }
void Turret_Q8::stopShooting()
    {
    active = false;
    // تغییر وضعیت به غیر فعال
    } bool Turret_Q8::isActive()
    {
    return active;
    }


void Turret_Q8::startShotBullet()
{
    timer->start(200);
}

void Turret_Q8::getLabel( QVector<QLabel*> l )
{
    label = l;
}
