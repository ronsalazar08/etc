#!/usr/bin/python
from picamera.array import PiRGBArray
from picamera import PiCamera
import time
import cv2
import os


# initialize the camera and grab a reference to the raw camera capture
camera = PiCamera()
camera.resolution = (960, 544)
camera.framerate = 32
rawCapture = PiRGBArray(camera, size=(960, 544))
Id=raw_input('enter your id: ')
sampleNum=0


# allow the camera to warmup
time.sleep(0.1)
 
# capture frames from the camera
for frame in camera.capture_continuous(rawCapture, format="bgr", use_video_port=True):
	# grab the raw NumPy array representing the image, then initialize the timestamp
	# and occupied/unoccupied text
	
	image = frame.array
	face_cascade = cv2.CascadeClassifier('/home/pi/opencv-3.3.0/data/lbpcascades/lbpcascade_frontalface_improved.xml')
	gray = cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)
        
        faces = face_cascade.detectMultiScale(gray, 1.1, 5)
            
        
        for (x,y,w,h) in faces:
                                   
            #if (len(faces) > 1):
                #cv2.rectangle(image,(x,y),(x+w,y+h),(0,0,255),120)
                #cv2.putText(image, "ONLY ONE PERSON ALLOWED", (200,50), cv2.FONT_HERSHEY_TRIPLEX, 1, (0,0,255), 3)
                
            #elif (len(faces) == 1):
               # cv2.rectangle(image,(x,y),(x+w,y+h),(255,0,0),2)
                #cv2.putText(image, "TOLITS", (250,50), cv2.FONT_HERSHEY_TRIPLEX, 1, (0,255,0), 2)
               
                cv2.rectangle(image,(x,y),(x+w,y+h),(0,0,255),2)
                sampleNum=sampleNum+1
                
                cv2.imwrite("dataSet/user."+Id+'.'+str(sampleNum)+".jpg",gray[y:y+h,x:x+w])           
                        
	# show the frame
	cv2.imshow('frame', image)
	key = cv2.waitKey(100) & 0xFF
 
	# clear the stream in preparation for the next frame
	rawCapture.truncate(0)
 
	# if the `q` key was pressed, break from the loop
	if key == ord("q"):
		break
	    
	elif sampleNum>20:
                break
            
cv2.destroyAllWindows()
