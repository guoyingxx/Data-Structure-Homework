//�ڱ���ʵ�ֵ�˳����������������������Ա�Ĺ��ܡ�
//˳�������û�����ʹ�ñ��ʽC=A+B�����Ա�A��B�鲢��������Ա�C��
#include <iostream>
#include"seqList.h"
using namespace std;


int main()
{
    cout<<"����ʱ��һ���зֱ�Ϊ���Ա�A��B��������Ϊ�鲢������Ա�C"<<endl;
    seqList<int> A(5),B(5);
    for(int i=0;i<5;i++)
        A.insert(i,i);
    cout<<"A:";
    A.tranverse();
    for(int i=0;i<5;i++)
        B.insert(i,i+5);
    cout<<"B:";
    B.tranverse();

    seqList<int> C;
    C=A+B;//ʹ�ñ��ʽC=A+B�����Ա�A��B�鲢��������Ա�C
    cout<<"C:";
    C.tranverse();
    return 0;
}
