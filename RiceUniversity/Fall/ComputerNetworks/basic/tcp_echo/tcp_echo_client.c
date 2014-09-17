//C classic standard libraries
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//socket communication API
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

//defines max size of the msg
#define BUFFSIZE 32

//error function
void Die(char *mess) { perror(mess); exit(1); }

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in echoserver;
    char buffer[BUFFSIZE];
    unsigned int echolen;
    int received = 0;

    if (argc != 4) {
      fprintf(stderr, "USAGE: TCPecho <server_ip> <word> <port>\n");
      exit(1);
    }
    /* Create the TCP socket 
    the TCP port is defined by the arguments send to the socket constructor.
    If we use PF_INET, SOCK_STREAM and IPPROTO_TCP we will be using TCP.
    A option to TCP is UDM, or something like that*/
    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        //in case of failure, the constructor return -1
      Die("Failed to create socket");
    }

/* Construct the server sockaddr_in structure 
    we need to specify the server addr at .sin_addr.s_addr, 
    the port at .sin_port and the family at .sin_family*/
    memset(&echoserver, 0, sizeof(echoserver));       /* Clear struct */
    echoserver.sin_family = AF_INET;                  /* Internet/IP */
    echoserver.sin_addr.s_addr = inet_addr(argv[1]);  /* IP address */
    echoserver.sin_port = htons(atoi(argv[3]));       /* server port */
    //the line above convert the address from Host order to Server order

    /* Establish connection */
    if (connect(sock,
                (struct sockaddr *) &echoserver,
                sizeof(echoserver)) < 0) {
      Die("Failed to connect with server");
    }

    /* Send the word to the server */
   echolen = strlen(argv[2]);
   if (send(sock, argv[2], echolen, 0) != echolen) {
     Die("Mismatch in number of sent bytes");
   }
    /* Receive the word back from the server */
    fprintf(stdout, "Received: ");
    while (received < echolen) {
      int bytes = 0;
      if ((bytes = recv(sock, buffer, BUFFSIZE-1, 0)) < 1) {
        Die("Failed to receive bytes from server");
      }
      received += bytes;
      buffer[bytes] = '\0';        /* Assure null terminated string */
      fprintf(stdout, "%s", buffer);
    }

    fprintf(stdout, "\n");
    close(sock);
    exit(0);
}

