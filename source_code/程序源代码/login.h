#ifndef LOGIN_H
#define LOGIN_H
//登陆界面
#include <QDialog>
#include<QSound>

extern int t;//系统时间的声明

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();
protected:
    void timerEvent(QTimerEvent * event);//时间事件

private slots:
    void on_denglu_clicked();//登陆
    void on_close_clicked();//关闭
    void on_zhuce_clicked();//注册

private:
    Ui::login *ui;
    int id1;//时间片
};

#endif // LOGIN_H
