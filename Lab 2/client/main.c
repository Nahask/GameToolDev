#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main(int argc , char *argv[])
{
	int sock;
	struct sockaddr_in server;
	char message[1500];
	char server_reply[3000];
	
	sock = socket(AF_INET , SOCK_STREAM , 0);
	if (sock == -1)
	{
		printf("error : Could not create socket");
	}
	printf("Socket created");
	
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(2525);

	if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		printf("Error : connect failed");
		return 1;
	}
	
	printf("Connected\n");
	
	while(1)
	{
		printf("Enter number : ");
		scanf("%s" , message);
		
		if( send(sock , message , strlen(message) , 0) < 0)
		{
			printf("error : Send failed");
			return 1;
		}
		
		if( recv(sock , server_reply , 3000 , 0) < 0)
		{
			puts("error : recv failed");
			break;
		}
		
		printf("server response :");
		puts(server_reply);
	}
	
	close(sock);
	return 0;
}