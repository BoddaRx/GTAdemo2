#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include "enemy.h"

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row, column;
    int data[15][15];
    Enemy **enemyArr;

public:
    Player(int boardData[15][15], Enemy *arr[2])
{
    // Set Image
    QPixmap FrankTop("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/frankTop.png");
    FrankTop = FrankTop.scaledToWidth(50);
    FrankTop = FrankTop.scaledToHeight(50);
    setPixmap(FrankTop);

    this->enemyArr=arr;

    // Set Position
    row = 7;
    column = 7;
    setPos(50 + column * 50, 50 + row * 50);

    // Set data Array
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            data[i][j] = boardData[i][j];
}

    int bulletCount = 4;
    int playerHealth = 3;

    int pelletCount = 2;

    int enemyCount = 2;
    int enemyHealth = 2;

    bool isInvincible = false;

public slots:
    void keyPressEvent(QKeyEvent* event);

signals:
    void vertexChanged(int newValue);
};

#endif // PLAYER_H
