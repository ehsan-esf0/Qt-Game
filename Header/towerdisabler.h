#ifndef TOWERDISABLER_H
#define TOWERDISABLER_H

#include "enemy.h"
#include <QTimer>
#include <QWidget>
#include "turret_q8.h"

class TowerDisabler : public Enemy {
    Q_OBJECT

public:
    explicit TowerDisabler(QWidget *parent = nullptr);
    ~TowerDisabler();

private slots:
    void attemptToDisableTower();

private:
    QTimer *disableTimer;
    QList<ClickableLabel *> disabledTowers;

protected:
    void takeHit(int hit) override;
    void playDeathAnimation();
};

#endif // TOWERDISABLER_H
