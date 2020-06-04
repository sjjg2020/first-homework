#include <iostream>
#include <time.h>
#include <Windows.h>
#include"wall.h"
#include"apple.h"
#include"snake.h"
using namespace std;

Snake::Snake(Wall &tempWall,Apple &apple,int sz):m_wall(tempWall),m_apple(apple)//æ„é€ ç©ºè›‡ã€ä¼ å…¥å¤–éƒ¨çš„å¢™å’Œæœå­
{
    length=0;
    maxSize=sz;
    Head=NULL;
}

Snake::~Snake()//å°†è›‡ææ„
{
    delete [] Head;
}

void Snake::InitSnake(char head_direction, int x, int y)//æ— è®ºæ˜¯æ¸¸æˆç¬¬ä¸€æ¬¡å¼€å§‹è¿˜æ˜¯é‡æ–°å¼€å§‹ï¼Œå°†è›‡åˆå§‹åŒ–ï¼ˆå¤ä½ï¼‰
{
    if (Head == NULL)
    {
        Head = new Point[maxSize];
        if (Head == NULL)
        {
            cerr << "å†…å­˜åˆ†é…é”™è¯¯" << endl; exit(1);
        }
    }//å¦‚æœç¬¬ä¸€æ¬¡å¼€å§‹åˆ™è›‡å¤´æŒ‡é’ˆä¸ºç©ºï¼Œåˆ†é…ç©ºé—´ï¼›åˆ†é…ç©ºé—´å¤±è´¥åˆ™æŠ¥é”™
    else
        for (int i = 0; i < maxSize; i++)
            Head[i].x = Head[i].y = 0;//å¦‚æœæ˜¯é‡æ–°å¼€å§‹æ¸¸æˆï¼Œåˆ™æŠŠè›‡èº«å…¨éƒ¨å¤ä½ä¸º0
    if (head_direction == 'v')//æ ¹æ®å…¶ä»–æ¨¡å—ç¼–ç¨‹è€…éœ€è¦ï¼Œå¯ä»¥å°†åˆå§‹è›‡å¤´æŒ‡å‘ä¸åŒæ–¹å‘
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
    length = 3;//åˆå§‹è®¾å®šè›‡æœ‰ä¸‰æ®µï¼Œè›‡å¤´åæ ‡ï¼ˆ5ï¼Œ5ï¼‰ï¼Œè›‡èº«ï¼ˆ5ï¼Œ6ï¼‰å’Œï¼ˆ5ï¼Œ7ï¼‰  
    tailx = x;
    taily = y;
<<<<<<< HEAD
=======
>>>>>>> 7ec958dca07898da6a47489bd5a9467dd2a20c82
}

void Snake::AddMaxsize()//å¢åŠ è›‡èº«æœ€å¤§é•¿åº¦
{
    Point *m_newhead=NULL;
    maxSize+=50;//ä¸€æ¬¡å¢åŠ 50èŠ‚
    m_newhead = new Point[maxSize];
    if (m_newhead == NULL)
    {
        cerr << "å†…å­˜åˆ†é…é”™è¯¯" << endl; exit(1);
    }
    for (int i=0; i<length; i++)
        m_newhead[i]=Head[i];
    delete [] Head;
    Head = m_newhead;
}

