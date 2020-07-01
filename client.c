#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(){
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(3030);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int connection_status = connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    if(connection_status == -1){
        printf("Connection Error\n");
    }

    char server_response[256];
    recv(client_socket, &server_response, sizeof(server_response), 0);

    printf("Server response: %s\n", server_response);

    close(client_socket);

    return 0;
}