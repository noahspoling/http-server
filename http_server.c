#include <sys/socket.h>
#include <sys/sendfile.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>

void main() {
	int socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in socket_addr = {
		AF_INET,
		0x901f, //port 8080
		0
	};
	bind(socket_file_descriptor, &socket_addr, sizeof(socket_addr));
	listen(socket_file_descriptor, 10);
	int client_file_descriptor = accept(socket_file_descriptor, 0, 0);
	char buffer[256] = {0};
	recv(client_file_descriptor, buffer, 256, 0);
	char* file = buffer + 5;
	//GET /file.html
	//     ^starts here
	*strchr(file, ' ') = 0;
	int open_file = open(file, O_RDONLY);
	sendfile(client_file_descriptor, open_file, 0, 256);
	close(open_file);
	close(client_file_descriptor);
	close(socket_file_descriptor);
}

