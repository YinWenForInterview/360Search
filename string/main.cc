#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "qh_string.h"
#include <cstring>

using namespace qh;
void test1()
{
    string line1;
    assert(line1.size() == 0);

}

void test2()
{
    string line2("bye bye");
    if(!strcmp(line2.c_str(), "bye bye"))
        assert(true);
    else
        assert(false);
}

void test3()
{
    char array[20] = "say hello";
    string line3(array, 6);
    if(!strncmp(array, line3.data(), 6))
        assert(true);
    else
        assert(false);
}

void test4()
{
    string lineA("how are you?");
    string lineB(lineA);
    if(!strcmp(lineA.c_str(), lineB.c_str()))
        assert(true);
    else
        assert(false);
}




int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
    //TODO 单元测试写法请参考INIParser那个项目，不要写一堆printf，要用assert进行断言判断。

#ifdef WIN32
    system("pause");
#endif

	return 0;
}

