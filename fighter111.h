#ifndef FIGHTER111_H
#define FIGHTER111_H

#include "enemy.h"

class fighter111 : public Enemy {
    Q_OBJECT

public:
    explicit fighter111(QWidget *parent = nullptr);
    ~fighter111();


    void takeHit() override;

private:
};

#endif // ENEMY_H