#include "SCORERECORD.h"
#include <QLCDNumber>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QFile>
#include <QDataStream>
#include <QMessageBox>

SCORERECORD::SCORERECORD(QWidget *parent)
    :QDialog(parent)
{
    player=new QLabel[10];
    okButton=new QPushButton(tr("OK"));
    score=new QLCDNumber[10];

    connect(okButton,SIGNAL(clicked()),this,SLOT(close()));

    QHBoxLayout *inform=new QHBoxLayout[10];
    for(int i=0;i<=9;i++)
    {
        inform[i].addWidget(player+i);
        inform[i].addWidget(score+i);
    }

    QVBoxLayout *mainlayout=new QVBoxLayout;
    for(int i=0;i<=9;i++)
        mainlayout->addLayout(inform+i);
    mainlayout->addWidget(okButton);
    setLayout(mainlayout);

    setWindowTitle(tr("Top 10"));
    setFixedHeight(sizeHint().height());
}

void SCORERECORD::read_record()
{
    QString fileName="record.dat";
    QFile file(fileName);

    int scores_n[10];
    QString player_n[10];

    for(int i=0;i<=9;i++)
    {
        scores_n[i]=0;
        player_n[i]="Anonymous";
    }

    if(file.open(QIODevice::ReadOnly))
    {
        QDataStream in(&file);
        int i=0;
        while(i<=9)
        {
            in>>scores_n[i]>>player_n[i];
            player[i].setText(player_n[i]);
            score[i].display(scores_n[i]);
            i++;
        }
        file.close();
    }
    else
        QMessageBox::warning(this,"Warnning","can't open",QMessageBox::Yes);
}

void SCORERECORD::closeEvent(QCloseEvent *e)
{
    emit send_close();
}
