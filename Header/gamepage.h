#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include "bullet.h"
#include "clickablelabel.h"
#include "clickablelabel2.h"
#include "turret_q8.h"
#include <QApplication>
#include <QMainWindow>
#include <QTabWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>
#include <QString>
#include <QDebug>
#include <map>
#include <utility>
#include <QList>
#include <QMouseEvent>
#include <QGroupBox>

namespace Ui {
class Gamepage;
}

class Gamepage : public QWidget
{
    Q_OBJECT

public:

    explicit Gamepage(QWidget *parent = nullptr);
    ~Gamepage();
    void labelInMap(int x , int y , int z, int k, QString s );
    QLabel *label_2;
    static QVector<Enemy*> enimi;
    static QVector<ClickableLabel*> turrets;
    static QVector<ClickableLabel*> bombs;
    void startNewWave();
    void ironLabelshow();
    void updateEnemies();
    void moveObject(Enemy *label);
    void moveObject2( Enemy *label );
    QSequentialAnimationGroup *animationGroup;
    static int enimiInMap;


private slots:
    void on_pushButton_2_clicked();
    void onEnemyExited();

private:
    std::map<std::pair<int, int>, std::pair<int, int>> matrix;
    void addMatrix();
    Ui::Gamepage *ui;
    static std::vector <int> cartbar;
    void on_pushButton_clicked();
    void extracted(Enemy *&label);
    void createBlueSquareLabel();
    QTimer *timer;
    QTimer *timer2;
    QTimer *timer3;
    QTimer *timer4;
    int labelCount;
    void labelClicked();
    void labelClicked2();
    void mousePressEvent(QMouseEvent *event) override;
    void mousePressEvent2(QMouseEvent *event);
    QPoint position = QPoint(50, 50);
    static bool check;
    ClickableLabel *selectedLabel;
    ClickableLabel2 *selectedLabel2;
    QVector<ClickableLabel*> labels;
    void createLabelsInGroupBox(int initialCount);
    void createNewLabel(QPoint position);
    bool isPositionOccupied(QRect position);
    void createLabelMap( int startx , int starty);
    bool checkMap(QMouseEvent *event);
    bool checkMap2 ( QMouseEvent *event );
    int countWave;
    int wCount;
    int bossCount;
    int timeCount;
    void timeLabelText();
    int icount;
    QTimer *checkOutOfBoundsTimer;
    void checkOutOfBounds();
    void countIron();
    int iron;
    QLabel *ironLabel;
    int enemiesExited;
    QLabel *exitCounterLabel;
    int speedWave;
    float healthWave;
};

#endif // GAMEPAGE_H