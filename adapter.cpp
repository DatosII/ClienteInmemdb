#include "adapter.h"

Adapter::Adapter(){

}

std::string Adapter::createScheme(std::string pMsg){
    xml_document <> document;
    if(_protocol=="content-type: xml"){
        _wrapperXml->writeCreateSchemeXml(pMsg, document);
        std::string xml_as_string;
        rapidxml::print(std::back_inserter(xml_as_string), document);
        std::cout << xml_as_string << std::endl;

        //_wrapperXml->prueba();

        // Save to file
        std::ofstream file_stored ("/home/jairodaniel_23/r.xml");
        file_stored << document;
        file_stored.close();
        document.clear();
    }

    return "000";
}

void Adapter::setProtocol(std::string pProtocol){
    this->_protocol = pProtocol;
}
