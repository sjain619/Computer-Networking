// UDP Pinger
//Client 

#include <iostream>
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <time.h> 
#include <sys/types.h> 
#include <sys/time.h>
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <chrono>
#include <ctime>  

#define PORT	 12000


int main() { 
	int sockfd, n;
	socklen_t len;
	char buffer[1024];
	char *hello = "Hello! from Client"; 
	struct sockaddr_in servaddr; 
	
	
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	
	memset(&servaddr, 0, sizeof(servaddr)); 
	//memset(&cliaddr, 0, sizeof(cliaddr)); 
	
	// Fill server information 
	servaddr.sin_family = AF_INET; // IPv4 
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // localhost
	servaddr.sin_port = htons(PORT); // port number	

int counter = 0;
while(counter < 10){
//Starttime
    auto start = std::chrono::system_clock::now();
sendto(sockfd, (const char *)hello, strlen(hello), 
			MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr));
    std::cout<<"Hello message sent.\n";
counter++;
n = recvfrom(sockfd, (char *)buffer, sizeof(buffer), 
			MSG_WAITALL, ( struct sockaddr *) &servaddr, &len);
		buffer[n] = '\0';    
	std::cout << "Server :" << buffer;
    auto end = std::chrono::system_clock::now();
	
std::chrono::duration<double> RTT = end-start;

std::cout<< "RTT: " << RTT.count() << "s\n";
}
	close(sockfd); 
	return 0; 
} 
