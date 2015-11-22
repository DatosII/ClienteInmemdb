#include "adapter.h"

Adapter::Adapter(){

}

std::string Adapter::createScheme(std::string pMsg){
    xml_document <> document;
    if(_protocol=="content-type: xml"){
        _wrapperXml->writeCreateSchemeXml(pMsg, document);

        std::string xmlString;
        rapidxml::print(std::back_inserter(xmlString), document);
        std::cout << xmlString << std::endl;
        //Guardar el archivo
//        std::ofstream file_stored ("/home/jairodaniel_23/xmlAEnviar.xml");
//        file_stored << document;
//        file_stored.close();
//        document.clear();
    }
    else{
        _wrapperJson->writeCreateSchemeJson(pMsg);
    }
    return "000";
}

void Adapter::setProtocol(std::string pProtocol){
    this->_protocol = pProtocol;    
    char* pMsg = (char * ) &_protocol[0u];
    client = new ClientInmemdb("172.26.105.77",8000, pMsg);
//    client->setMsg();
}
