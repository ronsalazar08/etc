#!/usr/bin/python
import RPi.GPIO
import sys
import time
import datetime
import sqlite3
import os.path
import new_design
import pymssql
import socket
import subprocess
import os
from PIL import Image
from sqlite3 import Error
from uuid import getnode as get_mac
from new_design import Ui_MainWindow
from PyQt5.QtGui import QIcon, QPixmap
from PyQt5 import QtCore, QtGui, QtWidgets
from datetime import date,timedelta
from time import gmtime, strftime
from mfrc522 import SimpleMFRC522
RPi.GPIO.setwarnings(False)

def write_file(data, filename):
    with open(filename, 'wb') as file:
        file.write(data)
    file.close()


def write_error(errmsg):
    with open('error.txt', 'a+') as file:
        file.write(errmsg+"----------------------------"+str(datetime.datetime.now().replace(microsecond=0))+"\n")
    file.close()


def cvt_serial(uid):
    buff = ''
    for i in uid:
        if len(str(format(i,'x'))) < 2:
            buff=buff+"0"+str(format(i,'x'))
        else:
            buff = buff + str(format(i,'x'))
    return buff


trans = ''
transaction = ''
transaction_code = ''
transactionCode = ''
date1 = time.strftime("%m/%d/%Y")
time2 = time.strftime('%H:%M:%S')

# get mac address
mac_temp = get_mac()
mac = ''.join(("%012X" % mac_temp)[i:i+2] for i in range(0, 12, 2))
# get host name
host_name = socket.gethostname()
# get ip address
ip_address = socket.gethostbyname(socket.gethostname())

print(mac)
print(host_name)
print(ip_address)

BASE_DIR = os.path.dirname(os.path.abspath(__file__))
databaselite = os.path.join(BASE_DIR, "TimeKeeping.db")
aval= " sample     "

server = "10.44.1.21"   # server = "10.44.1.21"
username = "sa"         # username = "dev"
password = "SaSql1"    # password = "dev1"
database = "LOGBOX"     # database = "LOGBOX"

isNetworkDown = False

render_flush = 0        # Lets the flush_data function to run only ONCE!
monday = 1              # Day of data flush (ie. Every monday = 1, tuesday = 2)
done = False
ttimes = 0
reader = SimpleMFRC522()
remarks = "TAP YOUR ID!"
oic = "  "
serialId = ""
serverdt = None
_translate = QtCore.QCoreApplication.translate

