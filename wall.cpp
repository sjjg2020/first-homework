#include<iostream>
#include"wall.h" 
using namespace std;
int Wall::GetRow() 
{
	return Row;
}
int Wall::GetCol()
{
	return Col;
}
//char Wall::Getdata(int a, int b)
//{
//	return wall[a][b];
//}
//void Wall::wallchange(int a, int b, char c)
//{

//	wall[a][b] = c;

//}
//void wallchange(int a, int b, char c);//墙是输出中心 
//char Newwall();//随时间形成的新的障碍 （新） 
//void difficulty(int a) ;//难度设置 (新) 
//void Wall::newwall()
//{
//	for (int i = 0; i < Row; i++)
//	{
//		for (int j = 0; j < Col; j++)
//		{
	//		//放墙壁的地方
	//		if (i == 0 || j == 0 || i == Row - 1 || j == Col - 1)
	//		{
	//			wall[i][j] = '#';
	//		}
	//		else
	//		{
	//			wall[i][j] = ' ';
	//		}
	//	}
//	}

//}
//void Wall::putwall()
//{
//	for (int i = 0; i < Row; ++i)
	//{
	//	for (int j = 0; j < Col; ++j)
	//	{
	//		cout << wall[i][j] << " ";
	//	}
	//	if (i == 5)
	//	{
	//		cout << "版本：初稿";
	//	}
	//	if (i == 6)
	//	{
	//		cout << "a:向左";
	//	}
	//	if (i == 7)
		//{
	//		cout << "d:向右";
	//	}
	//	if (i == 8)
	//	{
	//		cout << "w:向上";
	//	}
	//	if (i == 9)
	//	{
	//		cout << "s:向下";
	//	}
	//	cout << endl;
//	}
//}