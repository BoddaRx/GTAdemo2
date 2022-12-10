#include "player.h"
#include <QDebug>
#include <QProcess>
#include "bullet.h"
#include "enemy.h"
#include "pellet.h"
#include <QTimer>
#include "health.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTime>
#include <QObject>
#include "gameover.h"
#include "display.h"
#include "gate.h"
#include <QApplication>
#include "win.h"
#include "timer.h"
#include <QAbstractAnimation>

void Player::keyPressEvent(QKeyEvent* event)
{

    int boardData[17][15];

    QPixmap FrankTop("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/frankTopz.png");
    FrankTop = FrankTop.scaledToWidth(50);
    FrankTop = FrankTop.scaledToHeight(50);

    QPixmap FrankBottom("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/frankBottomz.png");
    FrankBottom = FrankBottom.scaledToWidth(50);
    FrankBottom = FrankBottom.scaledToHeight(50);

    QPixmap FrankRight("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/frankRightz.png");
    FrankRight = FrankRight.scaledToWidth(50);
    FrankRight = FrankRight.scaledToHeight(50);

    QPixmap FrankLeft("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/frankLeftz.png");
    FrankLeft = FrankLeft.scaledToWidth(50);
    FrankLeft = FrankLeft.scaledToHeight(50);

    QPixmap carFront("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/carFront.png");
    carFront = carFront.scaledToWidth(50);
    carFront = carFront.scaledToHeight(50);

    QPixmap carBack("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/carBack.png");
    carBack = carBack.scaledToWidth(50);
    carBack = carBack.scaledToHeight(50);

    QPixmap carRight("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/carRight.png");
    carRight = carRight.scaledToWidth(50);
    carRight = carRight.scaledToHeight(50);

    QPixmap carLeft("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/carLeft.png");
    carLeft = carLeft.scaledToWidth(50);
    carLeft = carLeft.scaledToHeight(50);

    //4 arrows of movement
    if (event->key() == Qt::Key_Up && data[row - 1][column] > 0)
    {

        setPixmap(FrankTop);
        row--;
    }
    else if (event->key() == Qt::Key_Down && data[row + 1][column] > 0)
    {

        setPixmap(FrankBottom);
        row++;
    }
    else if (event->key() == Qt::Key_Right && data[row][column + 1] > 0)
    {

        setPixmap(FrankRight);
        column++;
    }
    else if (event->key() == Qt::Key_Left && data[row][column - 1] > 0)
    {

        setPixmap(FrankLeft);
        column--;
    }
    else if (event->key() == Qt::Key_W && data[row - 1][column] > 0)
            {
                setPixmap(carFront);
                row--;
            }
            else if (event->key() == Qt::Key_S && data[row + 1][column] > 0)
            {
                setPixmap(carBack);
                row++;
            }
            else if (event->key() == Qt::Key_D && data[row][column + 1] > 0)
            {
                setPixmap(carRight);
                column++;
            }
            else if (event->key() == Qt::Key_A && data[row][column - 1] > 0)
            {
                setPixmap(carLeft);
                column--;
            }

    setPos(50 + column * 50, 50 + row * 50);

    QPixmap FrankBullet("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/frankBullets.png");
    FrankBullet = FrankBullet.scaledToWidth(50);
    FrankBullet = FrankBullet.scaledToHeight(50);

    QPixmap FrankPellet("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/frankPellet.png");
    FrankPellet = FrankPellet.scaledToWidth(50);
    FrankPellet = FrankPellet.scaledToHeight(50);

    QList<QGraphicsItem*> items = collidingItems();
    for (int i = 0; i < items.size(); i++)
    {
        //If the player collides with a bullet, the bullet disapears
        if (typeid(*items[i]) == typeid(bullet))
        {
            this -> bulletCount--;

        scene()->removeItem(items[i]);

        setPixmap(FrankBullet);

        QTimer* timer5 = new QTimer(this);
        timer5->start(1000);

        connect(timer5, &QTimer::timeout, [=]() {

                setPixmap(FrankTop);
                timer5->stop();
    });

        if(bulletCount == 3)
        {
            qDebug() << "Enemy 1 now has a half life";
        }

        else if(bulletCount == 2)
        {
            this -> enemyCount--;
        qDebug() << "Enemy 1 now is dead";
        scene() -> removeItem(this->enemyArr[0]);
        }

        else if (bulletCount == 1)
        {
            qDebug() << "Enemy 2 now has a half life";
        }
        else if (bulletCount == 0)
        {
            this -> enemyCount--;
            qDebug() << "Enemy 2 now is dead";
            scene() -> removeItem(this->enemyArr[1]);

            gate *g1 = new gate(boardData,12,4);
            scene()->addItem(g1);
        }
        }

        //If the player collides with a pellet, his shape changes and become powerful and unaffected by his enemies
        else if (typeid(*items[i]) == typeid(pellet))
        {
            this -> pelletCount--;
            qDebug() << "SpongeBob now is immortal and powerful";
            scene() -> removeItem(items[i]);



            if (pelletCount == 1)
            {
                setPixmap(FrankPellet);
                display *d1 = new display(boardData,1,13);
                scene()->addItem(d1);

                timerx *tzx = new timerx(boardData,0,0);
                scene()->addItem(tzx);

            QTimer* timer3 = new QTimer(this);
            timer3->start(5000);

            this->isInvincible = true;

            connect(timer3, &QTimer::timeout, [=]() {
                scene()->removeItem(d1);
                this->isInvincible = false;
                scene()->removeItem(tzx);
                    timer3->stop();
        });


            }else if(pelletCount == 0)
            {
                setPixmap(FrankPellet);

                display *d2 = new display(boardData,1,13);
                scene()->addItem(d2);

                timerx *t2 = new timerx(boardData,0,0);
                scene()->addItem(t2);

                QTimer* timer4 = new QTimer(this);
                timer4->setInterval(5000);
                timer4->start();

                this->isInvincible = true;

                connect(timer4, &QTimer::timeout, [=]() {
                    scene()->removeItem(d2);
                    scene()->removeItem(t2);
                    this->isInvincible = false;
                        timer4->stop();
            });
            }
        }

        //If the player collides with an enemy, he loses health and start from the begining till he loses the game
        else if (typeid(*items[i]) == typeid(Enemy))
        {

            if(!this->isInvincible)
            {
            this -> playerHealth--;
            }

            if(playerHealth == 2)
            {
                this->row=7;
                this->column=7;
                this->setPos(50 + column * 50, 50 + row * 50);

                if(enemyCount == 1)
                {
                    scene() -> addItem(this->enemyArr[0]);
                        this->enemyCount++;

                }

                if(bulletCount == 3)
                {
                    bullet *b5 = new bullet(boardData,2,2);
                    scene()->addItem(b5);
                    bulletCount++;
                }

                else if(bulletCount == 2)
                {
                    bullet *b6 = new bullet(boardData,2,5);
                    scene()->addItem(b6);

                    bullet *b7 = new bullet(boardData,12,1);
                    scene()->addItem(b7);
                    bulletCount+=2;
                }

                else if(bulletCount == 1)
                {
                    bullet *b8 = new bullet(boardData,3,1);
                    scene()->addItem(b8);

                    bullet *b9 = new bullet(boardData,13,1);
                    scene()->addItem(b9);

                    bullet *b10 = new bullet(boardData,10,11);
                    scene()->addItem(b10);
                    bulletCount+=3;
                }

                if(pelletCount == 1)
                {
                    pellet *b3 = new pellet(boardData,4,6);
                    scene()->addItem(b3);
                    pelletCount++;
                }

                else if(pelletCount == 0)
                {
                    pellet *b4 = new pellet(boardData,11,5);
                    scene()->addItem(b4);

                    pellet *b5 = new pellet(boardData,4,11);
                    scene()->addItem(b5);
                    pelletCount+=2;
                }


        qDebug() << "Your player now has two lives left";

        health *h1 = new health(boardData,14,12);
        scene()->addItem(h1);

            }
            else if (playerHealth == 1)
            {
                qDebug() << "Your player now has 1 life left";

                this->row=7;
                this->column=7;
                this->setPos(50 + column * 50, 50 + row * 50);

                if(enemyCount == 1)
                {
                    scene() -> addItem(this->enemyArr[0]);
                        this->enemyCount++;

                }

                if(bulletCount == 3)
                {
                    bullet *b5 = new bullet(boardData,2,2);
                    scene()->addItem(b5);
                    bulletCount++;
                }

                else if(bulletCount == 2)
                {
                    bullet *b6 = new bullet(boardData,1,11);
                    scene()->addItem(b6);

                    bullet *b7 = new bullet(boardData,14,1);
                    scene()->addItem(b7);
                    bulletCount+=2;
                }

                if(bulletCount == 1)
                {
                    bullet *b8 = new bullet(boardData,3,2);
                    scene()->addItem(b8);

                    bullet *b9 = new bullet(boardData,11,12);
                    scene()->addItem(b9);

                    bullet *b10 = new bullet(boardData,10,11);
                    scene()->addItem(b10);
                    bulletCount+=3;
                }

                if(pelletCount == 1)
                {
                    pellet *b3 = new pellet(boardData,4,5);
                    scene()->addItem(b3);
                    pelletCount++;
                }

                else if(pelletCount == 0)
                {
                    pellet *b4 = new pellet(boardData,8,9);
                    scene()->addItem(b4);

                    pellet *b5 = new pellet(boardData,2,6);
                    scene()->addItem(b5);
                    pelletCount+=2;
                }

                health *h2 = new health(boardData,14,13);
                scene()->addItem(h2);

            }
            else if (playerHealth == 0)
            {
                qDebug() << "GAME OVER";

                gameover *g1 = new gameover(boardData,0,0);
                scene()->addItem(g1);
            }

        }
        else if (typeid(*items[i]) == typeid(gate))
        {
            win *w1 = new win(boardData,0,0);
            scene()->addItem(w1);
            qDebug() << "YOU WON!";
        }
    }

}
