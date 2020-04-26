#include"apple.h"
#include<Windows.h>
using namespace std;

void gotoxy2(HANDLE hOut2, int x, int y)
{
	COORD pos;//字符坐标 
	pos.X = x; //横坐标
	pos.Y = y; //纵坐标 
	SetConsoleCursorPosition(hOut2, pos);
}
HANDLE hOut2 = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量

Apple::Apple(Wall &tempwall) :wall1(tempwall)
{

}

void Apple::suijifangzhi()
{

	while (true)
	{
		ix = rand() % (Wall::Row - 2) + 1;
		iy = rand() % (Wall::Col - 2) + 1;
		//如果随机的位置是蛇头或蛇身，就重新生成随机数
		if (wall1.Getdata(ix, iy) == ' ')
		{
			wall1.wallchange(ix, iy,'*');//改变墙 
			gotoxy2(hOut2, iy * 2, ix);//获得果子位置 ，定位光标 
			cout << '*';
			break;
		}

	}
   	
}
void Apple::anotherapple()
{ if(clock() / CLOCKS_PER_SEC==5)
	suijifangzhi();	
}
