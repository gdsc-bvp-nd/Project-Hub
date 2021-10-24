#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import pywhatkit as kit
try:
    kit.sendwhatmsg("enter number",
                      "send message",
						23, 6)  # set time 24hour format
    print("Successfully Sent!")

except:
    print("An Unexpected Error!")

