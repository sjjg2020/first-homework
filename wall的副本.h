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

private:
	int Row;
	int Col;
	//char wall[Row][Col];//所含字符 
};  
#endif/* wall_h */
