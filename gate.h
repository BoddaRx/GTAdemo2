#ifndef GATE_H
#define GATE_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>

class gate : public QGraphicsPixmapItem
{
private:
    int row, column;
    int data[17][15];
public:

    gate(int boardData[17][15],int r,int c)
{
    // Set Image
    QPixmap gateImage("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/Fgate.png");
    gateImage = gateImage.scaledToWidth(50);
    gateImage = gateImage.scaledToHeight(50);
    setPixmap(gateImage);

    row = r;
    column = c;
    setPos(50 + column * 50, 50 + row * 50);

    // Set data Array
    for (int i = 0; i < 17; i++)
        for (int j = 0; j < 15; j++)
            data[i][j] = boardData[i][j];
}
};

#endif // GATE_H
