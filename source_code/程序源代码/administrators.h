#ifndef ADMINISTRATORS_H
#define ADMINISTRATORS_H
//管理员界面
#include <QDialog>
#include <string>

using namespace std;

extern string name;//string声明

namespace Ui {
class administrators;
}

class administrators : public QDialog
{
    Q_OBJECT

public:
    explicit administrators(QWidget *parent = 0);
    ~administrators();
    void MIMA(QString,QString);//将密码信息传递到当前界面
    void Open();//显示日志文件

private slots:
    void on_pushButton_clicked();//关闭该界面，并重新打开的登陆界面

    void on_pushButton_2_clicked();//管理员的三种功能

private:
    Ui::administrators *ui;
};

#endif // ADMINISTRATORS_H
