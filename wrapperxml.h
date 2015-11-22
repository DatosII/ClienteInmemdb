#ifndef WRAPPERXML_H
#define WRAPPERXML_H

#include<fstream>
#include<sstream>
#include <iostream>
#include <string.h>
#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_print.hpp>

#define HASH "#"
#define DATANAME "dataType"
#define DATALENGHT "dataName"
#define DATATYPE "dataLenght"
#define DATA "data"
#define RAID "RAID"
#define SCHEMENAME "schemeName"
#define SCHEME "scheme"
#define VERSION "version"
#define NUMVERSION "1.0"
#define ENCODE "encoding"
#define TYPEENCODE "utf-8"

using namespace rapidxml;

class WrapperXml{
private:
public:
    WrapperXml();
    void readXml(const char *pRuta, const char *pRoot, const char *pSon);
    void writeCreateSchemeXml(std::string pMsg, xml_document<> &pDocument);
};

#endif // WRAPPERXML_H
