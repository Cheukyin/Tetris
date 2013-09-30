#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <QDialog>

class QLineEdit;
class QPushButton;
class QLabel;
class QString;

class USERDIALOG:public QDialog
{
    Q_OBJECT

public:
    USERDIALOG(QWidget *parent=0);

private slots:
    void okClicked();
    void receive_score(int s);
    void enableOKButton(const QString &text);

private:
    QLineEdit *lineEdit;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *userLabel;
    int score;
};

#endif // USERDIALOG_H