void Snake::Move(char& pre_direction, char& cur_direction)//è›‡çš„çˆ¬è¡Œå‡½æ•°ï¼Œå¯ä½¿è›‡æŒ‰é€‚å½“æ–¹å‘çˆ¬è¡Œï¼›å‚æ•°ä¸ºä¸Šä¸€æ¬¡è¿åŠ¨æ–¹å‘çš„å¼•ç”¨ï¼Œä»¥åŠæ“ä½œè€…æœ€æ–°è¾“å…¥çš„æ–¹å‘çš„å¼•ç”¨
{
    int x = Head[0].x, y = Head[0].y;//è·å¾—è›‡å¤´åæ ‡
    char direction;//ç”¨äºå­˜å‚¨è›‡æœ¬æ¬¡è¿åŠ¨æ–¹å‘
    if (((cur_direction != UP && cur_direction != Up) && (cur_direction != DOWN && cur_direction != Down) && (cur_direction != RIGHT && cur_direction != Right) && (cur_direction != LEFT && cur_direction != Left)) ||
        ((pre_direction == LEFT || pre_direction == Left) && (cur_direction == RIGHT || cur_direction == Right)) ||
        ((pre_direction == RIGHT || pre_direction == Right) && (cur_direction == LEFT || cur_direction == Left)) ||
        ((pre_direction == UP || pre_direction == Up) && (cur_direction == DOWN || cur_direction == Down)) ||
        ((pre_direction == DOWN || pre_direction == Down) && (cur_direction == UP || cur_direction == Up)))
        direction = pre_direction;  //å¦‚æœè¾“å…¥çš„å½“å‰æ–¹å‘ä¸ºâ€œéæ–¹å‘å­—ç¬¦â€ï¼Œæˆ–è€…ä¸ä¸Šä¸€ä¸ªè¿åŠ¨æ–¹å‘æ­£å¥½ç›¸åï¼Œåˆ™é‡‡ç”¨ä¸Šä¸€æ¬¡çš„è¿åŠ¨æ–¹å‘
    else//å¦åˆ™ï¼Œé‡‡ç”¨æœ€æ–°è¾“å…¥çš„æ–¹å‘ï¼Œå¹¶å°†è¯¥æ–¹å‘åŒæ—¶å­˜å‚¨åˆ°pre_direction
    {
        direction = cur_direction;
        pre_direction = cur_direction;
    }
    switch (direction) {//æ ¹æ®è¿åŠ¨æ–¹å‘ï¼Œè·å¾—æœ€æ–°è›‡å¤´ç»“ç‚¹åæ ‡
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
    for (int i = getLength() - 1; i > 0; i--)//ä½¿è›‡èº«å‘å‰è •åŠ¨ä¸€æ ¼
        Head[i] = Head[i - 1];
    Head[0].x = x;//å°†è›‡å¤´ç»“ç‚¹åæ ‡æ”¹ä¸ºæœ€æ–°
    Head[0].y = y;
}
bool Snake::Eat()
{
    int x = Head[0].x, y = Head[0].y;
<<<<<<< HEAD
    if (length==maxSize)//å¦‚æœå·²è¾¾åˆ°æœ€é•¿ï¼Œåˆ™è°ƒç”¨å¢åŠ è›‡é•¿å‡½æ•°
        AddMaxsize();
    if (x == m_apple.ix && y == m_apple.iy)
=======
    if (x == m_apple.ix && y == m_apple.iy)//³Ôµ½¹û×Ó 
>>>>>>> 7ec958dca07898da6a47489bd5a9467dd2a20c82
    {
        if(x==m_apple.ix&&y==m_apple.iy){
        length++;
        if (length == 4 && Head[2].x == 5 && Head[2].y == 6)
        {
            Head[3].x = 5; Head[3].y = 7;//Èç¹ûÉßÔÚÒÆ¶¯µÄµÚÒ»²½¾Í³Ôµ½ÁË¹û×Ó£¬ÉßÎ²y×ø±êÖ±½Ó¼ÓÒ»¸öµ¥Î»³¤¶È 
        }
<<<<<<< HEAD
        else
        {
            Head[length - 1].x = tailx;
            Head[length - 1].y = taily;
        }
=======
        else { Head[length - 1].x = tailx; Head[length - 1].y = taily; }//Èç¹û²»ÊÇµÚÒ»²½³Ôµ½¹û×Ó£¬ÉßÎ²×ø±ê±äÎª×îºóÒ»´ÎÒÆ¶¯Ö®Ç°µÄÉßÎ²×ø±ê 
>>>>>>> 7ec958dca07898da6a47489bd5a9467dd2a20c82
        tailx = Head[length - 1].x;
        taily = Head[length - 1].y;//¸øÉßÎ²µÄ×ø±êÖØĞÂ¸³Öµ 
        return true;
    }
    else
    {
        tailx = Head[length - 1].x;
        taily = Head[length - 1].y;//Ã»ÓĞ³Ôµ½¹û×Ó²»Ôö¼Ó³¤¶È£¬Ö»¸Ä±äÉßÎ²×ø±ê 
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
<<<<<<< HEAD
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
=======
        if (x == Head[k].x && y == Head[k].y) { cout << "Game Over" << endl; return true; }//Èç¹ûÉßÍ·×²µ½ÉßÉí£¬ÓÎÏ·½áÊø 
    }
    if (x == 4 || x == boux || y == 0 || y == bouy) { cout << "Game Over" << endl; return true; }//Èç¹ûÉßÍ·×²µ½Ç½£¬ÓÎÏ·½áÊø 
>>>>>>> 7ec958dca07898da6a47489bd5a9467dd2a20c82
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
        if (s1_x == Head[k].x && s1_y == Head[k].y)  return true; //Èô¸ÃÉßÉßÍ·×²µ½×Ô¼º£¬¸ÃÉßËÀ 
        if (s1_x == 0 || s1_x == boux || s1_y == 0 || s1_y == bouy)  return true;//Èô¸ÃÉßÉßÍ·×²Ç½£¬¸ÃÉßËÀ 
        for (k = 0; k <= s2_length - 1; k++) {
<<<<<<< HEAD
            if (s1_x == s2[k].x && s1_y == s2[k].y) return true; 
=======
            if (s1_x == s2[k].x && s1_y == s2[k].y)  return true; //Èô¸ÃÉßÉßÍ·×²µ½ÁíÒ»ÌõÉß£¬¸ÃÉßËÀ 
>>>>>>> 7ec958dca07898da6a47489bd5a9467dd2a20c82
        }
    }
    return false;
}

int Win(Snake & s1, Snake & s2)//åŒè›‡æ¨¡å¼ä¸‹ï¼Œåˆ¤æ–­ä¸¤æ¡è›‡çš„è¾“èµ¢ï¼›ä¼ å…¥ä¸¤æ¡è›‡çš„å¼•ç”¨ï¼›
{
    bool s1_death = s1.Death(s2), s2_death = s2.Death(s1);//è·å¾—ä¸¤æ¡è›‡çš„æ­»äº¡æƒ…å†µ
    int s1_length=s1.getLength(),s2_length=s2.getLength();//è·å¾—ä¸¤æ¡è›‡çš„è›‡èº«æ€»é•¿
    if (!s1_death && !s2_death)//å¦‚æœä¸¤æ¡è›‡æ²¡æœ‰æ­»ï¼Œè¿”å›0
        return 0;
    else
    {
<<<<<<< HEAD
        if (s1_death && s2_death)//å¦‚æœä¸¤æ¡è›‡åŒæ—¶æ­»äº¡ï¼Œåˆ™æ¯”è¾ƒè›‡èº«æ€»é•¿ï¼Œé•¿è€…è·èƒœï¼Œç­‰é•¿åˆ™å¹³æ‰‹
        {
            if (s1_length > s2_length) return 1;//ç©å®¶1è·èƒœ
            else if (s1_length < s2_length) return 2;//ç©å®¶2è·èƒœ
            else return 3;//å¹³å±€
        }
        else//å¦‚æœåªæœ‰ä¸€æ¡è›‡æ­»ï¼Œåˆ™ä»å­˜æ´»ç€èƒœ
        {
            if (s2_death) return 1;//ç©å®¶1è·èƒœ
            else return 2;//ç©å®¶2è·èƒœ
        }
    }
}
=======
        bool s1_death = s1.Death(s2), s2_death = s2.Death(s2);
        if (!s1_death && !s2_death)//Èç¹û¶¼Ã»ËÀ£¬ÓÎÏ·¼ÌĞø 
            return 0;
        else
        {
            if (s1_death && s2_death)
            {
                if (s1.getLength() > s2.getLength()) return 1;//Èç¹û1ºÅÉßÉßÉí³¤¶È´óÓÚ2ºÅÉß£¬Ôò1ºÅÉßÓ® 
                else if (s1.getLength() < s2.getLength()) return 2;//Èç¹û2ºÅÉßÉßÉí³¤¶È´óÓÚ1ºÅÉß£¬Ôò2ºÅÉßÓ® 
                else return 3;//Èç¹ûÉßÉí³¤¶ÈÏàµÈ£¬ÔòÆ½¾Ö 
            }
            else
            {
                if (s2_death) return 1;//Èç¹û2ºÅÉßËÀÍö£¬Ôò1ºÅÉßÓ® 
                else return 2; 
            }
        }
    }
>>>>>>> 7ec958dca07898da6a47489bd5a9467dd2a20c82
