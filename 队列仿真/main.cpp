#include<iostream>
#include"simulator.h"
using namespace std;

int main()
{
    simulator sim;//构造模拟类
    cout<<"平均的等待时间为"<<sim.avgWaitTime();//进行排队的仿真
    return 0;
}
