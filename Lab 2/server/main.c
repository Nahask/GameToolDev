#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<pthread.h>


void *connection_handler(void *);

int main(int argc , char *argv[])
{
	int socket_desc , client_sock , c , *new_sock;
	struct sockaddr_in server , client;
	
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("ERROR : Could not create socket");
	}
	printf("Socket created");
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(2525);
	
	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
		printf("Error : bind failed. Error");
		return -1;
	}
	printf("binded");
	
	listen(socket_desc , 3);
	
	puts("Waiting for connections");
	c = sizeof(struct sockaddr_in);
	
	
	printf("Waiting for connections");
	c = sizeof(struct sockaddr_in);
	while(client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c))
	{
		printf("Connection accepté");
		
		pthread_t sniffer_thread;
		new_sock = malloc(1);
		*new_sock = client_sock;
		
		if( pthread_create( &sniffer_thread , NULL ,  connection_handler , (void*) new_sock) < 0)
		{
			printf("error : could not create thread");
			return -1;
		}
		
		//Now join the thread , so that we dont terminate before the thread
		//pthread_join( sniffer_thread , NULL);
		printf("Handler assigned");
	}
	
	if (client_sock < 0)
	{
		printf("error : accept failed");
		return -1;
	}
	
	return 0;
}

void *connection_handler(void *socket_desc)
{
	int sock = *(int*)socket_desc;
	int read_size;
	char *message , client_message[2000];
	
	message = "now connected\n";
	write(sock , message , strlen(message));
	
	message = "Now type a number \n";
	write(sock , message , strlen(message));
	
	while( (read_size = recv(sock , client_message , 3000 , 0)) > 0 )
	{
		write(sock , client_message , strlen(client_message));
	}
	
	if(read_size == 0)
	{
		printf("Client disconnected");
		fflush(stdout);
	}
	else if(read_size == -1)
	{
		printf("error : recv failed");
	}
		
	//Free the socket pointer
	free(socket_desc);
	
	return 0;
}