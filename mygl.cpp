#include "mygl.h"
#include <GL/gl.h>
#include <GL/glaux.h>
#include <GL/glu.h>
#include <mainwindow.h>
#include <math.h>

extern double sigm, ro1, ro2;
extern double n_x[600000], x[600000], ksi[600000],teta[600000],x1[600000],n_x1[600000];
extern int valueTurns, valuePoints;

void mygl::initializeGL()
{
    FlagDraw = false;
    glClearColor(0, 0, 0, 1.0);
}

extern void Habibi();

void mygl::paintGL()
{
    if (FlagDraw==true){
    Habibi();
    glClear(GL_COLOR_BUFFER_BIT);

    double step = 6.2833*pow(valuePoints,-1); //переменная для раного перехода между витками
    double a = 0.00125; //расстояние между витками
    double R; // радиус -- зависимая переменная, меняется в зависимости от угла
    int i=0;

    for( double ugol=0; ugol<2*M_PI*valueTurns; ugol+=step)
    {
        R = a*ugol/2/M_PI;
        double x = R * cos( ugol );
        double y = R * sin( ugol );
        x+=0.5;
        y+=0.2;

        glPointSize(1);
        glBegin(GL_POINTS);
        glColor3d(n_x[i], n_x[i], n_x[i]);
        glVertex3d(x, y,0);
        glEnd();
        i++;
    }
    }
}

void mygl::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 0.5);
    glMatrixMode(GL_MODELVIEW);
}
