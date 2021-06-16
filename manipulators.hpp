#pragma once
#include <iostream>
#include <string>

std::istream &cleanline(std::istream &is);
std::ostream &amp(std::ostream &os);
std::ostream &lt(std::ostream &os);
std::ostream &gt(std::ostream &os);
std::ostream &quot(std::ostream &os);
std::ostream &slash(std::ostream &os);

struct ignore 
{
    int x_;
    friend std::istream& operator>>(std::istream&is, const ignore &ig);
    public:
        ignore (int x): x_(x){}
};


struct attr 
{
    std::string key_;
    std::string value_;
    friend std::ostream& operator<<(std::ostream&os, const attr &at);
    public:
        attr (std::string key, std::string value): key_(key), value_(value) {}
};
