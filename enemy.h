#ifndef ENEMY_H
#define ENEMY_H

#include <QLabel>

class Enemy : public QLabel {
    Q_OBJECT

public:
    explicit Enemy(QWidget *parent = nullptr);
    ~Enemy();

    void takeHit();
    bool isAlive() const; // تعریف تابع isAlive

private:
    int health;
};

#endif // ENEMY_H
