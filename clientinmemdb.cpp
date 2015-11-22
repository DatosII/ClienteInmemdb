#include "clientinmemdb.h"

ClientInmemdb::ClientInmemdb(std::string pIp, int pPuerto){
    informacion = new informacionCliente();
    informacion->_IP=pIp;
    informacion->_PUERTO=pPuerto;
    pthread_create(&clienteThread,NULL,&conectarClientes,informacion);
    pthread_join(clienteThread, NULL);
}

void *ClientInmemdb::conectarClientes(void *pInformacion){
    int cliente;
    int _PUERTO=((informacionCliente*)pInformacion)->_PUERTO;
    std::string IP=((informacionCliente*)pInformacion)->_IP;
    char* buffer=new char[BUFSIZE];
    char* ipTemp = (char*)IP.c_str();
    for(int i=0; i<IP.length();i++){
        if(ipTemp[i] == 0) ipTemp[i] = 0x2e;
    }
    struct sockaddr_in direc;
    if ((cliente=socket(AF_INET,SOCK_STREAM,0))<CERO){
        std::cout<<"No hay conexion"<<std::endl;
        exit(0);
    }
    direc.sin_family=AF_INET;
    direc.sin_port=htons(_PUERTO);
    inet_pton(AF_INET,ipTemp,&direc.sin_addr);

    if (connect(cliente,(struct sockaddr *)&direc,sizeof(direc))==0){
        recv(cliente,buffer,BUFSIZE,CERO);
        std::cout<<buffer<<std::endl;
        std::cout<<"Entro"<<std::endl;
        while(LOOP){
            //send(cliente,buffer,_BUFSIZE,_CERO);
            recv(cliente,buffer,BUFSIZE,CERO);
            std::cout<<buffer<<std::endl;
        }
        close(cliente);
    }
    else{
        std::cout<<"Error.No se pudo conectar al servidor." <<std::endl;
    }
}

