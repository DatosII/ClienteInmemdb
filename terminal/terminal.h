#ifndef TERMINAL_H
#define TERMINAL_H

#include<iostream>
#include <stdlib.h>
#define MSGWELCOME "Elija su opcion entre: crearEsquema, borrarEsquema, insertarDatosEnEsquema, borrarDatosEnEsquema, crearIndice, borrarIndice o salir: "
#define CREARESQUEMA "crearEsquema"
#define BORRARESQUEMA "borrarEsquema"
#define INSERTARDATOESQUEMA "insertarDatosEnEsquema"
#define BORRARDATOESQUEMA "borrarDatosEnEsquema"
#define CREARINDICE "crearIndice"
#define BORRARINDICE "borrarIndice"
#define SALIR "salir"

class Terminal{
private:
    std::string choice;
    void crearEsquema();
    void borrarEsquema();
    void insertarDatoEsquema();
    void borrarDatoEsquema();
    void crearIndice();
    void borrarIndice();

public:
    Terminal();
    void solicitud();
};

#endif // TERMINAL_H
