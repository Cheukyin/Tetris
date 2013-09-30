#include "PGLWidget.h"
#include <OPERATOR.h>
#include <QTimer>
#include <GL/glu.h>
#include <QDebug>
#include <QSize>
#include <cmath>
#include <QtOpenGL>
#include <QApplication>

PGLWidget::PGLWidget(QWidget *parent)
    :QGLWidget(QGLFormat(QGL::SampleBuffers),parent)
{
    for(int i=0;i<=3;i++)
        tt[i]=new Coord(i,0);

    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateGL()));
    timer->start(100);
}

void PGLWidget::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(1.0f,1.0f,1.0f,0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);

    glEnable (GL_POINT_SMOOTH);
    glHint (GL_POINT_SMOOTH, GL_NICEST);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);

    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
}

void PGLWidget::resizeGL(int w, int h)
{
    if(0==h)    h=1;
    glViewport(0,0,(GLint)w,(GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0,(GLfloat)w/(GLfloat)h,0.1,100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void PGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(  0.0,  0.0, -13 );
    glTranslatef(1.5,1.7,0.0);
    glRotatef(-20,0.0f,1.0f,0.0f);
    glRotatef(-35,1.0f,0.0f,0.0f);
    glRotatef(-30,0.0f,1.0f,0.0f);

    draw_block();
}

void PGLWidget::keyPressEvent(QKeyEvent *e)
{
}

QSize PGLWidget::minimumSizeHint() const
{
        return QSize(5, 5);
}

QSize PGLWidget::sizeHint() const
{
        return QSize(100, 100);
}

void PGLWidget::draw_block()
{
    for(int i=0;i<=3;i++)
        drawcube(tt[i]->y,tt[i]->x);
}

void PGLWidget::set_t(Coord *q)
{
    for(int i=0;i<=3;i++)
        tt[i]=new Coord(q[i].x,q[i].y);
}

void PGLWidget::drawcube(GLfloat level,GLfloat angle_cnt)
{
    GLfloat half_len=0.4;
    GLfloat half_xlen=4*tan(15*3.141592653/180);
    GLfloat delta_x=2*half_len*tan(15*3.141592653/180);

    GLfloat v1[3]={-half_xlen-delta_x,0.5,half_len};
    GLfloat v2[3]={half_xlen+delta_x,0.5,half_len};
    GLfloat v3[3]={-half_xlen,0.5,-half_len};
    GLfloat v4[3]={half_xlen,0.5,-half_len};

    GLfloat v5[3]={-half_xlen-delta_x,-0.5,half_len};
    GLfloat v6[3]={half_xlen+delta_x,-0.5,half_len};
    GLfloat v7[3]={-half_xlen,-0.5,-half_len};
    GLfloat v8[3]={half_xlen,-0.5,-half_len};

    glPushMatrix();
    //glRotatef(0.0,0.0f,1.0f,0.0f);
    glRotatef(30*angle_cnt,0.0f,1.0f,0.0f);
    glTranslatef(0.0,level,4.0+half_len);

    glBegin(GL_POLYGON);
            glColor3f( 0.0, 1.0, 1.0 );
            glVertex3fv(v4);
            glColor3f( 1.0, 0.0, 0.0 );
            glVertex3fv(v3);
            glColor3f( 0.0, 0.0, 1.0 );
            glVertex3fv(v1);
            glColor3f( 0.0, 1.0, 0.0 );
            glVertex3fv(v2);
    glEnd();

    glBegin(GL_POLYGON);
            glColor3f( 0.0, 1.0, 0.0 );
            glVertex3fv(v6);
            glColor3f( 0.0, 0.0, 1.0 );
            glVertex3fv(v8);
            glColor3f( 0.0, 1.0, 0.0 );
            glVertex3fv(v7);
            glColor3f( 0.0, 1.0, 1.0 );
            glVertex3fv(v5);
    glEnd();

    glBegin(GL_POLYGON);
            glColor3f( 0.0, 1.0, 1.0 );
            glVertex3fv(v2);
            glColor3f( 0.0, 1.0, 0.0 );
            glVertex3fv(v1);
            glColor3f( 1.0, 0.0, 0.0 );
            glVertex3fv(v5);
            glColor3f( 0.0, 1.0, 1.0 );
            glVertex3fv(v6);
    glEnd();

    glBegin(GL_POLYGON);
            glColor3f( 0.0, 1.0, 0.0 );
            glVertex3fv(v8);
            glColor3f( 0.0, 0.0, 1.0 );
            glVertex3fv(v4);
            glColor3f( 0.0, 0.0, 1.0 );
            glVertex3fv(v3);
            glColor3f( 0.0, 1.0, 0.0 );
            glVertex3fv(v7);
    glEnd();

    glBegin(GL_POLYGON);
            glColor3f( 0.0, 0.0, 1.0 );
            glVertex3fv(v1);
            glColor3f( 1.0, 0.0, 0.0 );
            glVertex3fv(v3);
            glColor3f( 0.0, 1.0, 0.0 );
            glVertex3fv(v7);
            glColor3f( 0.0, 0.0, 1.0 );
            glVertex3fv(v5);
    glEnd();

    glBegin(GL_POLYGON);
            glColor3f( 0.0, 1.0, 1.0 );
            glVertex3fv(v4);
            glColor3f( 0.0, 1.0, 0.0 );
            glVertex3fv(v2);
            glColor3f( 0.0, 1.0, 0.0 );
            glVertex3fv(v6);
            glColor3f( 1.0, 1.0, 1.0 );
            glVertex3fv(v8);
    glEnd();

    glPopMatrix();
}
