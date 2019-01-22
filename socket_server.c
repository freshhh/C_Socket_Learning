#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>

#define ZERO 0
#define ONE 1
#define TWO 2
#define lh localhost
#define local_h 192.168.100.64
#define PortNo 19987


//The function "call_error" prints the error given and exits the program.
void call_error(char * msg){
	perror(msg);
	exit(1);
}

int main(int argc, char * argv){
	
	struct sockaddr_in   serv_addr, cli_addr;	
	int socket_fd, new_socket_fd, cli_len, buffer_size = 750,n=0,p;
	char buffer[buffer_size];
	
	socket_fd = socket(AF_INET, SOCK_STREAM, ZERO);
	if(socket_fd < 0){
		call_error("SERVER_SIDE_ERROR: #1 -> Socket initiation error.");
	}
	
//Apply the Address Family, Port No. & Socket address to server struct.
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PortNo);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	
//Call bind(sock_fd,(struct sockaddr *) &server_struct, sizeof(server_struct))
if(bind(socket_fd,(struct sockaddr *)&serv_addr,sizeof(serv_addr) ) < 0  ) {
	call_error("SERVER_SIDE_ERROR: #2 -> Socket Binding error.");
}	
	
if(listen(socket_fd,5) < 0){
call_error("SERVER_SIDE_ERROR: #3 -> Socket Listening error.");
}
printf("Listening...... @ %d:%d\n",INADDR_ANY,PortNo);
//Steps in reciving a client, allocate size
cli_len = sizeof(cli_addr);
int pid = 0;
int read_value = 0;

while((new_socket_fd = accept(socket_fd,(struct sockaddr *) &cli_addr, &cli_len)) > 0) {

		/* if(new_socket_fd < 0) {
				perror("Plain error (1) -- SERVER_SIDE_ERROR: #4 -> New Socket failed to accept");
				exit(1);
			 } */	
	printf("val before read : %d\n",read_value);
	//if( ( pid = fork() ) == 0 ){
		//If connected to socket, we will read, Continuously
		while((read_value = read(new_socket_fd,buffer,buffer_size)) > 0){
			
			printf("val during read : %d\n",read_value);
			
			printf("Client: %s\n",buffer);
			
			//Reply to server
			p = write(new_socket_fd,"Message Recieved :)\n",24);
			if(p < 0) perror("Plain error (3) -- SERVER_SIDE_ERROR: #6 -> failed to reply to new socket");
			
			}
			printf("val after read : %d\n",read_value);
			printf("n = %d\n",n);		
			//printf("Exiting...\n");
			
		//}
		
		//exit(1);
		
	}
	
	//if(n < 0) perror("Plain error (2) -- SERVER_SIDE_ERROR: #5 -> failed to read from New Socket"); 		
	return 0;
}