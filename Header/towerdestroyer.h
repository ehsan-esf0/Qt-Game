#ifndef TOWERDESTROYER_H
#define TOWERDESTROYER_H

#include "enemy.h"
#include <QTimer>
#include <QWidget>

class TowerDestroyer : public Enemy {
    Q_OBJECT

public:
    explicit TowerDestroyer(QWidget *parent = nullptr);
    ~TowerDestroyer();
    void takeHit(int hit) override;


private slots:
    void attemptToDestroyTower();

private:
    QTimer *destructionTimer;
    void playDeathAnimation();
};

#endif // TOWERDESTROYER_H
