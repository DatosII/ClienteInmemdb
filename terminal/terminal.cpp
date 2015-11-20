#include "terminal.h"

Terminal::Terminal(){

}

void Terminal::solicitud(){
    do{
        std::cout << MSGWELCOME << std::endl;
        std::getline (std::cin , choice);
    }
    while( (choice != CREARESQUEMA) && (choice != BORRARESQUEMA) && (choice != INSERTARDATOESQUEMA) && (choice != BORRARDATOESQUEMA) && (choice != CREARINDICE) && (choice != BORRARINDICE) && (choice != SALIR));
    if(choice == CREARESQUEMA){
        crearEsquema();
    }
    else if (choice == BORRARESQUEMA){
        borrarEsquema();
    }
    else if (choice == INSERTARDATOESQUEMA){
        insertarDatoEsquema();
    }
    else if (choice == BORRARDATOESQUEMA){
        borrarDatoEsquema();
    }
    else if (choice == CREARINDICE){
        crearIndice();
    }
    else if (choice == BORRARINDICE){
        borrarIndice();
    }
    else if (choice== SALIR)
        exit(0);
    solicitud();
}

void Terminal::crearEsquema(){

}

void Terminal::borrarEsquema(){

}

void Terminal::insertarDatoEsquema(){

}

void Terminal::borrarDatoEsquema(){

}

void Terminal::crearIndice(){

}

void Terminal::borrarIndice(){

}
