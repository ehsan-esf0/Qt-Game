#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>

class ClickableLabel : public QLabel {
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget *parent = nullptr);
    int status;
    //int select;
    void setDamage( int x );
    int getDamage();
    void setLvl( int x );
    int getLvl();
signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    int speedshoot;
    int damage;
    int lvl;

};

#endif // CLICKABLELABEL_H
