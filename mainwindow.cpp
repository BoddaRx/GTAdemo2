#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/#include "mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QApplication>

int main(int argc, char *argv[])
{
      QApplication a(argc, argv);
      QGraphicsScene * scene = new QGraphicsScene();



      QGraphicsRectItem * rect = new   QGraphicsRectItem();
      rect-> setRect(0, 0, 100, 100 )  ;

      scene -> addItem (rect);
      QGraphicsView * view = new QGraphicsView(scene);
          view-> setScene (scene);
    view->show( ) ;

   // MainWindow w;
    //w.show();
    return a.exec();
}
