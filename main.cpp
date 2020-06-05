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
		setfillcolor(GREEN);// setfillcolorָ�������ɫGREEN��ɫ 
		fillrectangle(x * 10, y * 10, (x + 1) * 10, (y + 1) * 10);//fillrectangle�������ɫ���ƾ��Σ�4����ֵΪ���ε������� ����ÿ������Ϊ10*10 
	}
	else {
		setfillcolor(BLUE);// setfillcolorָ�������ɫBLUE��ɫ 
		fillrectangle(x * 10, y * 10, (x + 1) * 10, (y + 1) * 10);
	}
}//��˫�� 
void draw(int x, int y) {
	setfillcolor(RED);// setfillcolorָ�������ɫRED��ɫ 
	fillrectangle(x * 10, y * 10, (x + 1) * 10, (y + 1) * 10);
}//������ ����� 
struct Node//���нڵ� 
{
	char ch;
	Node* link;
	Node(char& ch, Node* ptr = NULL) :ch(ch), link(ptr) {};
};
class Queue//�������ڴ��滺�����������ָ�� 
{
private:
	Node* front;
	Node* rear;
public:
	Queue() { front = rear = NULL; }
	void EnQueue(char& ch) { if (front == NULL) front = rear = new Node(ch); else { rear->link = new Node(ch); rear = rear->link; } }//���ش�������  
	void DeQueue(char&,int, char );//���ش������� 
};
void Queue::DeQueue(char& x,int y,char z)//���к��� 
{
	Node* p = front;
	if (y == 1)
	{
		while (p->ch != 'w' && p->ch != 'a' && p->ch != 's' && p->ch != 'd' && p->link!=NULL) {
			p = p->link;
		} //��������ָ��ų���Чָ�� 
		if (p->ch != 'w' && p->ch != 'a' && p->ch != 's' && p->ch != 'd' && p == rear) {
			x = z;
		}//����Чָ������ϸ����� 
		else {
			x = p->ch;
			p->ch = 'c';
		}//�������� 
	}
	else {
		while (p->ch != 'i' && p->ch != 'j' && p->ch != 'k' && p->ch != 'l' && p->link != NULL) {
			p = p->link;
		}//��������ָ��ų���Чָ�� 
		if (p->ch != 'i' && p->ch != 'j' && p->ch != 'k' && p->ch != 'l' && p == rear) {
			x = z;
		}//����Чָ������ϸ����� 
		else {
			x = p->ch;
			p->ch = 'c';
		}//�������� 
	}
}

int main(){
	Queue Q;//�������� 
	initgraph(1240, 640);//���û�����С 
	setbkcolor(BLACK);//��䱳��ɫ
	settextcolor(RGB(255, 255, 255));//ѡ��������ɫ
	settextstyle(40, 0, _T("΢���ź�")); //ѡ������ 
	outtextxy(570, 270, _T("̰����"));//outtextxy�����ı� 
	outtextxy(570, 470, _T("������ǽ���С1��2��3"));
	outtextxy(570, 570, _T("����������1��˫��������2"));
	int level;//ǽ���С 
	cin >> level;
	Wall thewall(level);//����ǽ���С ����ǽ 
	Apple apple(thewall);//����ǽ�����ɹ��� 
	Snake s1(thewall, apple, defaultSize);
	Snake s2(thewall, apple, defaultSize);//����ǽ����ӽ����߶���
	Point* p1;
	Point* p2;//��ͷ�ڵ�
	char pre_direction1, cur_direction1,pre_direction2, cur_direction2;
	s1.InitSnake('v', 5, 5);
	s2.InitSnake('v', 20, 5);//��ʼ���� 
	pre_direction1 = 's';
	pre_direction2 = 'k';//�����ʼ��
	p1 = s1.GetHead();
	p2 = s2.GetHead();//�õ���ͷ�ڵ� 
	int a, b, i, len1, len2, len;
	a = thewall.GetRow();
	b = thewall.GetCol();//�õ�����
	apple.suijifangzhi(); //�Ƚ��е�һ�����ӷ��� 
	int jj,T=3;
	cin >> jj;
	if (jj == 1)//����12���ж�Ϊ����˫��
	{
		while (!s1.Death())//�߲����������Ϸ 
		{
		    len = s1.getLength();
			setfillcolor(RED);
			fillrectangle(0, 0, b * 10 + 10, a * 10 + 10);
			setfillcolor(BLACK);
			fillrectangle(10, 10, b * 10, a * 10);//�߿���ô�����ȴ��ɫ����ɫ���ٸ�����С�ľ��� ����ɫ�� 
			draw(apple.ix, apple.iy);//����ƻ�� 
			for (int i = 0; i < len; i++)
				draw(p1[i].x, p1[i].y);//���ߵ�ÿһ���ڵ��������� 
			Sleep(170);//������ͣ��Ӧʱ�� 
			cleardevice();//������Ϊ��һ��׼�� 
			cur_direction1 = char(_getch());//��ȡ���� 
			s1.Move(pre_direction1, cur_direction1);//�ƶ�
			if (s1.Eat())//�Ե����������ƻ�� 
				apple.suijifangzhi();
		}
		outtextxy(470, 170, _T("Game over"));
		outtextxy(470, 270, _T("socre:" ));//�����Ϸ�����Լ����� 
		char s[5];
		sprintf_s(s, "%d", len*100);//������lenת�����ַ���
		outtextxy(600, 270, s);//������� 
		Sleep(3000);//��ֹ��ʾ���һ��ʱ�� 
	}
	else {
		while (!(T = Win(s1, s2)))//�ж��Ƿ���һ��ʤ�� 
		{
			len1 = s1.getLength();
			len2 = s2.getLength();//��ȡ�߳� 
			setfillcolor(RED);
			fillrectangle(0, 0, b * 10 + 10, a * 10 + 10);
			setfillcolor(BLACK);
			fillrectangle(10, 10, b * 10, a * 10);//�߿���ô�����ȴ��ɫ����ɫ���ٸ�����С�ľ��� ����ɫ��
			draw(apple.ix, apple.iy);//����ƻ�� 
			for (int i = 0; i < len1; i++)
				draw(p1[i].x, p1[i].y,1);//���ߵ�ÿһ���ڵ��������� 
			for (int i = 0; i < len2; i++)
				draw(p2[i].x, p2[i].y,2);//���ߵ�ÿһ���ڵ��������� 
			Sleep(170);//������ͣ��Ӧʱ�� 
			cleardevice();//������Ϊ��һ��׼�� 
			i = 0;
			char ru;
			while (i < 2) {
				ru = char(_getch());
				Q.EnQueue(ru);
				i++;
			}//���ܶ��ָ�� 
			Q.DeQueue(cur_direction1, 1, pre_direction1);
			Q.DeQueue(cur_direction2, 2, pre_direction2);//�������ж�Ӧ���Ƽ���� 
			s1.Move(pre_direction1, cur_direction1);
			s2.Move(pre_direction2, cur_direction2);//�����ߵ��ƶ� 
			if (s1.Eat() || s2.Eat())//��һ�Ե����������ƻ�� 
				apple.suijifangzhi();

		}
		if( T == 1) outtextxy(570, 270, _T("1��win"));
		if (T == 2) outtextxy(570, 270, _T("2��win"));
		if (T == 3) outtextxy(570, 270, _T("ƽ"));
		Sleep(3000);//����������ֹ����չʾ 
	}
}

