#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>

class health : public QGraphicsPixmapItem
{
private:
    int row, column;
    int data[15][15];
public:

    health(int boardData[15][15],int r,int c)
{
    // Set Image
    QPixmap healthy("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/heartBLCK.png");
    healthy = healthy.scaledToWidth(50);
    healthy = healthy.scaledToHeight(50);
    setPixmap(healthy);

    row = r;
    column = c;
    setPos(50 + column * 50, 50 + row * 50);

    // Set data Array
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            data[i][j] = boardData[i][j];
}
};

#endif // HEALTH_H
