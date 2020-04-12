#include <iostream>
#inlcude <time.h>
#include"wall.h"
#include"food.h"
#include"snake.h"
using namespace std;
Snake::Snake(Wall &tempWall,Apple &apple,int sz):m_wall(tempWall),m_apple(apple)
{
    length=0;maxSize=sz;Head=NULL;
}
Snake::~Snake()
{delete [] Head;}
bool Snake::InitSnake()//无论是游戏第一次开始还是重新开始，将蛇初始化（复位）
{
    if (Head==NULL){
        Head=new Point[maxSize];
        if (Head==NULL)
        {cerr<<""<<endl;exit(1);}}//如果第一次开始则蛇头指针为空，分配空间；分配空间失败则报错
    else
        for (int i=0;i<maxSize;i++)
            Head[i].x=Head[i].y=0;//如果是重新开始游戏，则把蛇身全部复位为0
    Head[0].x=Head[1].x=Head[2].x=5;
    Head[0].y=5;Head[1].y=6;Head[2].y=7;
    length=3;                    //初始设定蛇有三段，蛇头坐标（5，5），蛇身（5，6）和（5，7）
    return true;                 //成功返回true，从而进行下一次操作，还没想好什么情况下返回false
}
bool Snake::Move(char direction)//控制蛇最基本的移动
{
    int x=Head[0].x,y=Head[0].y;
    switch (direction) {
        case Up:    y++;
            break;
        case Down:  y--;
            break;
        case Right: x++;
            break;
        case Left:  x--;
            break;
        default:
            break;
    }                           //以上内容，获取并更新了蛇头坐标
    for (int i=getLength()-1;i>0;i--)
        Head[i]=Head[i-1];
    Head[0].x=x;
    Head[0].y=y;//实现蛇的蠕动
    return true;
}
