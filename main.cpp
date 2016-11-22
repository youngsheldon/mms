/* 
* @Author: anchen
* @Date:   2016-11-22 10:06:58
* @Last Modified by:   anchen
* @Last Modified time: 2016-11-22 17:51:17
*/

#include "mm1.h"

int main()
{
    Mm1 obj(MMBOX_DELETE_REQ);
    obj.header["X-MMS-Message-Reference"] = "v1.1.0";
    obj.set_head();
    obj.show();

    return 0;
}
