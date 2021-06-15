#pragma once
#include <unordered_map>
#include <string>
#include <list>
#include <iostream>

class XMLExpression
{
private:
    /* data */
public:
    //virtual double calculate_expr() = 0;
    //virtual std::string to_string_expr() = 0;
    friend std::istream& operator>>(std::istream& is, const XMLExpression& e);
    virtual ~XMLExpression() {};
};

class SingleTag : XMLExpression
{
protected:
    std::unordered_map<std::string, std::string> attributes_;
public:
    SingleTag(/* args */);
    ~SingleTag();
};

class DoubleTag : SingleTag
{
private:
    std::list<::XMLExpression> subexpressions_;
public:
    DoubleTag(/* args */);
    ~DoubleTag();
};

class Text : XMLExpression
{
protected:
    std::string content_;
public:
    Text(/* args */);
    ~Text();
};


