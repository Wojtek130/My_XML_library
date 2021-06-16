#include "xml.hpp"
#include <iostream>




SingleTag::SingleTag(std::string name, std::unordered_map<std::string, std::string> attributes)
{
    name_ = name;
    attributes_ = attributes;
}

SingleTag::~SingleTag()
{
}

DoubleTag::DoubleTag(std::string name, std::list<::XMLExpression*> subexpressions, std::unordered_map<std::string, std::string> attributes) : SingleTag(name, attributes)
{
    subexpressions_ = subexpressions;
}

DoubleTag::~DoubleTag()
{
}

RootTag::RootTag(std::string name, std::list<::XMLExpression*> subexpressions, std::unordered_map<std::string, std::string> attributes) : DoubleTag(name, subexpressions, attributes)
{
}

RootTag::~RootTag()
{
}

Text::Text(std::string content)
{
    content_ = content;
}

Text::~Text()
{
}

std::ostream& operator<<(std::ostream& os, const XMLExpression& e)
{
  // std::cout<<"hopla5\n";
    e.print(os);
    return os;
}
/*
std::ostream& operator<<(std::ostream& os, const RootTag& rt)
{
   std::cout<<"hopla6\n";
    
    rt.print(os);
    return os;
}*/



void RootTag::print(std::ostream& os) const
{
    
  // std::cout<<"hopla2\n";
    tag_begin(os, this->name_, this->attributes_);
    for (const auto& expr : this->subexpressions_ )
    {
        os<<'\t';
        os<<expr;
    }
    tag_end(os, this->name_);
}

/*
std::istream& operator>>(std::istream& is, const XMLExpression& e)
{
    std::string input;
    std::list<std::string> expr;
    while (is && (is >> input)) 
    {
        expr.push_back(input);
    }
    for(std::string i : expr) 
    {
        std::cout << i << "\n";
    }
    std::cout << "\n";
        
    return is;
}
*/
void Text::print(std::ostream& os) const
{
    //std::cout<<"hopla\n";
    os<<this->content_;
}

void SingleTag::print(std::ostream& os) const
{
   // std::cout<<"hopla3\n";
    os<<lt;
    os<<this->name_;
    for (auto p : this->attributes_)
    {
        os<<attr(p.first, p.second);
    }
    os<<slash;
    os<<gt;
    os<<std::endl;
}

void DoubleTag::print(std::ostream& os) const
{
    //std::cout<<"hopla4\n";
    tag_begin(os, this->name_, this->attributes_);
    for (const auto& expr : this->subexpressions_ )
    {
        os<<'\t';
        os<<expr;
    }
    tag_end(os, this->name_);
}

void tag_begin(std::ostream& os, const std::string& name, const std::unordered_map<std::string, std::string>& attributes)
{
    os<<lt;
    os<<name;
    for (auto p : attributes)
    {
        os<<attr(p.first, p.second);
    }
    os<<gt;
    os<<std::endl;
}

void tag_end(std::ostream& os, const std::string& name)
{
    os<<lt;
    os<<name;
    os<<slash;
    os<<gt;
    os<<std::endl;
}

