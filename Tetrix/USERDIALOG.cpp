#include "USERDIALOG.h"
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QLayout>
#include <QFile>
#include <QDataStream>
#include <QTextStream>
#include <QMessageBox>

USERDIALOG::USERDIALOG(QWidget *parent)
    :QDialog(parent)
{
    userLabel=new QLabel(tr("Username:"));
    lineEdit=new QLineEdit;
    okButton=new QPushButton(tr("OK"));
    cancelButton=new QPushButton(tr("Cancel"));

    connect(lineEdit,SIGNAL(textChanged(const QString &)),this,SLOT(enableOKButton(const QString &)));
    connect(cancelButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(okButton,SIGNAL(clicked()),this,SLOT(okClicked()));

    QHBoxLayout *toplayout=new QHBoxLayout;
    toplayout->addWidget(userLabel);
    toplayout->addWidget(lineEdit);

    QHBoxLayout *bottomlayout=new QHBoxLayout;
    bottomlayout->addWidget(okButton);
    bottomlayout->addWidget(cancelButton);

    QVBoxLayout *mainlayout=new QVBoxLayout;
    mainlayout->addLayout(toplayout);
    mainlayout->addLayout(bottomlayout);
    setLayout(mainlayout);

    setWindowTitle(tr("Username"));
    setFixedHeight(sizeHint().height());
}

void USERDIALOG::enableOKButton(const QString &text)
{
    okButton->setEnabled(!text.isEmpty());
}

void USERDIALOG::okClicked()
{
   QString text=lineEdit->text();

   QString fileName="record.dat" ;
   QFile file(fileName);

   int scores[10];
   QString player[10];

   for(int i=0;i<=9;i++)
   {
       scores[i]=0;
       player[i]="Anonymous";
   }

   if(file.open(QIODevice::ReadOnly))
   {
       QDataStream in(&file);
       int i=0;
       while(!in.atEnd())
       {
           in>>scores[i]>>player[i];
           i++;
       }
       file.close();
   }

   int k=10;
   for(int i=0;i<=9;i++)
       if(score>=scores[i])
       {
           k=i;
           break;
       }
   for(int i=9;i>k;i--)
   {
       scores[i]=scores[i-1];
       player[i]=player[i-1];
   }
   if(k<10)
   {
       scores[k]=score;
       player[k]=text;
   }

   if(file.open(QIODevice::WriteOnly))
   {
       QDataStream out(&file);
       for(int i=0;i<=9;i++)
           out<<scores[i]<<player[i];
       file.close();
   }
   else
       QMessageBox::warning(this,"Warnning","can't open",QMessageBox::Yes);

   close();
}

void USERDIALOG::receive_score(int s)
{
    score=s;
}
