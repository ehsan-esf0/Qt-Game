#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>

namespace Ui {
class Gamepage;
}

class Gamepage : public QWidget
{
    Q_OBJECT

public:
    explicit Gamepage(QWidget *parent = nullptr);
    ~Gamepage();

private:
    Ui::Gamepage *ui;
};

#endif // GAMEPAGE_H
