#include "enemy.h"
//#include "player.h"


void Enemy::moveEnemy()
{
    //spomewhere you need to make a graph of the board dat.
    // get the eenemny vertex and the player vertex
    int enemy_vertex = row*15+column;

    // use the function: get_next _ in shorted path to find the value of the move
    int m = gr->get_next_in_ShortestPath(enemy_vertex,player_vertex);
    //-1 means left
    //1 means right
    // >1 means down
    // <-1 means up


    // as writtten there
    //int m = rand()%4;
//    QList<QGraphicsItem*> items = collidingItems();
//    for (int i = 0; i < items.size(); i++)
//    {
//        if (typeid(*items[i]) == typeid(Player)){
//             column =4;
//             row = 3;
//        }
//    }
    //m==0 move up
    if (m<-1 && data[row - 1][column] > 0)
    {
        row--;
    }
    //m==1 move down
    else if (m>1 && data[row + 1][column] > 0)
    {
        row++;
    }
    //m==2 move right
    else if (m==1 && data[row][column + 1] > 0)
    {
        column++;
    }
    //m==3 move left
    else if (m==-1 && data[row][column - 1] > 0)
    {
        column--;
    }
    setPos(50 + column * 50, 50 + row * 50);


}
