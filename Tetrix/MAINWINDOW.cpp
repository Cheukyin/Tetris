#ifndef MAINWINDOW_CPP
#define MAINWINDOW_CPP

#include "TGLWidget.h"
#include "MAINWINDOW.h"
#include <QPushButton>
#include <QKeyEvent>
#include <QLabel>
#include <QLayout>
#include <QLCDNumber>
#include <QApplication>
#include <QMessageBox>
#include <QTimer>
#include "PGLWidget.h"
#include "OPERATOR.h"
#include "USERDIALOG.h"
#include "SCORERECORD.h"

MainWindow::MainWindow()
{
    userdialog=new USERDIALOG;

    tglWidget = new TGLWidget;

    connect(tglWidget,SIGNAL(user_show()),userdialog,SLOT(show()));
    connect(tglWidget,SIGNAL(send_score(int)),userdialog,SLOT(receive_score(int)));

    next_label=new QLabel(tr("NEXT PIECE"));
    //next_board_label=new QLabel();
    //next_board_label=new PGLWidget();

    level_label=new QLabel(tr("LEVEL"));
    level_lcd=new QLCDNumber(5);
    connect(tglWidget,SIGNAL(levelchanged(int)),level_lcd,SLOT(display(int)));

    score_label=new QLabel(tr("SCORE"));
    score_lcd=new QLCDNumber(5);
    connect(tglWidget,SIGNAL(scorechanged(int)),score_lcd,SLOT(display(int)));

    lines_label=new QLabel(tr("LINES REMOVED"));
    lines_lcd=new QLCDNumber(5);
    connect(tglWidget,SIGNAL(linechanged(int)),lines_lcd,SLOT(display(int)));

    start_button=new QPushButton(tr("START"));
    start_button->setFocusPolicy(Qt::NoFocus);
    connect(start_button,SIGNAL(clicked()),tglWidget,SLOT(start()));

    pause_button=new QPushButton(tr("PAUSE"));
    pause_button->setFocusPolicy(Qt::NoFocus);
    connect(pause_button,SIGNAL(clicked()),tglWidget,SLOT(set_pause()));

    exit_button=new QPushButton(tr("EXIT"));
    exit_button->setFocusPolicy(Qt::NoFocus);
    connect(exit_button,SIGNAL(clicked()),this,SLOT(close()));

    resume_button=new QPushButton(tr("RESUME"));
    resume_button->setFocusPolicy(Qt::NoFocus);
    connect(resume_button,SIGNAL(clicked()),tglWidget,SLOT(unset_paused()));

    highscore_button=new QPushButton(tr("HIGHSCORE"));
    highscore_button->setFocusPolicy(Qt::NoFocus);
    scorerecord=new SCORERECORD;
    connect(highscore_button,SIGNAL(clicked()),scorerecord,SLOT(show()));
    connect(highscore_button,SIGNAL(clicked()),scorerecord,SLOT(read_record()));
    connect(highscore_button,SIGNAL(clicked()),tglWidget,SLOT(set_pause()));

    connect(scorerecord,SIGNAL(send_close()),tglWidget,SLOT(unset_paused()));

    QVBoxLayout *layout1 = new QVBoxLayout;
         layout1->addWidget(next_label);
         //layout1->addWidget(next_board_label);

         layout1->addWidget(score_label);
         layout1->addWidget(score_lcd);

         layout1->addWidget(level_label);
         layout1->addWidget(level_lcd);

         layout1->addWidget(lines_label);
         layout1->addWidget(lines_lcd);

    QVBoxLayout *layout3 = new QVBoxLayout;
         layout3->addWidget(start_button);
         layout3->addWidget(pause_button);
         layout3->addWidget(resume_button);
         layout3->addWidget(highscore_button);
         layout3->addWidget(exit_button);

    QHBoxLayout *mainlayout = new QHBoxLayout;
         mainlayout->addLayout(layout1);
         mainlayout->addWidget(tglWidget);
         mainlayout->addLayout(layout3);

    //setGeometry(100,100,1000,768);
    setWindowTitle(tr("Tetrix"));

    QWidget * widget = new QWidget (this) ;
         widget->setLayout(mainlayout) ;
         this->setCentralWidget(widget) ;

    //timer_predict=new QTimer(this);
    //connect(timer_predict,SIGNAL(timeout()),this,SLOT(show_pgl()));
    //timer_predict->start(500);

    resize(600, 500);
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
    {
            QMessageBox::StandardButton reply;
            emit pause_button->clicked();
            reply=QMessageBox::question(NULL,"Tetrix","Do you want to exit?",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
            if(reply==QMessageBox::Yes)
                    qApp->quit();
            else
                emit resume_button->clicked();
    }
    if (e->key() == Qt::Key_F)
    {
        fullscreen=!fullscreen;
        if(fullscreen)
            showFullScreen();
        else
            showNormal();
     }
    else
        tglWidget->keyPressEvent(e);
}

void MainWindow::show_pgl()
{
    Coord t[4];
    tglWidget->get_predict(t);
    //pglwidget->set_t(t);
}

#endif // MAINWINDOW_CPP
