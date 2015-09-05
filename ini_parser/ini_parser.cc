#include "ini_parser.h"
#include <cstring>
#include <stdio.h>



std:: string getKey(const char *& startPos, const char * line_sep, const char * key_value_sep)
{
    std::string get("");
    const char * front;
    const char * rear;
    /*前面还有line分隔符*/
    while(strstr(startPos, line_sep) == startPos)
        startPos += strlen(line_sep);

    rear = strstr(startPos, key_value_sep);
    if(rear == NULL)
        return get;

    get.assign(startPos, rear - startPos);
    startPos = rear + strlen(key_value_sep);
    return get;
}


std:: string getValue(const char *& startPos, const char * line_sep, const char * key_value_sep)
{
    std::string get("");
    const char * rear;
    rear = strstr(startPos, line_sep);
    /*到达了字符串尾部*/
    if(rear == NULL)
    {
        get.assign(startPos);
        startPos += strlen(startPos);
    }
    else
    {
        get.assign(startPos, rear - startPos);
        startPos = rear +strlen(line_sep);
    }
    return get;
}


namespace qh
{
    INIParser::INIParser()
    {
        sections = 1;
        Items = new std::unordered_map<std::string,std::string>[1];
        empty = "";
    }

    INIParser::~INIParser()
    {
        delete [] Items;
    }

    bool INIParser::Parse(const std::string& ini_file_path)
    {
        FILE * iniFile; 
        iniFile = fopen(ini_file_path.c_str(), "r");
        if(iniFile == NULL)
            return false;

        char temp[1024];
        int nread;
        std::string to_parser;
        while( (nread = fread(temp, 1, 1024, iniFile)) > 0)
        {
            to_parser +=std::string(temp, nread);
        }
        Parse(to_parser.c_str(), to_parser.size());
        fclose(iniFile);
        return true;
    }



    bool INIParser::Parse(const char* ini_data, size_t ini_data_len, const std::string& line_seperator, const std::string& key_value_seperator)
    {
        if(ini_data == NULL || line_seperator.size() == 0 || key_value_seperator.size() == 0)
            return false;

        if(strlen(ini_data) < ini_data_len)
            ini_data_len = strlen(ini_data);

        const char * line_sep = line_seperator.c_str();
        const char * key_value_sep = key_value_seperator.c_str();
        size_t line_sep_len = strlen(line_sep);
        size_t key_value_sep_len = strlen(key_value_sep);

        std::string key;
        std::string value;

        const char * startPos = ini_data;
        const char * endPos = ini_data;
        while(ini_data + ini_data_len > startPos)
        {
            key = getKey(startPos, line_sep, key_value_sep);
            /*到达末尾*/
            if(key.empty())
            break;

            value = getValue(startPos, line_sep, key_value_sep);
            Items[0].insert(make_pair(key, value));
        }
        return true;
    }

    const std::string& INIParser::Get(const std::string& key, bool* found)
    {
        auto got = Items[0].find(key);
        if(got != Items[0].end())
        {
            if(found != NULL)
                *found = true;
            return got->second;
        }
        else
        {
            if(found != NULL)
                *found = false;
            return this->empty;
        }
    }

    const std::string& INIParser::Get(const std::string& section, const std::string& key, bool* found)
    {
        std::string empty("");
        auto got = Items[0].find(key);
        if(got != Items[0].end())
        {
            if(found != NULL)
                *found = true;
            return got->second;
        }
        else
        {
            if(found != NULL)
                *found = false;
            return this->empty;
        }
    }
}

