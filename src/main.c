#include <stdio.h>
#include <sys/socket.h>
#include "server.h"

int main() {
    Server server;
    initServer(&server, 4567);
    bindServer(&server);

    listenServer(&server);
    while (1)
    {
        server.clientfd =
    }
    
    closeServer(&server);
    return 0;
} 