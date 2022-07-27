#ifndef LAB2_H
#define LAB2_H


#include <QLabel>
#include <QPainter>

class lab2 : public QLabel
{
    Q_OBJECT
public:
    explicit lab2(QWidget *parent = 0);
    bool FlagDraw;

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *);

};

#endif // LAB2_H
