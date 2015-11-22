#ifndef CLIENTINMEMDB_H
#define CLIENTINMEMDB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>


#define _BUFSIZE 1024
#define _PUERTO 8000
#define _CERO 0
#define _LOOP true

class ClientInmemdb;
struct informacionCliente{
    std::string IP;
    int PUERTO;
    ClientInmemdb * cliente;
};

class ClientInmemdb{
private:
    pthread_t  clienteThread;
    informacionCliente* informacion;
    char * _msg;
public:
    ClientInmemdb(std::string pIp, int pPuerto, char* pMsg);
    static void* conectarClientes(void *pInformacion);
    void setMsg(char * pMsg);
};

#endif // CLIENTINMEMDB_H
