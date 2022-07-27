#ifndef LAB_H
#define LAB_H

#include <QLabel>
#include <QPainter>

class lab : public QLabel
{
    Q_OBJECT
public:
    explicit lab(QWidget *parent = 0);
    bool FlagDraw;

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *);

};

#endif // LAB_H
