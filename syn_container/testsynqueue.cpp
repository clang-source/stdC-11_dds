//
// Created by Administrator on 2019/9/26.
//
#include <iostream>
#include "CondQueue.h"
#include <Windows.h>
#include <thread>

using namespace std;

class Student{
public:
    int a;

};


CondQueue<int> g_queue;
int g_index = 10;

void thread_Fuc_Pop()
{
    cout << "thread_Fuc_Pop start\n";
    int flag =1;
    while (flag)
    {
        int value=0;
        g_queue.WaitPop(value);
        printf("wait_and_pop done! value=%d  thread id:%d\n",value,GetCurrentThreadId());
    }
}

void thread_Fuc2_Push()
{
    cout << "thread_Fuc2_Push start\n";
    int flag =1;
    while (flag)
    {
        Sleep(1000);
        g_index++;
        g_queue.push(g_index);
    }
}

void thread_Fuc4_Push()
{
    cout << "thread_Fuc4_Push start\n";
    int flag =1;
    while (flag)
    {
        Sleep(1000);
        g_index++;
        g_queue.push(g_index);
    }
}

int main_int()
{
    thread thd(thread_Fuc_Pop);
    thd.detach();


    thread thd2(thread_Fuc2_Push);
    thd2.detach();


    thread thd4_p(thread_Fuc4_Push);
    thd4_p.detach();


    int a;
    while (cin >> a)
    {;}
    return 0;
}








static CondQueue<Student> stu_queue;

void thread_Fuc_Pop_VO()
{
    cout << "thread_Fuc_Pop_VO start\n";
    int flag =1;
    while (flag)
    {
        Student value;
        stu_queue.WaitPop(value);
        printf("student: wait_and_pop done! value.a=%d  thread id:%d\n",value.a,GetCurrentThreadId());
    }
}

void thread_Fuc2_Pop_VO()
{
    cout << "thread_Fuc2_Pop_VO start\n";
    int flag =1;
    while (flag)
    {
        Student value;
        stu_queue.WaitPop(value);
        printf("student: wait_and_pop2 done! value.a=%d  thread id:%d\n",value.a,GetCurrentThreadId());
    }
}




void thread_Fuc2_Push_VO()
{
    cout << "thread_Fuc2_Push_VO start\n";
    int flag =1;
    while (flag)
    {
        Sleep(1000);
        Student  *stu = new Student() ;
        stu->a=2000;
        stu_queue.push(*stu);
        delete  stu;
    }
}
void thread_Fuc4_Push_VO()
{
    cout << "thread_Fuc4_Push_VO start\n";
    int flag =1;
    while (flag)
    {
        Sleep(1000);
        Student  *stu = new Student() ;
        stu->a=4000;
        stu_queue.push(*stu);
        delete  stu;
    }
}


int main_vo()
{
    thread thd_pop(thread_Fuc_Pop_VO);
    thd_pop.detach();

    thread thd2_pop(thread_Fuc2_Pop_VO);
    thd2_pop.detach();

    thread thd2(thread_Fuc2_Push_VO);
    thd2.detach();


    thread thd4_p(thread_Fuc4_Push_VO);
    thd4_p.detach();


    int a;
    while (cin >> a)
    {;}
    return 0;
}

int main(){
  //  return main_int();
    return main_vo();
}
