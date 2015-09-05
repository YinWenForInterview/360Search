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
    string line;
    if(!strcmp(line.c_str(), ""))
        assert(true);
    else
        assert(false);
}

void test3()
{
    string line("");
    assert(line.size() == 0);

}

void test4()
{
    string line2("bye bye");
    if(!strcmp(line2.c_str(), "bye bye"))
        assert(true);
    else
        assert(false);
}

void test5()
{
    char array[20] = "say hello";
    string line3(array, 6);
    if(!strncmp(array, line3.data(), 6))
        assert(true);
    else
        assert(false);
}

void test6()
{
    string lineA("how are you?");
    string lineB(lineA);
    if(!strcmp(lineA.c_str(), lineB.c_str()))
        assert(true);
    else
        assert(false);
}

void test7()
{
    string lineA("8527");
    string lineB = lineA;
    if(!strcmp(lineA.data(), lineB.data()))
        assert(true);
    else
        assert(false);

}

void test8()
{

    string lineA("8527");
    string lineB = "8527";
    if(!strcmp(lineA.data(), lineB.data()))
        assert(true);
    else
        assert(false);
}

void test9()
{

    string lineA("8527");
    string lineB = "";
    lineB = lineA;
    if(!strcmp(lineA.data(), lineB.data()))
        assert(true);
    else
        assert(false);
}

void test10()
{
    
    string lineA("");
    string lineB = "3432";
    lineB = lineA;
    if(!strcmp(lineA.data(), lineB.data()))
        assert(true);
    else
        assert(false);
}

void test11()
{
    string line6("show me the money");
    if(*line6[3] == 'w')
        assert(true);
    else
        assert(false);

}
void test12()
{
    string line7("operation cwal");
    if(line7[100] == NULL)
        assert(true);
    else 
        assert(false);
}

void test13()
{
    char * ptr =NULL;
    string line(ptr);
    assert(line.size() == 0);
}

void test14()
{
    char * ptr =NULL;
    string line(ptr, 6);
    assert(line.size() == 0);
}

void test15()
{
    char array[20] = "good bye";
    string line(array, -1);
    assert(line.size() == 8);
}

void test16()
{
    char array[20] = "good bye";
    string line(array, 0);
    assert(line.size() == 0);

}

void test17()
{
    
    char array[20] = "good bye";
    string line(array, 30);
    assert(line.size() == 8);
}

void test18()
{
    string line8("blacksheep wall");
    if(line8[-10] == NULL)
        assert(true);
    else 
        assert(false);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();
    test12();
    test13();
    test14();
    test15();
    test16();
    test17();
    test18();
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
    //TODO 单元测试写法请参考INIParser那个项目，不要写一堆printf，要用assert进行断言判断。

#ifdef WIN32
    system("pause");
#endif

	return 0;
}

