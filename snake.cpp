#include <iostream>
#include <time.h>
#include <Windows.h>
#include"wall.h"
#include"apple.h"
#include"snake.h"
using namespace std;

Snake::Snake(Wall &tempWall,Apple &apple,int sz):m_wall(tempWall),m_apple(apple)//������ߡ������ⲿ��ǽ�͹���
{
    length=0;
    maxSize=sz;
    Head=NULL;
}

Snake::~Snake()//��������
{
    delete [] Head;
}

void Snake::InitSnake(char head_direction, int x, int y)//��������Ϸ��һ�ο�ʼ�������¿�ʼ�����߳�ʼ������λ��
{
    if (Head == NULL)
    {
        Head = new Point[maxSize];
        if (Head == NULL)
        {
            cerr << "�ڴ�������" << endl; exit(1);
        }
    }//�����һ�ο�ʼ����ͷָ��Ϊ�գ�����ռ䣻����ռ�ʧ���򱨴�
    else
        for (int i = 0; i < maxSize; i++)
            Head[i].x = Head[i].y = 0;//��������¿�ʼ��Ϸ���������ȫ����λΪ0
    if (head_direction == 'v')//��������ģ��������Ҫ�����Խ���ʼ��ͷָ��ͬ����
    {
        Head[0].x = Head[1].x = Head[2].x = x;
        Head[0].y = y++;
        Head[1].y = y++;
        Head[2].y = y;
    }
    else
    {
        Head[0].y = Head[1].y = Head[2].y = y;
        Head[0].x = x++;
        Head[1].x = x++;
        Head[2].x = x;
    }
    length = 3;//��ʼ�趨�������Σ���ͷ���꣨5��5��������5��6���ͣ�5��7��  
    tailx = x;
    taily = y;
}

void Snake::AddMaxsize()//����������󳤶�
{
    Point *m_newhead=NULL;
    maxSize+=50;//һ������50��
    m_newhead = new Point[maxSize];
    if (m_newhead == NULL)
    {
        cerr << "�ڴ�������" << endl; exit(1);
    }
    for (int i=0; i<length; i++)
        m_newhead[i]=Head[i];
    delete [] Head;
    Head = m_newhead;
}

void Snake::Move(char& pre_direction, char& cur_direction)//�ߵ����к�������ʹ�߰��ʵ��������У�����Ϊ��һ���˶���������ã��Լ���������������ķ��������
{
    int x = Head[0].x, y = Head[0].y;//�����ͷ����
    char direction;//���ڴ洢�߱����˶�����
    if (((cur_direction != UP && cur_direction != Up) && (cur_direction != DOWN && cur_direction != Down) && (cur_direction != RIGHT && cur_direction != Right) && (cur_direction != LEFT && cur_direction != Left)) ||
        ((pre_direction == LEFT || pre_direction == Left) && (cur_direction == RIGHT || cur_direction == Right)) ||
        ((pre_direction == RIGHT || pre_direction == Right) && (cur_direction == LEFT || cur_direction == Left)) ||
        ((pre_direction == UP || pre_direction == Up) && (cur_direction == DOWN || cur_direction == Down)) ||
        ((pre_direction == DOWN || pre_direction == Down) && (cur_direction == UP || cur_direction == Up)))
        direction = pre_direction;  //�������ĵ�ǰ����Ϊ���Ƿ����ַ�������������һ���˶����������෴���������һ�ε��˶�����
    else//���򣬲�����������ķ��򣬲����÷���ͬʱ�洢��pre_direction
    {
        direction = cur_direction;
        pre_direction = cur_direction;
    }
    switch (direction) {//�����˶����򣬻��������ͷ�������
    case Up:
    case UP:    y--;
        break;
    case Down:
    case DOWN:  y++;
        break;
    case Right:
    case RIGHT: x++;
        break;
    case Left:
    case LEFT:  x--;
        break;
    default:
        break;
    }
    for (int i = getLength() - 1; i > 0; i--)//ʹ������ǰ�䶯һ��
        Head[i] = Head[i - 1];
    Head[0].x = x;//����ͷ��������Ϊ����
    Head[0].y = y;
}
bool Snake::Eat()
{
    int x = Head[0].x, y = Head[0].y;
    if (length==maxSize)//����Ѵﵽ�������������߳�����
        AddMaxsize();
    if (x == m_apple.ix && y == m_apple.iy)
    {
        //if(x==m_apple.ix&&y==m_apple.iy){
        length++;
        if (length == 4 && Head[2].x == 5 && Head[2].y == 6)
        {
            Head[3].x = 5; Head[3].y = 7;
        }
        else
        {
            Head[length - 1].x = tailx;
            Head[length - 1].y = taily;
        }
        tailx = Head[length - 1].x;
        taily = Head[length - 1].y;
        return true;
    }
    else
    {
        tailx = Head[length - 1].x;
        taily = Head[length - 1].y;
        return false;
    }
}

bool Snake::Death()
{
    int boux = m_wall.GetRow();
    int bouy = m_wall.GetCol();
    int x = Head[0].x, y = Head[0].y;
    int i = getLength();
    int k;
    for (k = 4; k <= i - 1; k++) {
        if (x == Head[k].x && y == Head[k].y)
        {
            cout << "Game Over" << endl;
            return true;
        }
    }
    if (x == 0 || x == boux || y == 0 || y == bouy)
    {
        cout << "Game Over" << endl;
        return true;
    }
    return false;
}

bool Snake::Death(Snake& s)
{
    int boux = m_wall.GetRow();
    int bouy = m_wall.GetCol();
    int s1_x = Head[0].x, s1_y = Head[0].y;
    Point* s2 = s.GetHead();
    int s1_length = getLength(), s2_length = s.getLength();
    int k;
    for (k = 4; k <= s1_length - 1; k++) {
        if (s1_x == Head[k].x && s1_y == Head[k].y)  return true;
    }
        if (s1_x == 0 || s1_x == boux || s1_y == 0 || s1_y == bouy)  return true;
        for (k = 0; k <= s2_length - 1; k++) {
            if (s1_x == s2[k].x && s1_y == s2[k].y) return true; 
        }
    return false;
}

int Win(Snake & s1, Snake & s2)//˫��ģʽ�£��ж������ߵ���Ӯ�����������ߵ����ã�
{
    bool s1_death = s1.Death(s2), s2_death = s2.Death(s1);//��������ߵ��������
    int s1_length=s1.getLength(),s2_length=s2.getLength();//��������ߵ������ܳ�
    if (!s1_death && !s2_death)//���������û����������0
        return 0;
    else
    {
        if (s1_death && s2_death)//���������ͬʱ��������Ƚ������ܳ������߻�ʤ���ȳ���ƽ��
        {
            if (s1_length > s2_length) return 1;//���1��ʤ
            else if (s1_length < s2_length) return 2;//���2��ʤ
            else return 3;//ƽ��
        }
        else//���ֻ��һ�����������Դ����ʤ
        {
            if (s2_death) return 1;//���1��ʤ
            else return 2;//���2��ʤ
        }
    }
}
