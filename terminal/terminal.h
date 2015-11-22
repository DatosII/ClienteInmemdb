#ifndef TERMINAL_H
#define TERMINAL_H

#include <iostream>
#include <sstream>
#include <string>
#include<iostream>
#include <stdlib.h>
#include <stdexcept>
#include "adapter.h"
#define MSGPROTOCOL "Dijite el protocole <content-type: xml|content-type: json>: "
#define MSGWELCOME "Elija su opcion entre: cambiarProtocolo, crearEsquema, borrarEsquema, insertarDatosEsquema, borrarDatosEsquema, crearIndice, borrarIndice o salir: "
#define MSGNAMESCHEME "Digite el nombre del esquema: "
#define MSGNUMBERRAID "Ingrese el numero de RAID <0|1|5>: "
#define MSGDATA "Ingrese el dato <Tipo> <Largo> <Nombre> o no para cancelar: "
#define SELECTPROTOCOL "cambiarProtocolo"
#define CREATESCHEME "crearEsquema"
#define DELETESCHEME "borrarEsquema"
#define INSERTDATASCHEME "insertarDatosEsquema"
#define DELETEDATASCHEME "borrarDatosEsquema"
#define CREATEINDEX "crearIndice"
#define DELETEINDEX "borrarIndice"
#define EXIT "salir"

class Terminal{
private:
    std::string _choice;
    std::string _msgtemp;
    std::string _msg;
    std::string _protocol;
    Adapter * _adapter;
    void requestAux();
    void createScheme();
    void deleteScheme();
    void insertDataScheme();
    void deleteDataScheme();
    void createIndex();
    void deleteIndex();
    bool checkData(std::string pMsg);
    bool checkStringToInt(std::string pString);
    void crearDato();
    void selectProtocol();

public:
    Terminal();
    void request();
};

#endif // TERMINAL_H
