#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <map>
#include <utility>

namespace Ui {
class Gamepage;
}

class Gamepage : public QWidget
{
    Q_OBJECT

public:

    explicit Gamepage(QWidget *parent = nullptr);
    ~Gamepage();

private slots:
    void on_pushButton_clicked();

private:
    std::map<std::pair<int, int>, std::pair<int, int>> matrix;
    void addMatrix();
    Ui::Gamepage *ui;
    static std::vector <int> cartbar;

};

#endif // GAMEPAGE_H
