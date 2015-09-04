/*************************************************************************
	> File Name: Mountain.cpp
	> Author: YinWen
	> Mail: yinwenatbit@163.com
	> Created Time: 2015年09月03日 星期四 13时52分47秒
 ************************************************************************/

#include "Mountain.h"
#include <iostream>
#include <cstdlib>


#define ABS(x) (((x)>0) ? (x) : (-(x)))

using namespace std;

typedef struct Mountain* Mount;

int readFromStr(const char *strptr, Mount & M);
int getNumber(const char *&ptr);
int getTotalHight(const Mount & M, int totalMounts);
int getToNextHight(const Mount & front, const Mount & rear);

/*输入字符串，返回爬山经过的总长度*/
int resolve(const char * originstr)
{
    if(*originstr == '\0')
        return 0;

    Mount mounts=NULL;
    int totalMounts = readFromStr(originstr, mounts);
    
    if(totalMounts == 0)
        return 0;

    int totalhight = getTotalHight(mounts, totalMounts);
    int distance = totalhight + mounts[totalMounts -1].right;

    delete [] mounts;
    return distance;
}

/*开辟山信息结构体数组，传给M指针，返回山的总数*/
int readFromStr(const char *strptr, Mount & M)
{
    int num;

    std::string str = "";

    num = getNumber(strptr);
    M = new struct Mountain[num];

   for(int i=0; i<num; ++i)
   {
       M[i].left = getNumber(strptr);
       M[i].right = getNumber(strptr);
       M[i].hight = getNumber(strptr);
   }

    return num;
}


/*输入数字开始的地址，返回数字，并且修改指针指向下一个开始的数字*/
int getNumber(const char *&ptr)
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

/*计算爬山经过的总高度*/
int getTotalHight(const Mount & M, int totalMounts)
{
    int totalhight=0;
    Mount front =NULL;
    Mount rear = NULL;

    int i=0;
    /*jump to first mountain hight*/
    totalhight += M[0].hight;

    while(i<totalMounts -1)
    {
        front = &M[i];
        rear = &M[i+1];
        totalhight += getToNextHight(front, rear);
        ++i;
    }
    if(rear == NULL)
        totalhight += M[0].hight;
    else
        totalhight += rear->hight;

    return totalhight;
}

/*计算到达下一座山的高度上爬上爬下经过的高度*/
int getToNextHight(const Mount & front, const Mount &rear)
{
    if(front->right < rear->left)
        return front->hight + rear->hight;
    else
        return ABS(front->hight - rear->hight);
}









