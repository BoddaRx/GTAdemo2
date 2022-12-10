#ifndef WIN_H
#define WIN_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>

class win : public QGraphicsPixmapItem
{
private:
    int row, column;
    int data[15][15];
public:

    win(int boardData[15][15],int r,int c)
{
    // Set Image
    QPixmap wingame("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/SpongeWin.png");
    wingame = wingame.scaledToWidth(800);
    wingame = wingame.scaledToHeight(800);
    setPixmap(wingame);

    row = r;
    column = c;
    setPos(50 + column * 50, 50 + row * 50);

    // Set data Array
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            data[i][j] = boardData[i][j];
}
};

#endif // WIN_H
