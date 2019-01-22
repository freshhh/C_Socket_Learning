#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>


/*Steps
*socket(AF_INET,SOCK_STREAM,0)
*setup struct (sin_addr.s_addr,sin_port,sin_family) 
*bind(SOCKFD,(struct sockaddr *)&addr_struct,sizeof(addr_struct))
*listen()
*accpet(SOCKFD,(struct sockaddr *)&addr_struct,sizeof(addr_struct))
*recv()/read()
*write()/send()
*/

int main(){

int sockfd, bindfd, server_len, n, fd2, opt = 1;
char greet[12] = "Thank You!",resp[256];
struct sockaddr_in server;

sockfd = socket(AF_INET,SOCK_STREAM,0);
if(sockfd < 0){
	printf("SOCKET_ERROR_SERVER");
	return -1;
}
if(setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0){
	printf("SOCKET OPT IN USE");
	return -1;
}



server.sin_port = htons(1998);
server.sin_family = AF_INET;
server.sin_addr.s_addr = INADDR_ANY;

if((bindfd = bind(sockfd,(struct sockaddr*)&server,sizeof(server))) < 0) {
		printf("BIND_ERROR");
		return -1;
	}

if(listen(sockfd,5)<0) {
	printf("LISTEN_ERROR");
	return -1;
	}
	
server_len = sizeof(server);	
if((fd2 = accept(sockfd, (struct sockaddr *)&server,&server_len))<0) {
	printf("ACCEPT_ERROR");
	return -1;
}


n = read(fd2,resp,256);
if(n < 0){ 
printf("DIDNT_READ");
return -1;
}
printf("\nRECV: %s",resp);

n = write(fd2,greet,12);
if(n < 0){ 
printf("DIDNT_WRITE");
return -1;
}
printf("\nSENT!");



return 0;
}