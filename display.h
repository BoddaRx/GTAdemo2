#ifndef DISPLAY_H
#define DISPLAY_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>

class display : public QGraphicsPixmapItem
{
private:
    int row, column;
    int data[15][15];
public:

    display(int boardData[15][15],int r,int c)
{
    // Set Image
    QPixmap powerfulDisplay("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/powerDis.png");
    powerfulDisplay = powerfulDisplay.scaledToWidth(50);
    powerfulDisplay = powerfulDisplay.scaledToHeight(50);
    setPixmap(powerfulDisplay);

    row = r;
    column = c;
    setPos(50 + column * 50, 50 + row * 50);

    // Set data Array
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            data[i][j] = boardData[i][j];
}
};

#endif // DISPLAY_H
