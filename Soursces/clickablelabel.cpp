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
