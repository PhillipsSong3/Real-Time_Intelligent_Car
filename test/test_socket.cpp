#include <iostream>
#include <unistd.h>
#include <cstring>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdlib>
using namespace std;
#define USEPORT 1234


int main()
{
	//create socket
	int serverSock = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSock < 0)
	{
		cout << "socket creation failed" << endl;
		exit(-1);
	}
	cout << "socket creation successfully" << endl;
	//bind ip and port
	struct sockaddr_in serverAddr;
	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(USEPORT);
	//INADDR_ANY
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	//bind socket
	if (bind(serverSock,
		(struct sockaddr*)&serverAddr,
		sizeof(struct sockaddr)) == -1)
	{
		cout << "Bind error, Port[" << USEPORT << "]" << endl;
		exit(-1);
	}
	cout << "Bind successfully" << endl;

	//listen
	if (listen(serverSock, 10) == -1)
	{
		cout << "Listen error!" << endl;
	}
	cout << "Listening on port[" << USEPORT << "]" << endl;

	//start to accept
	struct sockaddr clientAddr;
	int size = sizeof(struct sockaddr);

	int clientSock = accept(serverSock, (struct sockaddr*)&clientAddr, (socklen_t*)&size);

	cout << "The Controler Connected!" << endl;
	//communication
	while (1)
	{
		char revData[5];
		int ret = recv(clientSock,revData,5,0);
		if(ret > 0){
			revData[ret] = 0x00;
			cout<<"retrevData:"<<revData<<endl;
		}
		cout<<"lenth:"<<ret<<endl;
		cout<<"revData:"<<revData<<endl;
		if(strcmp(revData, "UPUP") == 0){
			
			cout<<"up"<< '\n';
        }
		else if(strcmp(revData,"DOWN") == 0){

			cout<<"down"<< '\n';
		}
		else if(strcmp(revData,"LEFT") == 0){

			cout<<"left"<< '\n';
		}
		else if(strcmp(revData,"RIGHT") == 0){

			cout<<"right"<< '\n';
		}
		else if(strcmp(revData,"STOP") == 0){

			cout<<"stop"<< '\n';
		}
		else if(strcmp(revData,"QUIT") == 0){
			cout<<"shutdown"<<'\n';
			break;
		}
	}

	close(serverSock);
	return 0;
}