#include <iostream>
#include <time.h>
#include <windows.h>
#include"snake.h"
#include"wall.h"
#include"easyx.h"
#include"conio.h"

using namespace std;
void draw(int x, int y) {
	setfillcolor(WHITE);
	fillrectangle(x * 10, y * 10, (x + 1) * 10, (y + 1) * 10);
}//��
int main(){
	initgraph(1240, 640);//����
	setbkcolor(BLACK);//����ɫ
	settextcolor(RGB(255, 255, 255));//������ɫ
	settextstyle(40, 0, _T("΢���ź�"));
	outtextxy(520, 570, _T("̰����"));
	outtextxy(580, 570, _T("�����Ѷ�1��2��3"));
	int level;
	cin >> level;
	Wall thewall(level);//wall�Ѷȵȼ����루�ݶ�
	Apple apple(thewall);
	Snake s(thewall,apple,defaultSize);//�߶���
	Point* p;//��ͷ�ڵ�
	char pre_direction, cur_direction;
	s.InitSnake(v,5,5);//��ʼ��
	pre_direction = 's';//�����ʼ��
	//Sleep(1000);
	p = s.GetHead();//�õ���ͷ
	int a, b;
	a = thewall.GetRow();
	b = thewall.GetCol();//�õ�����
	apple.suijifangzhi();
	while (!s.Death())
	{
		int len = s.getLength();
		setfillcolor(RED);
		fillrectangle(0, 0, b*10+10, a*10+10);
		setfillcolor(BLACK);
		fillrectangle(10, 10, b * 10, a*10);//�߿�
		draw(apple.ix, apple.iy);
		for (int i = 0; i < len; i++)
			draw(p[i].x, p[i].y);//����
        Sleep(s.SleepTime(level));
       cleardevice();//����
			cur_direction =char(_getch());
		s.Move(pre_direction, cur_direction);
		if (s.Eat())
			apple.suijifangzhi();
	}
} 
