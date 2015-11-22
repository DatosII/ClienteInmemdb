#ifndef ADAPTER_H
#define ADAPTER_H

#include <iostream>
#include "wrapperxml.h"
#include "wrapperjson.h"
#include "rapidxml/rapidxml.hpp"
#include "clientinmemdb.h"

class Adapter{
private:
    std::string _protocol;
    WrapperXml * _wrapperXml;
    ClientInmemdb* client;
    WrapperJson * _wrapperJson;
public:
    Adapter();
    void setProtocol(std::string pProtocol);
    std::string createScheme(std::string pMsg);
};

#endif // ADAPTER_H
