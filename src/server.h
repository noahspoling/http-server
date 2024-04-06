#ifndef SERVER_H
#define SERVER_H
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>

typedef struct Server {
    int sockfd;
    int clientfd;
    struct sockaddr_in serv_addr;
    int port;
    char sendBuff[1025];
    time_t ticks;
} Server;

void initServer(Server *server, int port);
void bindServer(Server *server);
void listenServer(Server *server);
void acceptServer(Server *server, int *newsockfd, struct sockaddr_in *cli_addr, socklen_t *clilen);
void closeServer(Server *server);


#endif