#ifndef snake_h
#define snake_h
#include <iostream>
#include"apple.h"
#include"wall.h"
using namespace std;
const int defaultSize=100;
struct Point
{
    int x;
    int y;
};
enum//设定按键与蛇移动方向的对应关系
{
    Up='w',
    Down='s',
    Right='d',
    Left='a'
};
class Snake
{
public:
   // Snake(int sz=defaultSize) {Head=NULL;maxSize=defaultSize;}//用于调试
    Snake(Wall &tempWall, Apple &apple,int sz);//正式版
     ~Snake();
    bool InitSnake();
    bool Death();//等有了wall，参数表里加入wall的引用
    bool Eat();
    bool Move(char &pre_direction,char &cur_direction);
    //bool Crawl(char pre_direction,char cur_direction);//实现不同难度之下，move，death，eat函数的调配
    int getLength() {return length;}
    Point *GetHead() {return Head;}
   Wall & m_wall;
   Apple  & m_apple;
protected:
    Point *Head;//指向蛇头
    int length;//蛇的长度
    int maxSize;//蛇的最大长度
    int tailx;
    int taily;
};
//用数组实现
#endif /* snake_h */
