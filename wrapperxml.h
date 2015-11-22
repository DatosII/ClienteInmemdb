#ifndef WRAPPERXML_H
#define WRAPPERXML_H

#include<fstream>
#include<sstream>
#include <iostream>
#include <string.h>
#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_print.hpp>
using namespace rapidxml;

class WrapperXml{
private:
    char *cstr;
public:
    WrapperXml();
    void readXml(const char *pRuta, const char *pRoot, const char *pSon);
    void writeCreateSchemeXml(std::string pMsg, xml_document<> &pDocument);
};

#endif // WRAPPERXML_H