class mainProgram(QtWidgets.QMainWindow, Ui_MainWindow):

    def __init__(self, parent=None):
        global msg, date, timerTime, QTimer, no_network,nonet
        super(mainProgram, self).__init__(parent)  
        self.setupUi(self)
        self.lbl_id.hide()
        self.get_trigger()
        self.upload_transaction()
        no_network = False
        timerTime = QtCore.QTimer(self)
        timerTime.timeout.connect(self.timerRdr)
        timerTime.start(500)

    def servertime(self):
        global serverdate, servertime, serverdt, isNetworkDown
        try:
            a = 1 if isNetworkDown else subprocess.call(["ping",server,"-c1","-W2","-q"])
            print(a)
            if a == 0:

                try:
                    with pymssql.connect(server, username, password, database) as sqlcon:
                        cursor = sqlcon.cursor()
                        try: 
                            cursor.execute("Select getdate() ")                 
                            rows = cursor.fetchone()
                        except:
                            pass
                except:
                    rows = None
                if rows is None:
                    serverdt = datetime.datetime.now().replace(microsecond=0)
                    serverdate = serverdt.date().strftime("%m/%d/%Y")
                    servertime = str(serverdt.time()) 
                else:
                    serverdt = rows[0].replace(microsecond=0)
                    serverdate = serverdt.date().strftime("%m/%d/%Y")
                    servertime = serverdt.time().strftime("%H:%M:%S")
                print(serverdt)

                if datetime.date.today().isoweekday() == monday and time.time()>render_flush: 
                    self.flush_data()
            else:
                isNetworkDown = True
                serverdt = datetime.datetime.now().replace(microsecond=0)
                serverdate = serverdt.date().strftime("%m/%d/%Y")
                servertime = str(serverdt.time())
        except Exception as exception:
            write_error("Error 100-"+str(exception))
            serverdt = datetime.datetime.now().replace(microsecond=0)
            serverdate = serverdt.date().strftime("%m/%d/%Y")
            servertime = str(serverdt.time())     

    def get_trigger(self):
        global trans, transaction_code, transaction, transactionCode
        try:
            with sqlite3.connect(databaselite) as conn:
                cur = conn.cursor()
                if time.strftime('%M') >= '30':
                    cur.execute("SELECT triggerCode FROM trigger_tbl where triggerDay=? "
                                "and strftime('%H:%M', triggerTime)=?",
                                (time.strftime('%A'), time.strftime('%H') + ':' + '30'))
                else:
                    cur.execute("SELECT triggerCode FROM trigger_tbl where triggerDay=? "
                                "and strftime('%H:%M', triggerTime)=?",
                                (time.strftime('%A'), time.strftime('%H') + ':' + '00'))

                rows = cur.fetchone()

                transactionCode = rows[0]
                if transactionCode == 'IN':
                    transaction = "I"
                else:
                    transaction = "O"
                trans = transaction
                transaction_code = transactionCode
        except Exception as exception:
             write_error("Error 102-"+str(exception))
    
    def timerRdr(self):
        global date1, serialId, reader, date, remarks, today, ttime, serverdate, servertime, nonet, no_network, remarks, oic, ttimes, done
        try:
            self.servertime()
            if time.time()<ttimes:    
                date = serverdate
                ttime = servertime
                self.lbl_date.setText("<html><head/><body><p><span style=\" color:#FFFFFF;\">" + date +
                                  "</span></p></body></html>")
                self.lbl_time.setText("<html><head/><body><p><span style=\" color:#FFFFFF;\">" + ttime +
                                  "</span></p></body></html>")
                self.label.setStyleSheet("background:white")
                self.label.setScaledContents(True)
                self.label.setAlignment(QtCore.Qt.AlignBottom|QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing)
                self.label.setWordWrap(True)
            else:                
                self.lbl_tap.show()
                font = QtGui.QFont()
                font.setPointSize(40)
                pixmap = QtGui.QPixmap('/home/pi/Desktop/TimeKeeping/logo3.png')
                self.label_4.setPixmap(pixmap)
                self.lbl_tap.setFont(font)
                self.lbl_tap.setText(
                "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + remarks + "</span></p></body></html>")
                self.lbl_time2.hide()
                self.lbl_trigger.hide()
                self.lbl_id.hide()
                date = serverdate
                ttime = servertime
                date1 = date
                self.lbl_date.setText("<html><head/><body><p><span style=\" color:#FFFFFF;\">" + date +
                                  "</span></p></body></html>")
                self.lbl_time.setText("<html><head/><body><p><span style=\" color:#FFFFFF;\">" + ttime +
                                  "</span></p></body></html>")
                self.lbl_tap.setStyleSheet("background:transparent")
                self.lbl_inout.setText("<html><head/><body><p align=\"center\"><span style=\" color:#fff820;\">" + transaction_code + "</span></p></body></html>")
                today = datetime.datetime.now()
                serialId = ""
                uid,name_temp = reader.read()
                if uid != None:
                    ttimes=time.time()+1
                    serialId = cvt_serial(uid)[0:8].upper()
                    self.select_all_tasks(idserial=serialId)
        except Exception as exception:
            write_error("Error 103-"+str(exception))


    def select_all_tasks(self, idserial):
        global remarks, first_name, last_name, middle_name, transaction_code,trans, id_serial

        try:
            # check id serial if registered
                with sqlite3.connect(databaselite) as conn:
                    cur = conn.cursor()
                    cur.execute("SELECT id_serial,id_number,last_name,first_name,middle_name FROM employees_tbl "
                                "where id_serial=?", (idserial,))
                    rows = cur.fetchone()

                if rows is None:
                    #check server connection
                    a = 1 if isNetworkDown else subprocess.call(["ping",server,"-c1","-W2","-q"])
                    if a == 0:
                        #check id serial if registered as trigger
                        with pymssql.connect(server, username, password, database) as sqlcon:
                            cursor = sqlcon.cursor()
                            cursor.execute("Select id_serial from serial_transactions where id_serial=%s",
                                           (idserial,))
                            rows = cursor.fetchone()
                            if rows is None:
                                self.access_denied()
                                remarks = "ACCESS DENIED"
                                aval = "     "
                                self.lbl_time2.show()
                                self.lbl_trigger.show()
                                self.lbl_id.show()
                                print(remarks)

                                font = QtGui.QFont()
                                font.setFamily("Lato Black")
                                font.setPointSize(50)
                                font.setBold(True)
                                font.setWeight(75)
                                self.lbl_tap.setFont(font)

                                self.lbl_tap.setStyleSheet("background:#FF0000")
                                self.lbl_tap.setText(
                                    "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + remarks + "</span></p></body></html>")

                                font = QtGui.QFont()
                                font.setPointSize(30)
                                self.lbl_id.setFont(font)
                                self.lbl_id.setText(
                                    "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + aval + "</span></p></body></html>")
                                font = QtGui.QFont()
                                font.setPointSize(40)
                                self.lbl_time2.setFont(font)
                                self.lbl_time2.setText(
                                    "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + aval + "</span></p></body></html>")
                                font = QtGui.QFont()
                                font.setPointSize(40)
                                self.lbl_trigger.setFont(font)
                                self.lbl_trigger.setStyleSheet("background:transparent")
                                self.lbl_trigger.setText(
                                    "<html><head/><body><p align=\"center\"><span style=\" color:#fff820;\">" + aval + "</span></p></body></html>")
                                remarks = "TAP YOUR ID!"
                                self.get_trigger()
                            else:
                                if transaction_code == 'IN':
                                    transaction_code = 'OUT'
                                    trans = "O"
                                    self.lbl_inout.setText(
                                        "<html><head/><body><p><span style=\" color:#fff820;\">" + transaction_code + "</span></p></body></html>")
                                else:
                                    transaction_code = "IN"
                                    self.lbl_inout.setText(
                                        "<html><head/><body><p><span style=\" color:#fff820;\">" + transaction_code + "</span></p></body></html>")
                                    trans = "I"
                    #Not a registered employee
                    else:
                        self.access_denied()
                        remarks = "ACCESS DENIED"
                        aval = "     "
                        self.lbl_time2.show()
                        self.lbl_trigger.show()
                        self.lbl_id.show()
                        print(remarks)
                        font = QtGui.QFont()
                        font.setFamily("Lato Black")
                        font.setPointSize(50)
                        font.setBold(True)
                        font.setWeight(75)
                        self.lbl_tap.setFont(font)
                        self.lbl_tap.setStyleSheet("background:#FF0000")
                        self.lbl_tap.setText(
                            "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + remarks + "</span></p></body></html>")
                        font = QtGui.QFont()
                        font.setPointSize(30)
                        self.lbl_id.setFont(font)
                        self.lbl_id.setText(
                            "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + aval + "</span></p></body></html>")
                        font = QtGui.QFont()
                        font.setPointSize(40)
                        self.lbl_time2.setFont(font)
                        self.lbl_time2.setText(
                            "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + aval + "</span></p></body></html>")
                        font = QtGui.QFont()
                        font.setPointSize(40)
                        self.lbl_trigger.setFont(font)
                        self.lbl_trigger.setStyleSheet("background:transparent")
                        self.lbl_trigger.setText(
                            "<html><head/><body><p align=\"center\"><span style=\" color:#fff820;\">" + aval + "</span></p></body></html>") 
                        remarks = "TAP YOUR ID!"
                        self.get_trigger()
                #Registered employee proceed to validation
                else:
                    id_serial = rows[0]
                    id_number = rows[1]
                    first_name = rows[3]
                    last_name = rows[2]
                    middle_name = rows[4]
                    cur.close()

                    if id_serial== serialId:
                        self.check_repeated(idnum=id_number)

                    else:
                        self.access_denied()
                        remarks = "ACCESS DENIED"
                        aval = "     "
                        self.lbl_time2.show()
                        self.lbl_trigger.show()
                        self.lbl_id.show()
                        print(remarks)

                        font = QtGui.QFont()
                        font.setFamily("Lato Black")
                        font.setPointSize(50)
                        font.setBold(True)
                        font.setWeight(75)
                        self.lbl_tap.setFont(font)

                        self.lbl_tap.setStyleSheet("background:#FF0000")
                        self.lbl_tap.setText(
                            "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + remarks + "</span></p></body></html>")

                        font = QtGui.QFont()
                        font.setPointSize(30)
                        self.lbl_id.setFont(font)
                        self.lbl_id.setText(
                            "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + aval + "</span></p></body></html>")
                        font = QtGui.QFont()
                        font.setPointSize(40)
                        self.lbl_time2.setFont(font)
                        self.lbl_time2.setText(
                            "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + aval + "</span></p></body></html>")
                        font = QtGui.QFont()
                        font.setPointSize(40)
                        self.lbl_trigger.setFont(font)
                        self.lbl_trigger.setStyleSheet("background:transparent")
                        self.lbl_trigger.setText(
                            "<html><head/><body><p align=\"center\"><span style=\" color:#fff820;\">" + aval + "</span></p></body></html>")

                        font = QtGui.QFont()
                        font.setPointSize(60)
                        self.lbl_tap.setFont(font)
                        remarks = "TAP YOUR ID!"
                        self.get_trigger()

        except Exception as exception:
            write_error("Error 104-"+str(exception))
            self.access_denied()

    #Check if the transaction is repeated
    def check_repeated(self, idnum):
        global remarks,serverdate,serverdt
        try:
            # test server connection
            a = 1 if isNetworkDown else subprocess.call(["ping",server,"-c1","-W2","-q"])
            
            if a == 0: #If there is connection
                with pymssql.connect(server, username, password, database) as sqlcon:
                    cursor = sqlcon.cursor()
                    cursor.execute("select id_number,transaction_code FROM logbox_tbl where id_number=%s and "
                                   "CONVERT(VARCHAR(10), transaction_date, 101)=%s ORDER BY transaction_date DESC",
                                   (idnum, serverdt.date().strftime("%m/%d/%Y")))
                    try:
                    	rows = cursor.fetchall()
                    except Exception as e:
                    	rows = None
                    try:
                        for row in rows[0][1]:
                            if row != trans and len(rows) < 6:
                                self.insert_accepted(idnumber=idnum)
                                remarks = str(last_name) + ',' + str(first_name) + ' ' + str(middle_name)
                                self.lbl_trigger.show()
                                self.lbl_time2.show()
                                font = QtGui.QFont()
                                font.setFamily("Lato Black")
                                font.setPointSize(30)
                                font.setBold(True)
                                font.setWeight(75)
                                self.lbl_tap.setFont(font)
                                self.lbl_tap.setText("<html><head/><body><p><span style=\" color:#FFFFFF;\">" + remarks + "</span></p></body></html>")
                                self.lbl_id.show()
                                font = QtGui.QFont()
                                font.setFamily("Lato Black")
                                font.setPointSize(30)
                                font.setBold(True)
                                font.setWeight(75)
                                self.lbl_id.setFont(font)
                                self.lbl_id.setFont(font)
                                self.lbl_id.setText("<html><head/><body><p><span style=\" color:#FFFFFF;\">" + idnum + "</span></p></body></html>")
                                font = QtGui.QFont()
                                font.setFamily("Lato Black")
                                font.setPointSize(40)
                                font.setBold(True)
                                font.setWeight(75)
                                self.lbl_time2.setFont(font)
                                self.lbl_time2.setText("<html><head/><body><p><span style=\" color:#FFFFFF;\">" + ttime + "</span></p></body></html>")
                                font = QtGui.QFont()
                                font.setFamily("Lato Black")
                                font.setPointSize(40)
                                font.setBold(True)
                                font.setWeight(75)
                                self.lbl_trigger.setFont(font)
                                self.lbl_trigger.setStyleSheet("background:#137313")
                                self.lbl_trigger.setText("<html><head/><body><p align=\"center\"><span style=\" color:#FFFFFF;\">" + transaction_code + "</span></p></body></html>")   
                                
                                mydb = pymssql.connect(server,username,password,database)
                                SqlQuery = " select picture from employees_tbl where id_serial = '"+str(id_serial)+"'"
                                curs = mydb.cursor()     #Verify if the user exist on Database
                                curs.execute(SqlQuery)   #And put her'his BOOL img to variable "records"
                                records = curs.fetchall()
                                for i in records:
                                    temp = i

                                if curs.rowcount == 1:
                                    write_file(temp[0],'temp.png')
                                    im = Image.open("temp.png")
                                    im_resized = im.resize((155,207), Image.ANTIALIAS)
                                    im_resized.save("temp.png", "PNG")
                                    im.close()
                                    pixmap = QtGui.QPixmap('/home/pi/Desktop/TimeKeeping/temp.png')
                                    self.label_4.setPixmap(pixmap)
                                    
                                else:
                                    pixmap = QtGui.QPixmap('/home/pi/Desktop/TimeKeeping/logo3.png')
                                    self.label_4.setPixmap(pixmap)
                                remarks = "Tap your ID"
                                self.get_trigger()
                                

                            else:
                                cursor.close()
                                remarks = "REPEATED TRANSACTION"
                                aval = "     "
                                self.lbl_time2.show()
                                self.lbl_trigger.show()
                                self.lbl_id.show()
                                print(remarks)
                                font = QtGui.QFont()
                                font.setFamily("Lato Black")
                                font.setPointSize(40)
                                font.setBold(True)
                                font.setWeight(75)
                                self.lbl_tap.setFont(font)
                                self.lbl_tap.setStyleSheet("background:#000000")
                                self.lbl_tap.setText("<html><head/><body><p><span style=\" color:#FF0505;\">" + remarks + "</span></p></body></html>")
                                font = QtGui.QFont()
                                font.setPointSize(20)
                                self.lbl_id.setFont(font)
                                self.lbl_id.setText(
                                        "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + aval + "</span></p></body></html>")
                                font = QtGui.QFont()
                                font.setPointSize(20)
                                self.lbl_time2.setFont(font)
                                self.lbl_time2.setText(
                                        "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + aval + "</span></p></body></html>")
                                font = QtGui.QFont()
                                font.setPointSize(20)
                                self.lbl_trigger.setFont(font)
                                self.lbl_trigger.setStyleSheet("background:transparent")
                                self.lbl_trigger.setText(
                                        "<html><head/><body><p align=\"center\"><span style=\" color:#fff820;\">" + aval + "</span></p></body></html>")
                                self.duplicate(idnumber=idnum)
                                remarks = "Tap your ID"
                                self.get_trigger()
                    except:
                        self.insert_accepted(idnumber=idnum)
                        remarks = str(last_name) + ',' + str(first_name) + ' ' + str(middle_name)
                        self.lbl_trigger.show()
                        self.lbl_time2.show()
                        font = QtGui.QFont()
                        font.setFamily("Lato Black")
                        font.setPointSize(30)
                        font.setBold(True)
                        font.setWeight(75)
                        self.lbl_tap.setFont(font)
                        self.lbl_tap.setText("<html><head/><body><p><span style=\" color:#FFFFFF;\">" + remarks + "</span></p></body></html>")
                        self.lbl_id.show()
                        font = QtGui.QFont()
                        font.setFamily("Lato Black")
                        font.setPointSize(30)
                        font.setBold(True)
                        font.setWeight(75)
                        self.lbl_id.setFont(font)
                        self.lbl_id.setFont(font)
                        self.lbl_id.setText("<html><head/><body><p><span style=\" color:#FFFFFF;\">" + idnum + "</span></p></body></html>")
                        font = QtGui.QFont()
                        font.setFamily("Lato Black")
                        font.setPointSize(40)
                        font.setBold(True)
                        font.setWeight(75)
                        self.lbl_time2.setFont(font)
                        self.lbl_time2.setText("<html><head/><body><p><span style=\" color:#FFFFFF;\">" + ttime + "</span></p></body></html>")
                        font = QtGui.QFont()
                        font.setFamily("Lato Black")
                        font.setPointSize(40)
                        font.setBold(True)
                        font.setWeight(75)
                        self.lbl_trigger.setFont(font)
                        self.lbl_trigger.setStyleSheet("background:#137313")
                        self.lbl_trigger.setText("<html><head/><body><p align=\"center\"><span style=\" color:#FFFFFF;\">" + transaction_code + "</span></p></body></html>")   
                                    
                        mydb = pymssql.connect(server,username,password,database)
                        SqlQuery = " select picture from employees_tbl where id_serial = '"+str(id_serial)+"'"
                        curs = mydb.cursor()     #Verify if the user exist on Database
                        curs.execute(SqlQuery)   #And put her'his BOOL img to variable "records"
                        records = curs.fetchall()
                        for i in records:
                            temp = i

                        if curs.rowcount == 1:
                            write_file(temp[0],'temp.png')
                            im = Image.open("temp.png")
                            im_resized = im.resize((155,207), Image.ANTIALIAS)
                            im_resized.save("temp.png", "PNG")
                            im.close()
                            pixmap = QtGui.QPixmap('/home/pi/Desktop/TimeKeeping/temp.png')
                            self.label_4.setPixmap(pixmap)
                                        
                        else:
                            pixmap = QtGui.QPixmap('/home/pi/Desktop/TimeKeeping/logo3.png')
                            self.label_4.setPixmap(pixmap)
                        remarks = "Tap your ID"
                        self.get_trigger()
                        
            #No connection
            else:
                errormsg = "Unable to connect to Logbox server. Please contact IT-TTECH1"
                write_error(errormsg)
               
                with sqlite3.connect(databaselite) as conn:
                    cur = conn.cursor()
                    cur.execute("SELECT id_number FROM logbox_tbl where id_number=? "
                                "and strftime('%m/%d/%Y', transaction_date)=?"
                                " and transaction_code=?", (idnum, time.strftime("%m/%d/%Y"), trans))
                    try:
                    	rows = cur.fetchone()
                    except Exception as e:
                        print(str(e))
                        rows = None
                    print(rows)
                    if rows is None:
                        cur.execute("INSERT INTO logbox_tbl(id_number,transaction_date,transaction_code,upload_flag,"
                                    "mac_add,ip_add,comp_name) values (?,?,?,?,?,?,?)",
                                    (idnum, serverdt, trans, None, mac, ip_address, host_name))
                        conn.commit()
                        cur.close()
                        remarks = last_name + ',' + first_name + ' ' + middle_name
                        self.lbl_trigger.show()
                        self.lbl_time2.show()
                        font = QtGui.QFont()
                        font.setFamily("Lato Black")
                        font.setPointSize(30)
                        font.setBold(True)
                        font.setWeight(75)
                        self.lbl_tap.setFont(font)
                        self.lbl_tap.setText(
                            "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + remarks + "</span></p></body></html>")
                        self.lbl_id.show()
                        font = QtGui.QFont()
                        font.setFamily("Lato Black")
                        font.setPointSize(30)
                        font.setBold(True)
                        font.setWeight(75)
                        self.lbl_id.setFont(font)
                        self.lbl_id.setText(
                            "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + idnum + "</span></p></body></html>")
                        font = QtGui.QFont()
                        font.setFamily("Lato Black")
                        font.setPointSize(40)
                        font.setBold(True)
                        font.setWeight(75)
                        self.lbl_time2.setFont(font)
                        self.lbl_time2.setText("<html><head/><body><p><span style=\" color:#FFFFFF;\">" + ttime + "</span></p></body></html>")
                        font = QtGui.QFont()
                        font.setFamily("Lato Black")
                        font.setPointSize(40)
                        font.setBold(True)
                        font.setWeight(75)
                        self.lbl_trigger.setFont(font)
                        self.lbl_trigger.setStyleSheet("background:#137313")
                        self.lbl_trigger.setText(
                            "<html><head/><body><p align=\"center\"><span style=\" color:#FFFFFF;\">" + transaction_code + "</span></p></body></html>")
                        remarks = "Tap your ID"
                        self.get_trigger()
                    else:
                        remarks = "REPEATED TRANSACTION"
                        aval = "     "
                        self.lbl_time2.show()
                        self.lbl_trigger.show()
                        self.lbl_id.show()
                        print(remarks)
                        font = QtGui.QFont()
                        font.setFamily("Lato Black")
                        font.setPointSize(40)
                        font.setBold(True)
                        font.setWeight(75)
                        self.lbl_tap.setFont(font)
                        self.lbl_tap.setStyleSheet("background:#000000")
                        self.lbl_tap.setText("<html><head/><body><p><span style=\" color:#FF0505;\">" + remarks + "</span></p></body></html>")
                        font = QtGui.QFont()
                        font.setPointSize(20)
                        self.lbl_id.setFont(font)
                        self.lbl_id.setText(
                            "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + aval + "</span></p></body></html>")
                        font = QtGui.QFont()
                        font.setPointSize(20)
                        self.lbl_time2.setFont(font)
                        self.lbl_time2.setText(
                            "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + aval + "</span></p></body></html>")
                        font = QtGui.QFont()
                        font.setPointSize(20)
                        self.lbl_trigger.setFont(font)
                        self.lbl_trigger.setStyleSheet("background:transparent")
                        self.lbl_trigger.setText(
                            "<html><head/><body><p align=\"center\"><span style=\" color:#fff820;\">" + aval + "</span></p></body></html>")
                        self.duplicate(idnumber=idnum)
                        remarks = "Tap your ID"
                        self.get_trigger()
                        
        except Exception as exception:
            print(str(exception)+ "1")
            write_error("Connection Error-"+str(exception))
            
            with sqlite3.connect(databaselite) as conn:
                
                cur = conn.cursor()
                cur.execute("SELECT id_number FROM logbox_tbl where id_number=? "
                            "and strftime('%m/%d/%Y', transaction_date)=?"
                            " and transaction_code=?", (idnum, serverdate, trans))
                try:
                    rows = cursor.fetchone()
                except Exception as e:
                    rows = None
                if rows is None:
                    cur = conn.cursor()
                    cur.execute("INSERT INTO logbox_tbl(id_number,transaction_date,transaction_code,upload_flag,"
                                "mac_add,ip_add,comp_name) values (?,?,?,?,?,?,?)",
                                (idnum, serverdt, trans, None, mac, ip_address, host_name))
                    conn.commit()
                    cur.close()
                    remarks = last_name + ',' + first_name + ' ' + middle_name
                    self.lbl_trigger.show()
                    self.lbl_time2.show()
                    font = QtGui.QFont()
                    font.setFamily("Lato Black")
                    font.setPointSize(30)
                    font.setBold(True)
                    font.setWeight(75)
                    self.lbl_tap.setFont(font)
                    self.lbl_tap.setText(
                        "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + remarks + "</span></p></body></html>")
                    self.lbl_id.show()
                    font = QtGui.QFont()
                    font.setFamily("Lato Black")
                    font.setPointSize(30)
                    font.setBold(True)
                    font.setWeight(75)
                    self.lbl_id.setFont(font)

                    self.lbl_id.setText(
                        "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + idnum + "</span></p></body></html>")
                    font = QtGui.QFont()
                    font.setFamily("Lato Black")
                    font.setPointSize(40)
                    font.setBold(True)
                    font.setWeight(75)
                    self.lbl_time2.setFont(font)
                    self.lbl_time2.setText("<html><head/><body><p><span style=\" color:#FFFFFF;\">" + ttime + "</span></p></body></html>")
                    font = QtGui.QFont()
                    font.setFamily("Lato Black")
                    font.setPointSize(40)
                    font.setBold(True)
                    font.setWeight(75)
                    self.lbl_trigger.setFont(font)
                    self.lbl_trigger.setStyleSheet("background:#137313")
                    self.lbl_trigger.setText(
                        "<html><head/><body><p align=\"center\"><span style=\" color:#FFFFFF;\">" + transaction_code + "</span></p></body></html>")
                    remarks = "Tap your ID"
                    self.get_trigger()
                else:
                    remarks = "REPEATED TRANSACTION"
                    aval = "     "
                    self.lbl_time2.show()
                    self.lbl_trigger.show()
                    self.lbl_id.show()
                    print(remarks)
                    font = QtGui.QFont()
                    font.setFamily("Lato Black")
                    font.setPointSize(40)
                    font.setBold(True)
                    font.setWeight(75)
                    self.lbl_tap.setFont(font)
                    self.lbl_tap.setStyleSheet("background:#000000")
                    self.lbl_tap.setText("<html><head/><body><p><span style=\" color:#FF0505;\">" + remarks + "</span></p></body></html>")
                    font = QtGui.QFont()
                    font.setPointSize(20)
                    self.lbl_id.setFont(font)
                    self.lbl_id.setText(
                        "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + aval + "</span></p></body></html>")
                    font = QtGui.QFont()
                    font.setPointSize(20)
                    self.lbl_time2.setFont(font)
                    self.lbl_time2.setText(
                        "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + aval + "</span></p></body></html>")
                    font = QtGui.QFont()
                    font.setPointSize(20)
                    self.lbl_trigger.setFont(font)
                    self.lbl_trigger.setStyleSheet("background:transparent")
                    self.lbl_trigger.setText(
                        "<html><head/><body><p align=\"center\"><span style=\" color:#fff820;\">" + aval + "</span></p></body></html>")
                    self.duplicate(idnumber=idnum)
                    remarks = "Tap your ID"
                    self.get_trigger()

    def insert_accepted(self, idnumber):
        global remarks,serverdt
        try:
            a = 1 if isNetworkDown else subprocess.call(["ping",server,"-c1","-W2","-q"])
            #Check server connection
            if a == 0:
                with pymssql.connect(server, username, password, database) as sqlcon:
                        cursor = sqlcon.cursor()
                        cursor.execute(
                            "Insert into logbox_tbl(id_number,transaction_date,transaction_code,mac_add,ip_add,comp_name) "
                            "values(%s,%s,%s,%s,%s,%s)", (idnumber, serverdt, trans, mac, ip_address, host_name))
                        sqlcon.commit()
                        cursor.close()

                with sqlite3.connect(databaselite) as conn:
                    try:
                        cur = conn.cursor()
                        cur.execute("INSERT INTO logbox_tbl(id_number,transaction_date,transaction_code,upload_flag,"
                                "mac_add,ip_add,comp_name) values (?,?,?,?,?,?,?)",
                                (idnumber, serverdt, trans, None, mac, ip_address, host_name))
                        conn.commit()
                        cur.close()

                        print(str(today))
                        print(trans)

                        cur = conn.cursor()
                        cur.execute("UPDATE logbox_tbl set upload_flag = '1' where id_number=? and "
                                    "strftime('%m/%d/%Y', transaction_date)=? and transaction_code=?",
                                    (idnumber, time.strftime("%m/%d/%Y"), trans))
                        conn.commit()
                        cur.close()
                    except Exception as e:
                        if str(e) == 'database disk image is malformed':
                            pass
                        else:
                            raise e
            else:
                errormsg = "Unable to connect to Logbox server. Please contact IT-TTECH3"
                write_error(errormsg)
                
                with sqlite3.connect(databaselite) as conn:
                    cur = conn.cursor()
                    try:
                        cur.execute("SELECT id_number FROM logbox_tbl where id_number=? "
                                "and strftime('%m/%d/%Y', transaction_date)=?"
                                " and transaction_code=?", (idnumber, serverdate, trans))
                    
                        rows = cursor.fetchone()
                    except Exception as e:
                    	rows = None
                    if rows is None:
                        cur = conn.cursor()
                        cur.execute("INSERT INTO logbox_tbl(id_number,transaction_date,transaction_code,upload_flag,"
                                    "mac_add,ip_add,comp_name) values (?,?,?,?,?,?,?)",
                                    (idnumber, serverdt, trans, None, mac, ip_address, host_name))
                        conn.commit()
                        cur.close()
                    else:
                        self.duplicate(idnumber=idnumber)
                        remarks = "REPEATED TRANSACTION"
                        aval = "     "
                        self.lbl_time2.show()
                        self.lbl_trigger.show()
                        self.lbl_id.show()
                        print(remarks)

                        font = QtGui.QFont()
                        font.setFamily("Lato Black")
                        font.setPointSize(40)
                        font.setBold(True)
                        font.setWeight(75)
                        self.lbl_tap.setFont(font)
                        self.lbl_tap.setStyleSheet("background:#000000")
                        self.lbl_tap.setText("<html><head/><body><p><span style=\" color:#FF0505;\">" + remarks + "</span></p></body></html>")
                        font = QtGui.QFont()
                        font.setPointSize(20)
                        self.lbl_id.setFont(font)
                        self.lbl_id.setText(
                            "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + aval + "</span></p></body></html>")
                        font = QtGui.QFont()
                        font.setPointSize(20)
                        self.lbl_time2.setFont(font)
                        self.lbl_time2.setText(
                            "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + aval + "</span></p></body></html>")
                        font = QtGui.QFont()
                        font.setPointSize(20)
                        self.lbl_trigger.setFont(font)
                        self.lbl_trigger.setStyleSheet("background:transparent")
                        self.lbl_trigger.setText(
                            "<html><head/><body><p align=\"center\"><span style=\" color:#fff820;\">" + aval + "</span></p></body></html>")
                        remarks = "Tap your ID"
                        self.get_trigger()
        except Exception as exception:
            write_error("Connection Error-"+str(exception))
           
            with sqlite3.connect(databaselite) as conn:
                cur = conn.cursor()
                try:
                    cur.execute("SELECT id_number FROM logbox_tbl where id_number=? "
                            "and strftime('%m/%d/%Y', transaction_date)=?"
                            " and transaction_code=?", (idnumber, serverdate, trans))
                    rows = cursor.fetchone()
                except Exception as e:
                    rows = None
                if rows is None:
                    cur = conn.cursor()
                    cur.execute("INSERT INTO logbox_tbl(id_number,transaction_date,transaction_code,upload_flag,"
                                "mac_add,ip_add,comp_name) values (?,?,?,?,?,?,?)",
                                (idnumber, serverdt, trans, None, mac, ip_address, host_name))
                    conn.commit()
                    cur.close()
                else:
                    self.duplicate(idnumber=idnumber)
                    remarks = "REPEATED TRANSACTION"
                    aval = "     "
                    self.lbl_time2.show()
                    self.lbl_trigger.show()
                    self.lbl_id.show()
                    print(remarks)
                    font = QtGui.QFont()
                    font.setFamily("Lato Black")
                    font.setPointSize(40)
                    font.setBold(True)
                    font.setWeight(75)
                    self.lbl_tap.setFont(font)
                    self.lbl_tap.setStyleSheet("background:#000000")
                    self.lbl_tap.setText("<html><head/><body><p><span style=\" color:#FF0505;\">" + remarks + "</span></p></body></html>")
                    font = QtGui.QFont()
                    font.setPointSize(20)
                    self.lbl_id.setFont(font)
                    self.lbl_id.setText(
                        "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + aval + "</span></p></body></html>")
                    font = QtGui.QFont()
                    font.setPointSize(20)
                    self.lbl_time2.setFont(font)
                    self.lbl_time2.setText(
                        "<html><head/><body><p><span style=\" color:#FFFFFF;\">" + aval + "</span></p></body></html>")
                    font = QtGui.QFont()
                    font.setPointSize(20)
                    self.lbl_trigger.setFont(font)
                    self.lbl_trigger.setStyleSheet("background:transparent")
                    self.lbl_trigger.setText(
                        "<html><head/><body><p align=\"center\"><span style=\" color:#fff820;\">" + aval + "</span></p></body></html>")
                    remarks = "Tap your ID"
                    self.get_trigger()

    def access_denied(self):
        global serverdt,serialId,trans
        
        try:
            with sqlite3.connect(databaselite) as conn:
                cur = conn.cursor()
                cur.execute("INSERT INTO denied_tbl(id_serial,transaction_date,transaction_code) values (?,?,?)",
                            (serialId, serverdt, trans))
                conn.commit()
                self.get_trigger()
        except Exception as exception:
            write_error("Error 105-"+str(exception))

    def duplicate(self, idnumber):
        global serverdt,serialId,trans
        try:
            with sqlite3.connect(databaselite) as conn:
                cur = conn.cursor()
                cur.execute("INSERT INTO duplicate_tbl(id_number,transaction_date,transaction_code) values (?,?,?)",
                            (idnumber, serverdt, trans))
                conn.commit()
        except Exception as exception:
            write_error("Error 106-"+str(exception))
    
    
    def flush_data(self):
        global serverdt, render_flush
        try:
            print("Flushing datas")
            #flush DENIED TABLE
            with sqlite3.connect(databaselite) as sqlite:
                curso = sqlite.cursor()
                cursors = sqlite.cursor()
                temp = ""
                get_data = "SELECT * FROM denied_tbl WHERE strftime('%Y-%m-%d', transaction_date) BETWEEN " + '"'  + (serverdt - timedelta(days = 14)).strftime("%Y-%m-%d") +  '"' + " AND " + '"' + (serverdt - timedelta(days = 7)).strftime("%Y-%m-%d") + '"' + ";"
                delete_data = "DELETE FROM denied_tbl WHERE strftime('%Y-%m-%d', transaction_date) BETWEEN " + '"'  + (serverdt - timedelta(days = 14)).strftime("%Y-%m-%d") +  '"' + " AND " + '"' + (serverdt - timedelta(days = 7)).strftime("%Y-%m-%d") + '"' + ";"
                delete_log_data = "DELETE FROM logbox_tbl WHERE strftime('%Y-%m-%d', transaction_date) <= " + '"' + (serverdt - timedelta(days = 14)).strftime("%Y-%m-%d") +  '"'
                curso.execute(get_data)
                rows = None
                try:
                    rows = curso.fetchall()
                except Exception as e:
                    rows = None
                if rows != None:
                    for row in rows:
                        self.upload_data_before_flush('denied_tbl', row[0], row[1], row[2])
                    cursors.execute(delete_data)
                    cursors.execute(delete_log_data)
                    sqlite.commit()
                curso.close()
                cursors.close()
            #flush DUPLICATE TABLE
            with sqlite3.connect(databaselite) as sqlites:
                cursor = sqlites.cursor()
                cursorss = sqlites.cursor()
                get_data = "SELECT * FROM duplicate_tbl WHERE strftime('%Y-%m-%d', transaction_date) BETWEEN " + '"'  + (serverdt - timedelta(days = 14)).strftime("%Y-%m-%d") +  '"' + " AND " + '"' + (serverdt - timedelta(days = 7)).strftime("%Y-%m-%d") + '"' + ";"
                delete_data = "DELETE FROM duplicate_tbl WHERE strftime('%Y-%m-%d', transaction_date) BETWEEN " + '"'  + (serverdt - timedelta(days = 14)).strftime("%Y-%m-%d") +  '"' + " AND " + '"' + (serverdt - timedelta(days = 7)).strftime("%Y-%m-%d") + '"' + ";"
                cursor.execute(get_data)
                try:
                    rows = cursor.fetchall()
                except Exception as e:
                    rows = None
                if rows != None:
                    for row in rows:
                        self.upload_data_before_flush('duplicate_tbl', row[0], row[1], row[2])
                    cursorss.execute(delete_data)
                    sqlites.commit()
                cursor.close()
                cursorss.close()
            render_flush = time.time() + 86400
            sqlite.close()
            sqlites.close()
            print("Flushing done")
        except Exception as e:
            write_error("flush_data failed during E=" + str(e))


    def upload_data_before_flush(self, table, upload_id, trans_date, code):
        try:
            
            with pymssql.connect(server, username, password, database) as mssql:
                curs = mssql.cursor()
                curs.execute(
                            "Insert into " + table +
                            " values (%s,%s,%s)", (upload_id, datetime.datetime.strptime(trans_date,"%Y-%m-%d %H:%M:%S.%f"), code,))
                mssql.commit()
                curs.close()
            mssql.close()

        except Exception as e:
            
            with pymssql.connect(server, username, password, database) as mssql:
                curs = mssql.cursor()
                curs.execute(
                            "Insert into " + table +
                            " values (%s,%s,%s)", (upload_id, datetime.datetime.strptime(trans_date,"%Y-%m-%d %H:%M:%S"), code,))
                mssql.commit()
                curs.close()
            mssql.close()
            write_error("upload_data_before_flush error during E=" + str(e))


    def check_repeated_upload(self, upload_id, trans_date, code):
        
        try:
            with pymssql.connect(server, username, password, database) as sqlcon:
                cursor = sqlcon.cursor()
                cursor.execute("select id_number FROM logbox_tbl where id_number=%s and "
                                    "CONVERT(VARCHAR(10), transaction_date, 101)=%s and transaction_code=%s",
                                    (upload_id, datetime.datetime.strptime(trans_date,"%Y-%m-%d %H:%M:%S").strftime('%m/%d/%Y'), code))
                try:
                    row = cursor.fetchone()
                except Exception as e:
                    print(str(e))
                    row = None
                cursor.close()

                if row == None:
                    cursor = sqlcon.cursor()
                    cursor.execute(
                                "Insert into logbox_tbl(id_number,transaction_date,transaction_code,mac_add,ip_add,comp_name) "
                                "values(%s,%s,%s,%s,%s,%s)", (upload_id, trans_date, code, mac, ip_address, host_name))
                    sqlcon.commit()
                    cursor.close()
                    with sqlite3.connect(databaselite) as conn:
                        cur = conn.cursor()
                        cur.execute("UPDATE logbox_tbl set upload_flag = '1' where id_number=? and "
                                    "strftime('%m/%d/%Y', transaction_date)=? and transaction_code=?",
                                    (upload_id, datetime.datetime.strptime(trans_date,"%Y-%m-%d %H:%M:%S").strftime('%m/%d/%Y'), code))
                        conn.commit()
                        cur.close()
            sqlcon.close()
            conn.close()
        except Exception as e:
            print(str(e))
            write_error("Upload Un-uploaded transactions failed "+str(e))

    
    def upload_transaction(self):

        a = subprocess.call(["ping",server,"-c1","-W2","-q"])
        if a == 0:
            print('Uploading transactions!')
            try:

                with sqlite3.connect(databaselite) as conn:
                    cur = conn.cursor()
                    cur.execute("SELECT id_number,transaction_date,transaction_code FROM logbox_tbl WHERE upload_flag IS NULL")
                    
                    try:
                        rows = cur.fetchall()
                    except:
                        rows = None

                    if rows != None:
                        for row in rows:
                            self.check_repeated_upload(row[0], row[1], row[2])
                print('Upload done!')
            except Exception as exception:
                print(str(exception))
                write_error("Upload Un-uploaded transactions failed "+str(exception))
        else:
            pass   


if __name__ == "__main__":

    import sys
    app = QtWidgets.QApplication(sys.argv)
    Ui_MainWindow = mainProgram()
    Ui_MainWindow.showFullScreen()
    sys.exit(app.exec_())
