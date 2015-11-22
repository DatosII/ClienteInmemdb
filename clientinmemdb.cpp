#include "clientinmemdb.h"

/**
 * @brief ClientInmemdb::ClientInmemdb, constructor de la clase
 * @param pIp, ip del servidor
 * @param pPuerto, puerto del servidor
 */
ClientInmemdb::ClientInmemdb(std::string pIp, int pPuerto, char *pMsg){
    informacion = new informacionCliente();
    informacion->IP=pIp;
    informacion->PUERTO=pPuerto;
    informacion->cliente=this;
    pthread_create(&clienteThread,NULL,&conectarClientes,informacion);
    pthread_join(clienteThread, NULL);
    _msg=pMsg;
}
/**
 * @brief ClientInmemdb::conectarClientes
 * @param pInformacion
 * @return
 */
void *ClientInmemdb::conectarClientes(void *pInformacion){
    int cliente;
    int PUERTO =((informacionCliente*)pInformacion)->PUERTO;
    std::string IP=((informacionCliente*)pInformacion)->IP;
    char* buffer=new char[_BUFSIZE];
    char* ipTemp = (char*)IP.c_str();
    for(int i=0; i<IP.length();i++){
        if(ipTemp[i] == 0) ipTemp[i] = 0x2e;
    }
    struct sockaddr_in direc;
    if ((cliente=socket(AF_INET,SOCK_STREAM,0))<_CERO){
        std::cout<<"No hay conexion"<<std::endl;
        exit(0);
    }
    direc.sin_family=AF_INET;
    direc.sin_port=htons(PUERTO);
    inet_pton(AF_INET,ipTemp,&direc.sin_addr);
    bool flag = false;
    if (connect(cliente,(struct sockaddr *)&direc,sizeof(direc))==0){
//        recv(cliente,buffer,BUFSIZE,CERO);
        std::cout<<"Entro"<<std::endl;
        flag = true;
        while(flag){
            std::cout<<"Entro2"<<std::endl;
            if(((informacionCliente*)pInformacion)->cliente->_msg!=NULL){
                std::cout << "entrarif0" << std::endl;
                send(cliente,((informacionCliente*)pInformacion)->cliente->_msg, _BUFSIZE, _CERO);
            }
            //recv(cliente,buffer,BUFSIZE,CERO);
            //std::cout<<buffer<<std::endl;
        }
        close(cliente);
    }
    else{
        std::cout<<"Error. No se pudo conectar al servidor." <<std::endl;
    }
}

void ClientInmemdb::setMsg(char *pMsg){
    _msg=pMsg;
}
