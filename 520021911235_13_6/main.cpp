//学生需要选修一定数目的课程才能毕业，这些课程之间有先导关系。假设所有的课程在每学期都能提供学生选修，学生每学期可以选修的课程数不限。
//给出一些课程以及课程之间的关系，安排一个计划，用最少的学期数修完所有的课程。
#include <iostream>
#include"adjListGraph.h"
#include"adjListGraph.cpp"
#include<cstring>
using namespace std;

int main()
{
    string c[]={"数学","程序设计","离散数学","软件工程","数据结构","数据库","编译原理"};//书上的例子
    adjListGraph<string,int>course(7,c);
    course.insert(0,1);
    course.insert(0,2);
    course.insert(1,3);
    course.insert(1,4);
    course.insert(1,5);
    course.insert(2,4);
    course.insert(2,6);
    course.insert(4,5);
    course.insert(4,6);
    course.insert(5,3);

    course.topSort();
    return 0;
}
