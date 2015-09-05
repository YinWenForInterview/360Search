#include "ini_parser.h"

#include <string.h>
#include <assert.h>

void test1()
{
    const char* ini_text= "a=1\nb=2\n"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "\n", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}

void test2()
{
    const char* ini_text= "a=1||b=2||c=3"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", "=")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}

void test3()
{
    const char* ini_text= "||||a:1||b:2||||c:3||||||"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", ":")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}

void test4()
{
    /*end with 7 | */
    const char* ini_text= "||||a:1||b:2||||c:3|||||||"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", ":")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}

void test5()
{
    /*blank*/
    const char* ini_text= "         ||    ||a:1||b:2||      ||c:3||    |||||          "; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", ":")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}
    

void test6()
{
    const char* ini_text= "||||a:1||b:2||||c:3|||||||"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, 100, "||", ":")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}

void test7()
{
    /* lenght 0 */
    const char* ini_text= "||||a:1||b:2||||c:3|||||||"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, 0, "||", ":")) {
        assert(true);
    }
    else
        assert(false);

    const std::string& a = parser.Get("a", NULL);
    assert(a == "");

    std::string b = parser.Get("b", NULL);
    assert(b == "");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}


void test8()
{
    /* no line_sep */
    const char* ini_text= "||||a:1||b:2||||c:3|||||||"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, 10, "", ":")) {
        assert(true);
    }
    else
        assert(false);

    const std::string& a = parser.Get("a", NULL);
    assert(a == "");

    std::string b = parser.Get("b", NULL);
    assert(b == "");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}

void test9()
{
    /* no key_value_seperator_sep */
    const char* ini_text= "||||a:1||b:2||||c:3|||||||"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, 10, "||", "")) {
        assert(true);
    }
    else
        assert(false);

    const std::string& a = parser.Get("a", NULL);
    assert(a == "");

    std::string b = parser.Get("b", NULL);
    assert(b == "");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}


void test10()
{
    /*no key_value_seperator*/
    const char* ini_text= "         ||    ||a||b2||      ||c3||    |||||          "; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", ":")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "");

    std::string b = parser.Get("b", NULL);
    assert(b == "");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}
    

void test11()
{
    /*NULL pointer*/
    const char* ini_text= NULL; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, 10, "||", ":")) {
        assert(true);
    }
    else
        assert(false);

    const std::string& a = parser.Get("a", NULL);
    assert(a == "");

    std::string b = parser.Get("b", NULL);
    assert(b == "");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}


void test12()
{
    /*all blank*/
    const char* ini_text= "                  "; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", ":")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "");

    std::string b = parser.Get("b", NULL);
    assert(b == "");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}


void test13()
{
    /*all blank with sep*/
    const char* ini_text= "      ||            "; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", ":")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "");

    std::string b = parser.Get("b", NULL);
    assert(b == "");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}
    
void test14()
{
    /*nonsense data*/
    const char* ini_text= " 1wdfv  sadxc3 x  "; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", ":")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "");

    std::string b = parser.Get("b", NULL);
    assert(b == "");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}


void test15()
{
    /*without line_sep*/
    const char* ini_text= "a:1"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", ":")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}

void test16()
{
    /*blank equal to 2*/
    const char* ini_text= "a:1|| :2"; 
    qh::INIParser parser;
    if (!parser.Parse(ini_text, strlen(ini_text), "||", ":")) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get(" ", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "");
}

void test17()
{
    std::string file("./test.txt");
    qh::INIParser parser;
    if (!parser.Parse(file)) {
        assert(false);
    }

    const std::string& a = parser.Get("a", NULL);
    assert(a == "1");

    std::string b = parser.Get("b", NULL);
    assert(b == "2");

    const std::string& c = parser.Get("c", NULL);
    assert(c == "3");
}



int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好

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

    return 0;
}


