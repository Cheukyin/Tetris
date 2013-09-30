#include "TGLWidget.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include <QImage>
#include <GL/glu.h>
#include <QSize>
#include <QtOpenGL>
#include <cmath>
#include <BLOCK.h>
#include <BLOCK_MATRIX.h>
#include <OPERATOR.h>

TGLWidget::TGLWidget(QWidget *parent)
    :QGLWidget(QGLFormat(QGL::SampleBuffers), parent),rtri(0),xRot(0),yRot(0),zRot(0),xSpeed(0),ySpeed(0),zoom(-22),theta(0),dropdown_h(10),timer_flag(true),locker(false),isPaused(true),score(0),line(0),level(0),drop_speed(1000)
{
    block=new BLOCK;
    Bmatrix=new BLOCK_MATRIX;
    //pglwidget=new PGLWidget;

    timer_drop=new QTimer(this);
    connect(timer_drop,SIGNAL(timeout()),this,SLOT(slow_dropdown()));

    timer_update=new QTimer(this);
    connect(timer_update,SIGNAL(timeout()),this,SLOT(updateGL()));

    //timer_predict=new QTimer(this);
    //connect(timer_predict,SIGNAL(timeout()),this,SLOT(show_pgl()));
    //timer_predict->start(100);

    block->Random_Shape();
}

void TGLWidget::get_predict(Coord *t)
{
    Coord z[4];
    block->get_predict(z);
    for(int i=0;i<=3;i++)
        t[i]=z[i];
}

