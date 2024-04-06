#include "server.h"

void initServer(Server *server, int port) {
    server->port = port;
    server->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server->clientfd = 0;
    if (server->sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    bzero((char *) &server->serv_addr, sizeof(server->serv_addr));
    server->serv_addr.sin_family = AF_INET;
    server->serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server->serv_addr.sin_port = htons(server->port);
}

void bindServer(Server *server) {
    if (bind(server->sockfd, (struct sockaddr *) &server->serv_addr, sizeof(server->serv_addr)) != 0) {
        
    }
    else {
        perror("ERROR on binding");
        exit(1);
    }
}

void listenServer(Server *server) {
    listen(server->sockfd, 5);
}

void acceptServer(Server *server, int *newsockfd, struct sockaddr_in *cli_addr, socklen_t *clilen) {
    *newsockfd = accept(server->sockfd, (struct sockaddr *) cli_addr, clilen);
    if (*newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
}

void closeServer(Server *server) {
    close(server->sockfd);
}
