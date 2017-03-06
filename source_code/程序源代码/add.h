#ifndef ADD_H
#define ADD_H
//添加路线界面
#include <QDialog>

namespace Ui {
class add;
}

class add : public QDialog
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = 0);
    ~add();

private slots:
    void on_pushButton_clicked();//调用添加槽函数
    void on_pushButton_2_clicked();//添加结束，重新将图读写进去

private:
    Ui::add *ui;
};

#endif // ADD_H
