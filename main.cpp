/* 
* @Author: anchen
* @Date:   2016-11-22 10:06:58
* @Last Modified by:   anchen
* @Last Modified time: 2016-11-23 15:28:39
*/
#include "http_client.h"
#include "mm1.h"

int main()
{
    Mm1 mm(SUBMIT_REQ);
    HttpClient obj("192.168.139.133",8888);
    obj.connect_server();
    obj.post(mm.get_pdu());
    obj.send_data();
	return 0;
}