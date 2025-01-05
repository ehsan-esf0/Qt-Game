#include "Header/BaseEnemy.h"

BaseEnemy::BaseEnemy(QWidget *parent) : QWidget(parent), rotationAngle(0) {
    setFixedSize(50, 50);
}

void BaseEnemy::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
}
