#ifndef LUXIAN_H
#define LUXIAN_H
//显示路线界面
#include <QDialog>
#include <QString>

namespace Ui {
class luxian;
}

class luxian : public QDialog
{
    Q_OBJECT

public:
    explicit luxian(QWidget *parent = 0);
    ~luxian();
    void Print(QString s);//显示函数

private:
    Ui::luxian *ui;
};

#endif // LUXIAN_H
