#pragma once
#include <unordered_map>
#include <string>
#include <list>
#include <iostream>
#include "manipulators.hpp"

class XMLExpression
{
        
private:
    std::string root_name_;
    std::list<::XMLExpression> root_subexpressions_;
    std::unordered_map<std::string, std::string> root_attributes_;

public:
    XMLExpression();
    XMLExpression(std::string root_name, std::list<::XMLExpression> root_subexpressions, std::unordered_map<std::string, std::string> root_attributes);
    ~XMLExpression() {};
    friend std::ostream& operator<<(std::ostream& os, const XMLExpression& e);
};

class SingleTag : public XMLExpression
{

protected:
    std::unordered_map<std::string, std::string> attributes_;
    std::string name_;
    friend std::ostream& operator<<(std::ostream& os, const SingleTag& st);
public:
    SingleTag(std::string name, std::unordered_map<std::string, std::string> attributes);
    SingleTag();
    ~SingleTag();

};

class DoubleTag : public SingleTag
{
private:
    std::list<::XMLExpression> subexpressions_;
public:
    DoubleTag(std::string name, std::list<::XMLExpression> subexpressions, std::unordered_map<std::string, std::string> attributes);
    ~DoubleTag();
    friend std::ostream& operator<<(std::ostream& os, const DoubleTag& dt);
};

class Text : public XMLExpression
{
protected:
    std::string content_;
public:
    Text(std::string content);
    ~Text();
    friend std::ostream& operator<<(std::ostream& os, const Text& te);
};


void tag_begin(std::ostream& os, const std::string& name, const std::unordered_map<std::string, std::string>& attributes);
void tag_end(std::ostream& os, const std::string& name);