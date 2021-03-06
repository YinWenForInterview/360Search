#include "qh_string.h"

#include <string.h>

namespace qh
{
    // TODO 将在这里写实现代码

    string::string()
    {
        len_ =0;
        data_ = new char[1];
        data_[0] = '\0';

    }

    string::string( const char* s )
    {
        if(s == NULL)
        {
            len_ = 0;
            data_ = new char[1];
            data_[0] = '\0';
        }
        else
        {
            len_ = strlen(s);
            data_ = new char[len_ +1];
            strcpy(data_, s);
        }
    }

    string::string( const char* s, size_t len )
    {
        if(s == NULL )
        {
            len_ = 0;
            data_ = new char[1];
            data_[0] = '\0';
        }
        else
        {
            if(len > strlen(s))
            {
                len_ = strlen(s);
                data_ = new char[len_ +1];
                strcpy(data_, s);
            }
            else
            {
                len_ = len;
                data_ = new char[len_+1];
                strncpy(data_, s, len_);
                data_[len_] = '\0';
            }
        }
    }
    string::string( const string& rhs )
    {
        len_ = rhs.len_;
        data_ = new char[len_+1];
        strcpy(data_, rhs.data_);
    }

    string& string::operator=( const string& rhs )
    {
        if(this == &rhs)
            return *this;

        delete [] data_;
        len_ = rhs.len_ ;
        data_ = new char[len_ +1];
        strcpy(data_, rhs.data_);
        return *this;
    }

    string::~string()
    {
        delete [] data_;
    }

    size_t string::size() const
    {
        return len_;
    }

    const char* string::data() const
    {
        return data_;
    }

    const char* string::c_str() const
    {
        return data_;
    }

    char* string::operator[]( size_t index )
    {
        if(index>len_-1)
            return NULL;
        return &data_[index];
    }
}
