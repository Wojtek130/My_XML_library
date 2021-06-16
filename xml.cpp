#include "xml.hpp"
#include <iostream>

XMLExpression::XMLExpression(std::string root_name, std::list<::XMLExpression> root_subexpressions,std::unordered_map<std::string, std::string> root_attributes)
{
    root_name_ = root_name;
    root_subexpressions_ = root_subexpressions;
    root_attributes_ = root_attributes;
}

XMLExpression::XMLExpression() {}
/*
XMLExpression::~XMLExpression()
{
    delete root;
}
*/
SingleTag::SingleTag() 
{

}

SingleTag::SingleTag(std::string name, std::unordered_map<std::string, std::string> attributes)
{
    name_ = name;
    attributes_ = attributes;
}

SingleTag::~SingleTag()
{
}

DoubleTag::DoubleTag(std::string name, std::list<::XMLExpression> subexpressions, std::unordered_map<std::string, std::string> attributes)
{
    name_ = name;
    subexpressions_ = subexpressions;
    attributes_ = attributes;
}

DoubleTag::~DoubleTag()
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
    
   std::cout<<"hopla2\n";
    tag_begin(os, e.root_name_, e.root_attributes_);
    for (const auto& expr : e.root_subexpressions_ )
    {
        os<<'\t';
        os<<expr;
    }
    tag_end(os, e.root_name_);
    return os;
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
std::ostream& operator<<(std::ostream& os, const Text& te)
{
    std::cout<<"hopla\n";
    os<<te.content_;
    return os;
}

std::ostream& operator<<(std::ostream& os, const SingleTag& st)
{
    os<<lt;
    os<<st.name_;
    for (auto p : st.attributes_)
    {
        os<<attr(p.first, p.second);
    }
    os<<slash;
    os<<gt;
    os<<std::endl;
    return os;
}

std::ostream& operator<<(std::ostream& os, const DoubleTag& dt)
{
    tag_begin(os, dt.name_, dt.attributes_);
    for (const auto& expr : dt.subexpressions_ )
    {
        os<<'\t';
        os<<expr;
    }
    tag_end(os, dt.name_);
    return os;
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

