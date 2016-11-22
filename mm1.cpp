#include "mm1.h"

void Mm1::set_head()
{
    switch(this->msg_seq)
    {
        case SUBMIT_REQ:
            this->link_data(submit_req_head_key);
        break;
        case NOTIFI_RES:
           this->link_data(notification_res_head_key);
        break;
        case RETRIEVE_REQ:
            this->link_data(retrieve_req_head_key);
        break;
        case ACK_REQ:
            this->link_data(acknowledge_req_head_key);
        break;
        case FORWARD_REQ:
            this->link_data(forward_req_head_key);
        break;
        case READ_REPLY_REC_REQ:
            this->link_data(read_reply_rec_req_head_key);
        break;
        case MMBOX_STORE_REQ:
            this->link_data(mmbox_strore_req_head_key);
        break;
        case MMBOX_VIEW_REQ:
            this->link_data(mmbox_view_req_head_key);
        break;
        case MMBOX_UPLOAD_REQ:
            this->link_data(mmbox_uplaod_req_head_key);
        break;
        case MMBOX_DELETE_REQ:
            this->link_data(mmbox_delete_req_head_key);
        break;
    }
    
}

void Mm1::link_data(const string head_key[])
{
    map<string ,string >::iterator l_it;
    for (int i = 0; i < this->header_size; ++i)
    {
        l_it = this->header.find(head_key[i]);
        if(l_it == this->header.end())
        {

        }
        else 
        {
            string v = head_key[i] + ":" + this->header[head_key[i]];
            this->pdu.push_back(v);
        }
    }
}

void Mm1::show()
{
    list<string>::iterator iter;
    for(iter = this->pdu.begin(); iter != this->pdu.end(); ++iter)
    {
        cout<<*iter<<endl;
    }
}

Mm1::Mm1(int msg_type)
{
    this->msg_seq = msg_type;
    switch(msg_type)
    {
        case SUBMIT_REQ:
            this->header_size = 21;
            this->header["X-MMS-Message-Type"] = "MM1_submit.REQ";
            this->header["Content-Type"] = "application/vnd.cdma.text-mms-message";
            this->header["X-MMS-Transaction-ID"] = "d56g9q2c5n";
            this->header["X-MMS-MMS-Version"] = "1.0.0";
            this->header["To"] = "123456@mms.comverse.com,12345678/TYPE=PLMN";
        break;
        case NOTIFI_RES:
            this->header_size = 5;
            this->header["X-MMS-Message-Type"] = "MM1_notification.RES";
            this->header["X-MMS-Transaction-ID"] = "d56g9q2c5n";
            this->header["X-MMS-MMS-Version"] = "1.0.0";
        break;
        case RETRIEVE_REQ:
            this->header_size = 4;
            this->header["X-MMS-Message-Type"] = "MM1_retrieve.REQ";
            this->header["X-MMS-Transaction-ID"] = "d56g9q2c5n";
            this->header["X-MMS-MMS-Version"] = "1.0.0";
            this->header["X-MMS-Content-Location"] = "txt.txt";
        break;
        case ACK_REQ:
            this->header_size = 5;
            this->header["X-MMS-Message-Type"] = "MM1_retrieve.REQ";
            this->header["X-MMS-Transaction-ID"] = "d56g9q2c5n";
            this->header["X-MMS-MMS-Version"] = "1.0.0";
        break;
        case FORWARD_REQ:
            this->header_size = 14;
            this->header["X-MMS-Message-Type"] = "MM1_forward.REQ";
            this->header["X-MMS-Transaction-ID"] = "d56g9q2c5n";
            this->header["X-MMS-MMS-Version"] = "1.0.0";
            this->header["To"] = "123456@mms.comverse.com,12345678/TYPE=PLMN";
            this->header["X-MMS-Content-Location"] = "txt.txt";
        break;
        case READ_REPLY_REC_REQ:
            this->header_size = 7;
            this->header["X-MMS-Message-Type"] = "MM1_read_reply_recipient.REQ";
            this->header["X-MMS-MMS-Version"] = "1.0.0";
            this->header["To"] = "123456@mms.comverse.com,12345678/TYPE=PLMN";
            this->header["From"] = "12356425868/TYPE=PLMN";
            this->header["Message-ID"] = "<1234@1234>";
            this->header["X-MMS-Read-Status"] = "readed";
        break;
        case MMBOX_STORE_REQ:
            this->header_size = 6;
            this->header["X-MMS-Message-Type"] = "MM1_mmbox_store.REQ";
            this->header["X-MMS-Transaction-ID"] = "d56g9q2c5n";
            this->header["X-MMS-MMS-Version"] = "1.0.0";
            //类型未知
            this->header["X-MMS-Message-Reference"] = " ";
        break;
        case MMBOX_VIEW_REQ:
            this->header_size = 10;
            this->header["X-MMS-Message-Type"] = "MM1_mmbox_view.REQ";
            this->header["X-MMS-Transaction-ID"] = "d56g9q2c5n";
            this->header["X-MMS-MMS-Version"] = "1.0.0";
        break;
        case MMBOX_UPLOAD_REQ:
            this->header_size = 14;
            this->header["X-MMS-Message-Type"] = "MM1_mmbox_upload.REQ";
            this->header["X-MMS-Transaction-ID"] = "d56g9q2c5n";
            this->header["X-MMS-MMS-Version"] = "1.0.0";
            // 文本类型
            this->header["Content-Type"] = "text/plain;Name=txt.txt;Charset=utf-8";
            // Message body
        break;
        case MMBOX_DELETE_REQ:
            this->header_size = 4;
            this->header["X-MMS-Message-Type"] = "MM1_mmbox_delete.REQ";
            this->header["X-MMS-Transaction-ID"] = "d56g9q2c5n";
            this->header["X-MMS-MMS-Version"] = "1.0.0";
            this->header["X-MMS-Request-Text"] = "000 Ok";
    }
}