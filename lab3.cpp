#include "lab3.h"
#include <math.h>
#include <QDebug>
#include <QPainter>
#include <random>


lab3::lab3(QWidget *parent) :
    QLabel(parent)
{
    FlagDraw = false;
}

extern double sigm, ro1, ro2;
extern double n_x[600000], x[600000], ksi[600000],teta[600000],x1[600000],n_x1[600000];
extern int valueTurns, valuePoints;

double xx1[600000],xx2[600000],nnx[600000];
extern void lab3::paintEvent(QPaintEvent *)
{
    if(FlagDraw==true){
       /* QPainter painter(this);
        srand(time(0));
        painter.setPen(QPen(QBrush(QColor(rand()%255,rand()%255,rand()%255)), 20 ));
        painter.drawPoint( 125, 125 );
        FlagDraw=false;*/
int qq=0;

        xx1[0]=x1[0];
        for (int i = 0; i < valueTurns; ++i) {
            for (int j = 1; j < valuePoints; ++j) {
               xx1[j+qq]=0.5*xx1[qq+j-1]+0.5*(x1[qq+j]-0.5*xx1[qq+j-1]);

            }
            qq+=valuePoints;
        }

        xx2[valuePoints-1]=xx1[valuePoints-1];
        for (int i = valuePoints-1; i >0; --i) {
           xx2[i]=xx1[i]+0.5*(xx2[i-1]-0.5*xx1[i]);

        }

        for (int i = valuePoints; i < (valueTurns*valuePoints)-valuePoints; ++i) {
             xx1[i]=0.5*xx1[i-1]+0.5*(x1[i]-0.5*xx1[i-1]);
        }
        for (int i = (valueTurns*valuePoints)-valuePoints-1; i >0 ; --i) {
             xx2[i]=xx1[i]+0.5*(xx2[i-1]-0.5*xx1[i]);
        }


        double max, min;
        max = xx2[0];
        min = xx2[0];
        for (int i = 0; i < valueTurns*valuePoints; ++i) {
            if (xx2[i] < min) min = xx2[i];
            if ((xx2[i]) > max) max = xx2[i];
        }
        for (int i = 0; i < valueTurns*valuePoints; ++i) {
            nnx[i] = (xx2[i] - min) / (max - min);
        }


        double step = 6.2833*pow(valuePoints,-1); //переменная для раного перехода между витками
        int i=0;
        for( double ugol=0; ugol<2*M_PI*valueTurns; ugol+=step)
        {
            double R = 0.00078*ugol/2/M_PI;
            double x = R * cos( ugol );
            double y = R * sin( ugol );
            QPainter painter(this);
             painter.setPen(QPen(QBrush(QColor((int)(nnx[i]*255),(int)(nnx[i]*255),(int)(nnx[i]*255))), 1 ));
             painter.drawPoint( x*1000+125, y*1000+125 );
            i++;
        }
        FlagDraw=false;




    }
}
