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

private:
    Ui::selectMap *ui;
};

#endif // SELECTMAP_H
