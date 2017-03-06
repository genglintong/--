#ifndef SEARCHA_H
#define SEARCHA_H
//查找界面
#include <QDialog>
#include "graph.h"

extern string name;
extern int t;

namespace Ui {
class searcha;
}

class searcha : public QDialog
{
    Q_OBJECT

public:
    explicit searcha(QWidget *parent = 0);
    ~searcha();

private slots:
    void on_pushButton_2_clicked();//界面关闭

    void on_pushButton_clicked();//路线查找

    void on_pushButton_3_clicked();//中途城市设置

private:
    Ui::searcha *ui;
};

#endif // SEARCH_H
