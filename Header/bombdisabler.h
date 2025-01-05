#ifndef BOMBDISABLER_H
#define BOMBDISABLER_H

#include "enemy.h"
#include <QTimer>
#include <QWidget>
#include "clickablelabel.h"

class BombDisabler : public Enemy {
    Q_OBJECT

public:
    explicit BombDisabler(QWidget *parent = nullptr);
    ~BombDisabler();
    void takeHit(int hit) override;

private slots:
    void disableNearbyBombs();

private:
    QTimer *disableTimer;
    void playDeathAnimation();
};

#endif // BOMBDISABLER_H
