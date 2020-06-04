#include <iostream>
#include <time.h>
#include <Windows.h>
#include"wall.h"
#include"apple.h"
#include"snake.h"
using namespace std;

Snake::Snake(Wall &tempWall,Apple &apple,int sz):m_wall(tempWall),m_apple(apple)//构造空蛇、传入外部的墙和果子
{
    length=0;
    maxSize=sz;
    Head=NULL;
}

Snake::~Snake()//将蛇析构
{
    delete [] Head;
}

void Snake::InitSnake(char head_direction, int x, int y)//无论是游戏第一次开始还是重新开始，将蛇初始化（复位）
{
    if (Head == NULL)
    {
        Head = new Point[maxSize];
        if (Head == NULL)
        {
            cerr << "内存分配错误" << endl; exit(1);
        }
    }//如果第一次开始则蛇头指针为空，分配空间；分配空间失败则报错
    else
        for (int i = 0; i < maxSize; i++)
            Head[i].x = Head[i].y = 0;//如果是重新开始游戏，则把蛇身全部复位为0
    if (head_direction == 'v')//根据其他模块编程者需要，可以将初始蛇头指向不同方向
    {
        Head[0].x = Head[1].x = Head[2].x = x;
        Head[0].y = y++;
        Head[1].y = y++;
        Head[2].y = y;
    }
    else
    {
        Head[0].y = Head[1].y = Head[2].y = y;
        Head[0].x = x++;
        Head[1].x = x++;
        Head[2].x = x;
    }
    length = 3;//初始设定蛇有三段，蛇头坐标（5，5），蛇身（5，6）和（5，7）  
    tailx = x;
    taily = y;
}

void Snake::AddMaxsize()//增加蛇身最大长度
{
    Point *m_newhead=NULL;
    maxSize+=50;//一次增加50节
    m_newhead = new Point[maxSize];
    if (m_newhead == NULL)
    {
        cerr << "内存分配错误" << endl; exit(1);
    }
    for (int i=0; i<length; i++)
        m_newhead[i]=Head[i];
    delete [] Head;
    Head = m_newhead;
}

void Snake::Move(char& pre_direction, char& cur_direction)//蛇的爬行函数，可使蛇按适当方向爬行；参数为上一次运动方向的引用，以及操作者最新输入的方向的引用
{
    int x = Head[0].x, y = Head[0].y;//获得蛇头坐标
    char direction;//用于存储蛇本次运动方向
    if (((cur_direction != UP && cur_direction != Up) && (cur_direction != DOWN && cur_direction != Down) && (cur_direction != RIGHT && cur_direction != Right) && (cur_direction != LEFT && cur_direction != Left)) ||
        ((pre_direction == LEFT || pre_direction == Left) && (cur_direction == RIGHT || cur_direction == Right)) ||
        ((pre_direction == RIGHT || pre_direction == Right) && (cur_direction == LEFT || cur_direction == Left)) ||
        ((pre_direction == UP || pre_direction == Up) && (cur_direction == DOWN || cur_direction == Down)) ||
        ((pre_direction == DOWN || pre_direction == Down) && (cur_direction == UP || cur_direction == Up)))
        direction = pre_direction;  //如果输入的当前方向为“非方向字符”，或者与上一个运动方向正好相反，则采用上一次的运动方向
    else//否则，采用最新输入的方向，并将该方向同时存储到pre_direction
    {
        direction = cur_direction;
        pre_direction = cur_direction;
    }
    switch (direction) {//根据运动方向，获得最新蛇头结点坐标
    case Up:
    case UP:    y--;
        break;
    case Down:
    case DOWN:  y++;
        break;
    case Right:
    case RIGHT: x++;
        break;
    case Left:
    case LEFT:  x--;
        break;
    default:
        break;
    }
    for (int i = getLength() - 1; i > 0; i--)//使蛇身向前蠕动一格
        Head[i] = Head[i - 1];
    Head[0].x = x;//将蛇头结点坐标改为最新
    Head[0].y = y;
}
bool Snake::Eat()
{
    int x = Head[0].x, y = Head[0].y;
    if (length==maxSize)//如果已达到最长，则调用增加蛇长函数
        AddMaxsize();
    if (x == m_apple.ix && y == m_apple.iy)
    {
        //if(x==m_apple.ix&&y==m_apple.iy){
        length++;
        if (length == 4 && Head[2].x == 5 && Head[2].y == 6)
        {
            Head[3].x = 5; Head[3].y = 7;
        }
        else
        {
            Head[length - 1].x = tailx;
            Head[length - 1].y = taily;
        }
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
        if (x == Head[k].x && y == Head[k].y)
        {
            cout << "Game Over" << endl;
            return true;
        }
    }
    if (x == 0 || x == boux || y == 0 || y == bouy)
    {
        cout << "Game Over" << endl;
        return true;
    }
    return false;
}

bool Snake::Death(Snake& s)
{
    int boux = m_wall.GetRow();
    int bouy = m_wall.GetCol();
    int s1_x = Head[0].x, s1_y = Head[0].y;
    Point* s2 = s.GetHead();
    int s1_length = getLength(), s2_length = s.getLength();
    int k;
    for (k = 4; k <= s1_length - 1; k++) {
        if (s1_x == Head[k].x && s1_y == Head[k].y)  return true;
    }
        if (s1_x == 0 || s1_x == boux || s1_y == 0 || s1_y == bouy)  return true;
        for (k = 0; k <= s2_length - 1; k++) {
            if (s1_x == s2[k].x && s1_y == s2[k].y) return true; 
        }
    return false;
}

int Win(Snake & s1, Snake & s2)//双蛇模式下，判断两条蛇的输赢；传入两条蛇的引用；
{
    bool s1_death = s1.Death(s2), s2_death = s2.Death(s1);//获得两条蛇的死亡情况
    int s1_length=s1.getLength(),s2_length=s2.getLength();//获得两条蛇的蛇身总长
    if (!s1_death && !s2_death)//如果两条蛇没有死，返回0
        return 0;
    else
    {
        if (s1_death && s2_death)//如果两条蛇同时死亡，则比较蛇身总长，长者获胜，等长则平手
        {
            if (s1_length > s2_length) return 1;//玩家1获胜
            else if (s1_length < s2_length) return 2;//玩家2获胜
            else return 3;//平局
        }
        else//如果只有一条蛇死，则仍存活着胜
        {
            if (s2_death) return 1;//玩家1获胜
            else return 2;//玩家2获胜
        }
    }
}
