#ifndef CLICKABLELABEL2_H
#define CLICKABLELABEL2_H

#include <QLabel>
#include <QWidget>
#include <Qt>

class ClickableLabel2 : public QLabel {
    Q_OBJECT

public:
    explicit ClickableLabel2(QWidget *parent = nullptr);
    int mod;
signals:
    void clicked();

protected:
   void mousePressEvent(QMouseEvent *event) override;

};

#endif // CLICKABLELABEL2_H
