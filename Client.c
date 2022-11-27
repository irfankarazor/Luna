#include "Client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <Winsock2.h>



int sendMessage(char* message){
 
  char *ip = "127.0.0.1";
  int port = 8080;
 
  int sock;
  struct sockaddr_in addr;
  //socklen_t addr_size;
  
  int n;
  int message_len = strlen(message);
  char buffer[message_len];

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0){
    perror("[-]Socket error");
    exit(1);
  }
  printf("[+]TCP server socket created.\n");
 
  memset(&addr, '\0', sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = port;
  addr.sin_addr.s_addr = inet_addr(ip);
 
  connect(sock, (struct sockaddr*)&addr, sizeof(addr));
  printf("Connected to the server.\n");
 
  bzero(buffer, message_len);
  strncpy(buffer, message,message_len);
  printf("Client: Encrypted message sent.\n");
  send(sock, buffer, strlen(buffer), 0);
  
  free(message); //DO  NOT FORGET  free malloc !!!

  close(sock);
  printf("Disconnected from the server.\n");
 
  return 0;
}
