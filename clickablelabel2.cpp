#include "clickablelabel2.h"
#include "qevent.h"

ClickableLabel2::ClickableLabel2(QWidget *parent)
    : QLabel(parent)
{
}

void ClickableLabel2::mousePressEvent(QMouseEvent *event)
{

    if (event->button() == Qt::LeftButton) {

        emit clicked();
    }
    QLabel::mousePressEvent(event);
}
