#include "gamepage.h"
#include "mainwindow.h"
#include "qpropertyanimation.h"
#include "savegamedata.h"
#include "selectmap.h"
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
    ,   selectedLabel(nullptr)
{
    ui->setupUi(this);
    addMatrix();
    labelCount = 1;
    wCount = 10;
    timeCount = 10000;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Gamepage::createBlueSquareLabel);
    timer2 = new QTimer(this);
    connect(timer2, &QTimer::timeout, this, &Gamepage::timeLabelText);
    timer->start(500);


    for (int i = 450 ; i <= 850 ; i += 100 ) {

        for (int j = 250 ; j <= 600 ; j += 100 ) {

            createLabelMap( i , j );
            j += 10;
        }
        i += 10;
    }

    createLabelsInGroupBox(5);

    label_2 = new QLabel(saveGameData::str, this);
    label_2->setFixedSize(50, 50);
    int x = 100;
    int y = 50;
    label_2->move(x, y);
    label_2->show();

}

void Gamepage::changeLabelColor()
{
}

void Gamepage::createLabelMap( int startx , int starty)
{
    QLabel *labelpanel = new QLabel(this);
    labelpanel->move( startx , starty );
    labelpanel->setFixedSize( 100 , 100 );
    labelpanel->setStyleSheet("background-color : rgb(100, 100, 100);");
    labelpanel->show();
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
    label->setStyleSheet("background:url(:/res/C:/Users/User/Downloads/qj4vuf24u7l61.png);");

    label->setText(QString("%1").arg(labelCount++));
    int x = 200;
    int y = 800;
    label->move(x, y);
    label->show();
    moveObject( label );
    if ( labelCount  == wCount + 1 )
    {
        timeCount += 5000;
        icount = (timeCount / 1000);
        timer->setInterval(timeCount);
        timer2->start(1000);
        labelCount = 1;
        wCount += 10;
    }
    else {
        timer->setInterval(rand() % 600 + 400);
        ui->label->setText("مبارزه");
    }
}

void Gamepage::timeLabelText()
{
    ui->label->setText(QString(" %1 تا موج بعدی حمله ").arg( icount-- ));

    if ( icount ==  0 )
    {
        timer2->stop();
    }
}

void Gamepage::moveObject( QLabel *label )
{
    QSequentialAnimationGroup *animationGroup;
    animationGroup = new QSequentialAnimationGroup(this);
    QPropertyAnimation *animation0 = new QPropertyAnimation(label, "geometry");
    animation0->setDuration(4000);
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
        label->status = true;

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
    label->status = true;

    connect(label, &ClickableLabel::clicked, this, &Gamepage::labelClicked);

    label->move(position);
    label->show();

    labels.append(label);
}

void Gamepage::labelClicked()
{
    selectedLabel = qobject_cast<ClickableLabel*>(sender());
    if (selectedLabel) {
        if ( selectedLabel->status == true )
        {
            selectedLabel->setStyleSheet("background-color: red;");
        }
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

void Gamepage::labelClicked2()
{
    selectedLabel2 = qobject_cast<ClickableLabel2*>(sender());
    if (selectedLabel2) {
        if ( selectedLabel2->mod == 1 )
        {
            QLabel *parentLabel = qobject_cast<QLabel*>(selectedLabel2->parent());
            if (parentLabel) {
                parentLabel->move(1000,1000);
            }
        }
        if ( selectedLabel2->mod == 2)
        {
            QLabel *parentLabel = qobject_cast<QLabel*>(selectedLabel2->parent());
            if (parentLabel) {
                parentLabel->setStyleSheet("background-color: red;");
            }
        }
    }
}

bool Gamepage::checkMap ( QMouseEvent *event )
{
    for (int i = 450 ; i <= 850 ; i += 100 ) {

        for (int j = 250 ; j <= 600 ; j += 100 ) {

            if ((i + 30 < event->pos().rx() && event->pos().rx()  < i + 70) && (j + 30  < event->pos().ry() && event->pos().ry()  < j + 70))
            {
                return true;
            }
            j += 10;
        }
        i += 10;
    }
    return false;
}


void Gamepage::mousePressEvent(QMouseEvent *event)
{
    if (selectedLabel && event->button() == Qt::LeftButton) {
        QPoint previousPosition = selectedLabel->pos();
        QRect newRect(event->pos() - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2), selectedLabel->size());

        if ( selectedLabel->status == true )
        {
            if ( checkMap(event) )
            {
                if (!isPositionOccupied(newRect))
                {
                    selectedLabel->move(event->pos() - QPoint(selectedLabel->width() / 2, selectedLabel->height() / 2));
                    selectedLabel->setStyleSheet("background-color: blue;");

                    ClickableLabel2 *deletelabel = new ClickableLabel2(selectedLabel);
                    deletelabel->setStyleSheet("background-color: red;border-radius : 5px;");
                    deletelabel->setFixedSize(20, 20);
                    deletelabel->mod = 1;
                    //deletelabel->move(selectedLabel->pos().rx() , selectedLabel->pos().ry());

                    deletelabel->show();

                    connect(deletelabel, &ClickableLabel2::clicked, this, &Gamepage::labelClicked2);

                    ClickableLabel2 *editlabel = new ClickableLabel2(selectedLabel);
                    editlabel->setStyleSheet("background-color: green;border-radius : 5px;");
                    editlabel->setFixedSize(10, 10);
                    editlabel->mod = 2;
                    //deletelabel->move(selectedLabel->pos().rx() , selectedLabel->pos().ry());

                    editlabel->show();

                    connect(editlabel, &ClickableLabel2::clicked, this, &Gamepage::labelClicked2);

                    //selectedLabel->setEnabled(false);
                    selectedLabel->status = false;

                    selectedLabel = nullptr;
                    createNewLabel(previousPosition);
                    labels.removeOne(selectedLabel);
                }
            }
        }
    }
}


void Gamepage::on_pushButton_2_clicked()
{
    MainWindow *menu = new MainWindow();
    menu->show();
    this->close();
}

