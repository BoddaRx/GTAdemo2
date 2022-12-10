#ifndef CAR_H
#define CAR_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>

class car : public QGraphicsPixmapItem
{
private:
    int row, column;
    int data[15][15];
public:

    car(int boardData[15][15],int r,int c)
{
    // Set Image
    QPixmap carImage("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/carz.png");
    carImage = carImage.scaledToWidth(50);
    carImage = carImage.scaledToHeight(50);
    setPixmap(carImage);

    row = r;
    column = c;
    setPos(50 + column * 50, 50 + row * 50);

    // Set data Array
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            data[i][j] = boardData[i][j];
}
};

#endif // CAR_H
