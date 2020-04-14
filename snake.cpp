#include <iostream>
#include <time.h>
#include <Windows.h>
#include"wall.h"
#include"apple.h"
#include"snake.h"
using namespace std;
void gotoxy1(HANDLE hOut1, int x, int y)
{
    COORD pos;
    pos.X = x; //横坐标
    pos.Y = y; //纵坐标
    SetConsoleCursorPosition(hOut1, pos);
}

HANDLE hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量

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
    length=3;//初始设定蛇有三段，蛇头坐标（5，5），蛇身（5，6）和（5，7）  
	tailx=5;
	taily=7;                  
    return true; //成功返回true，从而进行下一次操作，还没想好什么情况下返回false                 
}

bool Snake::Move(char pre_direction,char cur_direction)//控制蛇最基本的移动
{
    int x=Head[0].x,y=Head[0].y;
    char direction;
    if ((pre_direction==Left&&cur_direction==Right)||
        (pre_direction==Right&&cur_direction==Left)||
        (pre_direction==Up&&cur_direction==Down)||
        (pre_direction==Down&&cur_direction==Up))
         direction=pre_direction;
    else direction=cur_direction;
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
    }                  //以上内容，获取并更新了蛇头坐标          
    for (int i=getLength()-1;i>0;i--)
        Head[i]=Head[i-1];
    Head[0].x=x;
    Head[0].y=y;//实现蛇的蠕动
    return true;
}

bool Snake::Eat()
{
	int x=Head[0].x,y=Head[0].y;
    if(x==m_apple.ix&&y==m_apple.iy){
	     length++;
	     if(length==4&&Head[2].x==5&&Head[2].y==6){Head[3].x=5;Head[3].y=7;}
		 else{Head[length-1].x=tailx;Head[length-1].y=taily;}
	}
	tailx=Head[length-1].x;
	taily=Head[length-1].y;
	return true; 
 }

bool Snake::Death()
{
	int x=Head[0].x,y=Head[0].y;
	int i=getLength();
	int k;
	for(k=4;k<=i-1;k++){
		if(x==Head[k].x&&y==Head[k].y){cout<<"Game Over"<<endl;return false;}
	}
	if(x==1||x==10||y==1||y==10){cout<<"Game Over"<<endl;return false;}
	return true;
}
