/*************************************************************************
	> File Name: Mountain.cpp
	> Author: YinWen
	> Mail: yinwenatbit@163.com
	> Created Time: 2015年09月03日 星期四 13时52分47秒
 ************************************************************************/

#include "Mountain.h"
#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include "sort.h"
#include "DisjSet.h"

using namespace std;

typedef struct Mountain* Mount;

int readFromStr(const char *strptr, Mount & M);
int getnumber(const char *&ptr);
void comboMountains(DisjSet &S, Mount &M, int num);

/*count the distance*/
int resolve(const char * originstr)
{
    Mount mounts=NULL;
    int totalMounts = readFromStr(originstr, mounts);

    QuickSort(mounts, totalMounts);
    DisjSet S;

    int length = 0;
    /*initialize Disjoint Set and calc the length*/
    for(int i=0; i<totalMounts; i++)
    {
        S[i] = -mounts[i].hight;
        if(length<mounts[i].right)
            length = mounts[i].right;
    }

    /*combine the mountains that get along with*/
    comboMountains(S, mounts, totalMounts);
    
    std::unordered_map<int, int> uniqueMounts;
    
    /*add mountains to map, the hightest mountain in each gather remains*/
    for(int i=0; i<totalMounts; i++)
    {
        SetType root = Find(i, S);
        uniqueMounts.insert({root, S[root]});
    }

    int totalhight =0;
    for(auto &x: uniqueMounts)
        totalhight += x.second;

    int distance = length -2*totalhight;
    return distance;
}

/*read mountains from str*/
int readFromStr(const char *strptr, Mount & M)
{
    int num;

    std::string str = "";

    num = getnumber(strptr);
    M = new struct Mountain[num];

   for(int i=0; i<num; i++)
   {
       M[i].left = getnumber(strptr);
       M[i].right = getnumber(strptr);
       M[i].hight = getnumber(strptr);
   }

    return num;
}


/*输入数字开始的地址，返回数字，并且修改指针指向下一个开始的数字*/
int getnumber(const char *&ptr)
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

void comboMountains(DisjSet &S, Mount &M, int num)
{
    SetType root1, root2;
    for(int i=0; i<num-1; i++)
    {
        if(M[i].left == M[i+1].left)
            SetUnion(S, Find(i, S),Find(i+1, S));

        if(M[i].right <= M[i+1].left)
            SetUnion(S, Find(i, S),Find(i+1, S));

    }
}
