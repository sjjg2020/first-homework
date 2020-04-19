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
}//画
int main(){
	initgraph(1240, 640);//画布
	setbkcolor(BLACK);//背景色
	settextcolor(RGB(255, 255, 255));//字体颜色
	settextstyle(40, 0, _T("微软雅黑"));
	outtextxy(520, 570, _T("贪吃蛇"));
	outtextxy(580, 570, _T("输入难度1，2，3"));
	int level;
	cin >> level;
	Wall thewall(level);//wall难度等级输入（暂定
	Apple apple(thewall);
	Snake s(thewall,apple,defaultSize);//蛇定义
	Point* p;//蛇头节点
	char pre_direction, cur_direction;
	s.InitSnake(v,5,5);//初始化
	pre_direction = 's';//方向初始化
	//Sleep(1000);
	p = s.GetHead();//得到蛇头
	int a, b;
	a = thewall.GetRow();
	b = thewall.GetCol();//得到长宽
	apple.suijifangzhi();
	while (!s.Death())
	{
		int len = s.getLength();
		setfillcolor(RED);
		fillrectangle(0, 0, b*10+10, a*10+10);
		setfillcolor(BLACK);
		fillrectangle(10, 10, b * 10, a*10);//边框
		draw(apple.ix, apple.iy);
		for (int i = 0; i < len; i++)
			draw(p[i].x, p[i].y);//画蛇
        Sleep(s.SleepTime(level));
       cleardevice();//清屏
			cur_direction =char(_getch());
		s.Move(pre_direction, cur_direction);
		if (s.Eat())
			apple.suijifangzhi();
	}
} 
