#include "turret_q8f.h"
#include "gamepage.h"

Turret_q8f::Turret_q8f(QWidget *parent) : ClickableLabel(parent)
{
    setStyleSheet("background: url(:/res/image/T1.png);");
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Turret_q8f::shotBullet);
    active = true;
    speedshoot = 550;
}

Turret_q8f::~Turret_q8f()
{
}


void Turret_q8f::shotBullet() {
    if (!isActive()) {
        return;
    }
    if (Gamepage::enimi.isEmpty()) {
        //stopShooting();
        return;
    } else if (!Gamepage::enimi.isEmpty()) {
        for (auto it = Gamepage::enimi.rbegin(); it != Gamepage::enimi.rend(); ++it) {
            Enemy *e = *it;
            if (e->isAlive) {
                Bullet *b = new Bullet(parentWidget());
                b->shoot(this->pos(), QPointer<Enemy>(e));
                bullet.append(b);
                return;
            }
        }
    }
}


void Turret_q8f::startShooting() {

    active = true;
    shotBullet();
}
void Turret_q8f::stopShooting()
{
    active = false;
} bool Turret_q8f::isActive()
{
    return active;
}


void Turret_q8f::startShotBullet()
{
    timer->start(speedshoot);
}

void Turret_q8f::getLabel( QVector<QLabel*> l )
{
    label = l;
}
