#include <iostream>
#include <time.h>
#include <Windows.h>
#include"wall.h"
#include"apple.h"
#include"snake.h"
using namespace std;

Snake::Snake(Wall &tempWall,Apple &apple,int sz):m_wall(tempWall),m_apple(apple)
{
    
    length=0;maxSize=sz;Head=NULL;
}

Snake::~Snake()
{delete [] Head;}

void Snake::InitSnake(char head_direction,int x,int y)//无论是游戏第一次开始还是重新开始，将蛇初始化（复位）
{
    if (Head==NULL){
        Head=new Point[maxSize];
        if (Head==NULL)
        {cerr<<""<<endl;exit(1);}}//如果第一次开始则蛇头指针为空，分配空间；分配空间失败则报错
    else
        for (int i=0;i<maxSize;i++)
            Head[i].x=Head[i].y=0;//如果是重新开始游戏，则把蛇身全部复位为0
    if (head_direction=='v')
    {
        Head[0].x=Head[1].x=Head[2].x=x;
        Head[0].y=y++;Head[1].y=y++;Head[2].y=y;
    }
    else
    {
        Head[0].y=Head[1].y=Head[2].y=y;
        Head[0].x=x++;Head[1].x=x++;Head[2].x=x;
    }
    length=3;//初始设定蛇有三段，蛇头坐标（5，5），蛇身（5，6）和（5，7）  
	tailx=x;
	taily=y;
    //return true;成功返回true，从而进行下一次操作，还没想好什么情况下返回false
}

bool Snake::Move(char& pre_direction, char& cur_direction)
{
    int x = Head[0].x, y = Head[0].y;
    char direction;
    if ((cur_direction != Up && cur_direction != Down && cur_direction != Right && cur_direction != Left) ||
        (pre_direction == Left && cur_direction == Right) ||
        (pre_direction == Right && cur_direction == Left) ||
        (pre_direction == Up && cur_direction == Down) ||
        (pre_direction == Down && cur_direction == Up))
        direction = pre_direction;
    else
    {
        direction = cur_direction;
        pre_direction = cur_direction;
    }
    switch (direction) {
    case Up:    y--;
        break;
    case Down:  y++;
        break;
    case Right: x++;
        break;
    case Left:  x--;
        break;
    default:
        break;
    }
    for (int i = getLength() - 1; i > 0; i--)
        Head[i] = Head[i - 1];
    Head[0].x = x;
    Head[0].y = y;
    return true;
}
bool Snake::Eat()
{
    int x = Head[0].x, y = Head[0].y;
    if (x == m_apple.ix && y == m_apple.iy)
    {
        //if(x==m_apple.ix&&y==m_apple.iy){
        length++;
        if (length == 4 && Head[2].x == 5 && Head[2].y == 6)
        {
            Head[3].x = 5; Head[3].y = 7;
        }
        else { Head[length - 1].x = tailx; Head[length - 1].y = taily; }
        tailx = Head[length - 1].x;
        taily = Head[length - 1].y;
        return true;
    }
    else
    {
        tailx = Head[length - 1].x;
        taily = Head[length - 1].y;
        return false;
    }
}

bool Snake::Death()
{
    int boux = m_wall.GetRow();
    int bouy = m_wall.GetCol();
    int x = Head[0].x, y = Head[0].y;
    int i = getLength();
    int k;
    for (k = 4; k <= i - 1; k++) {
        if (x == Head[k].x && y == Head[k].y) { cout << "Game Over" << endl; return true; }
    }
    if (x == 0 || x == boux || y == 0 || y == bouy) { cout << "Game Over" << endl; return true; }
    return false;
}

int Snake::SleepTime(int level)
{
    int sleeptime;
    if (level==1)
    {
        if (length<15)      sleeptime=400;
        else if (length<40) sleeptime=300;
        else                sleeptime=150;
    }
    else if (level==2)
    {
        if (length<15)      sleeptime=300;
        else if (length<30) sleeptime=250;
        else                sleeptime=150;
    }
    else
    {
        if (length<10)      sleeptime=250;
        else if (length<30) sleeptime=200;
        else                sleeptime=100;
    }
    return sleeptime;
}
