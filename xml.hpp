#pragma once
#include <unordered_map>
#include <string>
#include <list>
#include <iostream>
#include "manipulators.hpp"

class XMLExpression
{
        
private:
  
public:
    //XMLExpression() {};
    virtual ~XMLExpression() {};
    friend std::ostream& operator<<(std::ostream& os,XMLExpression* e);
    virtual void print(std::ostream& os)  const =0;
};

class SingleTag : public XMLExpression
{

protected:
    std::unordered_map<std::string, std::string> attributes_;
    std::string name_;
public:
    SingleTag(std::string name, std::unordered_map<std::string, std::string> attributes);
    ~SingleTag();
    virtual void print(std::ostream& os) const;

};

class DoubleTag : public SingleTag
{
protected:
    std::list<::XMLExpression*> subexpressions_;

public:
    DoubleTag(std::string name, std::list<::XMLExpression*> subexpressions, std::unordered_map<std::string, std::string> attributes);
    ~DoubleTag();
    //friend std::ostream& operator<<(std::ostream& os, const DoubleTag& dt);
    virtual void print(std::ostream& os) const;

};

class RootTag : public DoubleTag
{
private:
    /* data */
public:
    RootTag(std::string name, std::list<::XMLExpression*> subexpressions, std::unordered_map<std::string, std::string> attributes);
    ~RootTag();
    virtual void print(std::ostream& os)  const;
   // friend std::ostream& operator<<(std::ostream& os, const RootTag& rt);

};



class Text : public XMLExpression
{
protected:
    std::string content_;
public:
    Text(std::string content);
    ~Text();
    //friend std::ostream& operator<<(std::ostream& os, const Text& te);
    virtual void print(std::ostream& os) const;

};


void tag_begin(std::ostream& os, const std::string& name, const std::unordered_map<std::string, std::string>& attributes);
void tag_end(std::ostream& os, const std::string& name);