void TGLWidget::initializeGL()
{
   // glEnable(GL_COLOR_MATERIAL);
   // glColorMaterial(GL_FRONT, GL_DIFFUSE);

   // GLfloat lightAmbient[4] = { 0.09, 0.09, 0.09, 0.8 };
   // GLfloat lightDiffuse[4] = { 1, 1, 1, 1.0 };
   // GLfloat lightPosition[4] = { 0.0, 0.0, 100000000.0, 1 };

   // glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 2.0);     // c 系数
   // glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 1.0);        // l 系数
   // glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.5);    // q 系数

   // glLightfv( GL_LIGHT1, GL_AMBIENT, lightAmbient );
   // glLightfv( GL_LIGHT1, GL_DIFFUSE, lightDiffuse );
   // glLightfv( GL_LIGHT1, GL_POSITION, lightPosition );
   // glEnable( GL_LIGHT1 );
   // glEnable(GL_LIGHTING);

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

void TGLWidget::resizeGL(int w, int h)
{
    if(0==h)    h=1;
    glViewport(0,0,(GLint)w,(GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0,(GLfloat)w/(GLfloat)h,0.1,100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void TGLWidget::paintGL()
{
    GLfloat len=1;

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(  0.0,  0.0, zoom );
    glTranslatef(1.5,1.7,0.0);

    draw_block_predict();

    glRotatef(-20,0.0f,1.0f,0.0f);
    glRotatef(-35,1.0f,0.0f,0.0f);
    glRotatef(-30,0.0f,1.0f,0.0f);

    glRotatef(xRot,1.0f,0.0f,0.0f);
    glRotatef(yRot,0.0f,1.0f,0.0f);

    prism_12();

    draw_matrix();
    draw_block();

    if(rtri<=100)
        rtri+=-0.6f;
    xRot+=xSpeed;
    yRot+=ySpeed;
    //zRot+=-0.4f;
}

void TGLWidget::keyPressEvent(QKeyEvent *e)
{
    switch(e->key())
    {
    case Qt::Key_0:
            zoom+=0.5;
            updateGL();
            break;
    case Qt::Key_9:
            zoom-=0.5;
            updateGL();
            break;
    case Qt::Key_W:
            xSpeed=-10;
            updateGL();
            xSpeed=0;
            break;
    case Qt::Key_S:
            xSpeed=10;
            updateGL();
            xSpeed=0;
            break;
    case Qt::Key_Up:
        if(!isPaused && !isEnd)
        {
            if(!locker)
            {
                    locker=true;
                    if(!collision_detect(ROTATE))
                    {
                            block->Rotate();
                            updateGL();
                    }
                    locker=false;
            }
        }
            break;
    case Qt::Key_Down:
        if(!isPaused && !isEnd)
        {
                if(!locker)
                {
                        locker=true;
                        quick_dropdown();
                        updateGL();
                        locker=false;
                }
        }
            break;
    case Qt::Key_Left:
        if(!isPaused && !isEnd)
        {
                if(!locker)
                {
                        locker=true;
                        if(!collision_detect(LEFT))
                        {
                                ySpeed=30;
                                block->move(LEFT);
                                updateGL();
                                ySpeed=0;
                        }
                        locker=false;
                }
        }
            break;
    case Qt::Key_Right:
        if(!isPaused && !isEnd)
        {
                if(!locker)
                {
                        locker=true;
                        if(!collision_detect(RIGHT))
                        {
                                ySpeed=-30;
                                block->move(RIGHT);
                                updateGL();
                                ySpeed=0;
                        }
                        locker=false;
                }
        }
            break;
    case Qt::Key_D:
            ySpeed=-10;
            updateGL();
            ySpeed=0;
            break;
    case Qt::Key_A:
            ySpeed=10;
            updateGL();
            ySpeed=0;
            break;
    default:
            QGLWidget::keyPressEvent(e);
            break;
    }
}

QSize TGLWidget::minimumSizeHint() const
{
        return QSize(50, 50);
}

QSize TGLWidget::sizeHint() const
{
        return QSize(370, 360);
}

void TGLWidget::drawcube(GLfloat level,GLfloat angle_cnt)
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

void TGLWidget::start()
{
    line=0;
    score=0;
    level=0;
    isPaused=false;
    isEnd=false;
    locker=false;
    Bmatrix->clear();
    drop_speed=800;
    timer_drop->start(drop_speed);

    timer_update->start(20);

    block->tmp2block();
    block->init_cylinder();
    block->Random_Shape();

    emit scorechanged(level);
    emit scorechanged(score);
    emit scorechanged(line);
}

void TGLWidget::set_pause()
{
    isPaused=1;
    timer_drop->stop();
}

void TGLWidget::unset_paused()
{
    if(!isEnd)
    {
        isPaused=0;
        timer_drop->start(drop_speed);
    }
}

void TGLWidget::EndGame()
{
    timer_drop->stop();
    isEnd=true;
    emit user_show();
    emit send_score(score);
}

void TGLWidget::slow_dropdown()
{
    if(!locker)
    {
        locker=true;
        if(!reach_bottom())
        {
            block->move(SLOW_DOWN);
            updateGL();
        }

        locker=false;
    }
}

void TGLWidget::quick_dropdown()
{
    timer_drop->stop();
    for(int i=0;i<=4;i++)
        if(!reach_bottom())
            block->move(SLOW_DOWN);
        else
            break;
    timer_drop->start(drop_speed);
     updateGL();
}

void TGLWidget::prism_12()
{
    int x,y;
    int r=4;
    GLfloat half_len=r*tan(15*3.141592653/180);

    for(y=10;y>=-10;y--)
        for(x=0;x<=11;x++)
        {
            glPushMatrix();
            glTranslatef(0.0,y,0.0);
            glRotatef(30*x,0.0f,1.0f,0.0f);
            glTranslatef(0.0,0.0,r);
            glBegin(GL_QUADS);
            glColor4f(1.0f,1.0f,1.0f,0.1f);
            glVertex3f(-half_len, 0.5,0);
            glColor4f(0.5f,0.5f,0.5f,0.1f);
            glVertex3f( half_len, 0.5,0);
            glColor4f(1.0f,1.0f,1.0f,0.1f);
            glVertex3f( half_len,-0.5,0);
            glColor4f(0.5f,0.5f,0.5f,0.1f);
            glVertex3f(-half_len,-0.5,0);
            glEnd();
            glPopMatrix();
        }
}

int TGLWidget::matrixY2prism(int matrixY)
{
   return matrixY-10;
}

bool TGLWidget::reach_bottom()
{
    Coord t[4];
    block->get_cylinder(t);
    for(int i=0;i<=3;i++)
        if(!t[i].y || Bmatrix->a[(t[i].y)-1][t[i].x])
        {
            int n;
            int starting_point=t[0].y;
            for(int k=1;k<=3;k++)
                if(starting_point>t[k].y)
                    starting_point=t[k].y;
            
            int end_point=t[0].y;
            for(int k=1;k<=3;k++)
                if(end_point<t[k].y)
                    end_point=t[k].y;

            int higest_tmp=Bmatrix->highest_line;

            Bmatrix->set_block(t);
            Bmatrix->set_highest(t);
            n=Bmatrix->destroy_lines(starting_point,end_point);
            n++;
            line+=n-1;
            emit linechanged(line);
            score+=n*n;
            emit scorechanged(score);

            int level_tmp=level;
            level=score/10;
            emit levelchanged(level);

            if(level_tmp!=level && drop_speed>=200)
            {
                drop_speed-=70;
                timer_drop->stop();
                timer_drop->start(drop_speed);
            }

            if(higest_tmp==14 || (higest_tmp<14 && Bmatrix->highest_line>14))
            {
                drop_speed+=60;
                timer_drop->stop();
                timer_drop->start(drop_speed);
            }

            block->tmp2block();
            block->init_cylinder();
            block->Random_Shape();

            Coord z[4];
            block->get_cylinder(z);
            for(int u=0;u<=3;u++)
                if(Bmatrix->a[z[u].y][z[u].x])
                {
                    EndGame();
                    break;
                }
            return true;
        }

    return false;
}

void TGLWidget::draw_block()
{
    Coord t[4];
    block->get_cylinder(t);
    for(int i=0;i<=3;i++)
        drawcube(matrixY2prism(t[i].y),t[i].x);
}

void TGLWidget::draw_block_predict()
{
    glPushMatrix();
    glTranslatef(-10,10,-7);
    Coord t[4];
    block->get_predict(t);
    for(int i=0;i<=3;i++)
        drawcube(t[i].y,t[i].x);
    glPopMatrix();
}

void TGLWidget::draw_matrix()
{
    for(int i=0;i<=23;i++)
        for(int j=0;j<=11;j++)
            if(Bmatrix->a[i][j])
                drawcube(matrixY2prism(i),j);
}

bool TGLWidget::collision_detect(int direction)
{
    Coord t[4];
    block->get_cylinder(t);

    if(direction==LEFT)
    {
        for(int n=0;n<=3;n++)
        {
            t[n].x ? (t[n].x)-- : t[n].x=11;
            if(Bmatrix->a[t[n].y][t[n].x])
                return true;
        }
        return false;
    }

    else if(direction==RIGHT)
    {
        for(int n=0;n<=3;n++)
        {
            (t[n].x==11) ? t[n].x=0 : (t[n].x)++;
            if(Bmatrix->a[t[n].y][t[n].x])
                return true;
        }
        return false;
    }

    else if(direction==ROTATE)
    {
        block->Rotate();
        block->get_cylinder(t);
        for(int n=0;n<=3;n++)
            if(Bmatrix->a[t[n].y][t[n].x])
            {
                for(int i=0;i<=2;i++)
                    block->Rotate();
                return true;
            }
        for(int i=0;i<=2;i++)
            block->Rotate();
        return false;
    }
}

void TGLWidget::mousePressEvent(QMouseEvent *event)
{
    lastpos=event->pos();
}

void TGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastpos.x();
    int dy = event->y() - lastpos.y();

    if (event->buttons() & Qt::LeftButton)
    {
        xSpeed += 0.7*dy;
        ySpeed += 0.7*dx;
        updateGL();
        xSpeed=0;
        ySpeed=0;
    }

    lastpos = event->pos();
}

void TGLWidget::wheelEvent(QWheelEvent *e)
{
    if (e->delta() > 0)
    {
        if (e->orientation() == Qt::Vertical)
            zoom+=0.5;
    }
    else if (e->delta() < 0)
        if (e->orientation() == Qt::Vertical)
            zoom-=0.5;
}
