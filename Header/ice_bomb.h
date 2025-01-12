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
    void ReleaseTheBomb();
    void setRange( int x);
    int getRange();

signals:
    void bombExploded();
    void Release();

private slots:
    void handleBombExplosion();
    void animateBombLabel();
    void deleteBomb();
private:
    int range;
    QLabel* bombLabel;
};

#endif // BOMB_H
