#include "http_client.h"

ssize_t HttpClient::readline(int fd, char *vptr, size_t maxlen)
{
    ssize_t n, rc;
    char    c, *ptr;
    ptr = vptr;
    for (n = 1; n < maxlen; n++) {
        if ( (rc = read(fd, &c,1)) == 1) {
            *ptr++ = c;
            if (c == '\n')
                break;  
        } else if (rc == 0) {
            *ptr = 0;
            return(n - 1);  
        } else
            return(-1);     
    }
    *ptr = 0;   
    return(n);
}
void HttpClient::send_data()
{
    char sendline[MAX_LINE] , recvline[MAX_LINE];
    while(fgets(sendline , MAX_LINE , stdin) != NULL)   
    {
        write(this->sockfd , sendline , strlen(sendline));
        bzero(recvline , MAX_LINE);
        if(readline(this->sockfd , recvline , MAX_LINE) == 0)
        {
            perror("server terminated prematurely");
            exit(1);
        }
        if(fputs(recvline , stdout) == EOF)
        {
            perror("fputs error");
            exit(1);
        }
        bzero(sendline , MAX_LINE);
    }
}
HttpClient::HttpClient(char* ip_addr,int port)
{
    this->ip_addr = ip_addr;
    this->port = port;
    if((this->sockfd = socket(AF_INET , SOCK_STREAM , 0)) == -1)
    {
        perror("socket error");
        exit(1);
    }
    bzero(&this->servaddr , sizeof(this->servaddr));
    this->servaddr.sin_family = AF_INET;
    this->servaddr.sin_port = htons(this->port);
    if(inet_pton(AF_INET , this->ip_addr, &this->servaddr.sin_addr) < 0)
    {
        cout<<"inet_pton error"<<endl;
        exit(1);
    }
}
void HttpClient::connect_server()
{
    if(connect(this->sockfd ,(struct sockaddr *)&this->servaddr ,sizeof(this->servaddr)) < 0)
    {
        perror("connect error");
        exit(1);
    }
}
void HttpClient::close_connect()
{
    close(this->sockfd);
}

string HttpClient::int_to_str(int num)
{
    stringstream ss;  
    ss<<num;   
    return ss.str();  
}

void HttpClient::post(string content)
{
    string post_data;
    int len = content.size();
    post_data = "POST /mms/mm1 HTTP/1.1\r\nHost: 222.111.555.111\r\nContent-Type: application/vnd.cdma.text-mms-message\r\nContent-length: " + int_to_str(len) + "\r\n\r\n" + content;
    const char *p=post_data.data(); 
    write(this->sockfd , p , strlen(p));
}