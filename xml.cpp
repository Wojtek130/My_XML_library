#include "xml.hpp"
#include <istream>

SingleTag::SingleTag(/* args */)
{
}

SingleTag::~SingleTag()
{
}

DoubleTag::DoubleTag(/* args */)
{
}

DoubleTag::~DoubleTag()
{
}

std::istream& operator>>(std::istream& is, const XMLExpression& e)
{
    std::string input;
    is>>input;
    std::cout<<input;
}