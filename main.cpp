#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QDir>
#include <QTimer>
#include <QDebug>
#include "enemy.h"
#include "player.h"
#include "bullet.h"
#include "pellet.h"
//#include "main.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene;

    QFile file("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/board.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    file.flush();
    int boardData[17][15];
    QString temp;
    for (int i = 0; i < 17; i++)
        for (int j = 0; j < 15; j++)
        {
            stream >> temp;
            boardData[i][j] = temp.toInt();
        }

    QPixmap mapImage("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/mapz.png");
    mapImage = mapImage.scaledToWidth(700);
    mapImage = mapImage.scaledToHeight(700);

    //Normal display
    QPixmap normalDisplay("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/normalDis.png");
    normalDisplay = normalDisplay.scaledToWidth(50);
    normalDisplay = normalDisplay.scaledToHeight(50);

    QPixmap heartImage("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/heart.png");
    heartImage = heartImage.scaledToWidth(50);
    heartImage = heartImage.scaledToHeight(50);

    QGraphicsPixmapItem boardItems[17][15];
    for (int i = 0; i < 17; i++)
        for (int j = 0; j < 15; j++)
        {

             if(boardData[i][j] == -2)
                boardItems[i][j].setPixmap(mapImage);
             else if(boardData[i][j] == -3)
                 boardItems[i][j].setPixmap(heartImage);
             else if(boardData[i][j] == -4)
                 boardItems[i][j].setPixmap(heartImage);
             else if(boardData[i][j] == -5)
                 boardItems[i][j].setPixmap(heartImage);
             else if(boardData[i][j] == -6)
                 boardItems[i][j].setPixmap(normalDisplay);

            // Set Position
            boardItems[i][j].setPos(50 + j * 50, 50 + i * 50);

            // Add to the Scene
            scene.addItem(&boardItems[i][j]);
        }

    bullet *b1 = new bullet(boardData,1,1);
    scene.addItem(b1);

    bullet *b2 = new bullet(boardData,1,11);
    scene.addItem(b2);

    bullet *b3 = new bullet(boardData,14,1);
    scene.addItem(b3);

    bullet *b4 = new bullet(boardData,14,11);
    scene.addItem(b4);

    pellet *pt1 = new pellet(boardData,2,3);
    scene.addItem(pt1);

    pellet *pt2 = new pellet(boardData,14,6);
    scene.addItem(pt2);

        Enemy *e = new Enemy (boardData,13,5);
        scene.addItem(e);

        Enemy *e2 = new Enemy (boardData,13,8);
        scene.addItem(e2);

        //contains address of enemy object
        Enemy **arr[2] = {&e2, &e};

        Player *p = new Player(boardData, *arr);
        p -> setFlag(QGraphicsItem :: ItemIsFocusable);
        p -> setFocus();
        scene.addItem(p);

        QObject::connect(p,&Player::vertexChanged,e,&Enemy::PlayerMoved);
        QObject::connect(p,&Player::vertexChanged,e2,&Enemy::PlayerMoved);

        QTimer timer1,timer2;
        timer1.start(500);
        QObject::connect(&timer1,SIGNAL(timeout()),e,SLOT(moveEnemy()));
        timer2.start(500);
        QObject::connect(&timer2,SIGNAL(timeout()),e2,SLOT(moveEnemy()));

    QGraphicsView* view = new QGraphicsView(&scene);
    view->show();
    return a.exec();
}
