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

private slots:
    void disableNearbyBombs();  // اسلات برای غیرفعال کردن بمب‌های نزدیک

private:
    QTimer *disableTimer;  // تایمر برای بررسی برخورد با بمب‌ها
};

#endif // BOMBDISABLER_H
