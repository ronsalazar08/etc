/**
 * Simple Read
 * 
 * Read data from the serial port and change the color of a rectangle
 * when a switch connected to a Wiring or Arduino board is pressed and released.
 * This example works with the Wiring / Arduino program that follows below.
 */

import java.awt.AWTException;
import java.awt.Robot;
import java.awt.event.KeyEvent;
import processing.serial.*;

Serial myPort;  // Create object from Serial class

Robot robot;
boolean flag;
int linefeed = 10; // new line ASCII = 10
void setup() 
{
  flag = false;
  size(0, 0);
  myPort = new Serial(this, "/dev/ttyUSB0", 9600);
  myPort.bufferUntil(linefeed);
   try { 
    robot = new Robot();
  } catch (AWTException e) {
    e.printStackTrace();
    exit();
  }
}
void draw()
{
    
  if (!flag) {
    surface.setLocation(0, 0);
    flag = true;
  }
 
  

}





void serialEvent (Serial myPort)
{
  
  
    String val = myPort.readString();        
  if (val != null) {
     val = trim(val);
  if(val.equals("1") == true) { 
     
  robot.keyPress(KeyEvent.VK_0);
     
  robot.keyRelease(KeyEvent.VK_0);
     
  robot.keyPress(KeyEvent.VK_0);
     
  robot.keyRelease(KeyEvent.VK_0);
     
  robot.keyPress(KeyEvent.VK_1);
     
  robot.keyRelease(KeyEvent.VK_1); 
     
  robot.keyPress(KeyEvent.VK_ENTER);
     
  robot.keyRelease(KeyEvent.VK_ENTER); 
      
  }//1
  
  if(val.equals("2") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//2
  if(val.equals("3") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//3
  if(val.equals("4") == true) {  
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0); 
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_4);
  robot.keyRelease(KeyEvent.VK_4); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//4
  if(val.equals("5") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_5);
  robot.keyRelease(KeyEvent.VK_5); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//5
  if(val.equals("6") == true) { 
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);  
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_6);
  robot.keyRelease(KeyEvent.VK_6); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//6
  if(val.equals("7") == true) {  
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0); 
  robot.keyPress(KeyEvent.VK_7);
  robot.keyRelease(KeyEvent.VK_7); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//7
  if(val.equals("8") == true) { 
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);  
  robot.keyPress(KeyEvent.VK_8);
  robot.keyRelease(KeyEvent.VK_8); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//8
  if(val.equals("9") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_9);
  robot.keyRelease(KeyEvent.VK_9); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//9
  if(val.equals("10") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//10
  if(val.equals("11") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//11
  if(val.equals("12") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//12
  if(val.equals("13") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//13
  if(val.equals("14") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_4);
  robot.keyRelease(KeyEvent.VK_4); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//14
  if(val.equals("15") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_5);
  robot.keyRelease(KeyEvent.VK_5); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//15
  if(val.equals("16") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_6);
  robot.keyRelease(KeyEvent.VK_6); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//16
  if(val.equals("17") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_7);
  robot.keyRelease(KeyEvent.VK_7); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//17
  if(val.equals("18") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_8);
  robot.keyRelease(KeyEvent.VK_8); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//18
  if(val.equals("19") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_9);
  robot.keyRelease(KeyEvent.VK_9); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//19
  if(val.equals("20") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2);  
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//20
  if(val.equals("21") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2);  
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//21
  if(val.equals("22") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2);  
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//22
  if(val.equals("23") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2);  
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//23
  if(val.equals("24") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2);  
  robot.keyPress(KeyEvent.VK_4);
  robot.keyRelease(KeyEvent.VK_4); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//24
  if(val.equals("25") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2);  
  robot.keyPress(KeyEvent.VK_5);
  robot.keyRelease(KeyEvent.VK_5); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//25
  if(val.equals("26") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2);  
  robot.keyPress(KeyEvent.VK_6);
  robot.keyRelease(KeyEvent.VK_6); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//26
  if(val.equals("27") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2);  
  robot.keyPress(KeyEvent.VK_7);
  robot.keyRelease(KeyEvent.VK_7); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//27
  if(val.equals("28") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2);  
  robot.keyPress(KeyEvent.VK_8);
  robot.keyRelease(KeyEvent.VK_8); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//28
  if(val.equals("29") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2);  
  robot.keyPress(KeyEvent.VK_9);
  robot.keyRelease(KeyEvent.VK_9); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//29
  if(val.equals("30") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3);  
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//30
  if(val.equals("31") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3);  
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//31
  if(val.equals("32") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3);  
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//32
  if(val.equals("33") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3);  
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//33
  if(val.equals("34") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3);  
  robot.keyPress(KeyEvent.VK_4);
  robot.keyRelease(KeyEvent.VK_4); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//34
  if(val.equals("35") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3);  
  robot.keyPress(KeyEvent.VK_5);
  robot.keyRelease(KeyEvent.VK_5); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//35
  if(val.equals("36") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3);  
  robot.keyPress(KeyEvent.VK_6);
  robot.keyRelease(KeyEvent.VK_6); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//36
  if(val.equals("37") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3);  
  robot.keyPress(KeyEvent.VK_7);
  robot.keyRelease(KeyEvent.VK_7); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//37
  if(val.equals("38") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3);  
  robot.keyPress(KeyEvent.VK_8);
  robot.keyRelease(KeyEvent.VK_8); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//38
  if(val.equals("39") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3);  
  robot.keyPress(KeyEvent.VK_9);
  robot.keyRelease(KeyEvent.VK_9); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//39
  if(val.equals("40") == true) {   
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_4);
  robot.keyRelease(KeyEvent.VK_4);  
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0); 
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//40
  
   
  if(val.equals("100") == true) {   
     
  robot.keyPress(KeyEvent.VK_1);
   
  robot.keyRelease(KeyEvent.VK_1);  
   
  robot.keyPress(KeyEvent.VK_0);
   
  robot.keyRelease(KeyEvent.VK_0);
   
  robot.keyPress(KeyEvent.VK_0);
   
  robot.keyRelease(KeyEvent.VK_0);
   
  robot.keyPress(KeyEvent.VK_ENTER);
   
  robot.keyRelease(KeyEvent.VK_ENTER); 
   
  }//100
  if(val.equals("101") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("102") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("103") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("104") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_4);
  robot.keyRelease(KeyEvent.VK_4);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("105") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_5);
  robot.keyRelease(KeyEvent.VK_5);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("106") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_6);
  robot.keyRelease(KeyEvent.VK_6);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("107") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_7);
  robot.keyRelease(KeyEvent.VK_7);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("108") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_8);
  robot.keyRelease(KeyEvent.VK_8);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("109") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_9);
  robot.keyRelease(KeyEvent.VK_9);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("110") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("111") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("112") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("113") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("114") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);
  robot.keyPress(KeyEvent.VK_4);
  robot.keyRelease(KeyEvent.VK_4);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("115") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);
  robot.keyPress(KeyEvent.VK_5);
  robot.keyRelease(KeyEvent.VK_5);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("116") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);
  robot.keyPress(KeyEvent.VK_6);
  robot.keyRelease(KeyEvent.VK_6);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("117") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);
  robot.keyPress(KeyEvent.VK_7);
  robot.keyRelease(KeyEvent.VK_7);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("118") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);
  robot.keyPress(KeyEvent.VK_8);
  robot.keyRelease(KeyEvent.VK_8);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("119") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);
  robot.keyPress(KeyEvent.VK_9);
  robot.keyRelease(KeyEvent.VK_9);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("120") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2);
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("121") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2);
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("122") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2);
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("123") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2);
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("124") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2);
  robot.keyPress(KeyEvent.VK_4);
  robot.keyRelease(KeyEvent.VK_4);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("125") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2);
  robot.keyPress(KeyEvent.VK_5);
  robot.keyRelease(KeyEvent.VK_5);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("126") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2);
  robot.keyPress(KeyEvent.VK_6);
  robot.keyRelease(KeyEvent.VK_6);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("127") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2);
  robot.keyPress(KeyEvent.VK_7);
  robot.keyRelease(KeyEvent.VK_7);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("128") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2);
  robot.keyPress(KeyEvent.VK_8);
  robot.keyRelease(KeyEvent.VK_8);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
   
  if(val.equals("129") == true) { 
     
  robot.keyPress(KeyEvent.VK_1);
   
  robot.keyRelease(KeyEvent.VK_1);  
   
  robot.keyPress(KeyEvent.VK_2);
   
  robot.keyRelease(KeyEvent.VK_2);
   
  robot.keyPress(KeyEvent.VK_9);
   
  robot.keyRelease(KeyEvent.VK_9);
   
  robot.keyPress(KeyEvent.VK_ENTER);
   
  robot.keyRelease(KeyEvent.VK_ENTER); 
      
}//100
  if(val.equals("130") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3);
  robot.keyPress(KeyEvent.VK_0);
  robot.keyRelease(KeyEvent.VK_0);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("131") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3);
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("132") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3);
  robot.keyPress(KeyEvent.VK_2);
  robot.keyRelease(KeyEvent.VK_2);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("133") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3);
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("134") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3);
  robot.keyPress(KeyEvent.VK_4);
  robot.keyRelease(KeyEvent.VK_4);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  if(val.equals("135") == true) {   
  robot.keyPress(KeyEvent.VK_1);
  robot.keyRelease(KeyEvent.VK_1);  
  robot.keyPress(KeyEvent.VK_3);
  robot.keyRelease(KeyEvent.VK_3);
  robot.keyPress(KeyEvent.VK_5);
  robot.keyRelease(KeyEvent.VK_5);
  robot.keyPress(KeyEvent.VK_ENTER);
  robot.keyRelease(KeyEvent.VK_ENTER); 
  }//100
  }//ifNull
 
}