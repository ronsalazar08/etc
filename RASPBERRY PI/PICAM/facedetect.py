#!/usr/bin/python
from picamera.array import PiRGBArray
from picamera import PiCamera
#from pynput.keyboard import Key, Controller
import time
import cv2
import os
import numpy as np

camera = PiCamera()
camera.resolution = (960, 544)
camera.framerate = 32
rawCapture = PiRGBArray(camera, size=(960, 544))
#keyboard = Controller()

recognizer = cv2.createLBPHFaceRecognizer()
recognizer.load('trainner/trainner.yml')
time.sleep(0.1)


for frame in camera.capture_continuous(rawCapture, format="bgr", use_video_port=True):

    image = frame.array
    face_cascade = cv2.CascadeClassifier('/home/pi/opencv-3.3.0/data/lbpcascades/lbpcascade_frontalface_improved.xml')
    gray = cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, 1.1, 5)   
    for(x,y,w,h) in faces:
            cv2.rectangle(image,(x,y),(x+w,y+h),(225,0,0),2)
            Id, conf = recognizer.predict(gray[y:y+h,x:x+w])
            nameId = 'UNKNOWN' 
                               
            if(conf<50):
                if(Id==3):
	              nameId='TOLITS'
	              
                if(Id==4):
                  nameId='RON'                                                       
                  
            cv2.putText(image, str(nameId), (x,y-10), cv2.FONT_HERSHEY_TRIPLEX, 1, (0,255,0), 2)
            
            #keyboard.type(nameId)
            #keyboard.press(Key.enter)
            #keyboard.release(Key.enter)

            
            
            if(nameId=='UNKNOWN' or len(faces) > 1):
				image = np.zeros((544,960,3), np.uint8)
				cv2.putText(image,"YOU ARE NOT AUTHORIZED", (30,200), cv2.FONT_HERSHEY_TRIPLEX, 2, (0,0,255), 4)
				cv2.putText(image,"OR", (400,300), cv2.FONT_HERSHEY_TRIPLEX, 2, (0,0,255), 4)
				cv2.putText(image,"SOMEBODY BEHIND YOU", (80,400), cv2.FONT_HERSHEY_TRIPLEX, 2, (0,0,255), 4)
			 
         
    cv2.namedWindow('SAMPLE')
    cv2.moveWindow('SAMPLE',200,50)
    cv2.imshow('SAMPLE',image) 
    key = cv2.waitKey(10) & 0xFF
 
	# clear the stream in preparation for the next frame
    rawCapture.truncate(0)
 
	# if the `q` key was pressed, break from the loop
    if key == ord("q"):
		          break

cv2.destroyAllWindows()
