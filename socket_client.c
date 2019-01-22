#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include <arpa/inet.h>
#include<string.h>

#define PortNo 19987

int letter_count(char *a){
	return (sizeof(*a)/sizeof(a[0]));
}


int main(int argc, char * args){
int cli_socket_fd, ser_socket_fd, n,p, buffer_size = 256;
char buff[buffer_size];
char  msg[1024];
struct sockaddr_in client_,server_;
char * greetings = "Hey";

cli_socket_fd = socket(AF_INET,SOCK_STREAM,0);
if(cli_socket_fd < 0) perror("Client side Initiation error");

client_.sin_port = htons(PortNo);
client_.sin_family = AF_INET;

int ip_convert = inet_pton(AF_INET,"192.168.100.64", &client_.sin_addr);
if(ip_convert < 0) perror("Client side Conversion error");



ser_socket_fd = connect(cli_socket_fd,(struct sockaddr *)&client_, sizeof(client_));
if(ser_socket_fd < 0) {perror("Client side connection error"); exit(1);}
//int pid;
//pid = fork();

printf("Connecting to port :%d\n",PortNo);
while(1) {
	
		
	scanf("%s",msg);
	printf("Size of message: %d ",letter_count(msg));
	
	//if(msg == "exit()" || msg == "EXIT()" || msg == "Exit()" || msg == "EXIT" || msg == "exit" || msg == "Exit") break;
			
	p = write(cli_socket_fd,msg,1023);
	if(p < 0) perror("Client error, Message not Sent\n");

		
	n = read(cli_socket_fd,buff,255);
	if(n < 0) perror("Client error, Message not Recieved\n");
	printf("Server: %s",buff);
	
	p = 0;
	n = 0;
	
					
	}


exit(1);


return 0;

}