#include "ini_parser.h"


namespace qh
{
    INIParser::INIParser()
    {
        sections = 1;
        Items = new std::unordered_map<std::string,std::string>[1];
    }

    INIParser::~INIParser()
    {
        delete [] Items;
    }

    bool INIParser::Parse(const char* ini_data, size_t ini_data_len, const std::string& line_seperator, const std::string& key_value_seperator)
    {
        if(ini_data == NULL)
            return false;

        if(strlen(ini_data) < ini_data_len)
            ini_data_len = strlen(ini_data);

        Tokener token(ini_data, ini_data_len);
        char line_sep, key_value_sep;
        std::string key;
        std::string value;
        if(line_seperator.size() == 1 && key_value_seperator.size() == 1)
        {
            line_sep = line_seperator[0];
            key_value_sep = key_value_seperator[0];
            while(!token.isEnd())
            {
                key = token.nextString(key_value_sep);

                const char* curpos = token.getCurReadPos();
                int nreadable = token.getReadableSize();

                value = token.nextString(line_sep);

                if (value.empty() && nreadable > 0) 
                {
                    assert(curpos);
                    value.assign(curpos, nreadable);
                    Items[0].insert({key, value});
                    break;
                }
                Items[0].insert({key, value});

            }

        }
        return true;
    }

    const std::string& INIParser::Get(const std::string& key, bool* found)
    {
        std::string empty;
        auto got = Items[0].find(key);
        if(got != Items[0].end())
            return got->second;
        else
            return empty;
    }

    const std::string& INIParser::Get(const std::string& section, const std::string& key, bool* found)
    {

    }
}
