#include "adapter.h"

Adapter::Adapter(){
    client = new ClientInmemdb("172.26.105.77",8000);
}

std::string Adapter::createScheme(std::string pMsg){
    xml_document <> document;
    if(_protocol=="content-type: xml"){
        _wrapperXml->writeCreateSchemeXml(pMsg, document);

    }

    return "000";
}

void Adapter::setProtocol(std::string pProtocol){
    this->_protocol = pProtocol;
}
