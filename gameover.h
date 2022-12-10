#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>

class gameover : public QGraphicsPixmapItem
{
private:
    int row, column;
    int data[15][15];
public:

    gameover(int boardData[15][15],int r,int c)
{
    // Set Image
    QPixmap GameOverImage("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/gameoverPic.png");
    GameOverImage = GameOverImage.scaledToWidth(800);
    GameOverImage = GameOverImage.scaledToHeight(800);
    setPixmap(GameOverImage);

    row = r;
    column = c;
    setPos(50 + column * 50, 50 + row * 50);

    // Set data Array
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            data[i][j] = boardData[i][j];
}
};

#endif // GAMEOVER_H
