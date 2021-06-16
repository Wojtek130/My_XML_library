#include "manipulators.hpp"

std::istream &cleanline(std::istream &is)
{
    while(is && is.get() != '\n')
    {
    }
    return is;
}
/*
std::istream &addspace(std::istream &is)
{
    char c = is.get() != '\n';
    while(is && c != '\n')
    {
        is<<c;

    }
    return is;
}
*/
std::ostream &amp(std::ostream &os)
{
    os<<"&";
    return os;
}

std::ostream &lt(std::ostream &os)
{
    os<<"<";
    return os;
}

std::ostream &gt(std::ostream &os)
{
    os<<">";
    return os;
}

std::ostream &quot(std::ostream &os)
{
    os<<"\"";
    return os;
}

std::ostream &slash(std::ostream &os)
{
    os<<"/";
    return os;
}

std::istream& operator>>(std::istream&is, const ignore &ig)
{ 
    int num_chars_delete = ig.x_;
    while(is && is.get() != '\n' && num_chars_delete > 0)
    {
        num_chars_delete--;
    }
    return is;
}

std::ostream& operator<<(std::ostream&os, const attr &at)
{ 
    os<<" "<<at.key_<<"="<<quot<<at.value_<<quot;
    return os;
}