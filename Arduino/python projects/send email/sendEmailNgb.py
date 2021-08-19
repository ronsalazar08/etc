#!/usr/bin/env python
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email import encoders

email_user = 'ttechcontractordata@gmail.com'
email_password = 'ttechdata1'
#email_send = ['n.villanueva@yazaki-torres.com', 'a.landaos@yazaki-torres.com']
email_send = 'a.landaos@yazaki-torres.com'

subject = 'ATTENDANCE OF NGB'

msg = MIMEMultipart()
msg['From'] = email_user
msg['To'] = email_send
#msg['To'] = ", ".join(email_send)
msg['Subject'] = subject

body = 'Please See Attached File'
msg.attach(MIMEText(body,'plain'))

filename='NgbAttendanceLastWeek.pdf'
filename1='NgbAttendanceCurrentWeek.pdf'
attachment  =open(filename,'rb')
attachment1  =open(filename1,'rb')

part = MIMEBase('application','octet-stream')
part1 = MIMEBase('application','octet-stream')
part.set_payload((attachment).read())
part1.set_payload((attachment1).read())
encoders.encode_base64(part)
encoders.encode_base64(part1)
part.add_header('Content-Disposition',"attachment; filename= "+filename)
part1.add_header('Content-Disposition',"attachment; filename= "+filename1)

msg.attach(part)
msg.attach(part1)
text = msg.as_string()
server = smtplib.SMTP('smtp.gmail.com',587)
server.starttls()
server.login(email_user,email_password)


server.sendmail(email_user,email_send,text)
server.quit()
