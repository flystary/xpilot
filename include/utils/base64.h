#ifndef BASE64_H
#define BASE64_H

#pragma once
#include <string>

class CBase64
{
public:
    CBase64();
    ~CBase64();

    std::string Encode(const char* Data, int DataByte);

    std::string Decode(const char* Data, int DataByte, int& OutByte);
};

#endif
