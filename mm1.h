#ifndef MM1_H_
#define MM1_H_
#include <iostream>
#include <map>
#include <list>
#include <string>
#include <fstream>  
#include <stdlib.h>  
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
const int SUBMIT_RES = 11;
const int NOTIFI_REQ = 12;
const int RETRIEVE_RES = 13;
const int FORWARD_RES = 14;
const int DELIVERY_REPORT_REQ = 15;
const int READ_REPLY_ORI_REQ = 16;
const int MMBOX_STORE_RES = 17;
const int MMBOX_VIEW_RES = 18;
const int MMBOX_UPLOAD_RES = 19;
const int MMBOX_DELETE_RES = 20;

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
    "X-MMS-Message-Type","X-MMS-MMS-Version","X-MMS-Transaction-ID",
    "X-MMS-Message-Reference"
};
const string submit_res_head_key[9] = {
    "X-MMS-Message-Type","X-MMS-Transaction-ID","X-MMS-MMS-Version","X-MMS-Request-Status",
    "X-MMS-Request-Text","Message ID","X-MMS-Store-Status","X-MMS-Store-Text",
    "X-MMS-stored-Message"
};
const string notification_req_head_key[6] = {
    "X-MMS-Message-Type","X-MMS-Transaction-ID","X-MMS-MMS-Version","X-MMS-Expiry",
    "X-MMS-Server-Location","X-MMS-Content-ID"
};
const string retrieve_res_head_key[23] = {
    "X-MMS-Message-Type","X-MMS-Transaction-ID","X-MMS-MMS-Version","Message-ID","From",
    "Content-Type","To","X-MMS-Message-Class","Date","X-MMS-Delivery-Report",
    "X-MMS-Priority","X-MMS-Read-Reply","Subject","X-MMS-State","X-MMS-Flags",
    "X-MMS-Request-Status","X-MMS-Request-Text","X-MMS-Reply-Charging",
    "X-MMS-Reply-Charging-ID","X-MMS-Reply-charging-Deadline","X-MMS-Reply-Charging-Size",
    "X-MMS-Previously-Sent-By","X-MMS-Previously-Sent-Date"
};
const string forward_res_head_key[9] = {
    "X-MMS-Message-Type","X-MMS-Transaction-ID","X-MMS-MMS-Version","X-MMS-Request-status",
    "X-MMS-Request-Text","Message-ID","X-MMS-store-Status","X-MMS-Store-Text",
    "X-MMS-Stored-Message"
};
const string delivery_report_req_head_key[6] = {
    "X-MMS-Message-Type","X-MMS-MMS-Version","Message-ID","To","Date","X-MMS-Status"
};
const string read_reply_ori_req_head_key[6] = {
    "X-MMS-Message-Type","X-MMS-MMS-Version","From","Message-ID","Date","X-MMS-Read-Status"
};
const string mmbox_strore_res_head_key[6] = {
    "X-MMS-Message-Type","X-MMS-MMS-Version","X-MMS-Transaction-ID",
    "X-MMS-Stored-Message-Reference","X-MMS-store-Status","X-MMS-Store-Text"
};
const string mmbox_view_res_head_key[8] = {
    "X-MMS-Message-Type","X-MMS-MMS-Version","X-MMS-Transaction-ID","X-MMS-Listing",
    "X-MMS-request-Status","X-MMS-Request-Text","X-MMS-Totals","X-MMS-Quotas"
};
const string mmbox_uplaod_res_head_key[9] = {
    "X-MMS-Message-Type","X-MMS-MMS-Version","X-MMS-Transaction-ID",
    "X-MMS-Message-Reference","X-MMS-request-Status","X-MMS-Request-Text"
};
const string mmbox_delete_res_head_key[6] = {
    "X-MMS-Message-Type","X-MMS-MMS-Version","X-MMS-Transaction-ID",
    "X-MMS-Message-Reference","X-MMS-request-Status","X-MMS-Request-Text"
};

class Mm1
{
public:
    Mm1(int msg_type);
    ~Mm1(){}
    void set_head();
    void link_data(const string head_key[]);
    void show();
    string get_pdu();
    string set_mms_body();
    void set_text(string text);
public:
    map<string,string> header;
    list<string> pdu;
private:
    int msg_seq;
    int header_size;
    string text;
};


#endif