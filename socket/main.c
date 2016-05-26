#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

static int MakeSocket(unsigned int ServerPort)
{
	int Socket;
	struct sockaddr_in addr;
	/*AF and PF is the same, IPV4, TCP*/
	Socket = socket(PF_INET, SOCK_STREAM, 0);

	if (Socket < 0)
	{
		fprintf(stderr, "error: fail to make socket\n");
		exit(1);
	}
	
	/*Clear structure*/
	bzero(&addr,sizeof(addr));

	addr.sin_family = AF_INET;
	/*Host to network short*/
	addr.sin_port = htons(ServerPort);
	addr.sin_addr.s_addr = htons(INADDR_ANY);

	if(bind(Socket, (struct sockaddr*)&addr, sizeof(addr)) < 0)
	{
		fprintf(stderr, "error: Fail to bind\n");
		exit(1);
	}
	if(listen(Socket, 1) < 0)
	{
		fprintf(stderr, "error: Fail to listen\n");
		exit(1);
	}
	
	return Socket;
}

int StartUpServer(unsigned int ServerPort)
{
	int sockfd = MakeSocket(ServerPort);
	int nfds = sockfd + 1;
	int newsockfd;
	
	struct sockaddr_in addr;
	socklen_t size = sizeof(addr);
	
	fd_set master;
	fd_set readfds;
	
	fprintf(stdout, "Listening on port %d.\n\n", ServerPort);
	
	FD_ZERO(&master);
	FD_SET(sockfd, &master);
	
	while(1)
	{
		readfds = master;
		/*Monitor sockets*/
		if(select(nfds, &readfds, NULL, NULL, NULL) < 0)
		{
			fprintf(stderr, "error: Fail to select\n");
			exit(1);
		}
		
		/*Get a socket*/
		if (FD_ISSET(sockfd, &readfds))
		{
			newsockfd = accept(sockfd, (struct sockaddr *) &addr, &size);
			
			if(newsockfd < 0)
			{
				fprintf(stderr, "error: Fail to get newsockfd\n");
				exit(1);
			}
			
			FD_SET(newsockfd, &master);
		}
	}

	return 0;
}

int main(int argc, char *argv[])
{
	unsigned int ServerPort = 8080;

	if (argc > 1)
	{
		if(sscanf(argv[1], "%u", &ServerPort) == 0 || ServerPort > 65535)
		{
			fprintf(stderr , "error: invalid command, or port > 65535\n");
			ServerPort = 8080;
		}
	}
	
	StartUpServer(ServerPort);

	return 0;
}
