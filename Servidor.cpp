/***************************************************************************************/
/* @file    server_secuencial.c                                                        */
/* @brief   Secuencial server. TCP sockets                                             */
/***************************************************************************************/

/*standard symbols */
#include <unistd.h>

/* sockets */
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

/* strings / errors*/
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include "iostream"

using namespace std;

/* server parameters */
#define SERV_PORT       8080              /* port */
#define SERV_HOST_ADDR "127.0.0.1"     /* IP, only IPV4 support  */
#define BUF_SIZE        100               /* Buffer rx, tx max size  */
#define BACKLOG         1               /* Max. client pending connections  */

int main(int argc, char* argv[])          /* input arguments are not used */
{
    int sockfd, connfd ;  /* listening socket and connection socket file descriptors */
    unsigned int len;     /* length of client address */
    struct sockaddr_in servaddr, client;


    int  len_rx, len_tx = 0;                     /* received and sent length, in bytes */
    char buff_tx[BUF_SIZE] = "Hello client, I am the server";
    char buff_rx[BUF_SIZE];   /* buffers for reception  */
    int turno=0;
    string img1;
    string img2;
    string i1;
    string i2;
    string j1;
    string j2;
    string score;
    string jugador;

    /* socket creation */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        fprintf(stderr, "[SERVER-error]: socket creation failed. %d: %s \n", errno, strerror( errno ));
        return -1;
    }
    else
    {
        printf("[SERVER]: Socket successfully created..\n");
    }

    /* clear structure */
    memset(&servaddr, 0, sizeof(servaddr));

    /* assign IP, SERV_PORT, IPV4 */
    servaddr.sin_family      = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(SERV_HOST_ADDR);
    servaddr.sin_port        = htons(SERV_PORT);


    /* Bind socket */
    if ((bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
    {
        fprintf(stderr, "[SERVER-error]: socket bind failed. %d: %s \n", errno, strerror( errno ));
        return -1;
    }
    else
    {
        printf("[SERVER]: Socket successfully binded \n");
    }

    /* Listen */
    if ((listen(sockfd, BACKLOG)) != 0)
    {
        fprintf(stderr, "[SERVER-error]: socket listen failed. %d: %s \n", errno, strerror( errno ));
        return -1;
    }
    else
    {
        printf("[SERVER]: Listening on SERV_PORT %d \n\n", ntohs(servaddr.sin_port) );
    }

    len = sizeof(client);

    /* Accept the data from incoming sockets in a iterative way */
    while(1)
    {
        connfd = accept(sockfd, (struct sockaddr *)&client, &len);
        if (connfd < 0)
        {
            fprintf(stderr, "[SERVER-error]: connection not accepted. %d: %s \n", errno, strerror( errno ));
            return -1;
        }
        else
        {
            while(1) /* read data from a client socket till it is closed */
            {
                /* read client message, copy it into buffer */
                len_rx = recv(connfd, buff_rx, sizeof(buff_rx),0);

                if(len_rx == -1)
                {
                    fprintf(stderr, "[SERVER-error]: connfd cannot be read. %d: %s \n", errno, strerror( errno ));
                }
                else if(len_rx == 0) /* if length is 0 client socket closed, then exit */
                {
                    //printf("[SERVER]: client socket closed \n\n");
                    close(connfd);
                    break;
                }
                else
                {
                    std::string s(buff_rx,len_rx);

                    if(s.find("main")){
                        string mensaje;
                        cout<<"turno: "<<turno<<"\n";
                        cout<<"i1: "<<i1<<"\n";
                        cout<<"i2: "<<i2<<"\n";
                        cout<<"j1: "<<j1<<"\n";
                        cout<<"j2: "<<j2<<"\n";
                        cout<<"prueba"<<mensaje<<"\n";
                        int mlen=mensaje.length();
                        send(connfd,mensaje.c_str(),mlen,0);
                    }
                    else{
                        string id;
                        char i_char=s[2];
                        char j_char=s[3];
                        id="123456789";
                        cout << "Prueba 2:" << id.c_str() << "\n";
                        std::string i(1,i_char);
                        std::string j(1,j_char);
                        if((i=="0"&&j=="0") || (i=="1"&&j=="1") || (i=="2"&&j=="2") || (i=="3"&&j=="3") || (i=="4"&&j=="4") ){
                            cout<< "si sirve" <<"\n";
                            string mensaje="/home/cris/Escritorio/Proyecto1_Datos2/src/img/ballena.jpg";
                            img1="ballena";
                            if (turno==0){
                                turno+=1;
                                img1="ballena";

                            }
                            else {
                                turno=0;
                                img2="ballena";
                            }

                            int mlen=mensaje.length();
                            send(connfd,mensaje.c_str(),mlen,0);

                        }
                        else if((i=="0"&&j=="1") || (i=="1"&&j=="2") || (i=="2"&&j=="3") || (i=="3"&&j=="4")){
                            cout<< "tal vez sirve" <<"\n";
                            string mensaje="/home/cris/Escritorio/Proyecto1_Datos2/src/img/conejo.jpg";
                            if (turno==0){
                                turno+=1;
                                img1="conejo";
                                i1=i;
                                j1=j;

                            }
                            else {
                                turno=0;
                                img2="conejo";
                                i2=i;
                                j2=j;
                                if(img1==img2){
                                    cout<<"son iguales"<<"\n";
                                }
                                else{
                                    cout<<"no son iguales"<<"\n";
                                }
                            }
                            int mlen=mensaje.length();
                            cout<<mensaje.c_str()<<img1<<"\n";
                            send(connfd,mensaje.c_str(),mlen,0);
                        }
                        else if((i=="0"&&j=="2") || (i=="1"&&j=="3") || (i=="2"&&j=="4") || (i=="3"&&j=="5")){
                            string mensaje="/home/cris/Escritorio/Proyecto1_Datos2/src/img/delfin.jpg";
                            if (turno==0){
                                turno+=1;
                                img1="delfin";
                                i1=i;
                                j1=j;

                            }
                            else {
                                turno=0;
                                img2="delfin";
                                i2=i;
                                j2=j;
                            }
                            int mlen=mensaje.length();
                            cout<<mensaje.c_str()<<img1<<"\n";
                            send(connfd,mensaje.c_str(),mlen,0);
                        }
                        else if((i=="0"&&j=="3") || (i=="1"&&j=="4") || (i=="2"&&j=="5") || (i=="3"&&j=="0")){
                            string mensaje="/home/cris/Escritorio/Proyecto1_Datos2/src/img/dino.jpg";
                            if (turno==0){
                                turno+=1;
                                img1="dino";
                                i1=i;
                                j1=j;

                            }
                            else {
                                turno=0;
                                img2="dino";
                                i2=i;
                                j2=j;
                            }
                            int mlen=mensaje.length();
                            cout<<mensaje.c_str()<<img1<<"\n";
                            send(connfd,mensaje.c_str(),mlen,0);
                        }
                        else if((i=="0"&&j=="4") || (i=="1"&&j=="5") || (i=="2"&&j=="0") || (i=="3"&&j=="1")){
                            string mensaje="/home/cris/Escritorio/Proyecto1_Datos2/src/img/elefante.jpg";
                            if (turno==0){
                                turno+=1;
                                img1="elefante";
                                i1=i;
                                j1=j;

                            }
                            else {
                                turno=0;
                                img2="elefante";
                                i2=i;
                                j2=j;
                            }
                            int mlen=mensaje.length();
                            cout<<mensaje.c_str()<<img1<<"\n";
                            send(connfd,mensaje.c_str(),mlen,0);
                        }
                        else if((i=="0"&&j=="5") || (i=="1"&&j=="0") || (i=="2"&&j=="1") || (i=="3"&&j=="2")){
                            string mensaje="/home/cris/Escritorio/Proyecto1_Datos2/src/img/gato.jpg";
                            if (turno==0){
                                turno+=1;
                                img1="gato";
                                i1=i;
                                j1=j;

                            }
                            else {
                                turno=0;
                                img2="gato";
                                i2=i;
                                j2=j;
                            }
                            int mlen=mensaje.length();
                            cout<<mensaje.c_str()<<img1<<"\n";
                            send(connfd,mensaje.c_str(),mlen,0);
                        }
                        else if((i=="5"&&j=="0") || (i=="6"&&j=="1") || (i=="7"&&j=="2") || (i=="8"&&j=="3")){
                            string mensaje="/home/cris/Escritorio/Proyecto1_Datos2/src/img/koala.jpg";
                            if (turno==0){
                                turno+=1;
                                img1="koala";
                                i1=i;
                                j1=j;

                            }
                            else {
                                turno=0;
                                img2="koala";
                                i2=i;
                                j2=j;
                            }
                            int mlen=mensaje.length();
                            cout<<mensaje.c_str()<<img1<<"\n";
                            send(connfd,mensaje.c_str(),mlen,0);
                        }
                        else if((i=="5"&&j=="1") || (i=="6"&&j=="2") || (i=="7"&&j=="3") || (i=="8"&&j=="4")){
                            string mensaje="/home/cris/Escritorio/Proyecto1_Datos2/src/img/leon.jpg";
                            if (turno==0){
                                turno+=1;
                                img1="leon";
                                i1=i;
                                j1=j;

                            }
                            else {
                                turno=0;
                                img2="leon";
                                i2=i;
                                j2=j;
                            }
                            int mlen=mensaje.length();
                            cout<<mensaje.c_str()<<img1<<"\n";
                            send(connfd,mensaje.c_str(),mlen,0);
                        }
                        else if((i=="5"&&j=="2") || (i=="6"&&j=="3") || (i=="7"&&j=="4") || (i=="8"&&j=="5")){
                            string mensaje="/home/cris/Escritorio/Proyecto1_Datos2/src/img/mono.jpg";
                            if (turno==0){
                                turno+=1;
                                img1="mono";
                                i1=i;
                                j1=j;

                            }
                            else {
                                turno=0;
                                img2="mono";
                                i2=i;
                                j2=j;
                            }
                            int mlen=mensaje.length();
                            cout<<mensaje.c_str()<<img1<<"\n";
                            send(connfd,mensaje.c_str(),mlen,0);
                        }
                        else if((i=="5"&&j=="3") || (i=="6"&&j=="4") || (i=="7"&&j=="5") || (i=="8"&&j=="0")){
                            string mensaje="/home/cris/Escritorio/Proyecto1_Datos2/src/img/murcielago.jpg";
                            if (turno==0){
                                turno+=1;
                                img1="mur";
                                i1=i;
                                j1=j;

                            }
                            else {
                                turno=0;
                                img2="mur";
                                i2=i;
                                j2=j;
                            }
                            int mlen=mensaje.length();
                            cout<<mensaje.c_str()<<img1<<"\n";
                            send(connfd,mensaje.c_str(),mlen,0);
                        }
                        else if((i=="5"&&j=="4") || (i=="6"&&j=="5") || (i=="7"&&j=="0") || (i=="8"&&j=="1")){
                            string mensaje="/home/cris/Escritorio/Proyecto1_Datos2/src/img/pajaro.jpg";
                            if (turno==0){
                                turno+=1;
                                img1="pajaro";
                                i1=i;
                                j1=j;

                            }
                            else {
                                turno=0;
                                img2="pajaro";
                                i2=i;
                                j2=j;
                            }
                            int mlen=mensaje.length();
                            cout<<mensaje.c_str()<<img1<<"\n";
                            send(connfd,mensaje.c_str(),mlen,0);
                        }
                        else if((i=="9"&&j=="5") || (i=="4"&&j=="0") || (i=="9"&&j=="1") || (i=="4"&&j=="2")){
                            string mensaje="/home/cris/Escritorio/Proyecto1_Datos2/src/img/perro.jpg";
                            if (turno==0){
                                turno+=1;
                                img1="perro";
                                i1=i;
                                j1=j;

                            }
                            else {
                                turno=0;
                                img2="perro";
                                i2=i;
                                j2=j;
                            }
                            int mlen=mensaje.length();
                            cout<<mensaje.c_str()<<img1<<"\n";
                            send(connfd,mensaje.c_str(),mlen,0);
                        }
                        else {
                            string mensaje="/home/cris/Escritorio/Proyecto1_Datos2/src/img/panda.jpg";
                            if (turno==0){
                                turno+=1;
                                img1="panda";
                                i1=i;
                                j1=j;

                            }
                            else {
                                turno=0;
                                img2="panda";
                                i2=i;
                                j2=j;
                            }
                            int mlen=mensaje.length();
                            cout<<mensaje.c_str()<<img1<<"\n";
                            send(connfd,mensaje.c_str(),mlen,0);
                        }
                    }
                }
            }
        }
    }
}
