#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>

class QTimer;
class QKeyEvent;
class BLOCK;
class Coord;
class BLOCK_MATRIX;

class TGLWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit TGLWidget(QWidget *parent = 0);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    void keyPressEvent(QKeyEvent *);
    void drawcube(GLfloat,GLfloat);
    void drawplane();

    int matrixY2prism(int);

    void EndGame();

    void get_predict(Coord *t);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *e);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void prism_12();

    void draw_screen();
    bool collision_detect(int direction);

    void draw_block();
    void draw_block_predict();
    void draw_matrix();

    void move_left();

    bool reach_bottom();

signals:
    void scorechanged(int);
    void levelchanged(int);
    void linechanged(int);
    void user_show();
    void send_score(int);

private slots:
    void slow_dropdown();
    void quick_dropdown();
    void start();
    void set_pause();
    void unset_paused();

private:
    QTimer *timer_update;
    bool timer_flag;
    GLfloat rtri;
    GLfloat xRot;
    GLfloat yRot;
    GLfloat zRot;

    double theta;

    GLfloat zoom;
    GLfloat xSpeed,ySpeed;

    GLfloat dropdown_h;

    BLOCK *block;
    BLOCK_MATRIX *Bmatrix;
    QTimer *timer_drop;

    bool locker;
    bool isPaused;
    bool isEnd;

    int score;
    int level;
    int line;

    int drop_speed;

    QPoint lastpos;
};

#endif // TGLWIDGET_H
