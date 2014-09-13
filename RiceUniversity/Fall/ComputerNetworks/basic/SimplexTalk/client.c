#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


#define SERVER_PORT 5432
#define MAX_LINE 256

int main(int argc, char * argv[]){
	FILE *fp;
	struct hostent *hp;
	struct sockaddr_in sin;
	char *host;
	char buf[MAX_LINE];
	int s;
	int len;

	if(argc == 2){
		host = argv[1];
	}
	else{
		fprintf(stderr, "usage: client host\n" );
		exit(1);
	}

	/*translate host name into peers`s IP address*/
	hp = gethostbyname(host);
	if(!hp){
		fprintf(stderr, "unknown host: %s\n", host );
		exit(1);
	}

	bzero((char *)&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	bcopy(hp->h_addr, (char *)&sin.sin_addr, hp->h_length);
	sin.sin_port = htons(SERVER_PORT);

	if((s = socket(PF_INET, SOCK_STREAM, 0)) < 0){
		perror("simplex-talk: scoket");
		exit(1);
	}
	if (connect(s, (struct sockaddr *)&sin, sizeof(sin))<0){
		perror("client_simplex_talk: socket");
		exit(1);
	}
}
