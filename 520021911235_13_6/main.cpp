//ѧ����Ҫѡ��һ����Ŀ�Ŀγ̲��ܱ�ҵ����Щ�γ�֮�����ȵ���ϵ���������еĿγ���ÿѧ�ڶ����ṩѧ��ѡ�ޣ�ѧ��ÿѧ�ڿ���ѡ�޵Ŀγ������ޡ�
//����һЩ�γ��Լ��γ�֮��Ĺ�ϵ������һ���ƻ��������ٵ�ѧ�����������еĿγ̡�
#include <iostream>
#include"adjListGraph.h"
#include"adjListGraph.cpp"
#include<cstring>
using namespace std;

int main()
{
    string c[]={"��ѧ","�������","��ɢ��ѧ","�������","���ݽṹ","���ݿ�","����ԭ��"};//���ϵ�����
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
