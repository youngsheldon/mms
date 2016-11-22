/* 
* @Author: anchen
* @Date:   2016-11-22 10:06:58
* @Last Modified by:   anchen
* @Last Modified time: 2016-11-22 22:59:04
*/

#include "mm1.h"

int main()
{
    Mm1 obj1(SUBMIT_REQ);
    obj1.set_head();
    obj1.show();
    Mm1 obj2(NOTIFI_RES);
    obj2.set_head();
    obj2.show();
    Mm1 obj3(RETRIEVE_REQ);
    obj3.set_head();
    obj3.show();
    Mm1 obj4(MMBOX_DELETE_REQ);
    obj4.set_head();
    obj4.show();
    Mm1 obj5(FORWARD_REQ);
    obj5.set_head();
    obj5.show();
	return 0;
	}
