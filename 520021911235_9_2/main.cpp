//在二叉查找树类中增加3个成员函数：
//删除小于某个指定值的所有元素，删除大于某个指定值的所有元素，删除某一指定范围中的所有元素
#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
    BinarySearchTree<int> tree;
    int a[12]={3,2,8,1,6,12,4,16,7,5,9,10};//一棵比较平衡的树
    for(int i=0;i<12;i++)tree.insert(a[i]);
    cout<<"建立的二叉查找树为(层次遍历)：";
    tree.levelOrder();
    cout<<endl;
    tree.deleteLess(3);
    cout<<"删除小于3的所有元素后为：";
    tree.levelOrder();
    cout<<endl;
    tree.deleteGreater(8);
    cout<<"删除大于8的所有元素后为：";
    tree.levelOrder();
    cout<<endl;
    cout<<"删除(3,7)范围的所有元素后为：";
    tree.deleteRange(3,7);
    tree.levelOrder();
    cout<<endl;
    return 0;
}
