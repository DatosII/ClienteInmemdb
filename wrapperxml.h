#ifndef WRAPPERXML_H
#define WRAPPERXML_H

#include<fstream>
#include<sstream>
#include <iostream>
#include <rapidxml/rapidxml.hpp>
#include <rapidxml/rapidxml_print.hpp>
using namespace rapidxml;

class WrapperXml{
private:
public:
    WrapperXml();
    void readXml(const char *pRuta, const char *pRoot, const char *pSon);
    void writeXml();
};

#endif // WRAPPERXML_H
