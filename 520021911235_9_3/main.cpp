//��������������еĲ��롢ɾ���Ͳ��Һ����ĳɷǵݹ麯��
#include <iostream>
#include"BinarySearchTree.h"
using namespace std;

int main()
{
    BinarySearchTree<int> tree;//һ�ñȽ�ƽ�����
    int a[9]={3,2,8,1,6,12,4,7,16};
    for(int i=0;i<9;i++)tree.insert(a[i]);
    cout<<"���������Ϊ��";
    tree.levelOrder();
    cout<<endl;
    cout<<"����8:";
    if(tree.find(8))cout<<"true"<<endl;
    cout<<"����80:";
    if(!tree.find(80))cout<<"false"<<endl;
    tree.remove(16);
    cout<<"ɾ��ֵΪ6��Ԫ�غ�Ϊ��";
    tree.levelOrder();
    return 0;
}
