#ifndef LAB3_H
#define LAB3_H


#include <QLabel>
#include <QPainter>

class lab3 : public QLabel
{
    Q_OBJECT
public:
    explicit lab3(QWidget *parent = 0);
    bool FlagDraw;

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *);
};

#endif // LAB3_H
