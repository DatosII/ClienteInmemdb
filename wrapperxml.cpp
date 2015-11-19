#include "wrapperxml.h"

WrapperXml::WrapperXml(){

}

void WrapperXml::readXml(const char* pRuta){
    std::ifstream file(pRuta);
    std::stringstream buffer;
    if(file){
        buffer << file.rdbuf();
        file.close();

        std::string content = buffer.str();
        //std::cout << "--------------------------" << std::endl;
        std::cout << content << std::endl;
        //std::cout << "--------------------------" << std::endl;


        rapidxml::xml_document<> xml;
        xml.parse<0>((char*)&content[0]);
        rapidxml::xml_node<> * root_node = xml.first_node("root");
        if(root_node == 0)
            return ;
        std::cout << "Found node: " << root_node->name() << std::endl;

        rapidxml::xml_node<> * resources_node = root_node->first_node("ApplicationSettings");
        std::cout << "Found node: " << resources_node->name() << std::endl;

        rapidxml::xml_attribute<> * path_attribute = resources_node->first_attribute("option_b");
        std::cout << path_attribute->name() << std::endl;
    }
}
