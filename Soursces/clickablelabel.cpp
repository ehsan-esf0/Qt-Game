#include "Header/clickablelabel.h"

ClickableLabel::ClickableLabel(QWidget *parent)
    : QLabel(parent)
{
}

void ClickableLabel::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
}

void ClickableLabel::setDamage( int x )
{
    damage = x;
}

int ClickableLabel::getDamage()
{
    return damage;
}

void ClickableLabel::setLvl( int x )
{
    lvl = x;
}
int ClickableLabel::getLvl()
{
    return lvl;
}

void ClickableLabel::setSpeedshoot( int x )
{
    speedshoot = x ;
}
int ClickableLabel::getSpeedshoot()
{
    return speedshoot ;
}

void ClickableLabel::setCode( int x )
{
    code = x ;
}
int ClickableLabel::getCode()
{
    return code ;
}
void ClickableLabel::setLvlDamage(int x)
{
    lvlDamage = x;
}
