#include "Header/turret_q8r.h"
#include "Header/gamepage.h"

#include <cstdlib>
#include <ctime>

Turret_q8r::Turret_q8r(QWidget *parent) : ClickableLabel(parent)
{
    setStyleSheet("background: url(:/res/image/T2.png);");
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Turret_q8r::shotBullet);
    active = true;
    speedshoot = 550;
    damage = 30;
}

Turret_q8r::~Turret_q8r()
{
}



void Turret_q8r::shotBullet() {
    if (!isActive()) {
        return;
    }
    if (Gamepage::enimi.isEmpty()) {
        //stopShooting();
        return;
    } else if (!Gamepage::enimi.isEmpty()) {
        std::srand(std::time(nullptr));

        int randomIndex = std::rand() % Gamepage::enimi.size();
        Enemy *e = Gamepage::enimi[randomIndex];

        if (e->isAlive) {
            Bullet *b = new Bullet(parentWidget());
            b->setDamage(damage);
            b->shoot(this->pos(), QPointer<Enemy>(e));
            bullet.append(b);
        }
    }
}



void Turret_q8r::startShooting() {

    active = true;
    shotBullet();
}
void Turret_q8r::stopShooting()
{
    active = false;

} bool Turret_q8r::isActive()
{
    return active;
}


void Turret_q8r::startShotBullet()
{
    timer->start(speedshoot);
}

void Turret_q8r::getLabel( QVector<QLabel*> l )
{
    label = l;
}

void Turret_q8r::setActive( bool x ){
    active = x;
}
