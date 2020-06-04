#ifndef wall_h
#define wall_h
#include<iostream> 
using namespace std;
	
class Wall
{public:
	Wall(int x){
		if (x == 1) { Row = 20; Col = 20;  }
		if (x == 2) { Row = 30; Col = 30; }
		if (x == 3) {  Row = 40; Col = 40; }
	}
	int GetRow();
	int GetCol();
//	void newwall();//刷新 
//	void putwall();//输出 
	//void wallchange(int a,int b,char c);//墙是输出中心 
	char Newwall();//随时间形成的新的障碍 （新） 
//	void difficulty(int a) ;//难度设置 (新) 
private:
	int Row;
	int Col;
};  
#endif/* wall_h */