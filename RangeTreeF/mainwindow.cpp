#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ranget.h"
#include "utility"
#include "vector"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pixmap=new QPixmap(800,500);
    pixmap->fill();


    QColor color("black");
    lapiz=new QPen(color);

    ui->la1->setPixmap (*pixmap);
    q=new QPainter(pixmap);
    q->setPen(*lapiz);

    vector<point> Puntos;

    for(int i=0;i<1027;i++){

        point punto = point{rand()%800,rand()%500,0};

        Puntos.push_back(punto);

    }
pixmap->fill();
    for(int i=0;i<1027;i++){
       q->drawEllipse (Puntos[i].x-1,Puntos[i].y-1,2,2);
    }

 ui->la1->setPixmap(*pixmap);

    range_tree=new RangeT(Puntos,0,Puntos.size ());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int x1=ui->lineEdit->text ().toInt ();
    int y1=ui->lineEdit_2->text ().toInt ();
    int x2=ui->lineEdit_3->text ().toInt ();
    int y2=ui->lineEdit_4->text ().toInt ();

    rectangle query={x1,x2,y1,y2};

    range_tree->range2Dquery (range_tree,query,q);

}



