#ifndef snake_h
#define snake_h
#include <iostream>
#include"apple.h"
#include"wall.h"
using namespace std;
const int defaultSize=100;//��ʼ��������
struct Point
{
    int x;
    int y;
};
enum//���鷽���
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
    Snake(Wall &tempWall, Apple &apple,int sz);//���캯����������ߡ������ⲿǽ�͹��ӵ�����
     ~Snake();//��������
    void InitSnake(char , int , int );//�ߵĳ�ʼ������
    void AddMaxsize();//��������󳤶ȵĺ������Է����ʵ����ǿ
    bool Death();//����ģʽ���ߵ���������
    bool Death(Snake& );//˫��ģʽ���ߵ���������
    bool Eat();//�ߵĳԹ��Ӻ���
    void Move(char &pre_direction,char &cur_direction);//�ߵ����к���
    friend int Win(Snake& , Snake&);//˫��ģʽ���ж����ʤ���ĺ���
    int getLength() {return length;}//��ȡ������
    Point *GetHead() {return Head;}//��ȡ��ͷ���ָ��
    Wall & m_wall;//ǽ������
    Apple  & m_apple;//���ӵ�����
protected:
    Point *Head;//��ͷ���ָ��
    int length;//������
    int maxSize;//�ߵ���󳤶�
    int tailx;//��β������
    int taily;//��β������
};
#endif /* snake_h */
