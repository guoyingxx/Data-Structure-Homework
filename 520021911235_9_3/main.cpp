//将二叉查找树类中的插入、删除和查找函数改成非递归函数
#include <iostream>
#include"BinarySearchTree.h"
using namespace std;

int main()
{
    BinarySearchTree<int> tree;//一棵比较平衡的树
    int a[9]={3,2,8,1,6,12,4,7,16};
    for(int i=0;i<9;i++)tree.insert(a[i]);
    cout<<"二叉查找树为：";
    tree.levelOrder();
    cout<<endl;
    cout<<"查找8:";
    if(tree.find(8))cout<<"true"<<endl;
    cout<<"查找80:";
    if(!tree.find(80))cout<<"false"<<endl;
    tree.remove(16);
    cout<<"删除值为6的元素后为：";
    tree.levelOrder();
    return 0;
}
