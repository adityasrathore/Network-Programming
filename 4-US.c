#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
int main(){
	int sockfd;
	char str[100];
	struct sockaddr_in servaddr;
	struct sockaddr_in cliaddr;
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	bzero(&servaddr,sizeof(servaddr));
	
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(22000);
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	bind(sockfd,(struct sockaddr*) &servaddr,sizeof(servaddr));

	recvfrom(sockfd,str,100,0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));
	printf("C -> S %s\n",str);
	bzero(str,sizeof(str));

}

