#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>

class bullet : public QGraphicsPixmapItem
{
private:
    int data[17][15];
public:
int row, column;
    bullet(int boardData[17][15],int r,int c)
{
    // Set Image
    QPixmap image("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/bulletT.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);

    row = r;
    column = c;
    setPos(50 + column * 50, 50 + row * 50);

    // Set data Array
    for (int i = 0; i < 17; i++)
        for (int j = 0; j < 15; j++)
            data[i][j] = boardData[i][j];
}
};

#endif // BULLET_H
