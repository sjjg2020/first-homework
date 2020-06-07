#ifndef snake_h
#define snake_h
#include <iostream>
#include"apple.h"
#include"wall.h"
using namespace std;
const int defaultSize=100;//初始化蛇身长度
struct Point
{
    int x;
    int y;
};
enum//两组方向键
{
    UP = 'w',
    DOWN = 's',
    RIGHT = 'd',
    LEFT = 'a',
    
    Up = 'i',
    Down ='k',
    Right = 'l',
    Left ='j'
};
class Snake
{
public:
    Snake(Wall &tempWall, Apple &apple,int sz);//构造函数，构造空蛇、传入外部墙和果子的引用
     ~Snake();//析构函数
    void InitSnake(char , int , int );//蛇的初始化函数
    void AddMaxsize();//增长蛇最大长度的函数，以防玩家实力过强
    bool Death();//单蛇模式，蛇的死亡函数
    bool Death(Snake& );//双蛇模式，蛇的死亡函数
    bool Eat();//蛇的吃果子函数
    void Move(char &pre_direction,char &cur_direction);//蛇的爬行函数
    friend int Win(Snake& , Snake&);//双蛇模式，判断玩家胜负的函数
    int getLength() {return length;}//获取蛇身长度
    Point *GetHead() {return Head;}//获取蛇头结点指针
    Wall & m_wall;//墙的引用
    Apple  & m_apple;//果子的引用
protected:
    Point *Head;//蛇头结点指针
    int length;//蛇身长度
    int maxSize;//蛇的最大长度
    int tailx;//蛇尾横坐标
    int taily;//蛇尾纵坐标
};
#endif /* snake_h */
