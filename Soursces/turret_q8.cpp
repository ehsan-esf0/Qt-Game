#include "Header/turret_q8.h"
#include "Header/gamepage.h"

Turret_Q8::Turret_Q8(QWidget *parent) : ClickableLabel(parent) {
    setStyleSheet("background: url(:/res/image/T.png);");
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Turret_Q8::shotBullet);
    active = true;
    speedshoot = 550;
    damage = 15;
    lvl = 1;
    code = std::rand() % 1000 + 1;
}
void Turret_Q8::shotBullet()
{
    if (!isActive())
    {
        return;
    }
    if (Gamepage::enimi.isEmpty())
    {
        return;
    }
    Enemy *farthestEnemy = nullptr;
    int maxDistance = -1;
    for (Enemy *e : Gamepage::enimi)
    {
        if (e->isAlive)
        {
            int distance = e->x();
            if (distance > maxDistance)
            {
                maxDistance = distance;
                farthestEnemy = e;
            }
        }
    }
    if (farthestEnemy)
    {
        Bullet *b = new Bullet(parentWidget());
        b->setDamage(damage);
        b->shoot(this->pos(), QPointer<Enemy>(farthestEnemy));
        bullet.append(b);
    }
}

void Turret_Q8::startShooting() {

    active = true;
    shotBullet();
}
void Turret_Q8::stopShooting()
{
    active = false;
}
bool Turret_Q8::isActive()
{
    return active;
}


void Turret_Q8::startShotBullet()
{
    timer->start(speedshoot);
}

void Turret_Q8::getLabel( QVector<QLabel*> l )
{
    label = l;
}

void Turret_Q8::setActive( bool x ){
    active = x;
}
