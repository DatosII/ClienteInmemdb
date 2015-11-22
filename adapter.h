#ifndef ADAPTER_H
#define ADAPTER_H

#include <iostream>
#include "wrapperxml.h"
#include "rapidxml/rapidxml.hpp"

class Adapter{
private:
    std::string _protocol;
    WrapperXml * _wrapperXml;
public:
    Adapter();
    void setProtocol(std::string pProtocol);
    std::string createScheme(std::string pMsg);
};

#endif // ADAPTER_H
