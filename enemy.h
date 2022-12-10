#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include "graph.h"

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row, column;
    int data[15][15];
    Graph* gr;
    int player_vertex;


    void initialize_graph(Graph* gr,int boardData[][15])
    {
        for(int i=0;i<15;i++)
            for(int j=0;j<15;j++)
            {

                if(boardData[i][j]!=0)
                {
                int source = i*15+j;

                //add right neighbour
                if(j<14)
                    if(boardData[i][j+1]!=0)
                        gr->add_edge(source,source+1,1);

                //add left neighbour
                if(j>0)
                    if(boardData[i][j-1]!=0)
                        gr->add_edge(source,source-1,1);

                //add lower neighbour
                if(i<14)
                    if(boardData[i+1][j]!=0)
                        gr->add_edge(source,source+15,1);


                //add upper neighbour
                if(i>0)
                    if(boardData[i-1][j]!=0)
                        gr->add_edge(source,source-15,1);
                }
            }
    }
public:
    ~Enemy(){
        delete[] gr;
    }
    Enemy(int boardData[][15],int r,int c)
{
    // Set Image
    gr = new Graph(15*15);
    initialize_graph(gr,boardData);
    QPixmap image("/Users/AbdelrahmanNashed/Dropbox/Mac/Desktop/GTATrial/enemyz.gif");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);

    // Set Position
    row = r;
    column = c;
    setPos(50 + column * 50, 50 + row * 50);

    // Set data Array
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            data[i][j] = boardData[i][j];
}

   public slots:
    void moveEnemy();
    void PlayerMoved(int vertex){
        player_vertex = vertex;
        qDebug() <<player_vertex;
    };



};

#endif // ENEMY_H


