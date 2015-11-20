#include "wrapperxml.h"

/**
 * @brief WrapperXml::WrapperXml, constructor de la clase
 */
WrapperXml::WrapperXml(){

}
/**
 * @brief WrapperXml::readXml, metodo para realizar la lectura del xml
 * @param pRuta, directorio del documento
 * @param pRoot, raiz del documento
 * @param pSon, hijo del documento
 */
void WrapperXml::readXml(const char* pRuta, const char* pRoot, const char* pSon){
    std::ifstream file(pRuta);
    std::stringstream buffer;
    if(file){
        buffer << file.rdbuf();
        file.close();

        std::string content = buffer.str();

        rapidxml::xml_document<> xml;
        xml.parse<0>((char*)&content[0]);
        rapidxml::xml_node<> * root_node = xml.first_node(pRoot);
        if(root_node == 0)
            return ;
        std::cout << "Found node: " << root_node->name() << std::endl;

        rapidxml::xml_node<> * resources_node = root_node->first_node(pSon);
        std::cout << "Found node: " << resources_node->name() << std::endl;
    }
}

void WrapperXml::writeXml(){
    // Write xml file =================================
    xml_document<> doc;
    xml_node<>* decl = doc.allocate_node(node_declaration);
    decl->append_attribute(doc.allocate_attribute("version", "1.0"));
    decl->append_attribute(doc.allocate_attribute("encoding", "utf-8"));
    doc.append_node(decl);

    xml_node<>* root = doc.allocate_node(node_element, "root");
    doc.append_node(root);

    xml_node<>* child = doc.allocate_node(node_element, "AplicationSettings");
    child->append_attribute(doc.allocate_attribute("option_a", "10"));
    child->append_attribute(doc.allocate_attribute("option_b", "24"));
    root->append_node(child);

    // Convert doc to string if needed
    std::string xml_as_string;
    rapidxml::print(std::back_inserter(xml_as_string), doc);

    // Save to file
    std::ofstream file_stored ("/home/jairodaniel_23/file_stored.xml");
    file_stored << doc;
    file_stored.close();
    doc.clear();
}
