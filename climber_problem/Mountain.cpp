/*************************************************************************
	> File Name: Mountain.cpp
	> Author: YinWen
	> Mail: yinwenatbit@163.com
	> Created Time: 2015年09月03日 星期四 13时52分47秒
 ************************************************************************/

#include "Mountain.h"
#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Mountain* Mount;

int readFromStr(char const *strptr, Mount & M);
int getnumber(char const *&ptr);

/*count the distance*/
int resolve(char const * originstr)
{
    Mount mounts=NULL;
    int total = readFromStr(originstr, mounts);
    
}

/*read mountains from str*/
int readFromStr(char const *strptr, Mount & M)
{
    int num;
    int left, right, hight;

    std::string str = "";

    num = getnumber(strptr);
    M = new struct Mountain[num];

   for(int i=0; i<num; i++)
   {
       M[i].left = getnumber(strptr);
       M[i].right = getnumber(strptr);
       M[i].hight = getnumber(strptr);
   }
}


/*输入数字开始的地址，返回数字，并且修改指针指向下一个开始的数字*/
int getnumber(char const *&ptr)
{
    string str ="";
    while( *ptr >='0'&& *ptr<='9' )
    {
        str += *ptr;
        ++ptr;        
    }
    ++ptr;
    return atoi(str.c_str());

}
