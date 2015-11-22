#include "terminal.h"

/**
 * @brief Terminal::Terminal, constructor de la clase
 */
Terminal::Terminal(){
    _adapter = new Adapter();
}
/**
 * @brief Terminal::request, Metodo para ejecutar una tarea
 */
void Terminal::request(){
    selectProtocol();
    requestAux();

}

void Terminal::requestAux(){
    do{
        std::cout << MSGWELCOME << std::endl;
        std::getline (std::cin , _choice);
    }
    while( (_choice != SELECTPROTOCOL) && (_choice != CREATESCHEME) && (_choice != DELETESCHEME) && (_choice != INSERTDATASCHEME) && (_choice != DELETEDATASCHEME) && (_choice != CREATEINDEX) && (_choice != DELETEINDEX) && (_choice != EXIT));
    if(_choice == SELECTPROTOCOL){
        selectProtocol();
    }
    else if(_choice == CREATESCHEME){
        createScheme();
    }
    else if (_choice == DELETESCHEME){
        deleteScheme();
    }
    else if (_choice == INSERTDATASCHEME){
        insertDataScheme();
    }
    else if (_choice == DELETEDATASCHEME){
        deleteDataScheme();
    }
    else if (_choice == CREATEINDEX){
        createIndex();
    }
    else if (_choice == DELETEINDEX){
        deleteIndex();
    }
    else if (_choice== EXIT)
        exit(0);
    requestAux();
}

void Terminal::selectProtocol(){
    do{
        std::cout << MSGPROTOCOL << std::endl;
        std::getline (std::cin , _protocol);
    }
    while(_protocol != "content-type: xml" && _protocol != "content-type: json");
    _adapter->setProtocol(_protocol);
}

/**
 * @brief Terminal::createScheme, Metodo para crear un esquema
 */
void Terminal::createScheme(){
    do{
        std::cout << MSGNAMESCHEME << std::endl;
        std::getline (std::cin , _msgtemp);
    }
    while(_msgtemp.length() != 10);
    _msg=_msgtemp;
    do{
        std::cout << MSGNUMBERRAID << std::endl;
        std::getline (std::cin , _msgtemp);
    }
    while((_msgtemp != "0") && (_msgtemp != "1") && (_msgtemp != "5") );
    _msg=_msg+" "+_msgtemp;
    crearDato();
    _adapter->createScheme(_msg+" #");

}
/**
 * @brief Terminal::crearDato, Metodo para armar el dato del esquema
 */
void Terminal::crearDato(){
    bool state = true;
    int numData = 0;
    do{
        std::cout << MSGDATA << std::endl;
        std::getline (std::cin , _msgtemp);
        if(_msgtemp == "no")
            state=false;
        else if (checkData(_msgtemp) == true){
            _msg=_msg+" "+_msgtemp;
            std::cout << "Dato correcto" << std::endl;
            numData++;
        }
        else{
            std::cout << "Dato incorrecto" << std::endl;
            numData++;
        }
    }
    while(state == true && numData !=0 );

}
/**
 * @brief Terminal::checkData, Metodo auxiliar para verificar que el dato es correcto
 * @param pMsg
 * @return
 */
bool Terminal::checkData(std::string pMsg){
    int condition=-1;
    std::istringstream pBuffer(pMsg);
    std::string pArray[4];
    while (pBuffer) {
        condition++;
        std::string subString;
        pBuffer >> subString;
        pArray[condition]=subString;
    }
    if(checkStringToInt(pArray[1]) == true && pArray[2].length()==10){
        if(((pArray[0]=="i" || pArray[0]=="f") && pArray[1] == "4") || (pArray[0]=="s" || pArray[0]=="j"))
            return true;
        else
            return false;
    }
    else
        return false;
}
/**
 * @brief Terminal::checkStringToInt, Metodo para convertir string a int
 * @param pString, dato a convertir
 * @return, true si convierte el dato, false en caso contrario
 */
bool Terminal::checkStringToInt(std::string pString){
    bool cond=true;
    try{
        std::stoi(pString);
    }
    catch (std::invalid_argument){
        cond = false;
    }
    catch (std::out_of_range){
        cond = false;
    }
    return cond;
}

void Terminal::deleteScheme(){
    std::cout << "Opcion no disponible" << std::endl;
}

void Terminal::insertDataScheme(){
    std::cout << "Opcion no disponible" << std::endl;
}

void Terminal::deleteDataScheme(){
    std::cout << "Opcion no disponible" << std::endl;
}

void Terminal::createIndex(){
    std::cout << "Opcion no disponible" << std::endl;
}

void Terminal::deleteIndex(){
    std::cout << "Opcion no disponible" << std::endl;
}
