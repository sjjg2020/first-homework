#include <iostream>
using namespace std;
struct Point
{
    int x;
    int y;
    
    Point *link;//指向下一个节点（也就是靠近蛇尾的一段）
    
    Point(Point *ptr=NULL):link(ptr){};
    Point(int x,int y,Point *ptr=NULL):x(x),y(y),link(ptr){};
};
enum
{
    Up='w',
    Down='s',
    Right='d',
    Left='a'
};
class Snake
{
public:
    Snake() {first=new Point;length=0;}
    Snake(const int &x,const int &y) {first=new Point(x,y);}//这个需要修改，直接用一个初始化函数代替；
    Snake(Snake &s);
    ~Snake();
    
    bool Insert(int i,int &x,int &y);
    bool Remove(int i,int &x,int &y);
    bool Death();//等有了wall，参数表里加入wall的引用
    bool Eat();
    bool Move();//现在和eat还有点冲突，丞待解决
protected:
    Point *first;
    int length;
};
