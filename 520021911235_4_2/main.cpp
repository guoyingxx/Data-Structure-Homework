//4—2：某汽车轮渡口中过江渡船每次能载10辆车，每10分钟有一个渡轮到达。
//过江车辆分为客车和货车。上渡船有如下规定：
//客车先于货车上船，，每上4辆客车允许上一辆货车；若等待的客车数不满4辆，则以货车代替。
//试编写一程序模拟渡口的管理，统计客车和货车的平均等待时间。设车辆到达服从均匀分布，参数由用户指定。

#include<iostream>
#include"simulator.h"
using namespace std;

int main()
{
    simulator sim;//构造模拟类
    sim.avgWaitTime();//进行排队的仿真
    cout<<"客车等待的平均时间为："<<sim.getBusWaitTime()<<"分钟"<<endl;//输出客车的结果
    cout<<"货车等待的平均时间为："<<sim.getVanWaitTime()<<"分钟"<<endl;//输出货车的结果
    return 0;
}
