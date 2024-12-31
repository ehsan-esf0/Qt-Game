#ifndef ICE_BOMB_H
#define ICE_BOMB_H

#include <QLabel>
#include "clickablelabel.h"
#include "enemy.h"
#include <QWidget>

class Ice_Bomb : public ClickableLabel {
    Q_OBJECT

public:
    explicit Ice_Bomb(QWidget *parent = nullptr);
    void checkCollision();
    bool isActive;

signals:
    void bombExploded();

private slots:
    void handleBombExplosion();
private:

};

#endif // BOMB_H
