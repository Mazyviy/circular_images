#include "lab.h"
#include <math.h>
#include <QDebug>
#include <QPainter>


lab::lab(QWidget *parent) :
    QLabel(parent)
{
    FlagDraw = false;
}

extern double sigm, ro1, ro2;
extern double n_x[600000], x[600000], ksi[600000],teta[600000],x1[600000],n_x1[600000];
extern int valueTurns, valuePoints;
extern void lab::paintEvent(QPaintEvent *)
{
    if(FlagDraw==true){
        double step = 6.2833*pow(valuePoints,-1); //переменная для раного перехода между витками
        int i=0;
        for( double ugol=0; ugol<2*M_PI*valueTurns; ugol+=step)
        {
            double R = 0.00078*ugol/2/M_PI;
            double x = R * cos( ugol );
            double y = R * sin( ugol );
            QPainter painter(this);
             painter.setPen(QPen(QBrush(QColor((int)(n_x[i]*255),(int)(n_x[i]*255),(int)(n_x[i]*255))), 1 ));
             painter.drawPoint( x*1000+125, y*1000+125 );
            i++;
        }
        FlagDraw=false;
     }
}
