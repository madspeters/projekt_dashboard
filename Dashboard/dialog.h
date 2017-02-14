#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QTimer>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_Stop_clicked();

    void on_Start_clicked();

    void on_Automode_clicked();

private:
    Ui::Dialog *ui;

    QGraphicsScene *scene;

};

#endif // DIALOG_H
