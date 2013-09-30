#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class TGLWidget;
class PGLWidget;
class QLabel;
class QPushButton;
class QLCDNumber;
class QTimer;
class USERDIALOG;
class SCORERECORD;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    void keyPressEvent(QKeyEvent *);

private slots:
    void show_pgl();

private:
    TGLWidget *tglWidget;
    PGLWidget *pglwidget;

    bool fullscreen;

    QLabel *next_label;
    //QLabel *next_board_label;
    PGLWidget *next_board_label;

    QLabel *level_label;
    QLCDNumber *level_lcd;

    QLabel *score_label;
    QLCDNumber *score_lcd;

    QLabel *lines_label;
    QLCDNumber *lines_lcd;

    QPushButton *start_button;
    QPushButton *pause_button;
    QPushButton *exit_button;
    QPushButton *resume_button;
    QPushButton *highscore_button;

    QTimer *timer_predict;

    USERDIALOG *userdialog;
    SCORERECORD *scorerecord;
};

#endif // MAINWINDOW_H
