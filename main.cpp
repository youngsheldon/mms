/* 
* @Author: anchen
* @Date:   2016-11-22 10:06:58
* @Last Modified by:   anchen
* @Last Modified time: 2016-11-28 18:24:23
*/
#include "http_client.h"
#include "mm1.h"

int main()
{
    string text = "hi,what is your name!,i am from xxx";
    Mm1 mm(SUBMIT_REQ);
    mm.set_text(text);
    HttpClient obj("192.168.200.167",8888);
    obj.connect_server();
    obj.post(mm.get_pdu());
    obj.send_data();
	return 0;
}