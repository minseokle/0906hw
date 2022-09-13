#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsView>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    x=50;
    y=50;
    dx=0;
    dy=0;
    deg=0;
    cir=0;
    rec=0;
    tri=0;
    scene = new QGraphicsScene(this);
    scene->addLine(-400,0,400,0,Qt::NoPen);
    scene->addLine(0,-400,0,400,Qt::NoPen);

    QGraphicsView * view = new QGraphicsView(this);
    view->setScene(scene);
    ui->viewlayout->addWidget(view);

    mr=new Rectangle(scene);
    mc=new Circle(scene);
    mt=new Triangle(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_x_valueChanged(int arg1)
{
    x=arg1;
}

void MainWindow::on_y_valueChanged(int arg1)
{
    y=arg1;
}

void MainWindow::on_color_clicked()
{
    QColor color = QColorDialog::getColor(col);
    if(color.isValid()){
        col=color;
    }
}

void MainWindow::on_draw_clicked()
{
    if(y>0&&x>0)
    {
        if(ui->Rectangle->isChecked()&&!rec)
        {
            mr->Draw(0,0,x,y,Qt::NoPen,QBrush(col));
            rec=true;
        }
        if(ui->Circle->isChecked()&&!cir)
        {
            mc->Draw(0,0,x,y,Qt::NoPen,QBrush(col));
            cir=true;
        }
        if(ui->Triangle->isChecked()&&!tri)
        {
            mt->Draw(0,0,x,y,Qt::NoPen,QBrush(col));
            tri=true;
        }
    }
}

void MainWindow::on_dx_valueChanged(int arg1)
{
    dx=arg1;
}

void MainWindow::on_dy_valueChanged(int arg1)
{
    dy=arg1;
}

void MainWindow::on_move_clicked()
{
    if(ui->Rectangle->isChecked()&&rec)
    {
        mr->Move(dx,dy);
    }
    if(ui->Circle->isChecked()&&cir)
    {
        mc->Move(dx,dy);
    }
    if(ui->Triangle->isChecked()&&tri)
    {
        mt->Move(dx,dy);
    }
}

void MainWindow::on_deg_valueChanged(int arg1)
{
    deg=arg1;
}

void MainWindow::on_rotate_clicked()
{
    if(ui->Rectangle->isChecked()&&rec)
    {
        mr->Rotate(deg);
    }
    if(ui->Circle->isChecked()&&cir)
    {
        mc->Rotate(deg);
    }
    if(ui->Triangle->isChecked()&&tri)
    {
        mt->Rotate(deg);
    }
}







