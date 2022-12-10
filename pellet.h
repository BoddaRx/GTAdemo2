#ifndef PELLET_H
#define PELLET_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>

class pellet : public QGraphicsPixmapItem
{
private:
    int row, column;
    int data[15][15];
public:

    pellet(int boardData[15][15],int r,int c)
{
    // Set Image
    QPixmap image("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/powerPellet.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);

    row = r;
    column = c;
    setPos(50 + column * 50, 50 + row * 50);

    // Set data Array
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            data[i][j] = boardData[i][j];
}
};

#endif // PELLET_H
