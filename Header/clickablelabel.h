#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>

class ClickableLabel : public QLabel {
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget *parent = nullptr);
    bool status;
signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    int speedshoot;
    int damage;

};

#endif // CLICKABLELABEL_H
