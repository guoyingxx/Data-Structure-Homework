//假设树以孩子兄弟链的方法存储，试分别设计实现它的前序、后序和层次遍历的算法。
#include <iostream>
#include"Child-SiblingLinkedList.h"
using namespace std;

int main()
{
    ChildSiblingLinkedList<char>tree;
    tree.createTree('@');//建树
    tree.preOrder();//前序遍历
    tree.postOrder();//后序遍历
    tree.levelOrder();//层次遍历
    return 0;
}
