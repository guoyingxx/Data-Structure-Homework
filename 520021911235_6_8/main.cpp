//�������Ժ����ֵ����ķ����洢���Էֱ����ʵ������ǰ�򡢺���Ͳ�α������㷨��
#include <iostream>
#include"Child-SiblingLinkedList.h"
using namespace std;

int main()
{
    ChildSiblingLinkedList<char>tree;
    tree.createTree('@');//����
    tree.preOrder();//ǰ�����
    tree.postOrder();//�������
    tree.levelOrder();//��α���
    return 0;
}
