#ifndef MYGL_H
#define MYGL_H

#include <QObject>

#include <QOpenGLWidget>

class mygl : public QOpenGLWidget
{
    Q_OBJECT

public:
     bool FlagDraw;
    explicit mygl(QWidget *parent = 0);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
};

#endif // MYGL_H


