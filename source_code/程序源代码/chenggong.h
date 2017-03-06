#ifndef CHENGGONG_H
#define CHENGGONG_H
//登陆成功界面
#include <QDialog>

namespace Ui {
class chenggong;
}

class chenggong : public QDialog
{
    Q_OBJECT

public:
    explicit chenggong(QWidget *parent = 0);
    ~chenggong();

private:
    Ui::chenggong *ui;
};

#endif // CHENGGONG_H
