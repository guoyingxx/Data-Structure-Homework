//6.Pascal语言中，复合语句用begin…end表示，条件语句的格式是if…then…else…其中else子句可以出现也可以不出现。
//编一函数，检查Pascal源文件中的begin和end是否配对，if、then、else是否配对。
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

template<class T>
class seqStack//顺序栈类的定义
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
    seqStack<char*>s;//利用栈检测配对
    char txt[10];
    ifstream infile;

    cout<<"可以输入Pascal.txt，或自行创建文件"<<endl;
    cout<<"输入文件名：";
    cin>>filename;
    infile.open(filename);

    if(!infile)
    {
        cerr<<"文件不存在";
        return 1;
    }

    while(infile>>txt)//对文件中的每个字符串进行检测
    {
        if(strcmp(txt,"begin")==0)
        {
            s.push("begin");//遇到begin入栈
        }

        if(strcmp(txt,"end")==0)
        {
            if(s.isEmpty()||strcmp(s.top(),"begin")!=0)//检测end是否有配对的begin
            {
            cerr<<"存在end无配对";
            infile.close();
            return 1;
            }
            else s.pop();//如果配对则将begin出栈
        }

        if(strcmp(txt,"if")==0)
        {
            s.push("if");//遇到if入栈
            if(strcmp(s.top(),"then")==0) s.pop();//将之前未与else配对的then出栈
        }

        if(strcmp(txt,"then")==0)
        {
            if(s.isEmpty()||strcmp(s.top(),"if")!=0)//检测then是否有配对的if
            {
            cerr<<"存在then无配对";
            infile.close();
            return 1;
            }
            else
            {
                s.pop();//如果配对则将if出栈并将then入栈
                s.push("then");
            }
        }

        if(strcmp(txt,"else")==0)
        {
            if(s.isEmpty()||strcmp(s.top(),"then")!=0)//检测else有无配对
            {
            cerr<<"存在else无配对";
            infile.close();
            return 1;
            }
            else s.pop();//如果配对则将then出栈
        }
    }

    cout<<"程序正确";//检测完成后均配对则程序正确
    infile.close();//关闭文件
    return 0;
}
