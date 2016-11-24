#ifndef HTTP_CLIENT_H_
#define HTTP_CLIENT_H_
#include <iostream>
#include <sstream> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <string>
using namespace std;

#define MAX_LINE 2048

class HttpClient
{
public:
    HttpClient(char* ip_addr,int port);
    ~HttpClient(){}
    void connect_server();
    void close_connect();
    void send_data();
    ssize_t readline(int fd, char *vptr, size_t maxlen);
    void post(string content);
    string int_to_str(int num);
private:
    int sockfd;
    int port;
    char* ip_addr;
    struct sockaddr_in servaddr;
};

#endif