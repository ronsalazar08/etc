int pin =7;

int lastButtonState1 = 0;     
int buttonPushCounter1 = 0; 
void setup() {
  Serial.setTimeout(100);//for readstring
  // put your setup code here, to run once:
pinMode(pin, INPUT);
pinMode(5, OUTPUT);
Serial.begin(9600);
}

void loop() {
Serial.available() == 0; // do nothing if nothing sent
  // put your main code here, to run repeatedly:
int buttonState1 = digitalRead(pin);
String val = Serial.readString();
 if (buttonState1 != lastButtonState1)
 {
   if (buttonState1 == HIGH)
   {
      buttonPushCounter1++;
      Serial.println(buttonPushCounter1);
      delay(100);
   } 
   else{}
    delay(50);
 }
   else{}
  lastButtonState1 = buttonState1;
if (buttonPushCounter1 == 15)
{
  Serial.print("olo");
  delay(1000);
  Serial.print("mo");
  buttonPushCounter1 =0;
}
if (val== "1")
{
  digitalWrite(5,1);
}
}
