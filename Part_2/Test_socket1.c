#include<stdio.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>

//This will connect to a host and recieve its ip address.

int main(int args, char * argc[]){

//listing the needed variables
/**********************************/
char * hostname = "www.facebook.com";
int p = args-1;

char given_host_name[100];
strcpy(given_host_name,argc[1]);
 printf("\t\t\t%s\n",argc[0]);

	

char ip_addr[50],ip_2[50];
int i;
struct hostent *he,*he2;
struct in_addr **addr_list, **list2;
/**********************************/

if ((he = gethostbyname(hostname)) == NULL){
	perror("Didnt get hostname Error!");
	//exit(1);
}

addr_list = (struct in_addr **) he->h_addr_list;

for(i=0;addr_list[i] != NULL; i++){
	strcpy(ip_addr,inet_ntoa(*addr_list[i]));
}

printf("%s resolved to %s\n",hostname,ip_addr);
printf("Alias is %s\n",(char *)he->h_aliases);
printf("Official Name %s\n",he->h_name);
printf("Address Type is %d\n",he->h_addrtype);
printf("Address length is %d\n",he->h_length);



if(args >= 2){
if ((he2 = gethostbyname(given_host_name)) == NULL){
	perror("Didnt get hostname Error!");
	//exit(1);
}

list2 = (struct in_addr **) he2->h_addr_list;

for(i=0;list2[i] != NULL; i++){
	strcpy(ip_2,inet_ntoa(*list2[i]));
}
printf("\n%s resolved to %s\n",given_host_name,ip_2);
printf("Alias is %s\n",he->(*h_aliases));
printf("Official Name %s\n",he2->h_name);
printf("Address Type is %d\n",he2->h_addrtype);
printf("Address length is %d\n\n",he2->h_length);
}





return 0;
}
