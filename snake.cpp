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
bool Snake::InitSnake()//��������Ϸ��һ�ο�ʼ�������¿�ʼ�����߳�ʼ������λ��
{
    if (Head==NULL){
        Head=new Point[maxSize];
        if (Head==NULL)
        {cerr<<""<<endl;exit(1);}}//�����һ�ο�ʼ����ͷָ��Ϊ�գ�����ռ䣻����ռ�ʧ���򱨴�
    else
        for (int i=0;i<maxSize;i++)
            Head[i].x=Head[i].y=0;//��������¿�ʼ��Ϸ���������ȫ����λΪ0
    Head[0].x=Head[1].x=Head[2].x=5;
    Head[0].y=5;Head[1].y=6;Head[2].y=7;
    length=3;//��ʼ�趨�������Σ���ͷ���꣨5��5��������5��6���ͣ�5��7��                    
    return true; //�ɹ�����true���Ӷ�������һ�β�������û���ʲô����·���false                 
}
bool Snake::Move(char pre_direction,char cur_direction)//��������������ƶ�
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
    }                  //�������ݣ���ȡ����������ͷ����          
    for (int i=getLength()-1;i>0;i--)
        Head[i]=Head[i-1];
    Head[0].x=x;
    Head[0].y=y;//ʵ���ߵ��䶯
    return true;
}
bool Snake::Eat()
{
	int x=Head[0].x,y=Head[0].y;
	int i=getLength();
	if(x==7&&y==8){
	     length++;
		 if(Head[i-1].x==Head[i-2].x&&Head[i-1].y<Head[i-2].y){Head[length-1].x=Head[i-1].x;Head[length-1].y=Head[i-1].y-1;}
		 else if(Head[i-1].x==Head[i-2].x&&Head[i-1].y>Head[i-2].y){Head[length-1].x=Head[i-1].x;Head[length-1].y=Head[i-1].y+1;}
		 else if(Head[i-1].x<Head[i-2].x&&Head[i-1].y==Head[i-2].y){Head[length-1].x=Head[i-1].x-1;Head[length-1].y=Head[i-1].y;}
		 else if(Head[i-1].x>Head[i-2].x&&Head[i-1].y==Head[i-2].y){Head[length-1].x=Head[i-1].x+1;Head[length-1].y=Head[i-1].y;}
	}
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
	if(x==1||x==7||y==1||y==7){cout<<"Game Over"<<endl;return false;}
	return true;
}
 
