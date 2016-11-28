#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: anchen
# @Date:   2016-11-28 16:08:32
# @Last Modified by:   anchen
# @Last Modified time: 2016-11-28 16:08:50
from messaging.mms.message import MMSMessage, MMSMessagePage
mms = MMSMessage()
slide1 = MMSMessagePage()
slide1.add_text('hello world')
mms.add_page(slide1)
mms.to_file('mms_body.mms')