#include "dialog.h"
#include "ui_dialog.h"
#include <QGraphicsScene>
#include <QGraphicsview>
#include <QGraphicsItem>
#include <QGraphicsObject>
#include <QPixmap>
#include <vector>
#include <QPen>
#include <iostream>
#include <QPainterPath>


Dialog::Dialog(QWidget *parent) :

    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

Dialog::~Dialog()
{
    delete ui;
}

// Når startknappen klikkes
void Dialog::on_Start_clicked()
{
    // Banen og striben i midten deklareres.
    QPen pen;
         pen.setCapStyle(Qt::RoundCap);
         pen.setJoinStyle(Qt::MiterJoin);
         pen.setColor(qRgb(80,83,82));
         pen.setWidth(20);
    QPen stribe;
         stribe.setCapStyle(Qt::RoundCap);
         stribe.setJoinStyle(Qt::RoundJoin);
         stribe.setColor(qRgb(255,255,255));
         stribe.setWidth(2);

    // x, y , pi og vinkel deklareres.
    float x = 0;
    float y = 0;
    float angle = 0;
    double pi = 3.14159265;

    // Summeret data fra strain gauges gemmes i data.
    std::vector<double> data = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0};

    // Der itereres gennem data. For hvert tal tjekkes tallets værdi og banen kører enten ligeud, drejer til venstre eller til højre.
    for (unsigned i = 0; i < data.size(); i++){
        if (data[i] == 0){
            auto nx = x + 2.5 * cos(angle / 360.0 * 2.0 * pi);
            auto ny = y + 2.5 * sin(angle / 360.0 * 2.0 * pi);
            scene->addLine(x, y, nx, ny, pen);
            x = nx;
            y = ny;
            }
        else if (data[i] > 1 && data[i] < 5){
            for (unsigned j = 0; j < 90; j++){
                angle += 1;
                auto nx = x + 0.505 * cos(angle / 360.0 * 2.0 * pi);
                auto ny = y + 0.505 * sin(angle / 360.0 * 2.0 * pi);
                scene->addLine(x, y, nx, ny, pen);
                x = nx;
                y = ny;
            }
        }
        else if (data[i] > 5){
            for (int j = 0; j < 180; j++){
                angle += 1;
                auto nx = x + 0.505 * cos(angle / 360.0 * 2.0 * pi);
                auto ny = y + 0.505 * sin(angle / 360.0 * 2.0 * pi);
                scene->addLine(x, y, nx, ny, pen);
                x = nx;
                y = ny;
            }
        }
        else if (data[i] < -1 && data[i] > -5){
            for (int k = 0; k < 90; k++){
                angle -= 1;
                auto nx = x + 0.505 * cos(angle / 360.0 * 2.0 * pi);
                auto ny = y + 0.505 * sin(angle / 360.0 * 2.0 * pi);
                scene->addLine(x, y, nx, ny, pen);

                x = nx;
                y = ny;
            }
        }
        else if (data[i] < -5){
            for (int k = 0; k < 180; k++){
                angle -= 1;
                auto nx = x + 0.505 * cos(angle / 360.0 * 2.0 * pi);
                auto ny = y + 0.505 * sin(angle / 360.0 * 2.0 * pi);
                scene->addLine(x, y, nx, ny, pen);
                x = nx;
                y = ny;
             }
         }
    }

    // x, y og vinkel nulstilles.
        x = 0;
        y = 0;
        angle = 0;

    // Striben i midten tegnes med samme fremgangsmåde.
        for (unsigned i = 0; i < data.size(); i++){
            if (data[i] == 0){
                auto nx = x + 2.5 * cos(angle / 360.0 * 2.0 * pi);
                auto ny = y + 2.5 * sin(angle / 360.0 * 2.0 * pi);
                scene->addLine(x, y, nx, ny, stribe);
                x = nx;
                y = ny;
                }
            else if (data[i] > 1 && data[i] < 5){
                for (unsigned j = 0; j < 90; j++){
                    angle += 1;
                    auto nx = x + 0.505 * cos(angle / 360.0 * 2.0 * pi);
                    auto ny = y + 0.505 * sin(angle / 360.0 * 2.0 * pi);
                    scene->addLine(x, y, nx, ny, stribe);
                    x = nx;
                    y = ny;
                }
            }
            else if (data[i] > 5){
                for (int j = 0; j < 180; j++){
                    angle += 1;
                    auto nx = x + 1 * cos(angle / 360.0 * 2.0 * pi);
                    auto ny = y + 0.505 * sin(angle / 360.0 * 2.0 * pi);
                    scene->addLine(x, y, nx, ny, stribe);
                    x = nx;
                    y = ny;
                }
            }
            else if (data[i] < -1 && data[i] > -5){
                for (int k = 0; k < 90; k++){
                    angle -= 1;
                    auto nx = x + 0.505 * cos(angle / 360.0 * 2.0 * pi);
                    auto ny = y + 0.505 * sin(angle / 360.0 * 2.0 * pi);
                    scene->addLine(x, y, nx, ny, stribe);

                    x = nx;
                    y = ny;
               }
            }
            else if (data[i] < -5){
                for (int k = 0; k < 180; k++){
                    angle -= 1;
                    auto nx = x + 0.505 * cos(angle / 360.0 * 2.0 * pi);
                    auto ny = y + 0.505 * sin(angle / 360.0 * 2.0 * pi);
                    scene->addLine(x, y, nx, ny, stribe);

                    x = nx;
                    y = ny;
               }
            }
        }
    // Startlinjen tegnes.
        QPixmap start("//Mac/Home/Desktop/GitHub/projekt_dashboard/Dashboard_tegninger/start");
        QGraphicsPixmapItem *startlinje = scene->addPixmap(start);
        startlinje->moveBy(0, -10);
}

// Når stopknappen klikkes
void Dialog::on_Stop_clicked()
{

}

// Når automode klikkes
void Dialog::on_Automode_clicked()
{

}
