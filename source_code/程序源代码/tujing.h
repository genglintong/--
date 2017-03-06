#ifndef TUJING_H
#define TUJING_H

#include <QDialog>

namespace Ui {
class tujing;
}

class tujing : public QDialog
{
    Q_OBJECT

public:
    explicit tujing(QWidget *parent = 0);
    ~tujing();
   QString CITY();

private:
    Ui::tujing *ui;
};

#endif // TUJING_H
