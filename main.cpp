#include <iostream>
#include <time.h>
#include <windows.h>
#include"snake.h"
#include"wall.h"
#include"easyx.h"
#include"conio.h"
#include <string>


using namespace std;
void draw(int x, int y,int z) {
	if (z == 1) {
		setfillcolor(GREEN);// setfillcolor指定填充颜色GREEN绿色 
		fillrectangle(x * 10, y * 10, (x + 1) * 10, (y + 1) * 10);//fillrectangle用填充颜色绘制矩形，4个数值为矩形的四条边 ，故每个矩形为10*10 
	}
	else {
		setfillcolor(BLUE);// setfillcolor指定填充颜色BLUE蓝色 
		fillrectangle(x * 10, y * 10, (x + 1) * 10, (y + 1) * 10);
	}
}//画双蛇 
void draw(int x, int y) {
	setfillcolor(RED);// setfillcolor指定填充颜色RED红色 
	fillrectangle(x * 10, y * 10, (x + 1) * 10, (y + 1) * 10);
}//画单蛇 与果子 
struct Node//队列节点 
{
	char ch;
	Node* link;
	Node(char& ch, Node* ptr = NULL) :ch(ch), link(ptr) {};
};
class Queue//队列用于储存缓冲区已输入的指令 
{
private:
	Node* front;
	Node* rear;
public:
	Queue() { front = rear = NULL; }
	void EnQueue(char& ch) { if (front == NULL) front = rear = new Node(ch); else { rear->link = new Node(ch); rear = rear->link; } }//重载创建队列  
	void DeQueue(char&,int, char );//重载创建队列 
};
void Queue::DeQueue(char& x,int y,char z)//入列函数 
{
	Node* p = front;
	if (y == 1)
	{
		while (p->ch != 'w' && p->ch != 'a' && p->ch != 's' && p->ch != 'd' && p->link!=NULL) {
			p = p->link;
		} //搜索控制指令，排除无效指令 
		if (p->ch != 'w' && p->ch != 'a' && p->ch != 's' && p->ch != 'd' && p == rear) {
			x = z;
		}//无有效指令，沿用上个方向 
		else {
			x = p->ch;
			p->ch = 'c';
		}//用完作废 
	}
	else {
		while (p->ch != 'i' && p->ch != 'j' && p->ch != 'k' && p->ch != 'l' && p->link != NULL) {
			p = p->link;
		}//搜索控制指令，排除无效指令 
		if (p->ch != 'i' && p->ch != 'j' && p->ch != 'k' && p->ch != 'l' && p == rear) {
			x = z;
		}//无有效指令，沿用上个方向 
		else {
			x = p->ch;
			p->ch = 'c';
		}//用完作废 
	}
}

int main(){
	Queue Q;//储存输入 
	initgraph(1240, 640);//设置画布大小 
	setbkcolor(BLACK);//填充背景色
	settextcolor(RGB(255, 255, 255));//选择字体颜色
	settextstyle(40, 0, _T("微软雅黑")); //选择字体 
	outtextxy(570, 270, _T("贪吃蛇"));//outtextxy输入文本 
	outtextxy(570, 470, _T("请输入墙体大小1，2，3"));
	outtextxy(570, 570, _T("单人请输入1，双人请输入2"));
	int level;//墙体大小 
	cin >> level;
	Wall thewall(level);//依据墙体大小 生成墙 
	Apple apple(thewall);//依据墙体生成果子 
	Snake s1(thewall, apple, defaultSize);
	Snake s2(thewall, apple, defaultSize);//依据墙体果子进行蛇定义
	Point* p1;
	Point* p2;//蛇头节点
	char pre_direction1, cur_direction1,pre_direction2, cur_direction2;
	s1.InitSnake('v', 5, 5);
	s2.InitSnake('v', 20, 5);//初始化蛇 
	pre_direction1 = 's';
	pre_direction2 = 'k';//方向初始化
	p1 = s1.GetHead();
	p2 = s2.GetHead();//得到蛇头节点 
	int a, b, i, len1, len2, len;
	a = thewall.GetRow();
	b = thewall.GetCol();//得到长宽
	apple.suijifangzhi(); //先进行第一个果子放置 
	int jj,T=3;
	cin >> jj;
	if (jj == 1)//输入12来判断为单人双人
	{
		while (!s1.Death())//蛇不死则继续游戏 
		{
		    len = s1.getLength();
			setfillcolor(RED);
			fillrectangle(0, 0, b * 10 + 10, a * 10 + 10);
			setfillcolor(BLACK);
			fillrectangle(10, 10, b * 10, a * 10);//边框采用大矩形先打底色（红色）再覆盖稍小的矩形 （黑色） 
			draw(apple.ix, apple.iy);//画出苹果 
			for (int i = 0; i < len; i++)
				draw(p1[i].x, p1[i].y);//画蛇的每一个节点来表现蛇 
			Sleep(170);//合理暂停反应时间 
			cleardevice();//清屏，为下一步准备 
			cur_direction1 = char(_getch());//获取输入 
			s1.Move(pre_direction1, cur_direction1);//移动
			if (s1.Eat())//吃到就随机放置苹果 
				apple.suijifangzhi();
		}
		outtextxy(470, 170, _T("Game over"));
		outtextxy(470, 270, _T("socre:" ));//输出游戏结束以及分数 
		char s[5];
		sprintf_s(s, "%d", len*100);//将整形len转换成字符串
		outtextxy(600, 270, s);//出入分数 
		Sleep(3000);//静止显示结果一段时间 
	}
	else {
		while (!(T = Win(s1, s2)))//判断是否有一方胜利 
		{
			len1 = s1.getLength();
			len2 = s2.getLength();//获取蛇长 
			setfillcolor(RED);
			fillrectangle(0, 0, b * 10 + 10, a * 10 + 10);
			setfillcolor(BLACK);
			fillrectangle(10, 10, b * 10, a * 10);//边框采用大矩形先打底色（红色）再覆盖稍小的矩形 （黑色）
			draw(apple.ix, apple.iy);//画出苹果 
			for (int i = 0; i < len1; i++)
				draw(p1[i].x, p1[i].y,1);//画蛇的每一个节点来表现蛇 
			for (int i = 0; i < len2; i++)
				draw(p2[i].x, p2[i].y,2);//画蛇的每一个节点来表现蛇 
			Sleep(170);//合理暂停反应时间 
			cleardevice();//清屏，为下一步准备 
			i = 0;
			char ru;
			while (i < 2) {
				ru = char(_getch());
				Q.EnQueue(ru);
				i++;
			}//接受多个指令 
			Q.DeQueue(cur_direction1, 1, pre_direction1);
			Q.DeQueue(cur_direction2, 2, pre_direction2);//将队列中对应控制键提出 
			s1.Move(pre_direction1, cur_direction1);
			s2.Move(pre_direction2, cur_direction2);//两条蛇的移动 
			if (s1.Eat() || s2.Eat())//任一吃到就随机放置苹果 
				apple.suijifangzhi();

		}
		if( T == 1) outtextxy(570, 270, _T("1号win"));
		if (T == 2) outtextxy(570, 270, _T("2号win"));
		if (T == 3) outtextxy(570, 270, _T("平"));
		Sleep(3000);//输出结果，静止画面展示 
	}
}

