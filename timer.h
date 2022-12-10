#ifndef TIMER_H
#define TIMER_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QAbstractAnimation>

class timerx : public QGraphicsPixmapItem
{
private:
    int row, column;
    int data[15][15];
public:

    timerx(int boardData[15][15],int r,int c)
{
    // Set Image
    QPixmap secondsImage("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/5timez.png");
    secondsImage = secondsImage.scaledToWidth(50);
    secondsImage = secondsImage.scaledToHeight(50);
    setPixmap(secondsImage);

    row = r;
    column = c;
    setPos(50 + column * 50, 50 + row * 50);

    // Set data Array
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            data[i][j] = boardData[i][j];
}
};
#endif // TIMER_H
