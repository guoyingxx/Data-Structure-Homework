//6.Pascal�����У����������begin��end��ʾ���������ĸ�ʽ��if��then��else������else�Ӿ���Գ���Ҳ���Բ����֡�
//��һ���������PascalԴ�ļ��е�begin��end�Ƿ���ԣ�if��then��else�Ƿ���ԡ�
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

template<class T>
class seqStack//˳��ջ��Ķ���
{
private:
    T*elem;
    int top_p;
    int maxSize;
    void doublespace(){
        T*tmp=elem;
        elem=new T[maxSize*2];
        for(int i=0;i<maxSize;++i)elem[i]=tmp[i];
        maxSize*=2;
        delete []tmp;
    }
public:
    seqStack(int intiSize=10)
    {
        elem=new T[intiSize];
        maxSize=intiSize;
        top_p=-1;
    }
    ~seqStack(){delete []elem;}
    bool isEmpty()const{return top_p==-1;}
    void push(const T&x)
    {
        if(top_p==maxSize-1)doublespace();
        elem[++top_p]=x;
    }
    T pop(){return elem[top_p--];}
    T top(){return elem[top_p];}
};

int main()
{
    char filename[100];
    seqStack<char*>s;//����ջ������
    char txt[10];
    ifstream infile;

    cout<<"��������Pascal.txt�������д����ļ�"<<endl;
    cout<<"�����ļ�����";
    cin>>filename;
    infile.open(filename);

    if(!infile)
    {
        cerr<<"�ļ�������";
        return 1;
    }

    while(infile>>txt)//���ļ��е�ÿ���ַ������м��
    {
        if(strcmp(txt,"begin")==0)
        {
            s.push("begin");//����begin��ջ
        }

        if(strcmp(txt,"end")==0)
        {
            if(s.isEmpty()||strcmp(s.top(),"begin")!=0)//���end�Ƿ�����Ե�begin
            {
            cerr<<"����end�����";
            infile.close();
            return 1;
            }
            else s.pop();//��������begin��ջ
        }

        if(strcmp(txt,"if")==0)
        {
            s.push("if");//����if��ջ
            if(strcmp(s.top(),"then")==0) s.pop();//��֮ǰδ��else��Ե�then��ջ
        }

        if(strcmp(txt,"then")==0)
        {
            if(s.isEmpty()||strcmp(s.top(),"if")!=0)//���then�Ƿ�����Ե�if
            {
            cerr<<"����then�����";
            infile.close();
            return 1;
            }
            else
            {
                s.pop();//��������if��ջ����then��ջ
                s.push("then");
            }
        }

        if(strcmp(txt,"else")==0)
        {
            if(s.isEmpty()||strcmp(s.top(),"then")!=0)//���else�������
            {
            cerr<<"����else�����";
            infile.close();
            return 1;
            }
            else s.pop();//��������then��ջ
        }
    }

    cout<<"������ȷ";//�����ɺ������������ȷ
    infile.close();//�ر��ļ�
    return 0;
}
