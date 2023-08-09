Server Code-

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORTNO 10200
int main()
{
	int sockfd,newsockfd,portno,clilen,n=1;
	struct sockaddr_in seraddr,cliaddr;
	int i,value;
	// create an unnamed socket for the server
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	//Name the socket
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("172.16.58.22");
	seraddr.sin_port = htons(PORTNO);
	bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
	//Create a connection queue and wait for clients
	listen(sockfd,5);
	while (1) {
	char buf[256];
	printf("server waiting");
	//Accept a connection
	clilen = sizeof(clilen);
	newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);
	//Read and write to client on client_sockfd (Logic for problem mentioned here)
	n = read(newsockfd,buf,sizeof(buf));
	printf(" \nEncrypted message: %s \n",buf);
	n = write(newsockfd,buf,sizeof(buf));
	for(i = 0; (i < 100 && buf[i] != '\0'); i++)
        buf[i] = buf[i] - 4;
    printf(" \nDecrypted message: %s \n",buf);
	n = write(newsockfd,buf,sizeof(buf));
	}
}

Client Code-

#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int len,result,sockfd,n=1;
struct sockaddr_in address;
char ch[256],buf[256];
//Create a socket for the client
sockfd = socket(AF_INET, SOCK_STREAM, 0);
//Name the socket as agreed with the server
address.sin_family=AF_INET;
address.sin_addr.s_addr=inet_addr("172.16.58.22");
address.sin_port=htons(10200);
len = sizeof(address);
//Connect your socket to the server’s socket
result=connect(sockfd,(struct sockaddr *)&address,len);
if(result==-1)
{
perror("\nCLIENT ERROR");
exit(1);
}
//You can now read and write via sockfd (Logic for problem mentioned here)
printf("\nENTER STRING\t");
gets(ch);
ch[strlen(ch)]='\0';
for(int i = 0; (i < 100 && ch[i] != '\0'); i++)
        ch[i] = ch[i] + 4;
write(sockfd,ch,strlen(ch));
printf("STRING SENT BACK FROM SERVER IS ..... ");
while(n){
n=read(sockfd,buf,sizeof(buf));
puts(buf);
}
}
