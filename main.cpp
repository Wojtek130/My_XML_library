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
    std::list<XMLExpression> empty_list;
    std::unordered_map<std::string, std::string> empty_map;
   // std::list<XMLExpression> l = { Text("Janet"), Text("Bob") };
    //DoubleTag t1 = DoubleTag("to", l, empty_map);
    //std::cout<<t1;
    std::unordered_map<std::string, std::string> u = 
    {
        {"RED","#FF0000"},
        {"GREEN","#00FF00"},
        {"BLUE","#0000FF"}
    };
    XMLExpression* e1 = new RootTag("parent", std::list<XMLExpression>{},std::unordered_map<std::string, std::string>{{"RED","#FF0000"},});
    std::cout<<e1;
}