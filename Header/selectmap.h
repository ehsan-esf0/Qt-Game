#ifndef SELECTMAP_H
#define SELECTMAP_H

#include <QWidget>

namespace Ui {
class selectMap;
}

class selectMap : public QWidget
{
    Q_OBJECT

public:
    explicit selectMap(QWidget *parent = nullptr);

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_horizontalScrollBar_actionTriggered();

    void on_progressBar_valueChanged(int value);

private:
    Ui::selectMap *ui;
};

#endif // SELECTMAP_H
