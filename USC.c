#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
int main(){
	
	int sockfd;
	char send[100],recv[100];
	struct sockaddr_in servaddr;
	struct sockaddr_in cliaddr;
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	bzero(&servaddr,sizeof(servaddr));
	bzero(&cliaddr,sizeof(cliaddr));
	
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(22000);
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	bind(sockfd,(struct sockaddr*) &servaddr,sizeof(servaddr));
	int n=sizeof(cliaddr);
	while(1){
		recvfrom(sockfd,recv,100,0,(struct sockaddr*)&cliaddr,&n);
		printf("C -> S %s\n",recv);
		printf("Enter Message-\n");
		fgets(send,100,stdin);
		sendto(sockfd,send,100,0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));
	}
}

