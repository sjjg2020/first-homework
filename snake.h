#include <iostream>
#include"wall.h"
#include"food.h"
using namespace std;
const int defaultSize=100;
struct Point
{
    int x;
    int y;
};
enum//�趨���������ƶ�����Ķ�Ӧ��ϵ
{
    Up='w',
    Down='s',
    Right='d',
    Left='a'
};
class Snake
{
public:
    Snake(int sz=defaultSize);
    ~Snake();
    bool InitSnake();
    bool Death();//������wall�������������wall������
    bool Eat();
    bool Move(char pre_direction,char cur_direction);
    bool Crawl(char pre_direction,char cur_direction);//ʵ�ֲ�ͬ�Ѷ�֮�£�move��death��eat�����ĵ���
    int getLength() {return length;}
    wall &m_wall;
    apple &m_apple;
protected:
    Point *Head;//ָ����ͷ
    int length;//�ߵĳ���
    int maxSize;//�ߵ���󳤶�
    int tailx;
	int taily;
};
//������ʵ��
