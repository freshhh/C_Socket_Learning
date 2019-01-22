#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define SOCKET_STRUCT   struct sockaddr_in

int main(){
	int PORT_NO = 1998;
	SOCKET_STRUCT in_addr;
	
	char greetings[256], response[256];
	
	int socket_fd,/*FOR SERVER*/ bindfd;
	socket_fd = socket(AF_INET,SOCK_STREAM,0);
	if(socket_fd < 0)
	{ 
	printf("SOCKET_ERROR");
	return -1;			
	}
	
	in_addr.sin_family = AF_INET;
	in_addr.sin_port = htons(PORT_NO);
	if(inet_pton(AF_INET,"192.168.100.64",&in_addr.sin_addr)<=0) {
		printf("SIN_ADDR_ERROR");
		return -1;	
	}
		
	if(connect(socket_fd,(struct sockaddr *)&in_addr,sizeof(in_addr)) < 0 ){
		printf("CONNECT_ERROR");
		return -1;	
	}

	printf("ENTER YOUR MESSAGE: ");
	scanf("%s",greetings);
	send(socket_fd,greetings,256,0);
	printf("Message Sent");
	
	recv(socket_fd,response,256,0);
	printf("\nRECEIVED: %s\n",response);
	
	
	//ONLY FOR SERVER SIDE_______________________
	
	//__________________________________________
	
		
	
	
return 0;
}