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


#define BUFSIZE 1024
#define pPUERTO 8000
#define CERO 0
#define LOOP true

struct informacionCliente{
    std::string _IP;
    int _PUERTO;
};

class ClientInmemdb{
private:
    pthread_t  clienteThread;
    informacionCliente* informacion;
public:
    ClientInmemdb(std::string pIp, int pPuerto);
    static void* conectarClientes(void *pInformacion);
};

#endif // CLIENTINMEMDB_H
