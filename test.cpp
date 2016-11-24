/* 
* @Author: anchen
* @Date:   2016-11-22 14:54:20
* @Last Modified by:   anchen
* @Last Modified time: 2016-11-23 14:43:13
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream> 
using namespace std;

string int_to_str(int num)
{
    stringstream ss;  
    ss<<num;   
    return ss.str();  
}

void post(string content)
{
    string post_data;
    int len = content.size();
    post_data = "POST /mms/mm1 HTTP/1.1\r\nHost: 222.111.555.111\r\nContent-Type: application/vnd.cdma.text-mms-message\r\nContent-length: " + int_to_str(len) + "\r\n\r\n" + content;
}

int main()
{
    string a="jkkk";
    post(a);
    return 0;
}