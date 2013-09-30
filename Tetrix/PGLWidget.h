#ifndef PGLWIDGET_H
#define PGLWIDGET_H

#include <QGLWidget>

class Coord;
class QTimer;

class PGLWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit PGLWidget(QWidget *parent = 0);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

    void initializeGL();
    void resizeGL(int w, int h);

    void set_t(Coord *);

    void drawcube(GLfloat,GLfloat);

    Coord *tt[4];

protected:
    void paintGL();
    void keyPressEvent(QKeyEvent *);
    void draw_block();

private:
    QTimer *timer;
};

#endif // PGLWIDGET_H
