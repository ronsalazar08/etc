#!/usr/bin/env python

import schedule
import time
import os 

def job():
    os.system('python toPdfCurrentWeekBlairwin.py')
    os.system('python toPdfLastWeekBlairwin.py')
    os.system('python toPdfCurrentWeekNgb.py')
    os.system('python toPdfLastWeekNgb.py')

def send():
    os.system('python sendEmailBlairwin.py')
    os.system('python sendEmailNgb.py')
    
#schedule.every(1).minutes.do(job)
#schedule.every().hour.do(job)
#schedule.every().day.at("10:30").do(job)
#chedule.every(5).to(10).minutes.do(job)
#schedule.every().monday.do(job)
schedule.every().tuesday.at("9:00").do(job)
schedule.every().tuesday.at("9:01").do(send)
schedule.every().thursday.at("9:00").do(job)
schedule.every().thursday.at("9:01").do(send)
schedule.every().saturday.at("9:00").do(job)
schedule.every().saturday.at("9:01").do(send)

while True:
    schedule.run_pending()
    time.sleep(1)
