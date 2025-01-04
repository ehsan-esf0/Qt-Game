#include "Header/turret_q8m.h"
#include "Header/gamepage.h"
#include "Header/enemy.h"

Turret_q8m::Turret_q8m(QWidget *parent) : ClickableLabel(parent) {
    setStyleSheet("background: url(:/res/image/T3.png);");
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Turret_q8m::shotBullet);
    active = true;
    speedshoot = 550;
    damage = 22;
    lvl = 1;
    code = std::rand() % 1000 + 1;
}
void Turret_q8m::shotBullet()
{
    if (!isActive())
    {
        return;
    }
    if (Gamepage::enimi.isEmpty())
    {
        return;
    }
    Enemy *maxHealthEnemy = nullptr;
    int maxDistance = -1;
    for (Enemy *e : Gamepage::enimi)
    {
        if (e->isAlive)
        {
            int distance = e->getHealth();
            if (distance > maxDistance)
            {
                maxDistance = distance;
                maxHealthEnemy = e;
            }
        }
    }
    if (maxHealthEnemy)
    {
        Bullet *b = new Bullet(parentWidget());
        b->setDamage(damage);
        b->shoot(this->pos(), QPointer<Enemy>(maxHealthEnemy));
        bullet.append(b);
    }
}

void Turret_q8m::startShooting() {

    active = true;
    shotBullet();
}
void Turret_q8m::stopShooting()
{
    active = false;
}
bool Turret_q8m::isActive()
{
    return active;
}


void Turret_q8m::startShotBullet()
{
    timer->start(speedshoot);
}

void Turret_q8m::getLabel( QVector<QLabel*> l )
{
    label = l;
}

void Turret_q8m::setActive( bool x ){
    active = x;
}
