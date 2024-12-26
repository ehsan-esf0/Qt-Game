#ifndef FIGHTER298_H
#define FIGHTER298_H

#include "enemy.h"

class Fighter298 : public Enemy {
    Q_OBJECT

public:
    explicit Fighter298(QWidget *parent = nullptr);
    ~Fighter298();


    void takeHit() override;

private:
};

#endif // ENEMY_H
