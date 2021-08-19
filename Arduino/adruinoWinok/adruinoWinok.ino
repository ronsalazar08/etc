int pin[14];
void setup()
{
  
Serial.begin(9600);
Serial.setTimeout(100);                 //pag wala to lag ang pag basa ng serial.readstring mula sa vb


for (int i = 2; i < 13; i++)
{
  pin[i] = i;
  pinMode(pin[i],OUTPUT);
}


}//setup

//==============================================================
void loop() {
Serial.available() == 0;              // do nothing if nothing sent
String val = Serial.readString();

if (val== "olo")                      //  from button 1
{
 digitalWrite(pin[8],HIGH);
}
else if (val== "halho")               //  from button 2
{
 digitalWrite(pin[9],HIGH);
}
else if (val== "celluzon")            //  from button 3
{
 digitalWrite(pin[10],HIGH);
}
else if (val== "celluzoff")           //for msgbox(ok)
{
 digitalWrite(pin[10],LOW);
}

}//loop
