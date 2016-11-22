#ifndef MM1_H_
#define MM1_H_
#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;

const int SUBMIT_REQ = 1;
const int NOTIFI_RES = 2;
const int RETRIEVE_REQ = 3;
const int ACK_REQ = 4;
const int FORWARD_REQ = 5;
const int READ_REPLY_REC_REQ = 6;
const int MMBOX_STORE_REQ = 7;
const int MMBOX_VIEW_REQ = 8;
const int MMBOX_UPLOAD_REQ = 9;
const int MMBOX_DELETE_REQ = 10;

const string submit_req_head_key[21] = {
    "X-MMS-Message-Type","X-MMS-Transaction-ID","X-MMS-MMS-Version","To","From","Subject",
    "Content-Type","X-MMS-Message-Class","X-MMS-Expiry","X-MMS-Delivery-Time",
    "X-MMS-Delivery-Report","X-MMS-Reply-Charging","X-MMS-Reply-Charging-Deadline",
    "X-MMS-Reply-Charging-Size","X-MMS-Priority","X-MMS-Sender-Visibility","X-MMS-Store",
    "X-MMS-State","X-MMS-Flags","X-MMS-Read-Reply","X-MMS-Reply-Charging-ID"
};
const string notification_res_head_key[5] = {
    "X-MMS-Message-Type","X-MMS-Transaction-ID","X-MMS-MMS-Version","X-MMS-Status",
    "X-MMS-Report-Allowed"
};
const string retrieve_req_head_key[4] = {
    "X-MMS-Message-Type","X-MMS-Transaction-ID","X-MMS-MMS-Version","X-MMS-Content-ID"
};
const string acknowledge_req_head_key[5] = {
    "X-MMS-Message-Type","X-MMS-Transaction-ID","X-MMS-MMS-Version","X-MMS-Status",
    "X-MMS-Report-Allowed"
};
const string forward_req_head_key[14] = {
    "X-MMS-Message-Type","X-MMS-Transaction-ID","X-MMS-MMS-Version","To","From","Date",
    "X-MMS-Expiry","X-MMS-Delivery-Time","X-MMS-Store","X-MMS-State","X-MMS-Flags",
    "X-MMS-Delivery-Report","X-MMS-Read-reply","X-MMS-Content-Location"
};
const string read_reply_rec_req_head_key[7] = { 
    "X-MMS-Message-Type","X-MMS-MMS-Version","To","From","Message-ID","Date",
    "X-MMS-Read-Status"
};
const string mmbox_strore_req_head_key[6] = {
    "X-MMS-Message-Type","X-MMS-MMS-Version","X-MMS-Transaction-ID",
    "X-MMS-Message-Reference","X-MMS-State","X-MMS-Flags"
};
const string mmbox_view_req_head_key[10] = {
    "X-MMS-Message-Type","X-MMS-MMS-Version","X-MMS-Transaction-ID","X-MMS-Attributes-List",
    "X-MMS-Message-Reference-List","X-MMS-Select","X-MMS-Start","X-MMS-Limit",
    "X-MMS-Totals","X-MMS-Quotas"
};
const string mmbox_uplaod_req_head_key[14] = {
    "X-MMS-Message-Type","X-MMS-MMS-Version","X-MMS-Transaction-ID","To","From",
    "X-MMS-Message-Class","Date","X-MMS-Expiry","X-MMS-Delivery-Time","X-MMS-Priority",
    "X-MMS-State","X-MMS-Flags","Subject","Content-Type"
};
const string mmbox_delete_req_head_key[4] = {
    "X-MMS-Message-Type","X-MMS-MMS-Version","X-MMS-Transaction-ID","X-MMS-Message-Reference"
};

class Mm1
{
public:
    Mm1(int msg_type);
    ~Mm1(){}
    void set_head();
    void link_data(const string head_key[]);
    void show();
public:
    map<string,string> header;
    list<string> pdu;
private:
    int msg_seq;
    int header_size;
};


#endif