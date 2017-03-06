#ifndef WRONG_H
#define WRONG_H
//错误界面
#include <QDialog>

namespace Ui {
class wrong;
}

class wrong : public QDialog
{
    Q_OBJECT

public:
    explicit wrong(QWidget *parent = 0);
    ~wrong();

private:
    Ui::wrong *ui;
};

#endif // WRONG_H
