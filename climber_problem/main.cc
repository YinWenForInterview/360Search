#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <cstdlib>

#define H_ARRAYSIZE(a) \
    ((sizeof(a) / sizeof(*(a))) / \
    static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))



#define ABS(x) (((x)>0) ? (x) : (-(x)))

struct Mountain
{
	int left;
	int right;
	int hight;
};

using namespace std;

int resolve(const char * originstr);

int getDistance(const char * ptr, int totalMounts); 
int getNumber(const char *&ptr);
void getMount(struct Mountain & M, const char *& strptr);
int getToNextHight(const struct Mountain & front, const struct Mountain &rear);


int main(int argc, char* argv[]) 
{
    const char* input[] = {
        "3\n1,3,2\n2,4,4\n6,7,5\n", //The giving example
        "1\n1,2,1\n",
        "2\n1,2,1\n2,3,2",
        "3\n1,2,1\n2,3,2\n3,6,1",
        "4\n1,2,1\n2,3,2\n3,6,1\n5,8,2",
        "5\n1,2,1\n2,3,2\n3,6,1\n5,8,2\n7,9,1",
        "1\n0,1,1",
        "2\n0,1,1\n2,4,3",
        "3\n0,1,1\n2,4,3\n3,5,1",
        "4\n0,1,1\n2,4,3\n3,5,1\n5,6,1",
        "5\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3",
        "",
        "0\n",
        //TODO please add more test case here
        };
    int expectedSteps[] = {25, 4, 7, 10, 14, 15, 3, 12, 13, 14, 20, 0, 0};
    

    for (size_t i = 0; i < H_ARRAYSIZE(input); ++i)
    {
        assert(resolve(input[i]) == expectedSteps[i]);
    }
    return 0;
}




/*输入字符串，返回爬山经过的总长度*/
int resolve(const char * originstr)
{
    if(*originstr == '\0')
        return 0;

    int totalMounts = getNumber(originstr);
    
    if(totalMounts == 0)
        return 0;

    int distance = getDistance(originstr, totalMounts); 

    return distance;
}

void getMount(struct Mountain & M, const char *& strptr)
{
    M.left = getNumber(strptr);
    M.right = getNumber(strptr);
    M.hight = getNumber(strptr);
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

/*计算爬山经过的总距离*/
int getDistance(const char * ptr, int totalMounts)
{

    int i=0;
    int totalhight= 0;
    int totaldistance =0;
    struct Mountain front;
    struct Mountain rear = {-1,-1,-1};    

    getMount(front, ptr);

    /*jump to first mountain hight*/
    totalhight += front.hight;

    while(i<totalMounts -1)
    {
        getMount(rear, ptr);
        totalhight += getToNextHight(front, rear);
        front = rear;
        ++i;
    }
    if(rear.left == -1)
        totaldistance = totalhight+ front.hight +front.right;
    else
        totaldistance = totalhight+ rear.hight +rear.right;

    return totaldistance;
}

/*计算到达下一座山的高度上爬上爬下经过的高度*/
int getToNextHight(const struct Mountain & front, const struct Mountain &rear)
{
    if(front.right < rear.left)
        return front.hight + rear.hight;
    else
        return ABS(front.hight - rear.hight);
}









