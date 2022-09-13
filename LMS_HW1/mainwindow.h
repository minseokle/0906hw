#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_x_valueChanged(int arg1);

    void on_color_clicked();

    void on_draw_clicked();

    void on_dx_valueChanged(int arg1);

    void on_move_clicked();

    void on_rotate_clicked();

    void on_y_valueChanged(int arg1);

    void on_dy_valueChanged(int arg1);

    void on_deg_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QColor col;
    Rectangle *mr;
    Circle *mc;
    Triangle *mt;
    bool cir,rec,tri;

    int x,y,dx,dy,deg;
};
#endif // MAINWINDOW_H
