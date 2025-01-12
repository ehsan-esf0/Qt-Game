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
