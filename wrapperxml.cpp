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
/**
 * @brief WrapperXml::writeXml, metodo para escribir un xml
 * @param pRuta, directorio en el que se guardara el documento
 * @param pRoot, raiz del documento
 * @param pSon, hijo del documento
 */
void WrapperXml::writeCreateSchemeXml(std::string pMsg, xml_document<> &pDocument){
    xml_node<>* decl = pDocument.allocate_node(node_declaration);
    decl->append_attribute(pDocument.allocate_attribute("version", "1.0"));
    decl->append_attribute(pDocument.allocate_attribute("encoding", "utf-8"));
    pDocument.append_node(decl);

    xml_node<>* root = pDocument.allocate_node(node_element, "scheme");
    pDocument.append_node(root);

    std::istringstream pBuffer(pMsg);
    std::string subString;
    pBuffer >> subString;
    xml_node<>* childSN = pDocument.allocate_node(node_element, "schameName");
    childSN->value(strdup(subString.c_str()));
    root->append_node(childSN);
    pBuffer >> subString;
    xml_node<>* childR = pDocument.allocate_node(node_element, "RAID");
    childR->value(strdup(subString.c_str()));
    root->append_node(childR);

    while(pBuffer){
        pBuffer >> subString;
        if(subString=="#")
            break;
        else{
            xml_node<>* childD = pDocument.allocate_node(node_element, "data");
            xml_node<>* childDT = pDocument.allocate_node(node_element, "dataType");
            childDT->value(strdup(subString.c_str()));
            childD->append_node(childDT);
            pBuffer >> subString;
            xml_node<>* childDL = pDocument.allocate_node(node_element, "dataLenght");
            childDL->value(strdup(subString.c_str()));
            childD->append_node(childDL);
            pBuffer >> subString;
            xml_node<>* childDN= pDocument.allocate_node(node_element, "dataName");
            childDN->value(strdup(subString.c_str()));
            childD->append_node(childDN);
            root->append_node(childD);
        }
    }

}

