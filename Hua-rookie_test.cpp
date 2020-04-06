#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
    int num;
    string name;
    char sex;
public:
    void get_value()
    {cin>>num>>name>>sex;}
    void display()
    {
        cout<<"name:"<<name<<endl;
        cout<<"num:"<<num<<endl;
        cout<<"sex:"<<sex<<endl;
    }
};
class Student1: private Student
{
private:
    int age;
    string adr;
public:
    void get_value_1()
    {
        get_value();
        cin>>age>>adr;
    }
    void display_1()
    {
        display();
        cout<<"age:"<<age<<endl;
        cout<<"address:"<<adr<<endl;
    }
};
int main()
{
    Student1 stu;
    stu.get_value_1();
    stu.display_1();
    return 0;
}
