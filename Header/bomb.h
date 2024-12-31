#ifndef BOMB_H
#define BOMB_H

#include <QLabel>
#include "clickablelabel.h"
#include "enemy.h"
#include <QWidget>

class Bomb : public ClickableLabel {
    Q_OBJECT

public:
    explicit Bomb(QWidget *parent = nullptr);
    void checkCollision();
    bool isActive;


signals:
    void bombExploded();

private slots:
    void handleBombExplosion();
private:

};

#endif // BOMB_H
