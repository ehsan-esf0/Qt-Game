#ifndef BULLET_H
#define BULLET_H

#include <QLabel>
#include <QTimer>
#include <QPropertyAnimation>

class Bullet : public QLabel {
    Q_OBJECT

public:
    explicit Bullet(QWidget *parent = nullptr);
    void shoot(const QPoint &start, QLabel *targetLabel);

private slots:
    void moveBullet();
    void onAnimationFinished();

private:
    QPropertyAnimation *animation;
    QLabel *targetLabel;
    QTimer *moveTimer;
};

#endif
