#ifndef WRAPPERXML_H
#define WRAPPERXML_H

#include<fstream>
#include<sstream>
#include <iostream>
#include <rapidxml/rapidxml.hpp>

class WrapperXml{
private:

public:
    WrapperXml();
    void readXml(const char *pRuta);
};

#endif // WRAPPERXML_H
