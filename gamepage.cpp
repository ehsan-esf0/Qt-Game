#include "gamepage.h"
#include "mainwindow.h"
#include "qpropertyanimation.h"
#include "ui_gamepage.h"
#include <QThread>
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>
#include <QLabel>
#include <QTabWidget>
#include <QVBoxLayout>
#include "clickablelabel.h"

void Gamepage::addMatrix()
{
    matrix[{1,1}] = {200 ,800};
    matrix[{1,2}] = {200 ,100};
    matrix[{2,1}] = {1100 ,100};
    matrix[{2,2}] = {1100 ,800};
}

Gamepage::Gamepage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gamepage)
    ,   selectedLabel(nullptr) // مقدار اولیه برای لیبل انتخاب شده
{
    ui->setupUi(this);
    addMatrix();
    labelCount = 0;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Gamepage::createBlueSquareLabel);
    timer->start(1000);

    QLabel *labelpanel = new QLabel(this);
    labelpanel->move( 350 , 250 );
    labelpanel->setFixedSize( 600 , 200 );
    labelpanel->setStyleSheet("background-color : rgb(100, 100, 100);");
    labelpanel->show();

    createLabelsInGroupBox(5);
}


Gamepage::~Gamepage()
{
    delete ui;
}

void Gamepage::on_pushButton_clicked()
{
    MainWindow *m = new MainWindow();
    m->show();
    this->close();
}
void Gamepage::createBlueSquareLabel()
{
    QLabel *label = new QLabel(this);
    label->setFixedSize(50, 50);
    label->setStyleSheet("background-color : rgb(255, 67, 76);border-radius : 20px;text-align: center;");

    label->setText(QString("%1").arg(labelCount++));
    int x = 200;
    int y = 800;
    label->move(x, y);
    label->show();
    moveObject( label );
}

void Gamepage::moveObject( QLabel *label )
{
    QSequentialAnimationGroup *animationGroup;
    animationGroup = new QSequentialAnimationGroup(this);
    QPropertyAnimation *animation0 = new QPropertyAnimation(label, "geometry");
    animation0->setDuration(4000);
    animation0->setStartValue(QRect(matrix[{1,1}].first, matrix[{1,1}].second, label->width(), label->height()));
    animation0->setEndValue(QRect(matrix[{1,2}].first, matrix[{1,2}].second, label->width(), label->height()));
    QPropertyAnimation *animation1 = new QPropertyAnimation(label, "geometry");
    animation1->setDuration(6000);
    animation1->setStartValue(QRect(matrix[{1,2}].first, matrix[{1,2}].second, label->width(), label->height()));
    animation1->setEndValue(QRect(matrix[{2,1}].first, matrix[{2,1}].second, label->width(), label->height()));
    QPropertyAnimation *animation6 = new QPropertyAnimation(label, "geometry");
    animation6->setDuration(4000);
    animation6->setStartValue(QRect(matrix[{2,1}].first, matrix[{2,1}].second, label->width(), label->height()));
    animation6->setEndValue(QRect(matrix[{2,2}].first, matrix[{2,2}].second, label->width(), label->height()));

    animationGroup->addAnimation(animation0);
    animationGroup->addAnimation(animation1);
    animationGroup->addAnimation(animation6);

    animationGroup->start();
}

void Gamepage::createLabelsInGroupBox(int initialCount)
{
    for (int i = 0; i < initialCount; ++i) {
        ClickableLabel *label = new ClickableLabel(this);
        label->setFixedSize(80, 80);
        label->setStyleSheet("background-color: blue;");
        label->setText(QString("Label %1").arg(i));

        connect(label, &ClickableLabel::clicked, this, &Gamepage::labelClicked);

        int x = 50;
        int y = 100 + i * 100;
        label->move(x, y);
        label->show();

        labels.append(label);
    }
}

void Gamepage::createNewLabel(QPoint position)
{
    ClickableLabel *label = new ClickableLabel(this);
    label->setFixedSize(80, 80);
    label->setStyleSheet("background-color: blue;");
    label->setText(QString("Label %1").arg(labels.size()));

    connect(label, &ClickableLabel::clicked, this, &Gamepage::labelClicked);

    label->move(position);
    label->show();

    labels.append(label);
}

void Gamepage::labelClicked()
{
    selectedLabel = qobject_cast<ClickableLabel*>(sender());
    if (selectedLabel) {
        selectedLabel->setStyleSheet("background-color: red;");
    }
}

bool Gamepage::isPositionOccupied(QRect rec) {
    for (ClickableLabel *label : labels) {
        if (label->geometry().intersects(rec)) {
            return true;
        }
    }
    return false;
}


void Gamepage::mousePressEvent(QMouseEvent *event)
{
    if (selectedLabel && event->button() == Qt::LeftButton) {
        QPoint previousPosition = selectedLabel->pos();
        QRect newRect(event->pos() - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2), selectedLabel->size());

        if ( (350 < event->pos().rx() && event->pos().rx()  < 950) && (250 < event->pos().ry() && event->pos().ry()  < 450) )
        {
            if (!isPositionOccupied(newRect))
            {
                selectedLabel->move(event->pos() - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2));
                selectedLabel->setStyleSheet("background-color: blue;");

                selectedLabel->setEnabled(false);
                selectedLabel = nullptr;
                createNewLabel(previousPosition);
                labels.removeOne(selectedLabel);
            }
        }
    }
}


