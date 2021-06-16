#include <iostream>
#include <string>
#include "manipulators.hpp"
#include "xml.hpp"






int main()
{
    
    //std::cin>>cleanline;
    //std::cin>>ignore(3);
    //std::cout<<amp;
    //std::cout<<quot;
    //std::cout<<attr("my_var", "5");
    //std::cin>>e1;
    std::unordered_map<std::string, std::string> u2 = 
    {
        {"date_1","1.02.2021"},
        {"date_2","22.05.2021"},
    };
    std::list<XMLExpression*> empty_list;
    std::unordered_map<std::string, std::string> empty_map;
    DoubleTag *dt3 = new DoubleTag("Forwarded", std::list<XMLExpression*>{new Text("ann@email.com"),}, empty_map);
    SingleTag *st1 = new SingleTag("deadline", u2);
    DoubleTag *dt1 = new DoubleTag("Topic", std::list<XMLExpression*>{new Text("cpp")}, empty_map);
    DoubleTag *dt2 = new DoubleTag("From", std::list<XMLExpression*>{new Text("john@email.com"), dt3}, empty_map);

    std::list<XMLExpression*> l = { new Text("Janet"), dt1, dt2, st1};
    //std::list<XMLExpression*> l2 = { dt3};

    //DoubleTag t1 = DoubleTag("to", l, empty_map);
    //std::cout<<t1;
    std::unordered_map<std::string, std::string> u = 
    {
        {"RED","#FF0000"},
        {"GREEN","#00FF00"},
        {"BLUE","#0000FF"}
    };
    XMLExpression* e1 = new RootTag("parent", l,std::unordered_map<std::string, std::string>{{"RED","#FF0000"},});
    std::cout<<e1;

    delete e1;    
}