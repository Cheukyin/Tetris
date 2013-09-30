#ifndef SCORERECORD_H
#define SCORERECORD_H

#include <QDialog>

class QPushButton;
class QLabel;
class QString;
class QLCDNumber;

class SCORERECORD:public QDialog
{
    Q_OBJECT

public:
    SCORERECORD(QWidget *parent=0);
    void closeEvent(QCloseEvent *e);

signals:
    void send_close();

private slots:
    void read_record();

private:
    QPushButton *okButton;
    QLabel *player;
    QLCDNumber *score;
};

#endif // SCORERECORD_H
