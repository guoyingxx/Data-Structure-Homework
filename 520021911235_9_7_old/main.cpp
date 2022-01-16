//在二叉查找树中增加一个成员函数，找出集合中第i大的元素
#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
    BinarySearchTree<int> tree;//一棵比较平衡的树
    int a[9]={3,2,8,1,6,12,4,7,16};
    for(int i=0;i<9;i++)tree.insert(a[i]);
    cout<<"二叉查找树为：";
    tree.levelOrder();
    cout<<endl;
    cout<<"集合中第4大的元素为：";
    cout<<tree.findIth(4);
    return 0;
}
