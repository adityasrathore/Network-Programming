#include <stdio.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
int main(){
	int listen_fd,comm_fd;
	char str[100];
	struct sockaddr_in servaddr;
	listen_fd=socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(22000);
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	bind(listen_fd,(struct sockaddr *) &servaddr,sizeof(servaddr));
	listen(listen_fd,10);
	while(1){
		comm_fd=accept(listen_fd,(struct sockaddr *) NULL,NULL);
		bzero(str,100);
		recv(comm_fd,str,100,0);
		printf("Echo %s",str);
		send(comm_fd,str,sizeof(str),0);
		close(comm_fd);
	}
}
