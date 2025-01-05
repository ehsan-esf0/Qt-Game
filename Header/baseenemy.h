#ifndef BASEENEMY_H
#define BASEENEMY_H

#include <QWidget>

class BaseEnemy : public QWidget {
    Q_OBJECT

public:
    BaseEnemy(QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent *event) override;

protected:
    int rotationAngle;
};

#endif // BASEENEMY_H
