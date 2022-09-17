#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
int main(){
	
	int sockfd;
	char send[100],recv[100];
	struct sockaddr_in servaddr;
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	bzero(&servaddr,sizeof(servaddr));
	
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1 ");
	servaddr.sin_port=htons(22000);

	while(1){
		printf("Enter Message- \n");
		fgets(send,100,stdin);
		sendto(sockfd,send,100,0,(struct sockaddr*)&servaddr,sizeof(servaddr));	
		recvfrom(sockfd,recv,100,0,(struct sockaddr*)&servaddr,sizeof(servaddr));
		printf("S->C %s\n",recv);
	}
}

