#ifndef USERS_H
#define USERS_H
//用户界面
#include <QDialog>

extern int t1;

namespace Ui {
class Users;
}

class Users : public QDialog
{
    Q_OBJECT

public:
    explicit Users(QWidget *parent = 0);
    ~Users();
    void MIMA(QString,QString);

private slots:
    void on_pushButton_clicked();//关闭界面

    void on_queding_clicked();//用户的两个功能
protected:
    void timerEvent(QTimerEvent *event);
private:
    Ui::Users *ui;
    int id1;
};

#endif // USERS_H
