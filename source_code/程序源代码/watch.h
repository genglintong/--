#ifndef WATCH_H
#define WATCH_H
//观察用户状态
#include <QDialog>
#include<QPixmap>
#include<QLabel>
#include<QFileDialog>
#include<QPainter>
#include<QMouseEvent>
#include <string>

using namespace std;

extern int t;//系统时间
extern string name;//用户名

namespace Ui {
class watch;
}

class watch : public QDialog
{
    Q_OBJECT

public:
    explicit watch(QWidget *parent = 0);
    ~watch();

protected:
    void timerEvent(QTimerEvent * event);//时间事件
    void paintEvent(QPaintEvent * event);//绘画事件
    void mousePressEvent(QMouseEvent *e);//鼠标事件
private:
    Ui::watch *ui;
    int id2;
    QPixmap *pix;
};

void coordinate(int t,int &m,int &n);//实时坐标
void change(int a,int &m,int &n);//城市坐标
#endif // WATCH_H
