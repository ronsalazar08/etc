/*

  shift register mano-mano
  nasa link connection 
  pin8   data pin = yellow
  pin9   latch pin = pink
  pin10  clock pin = blue
  https://protostack.com.au/wp-content/uploads/shift_register_09.jpg
  http://bildr.org/blog/wp-content/uploads/2011/02/74HC595_4.png
  manuod ka din sa youtube ng tutorial tungkol sa shift register

 
*/
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
  data_On();                          // 1 
  clock_pin();                        // push yung 1
  data_Off();                         // 0
  clock_pin();                        // push yung 0
  clock_pin();                        // push ulit ng 0

  latch_pin();                        // ang iilaw ay Q2 yung pangat long led
  delay(5000);
  clear_data();                       //  mamatay ilaw after 5 sec
}
else if (val== "halho")               //  from button 2
{
  
  data_On();                          // 1 
  clock_pin();                        // push yung 1
  data_Off();                         // 0
  clock_pin();clock_pin();clock_pin();clock_pin();clock_pin();clock_pin();clock_pin();  // push ng 7 na 0
  data_On();                          // 1 
  clock_pin();                        // push yung 1
  
  latch_pin();                        // ang iilaw ay Q0 nung 2nd shift register at Q0 ng 1st shift register
                                      // yung unang 1 ang napapunta sa 2nd Shift reg yung pangalawang 1 ang nasa 1st Shift reg
  delay(5000);
  clear_data();                       //  mamatay lahat ng ilaw after 5 sec
}
else if (val== "celluzon")            //  from button 3
{
  data_On();                          // 1 
  clock_pin();                        // push yung 1
  data_Off();                         // 0
  clock_pin();clock_pin();clock_pin();clock_pin();  // push ng 4 na 0
  latch_pin();                        // ang iilaw ay Q4 1st shift register
}
else if (val== "celluzoff")
{
  clear_data();                       //clear para mamatay ilaw pag ka inokay ang messagebox
}

}//loop



//==============================================================
void data_On()
{
  digitalWrite(pin[8], HIGH);
}

//==============================================================
void data_Off()
{
  digitalWrite(pin[8], LOW);
}


//==============================================================
void clock_pin()
{
  digitalWrite(pin[10], HIGH);
  delay(10);
  digitalWrite(pin[10], LOW);
}//clock_pin


//==============================================================
void latch_pin()
{
  digitalWrite(pin[9], 1);
  delay(10);
  digitalWrite(pin[9], 0);
}//latch_pin


//==============================================================
void clear_data()
{
  int count = 16;                 //kung ilan lahat ng output ng SR
  
  data_Off();                     //push ka ng 0 sa SR
  
for (int i = 0; i < count; i++)   // loop kung ilan 0 ipupush mo para maclear lahat ng nsa SR
{
  clock_pin();
  delay(10);
}

  latch_pin();                    // latch para mag output na ang SR ng 16 na 0
                                  // mawawala last output mo sa SR dahil matutulak na ng 16 na 0
  
}//clear_data

/* parehas lng to ng my loop
 * //==============================================================
void clear_data()
{
  
  data_Off();

  clock_pin();clock_pin();clock_pin();clock_pin();
  clock_pin();clock_pin();clock_pin();clock_pin();
  clock_pin();clock_pin();clock_pin();clock_pin();
  clock_pin();clock_pin();clock_pin();clock_pin();

  latch_pin();
}//clear_data
*/
