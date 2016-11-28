#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: anchen
# @Date:   2016-11-28 16:53:42
# @Last Modified by:   anchen
# @Last Modified time: 2016-11-28 18:20:53
from messaging.mms.message import MMSMessage, MMSMessagePage

text = ''
mms = MMSMessage()
slide1 = MMSMessagePage()
with open('data/text.txt','r') as f:
    text = f.read()
slide1.add_text(text)
mms.add_page(slide1)
mms.to_file("data/mms_body.mms")