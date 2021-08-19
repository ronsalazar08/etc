int pin[14]; // pins

void setup() {
Serial.begin(9600);
//Serial.setTimeout(100);  //Serial.readString timeout

//pin declaration
for(int i = 2; i < 13; i++)
{
  pin[i] = i;
  pinMode(pin[i], OUTPUT);
}

for(int o = 0; o < 2; o++)
  { 
    for(int x = 2; x < 12; x++)
    {
       digitalWrite(pin[x], HIGH);
       
    }
    delay(500);
    for(int x = 2; x < 12; x++)
    {
       digitalWrite(pin[x], LOW);
       
    }
    delay(500);
  }
}

void loop() {
Serial.available() == 0;  //do nothing if nothing sent
//String val = Serial.readString();  //read string from vb
char val = Serial.read();  //read char from vb

if(val == 'a')
{
  digitalWrite(pin[2], HIGH);
}
else if(val == 'b')
{
  digitalWrite(pin[3], HIGH);
}
else if(val == 'c')
{
  digitalWrite(pin[4], HIGH);
}
else if(val == 'd')
{
  digitalWrite(pin[5], HIGH);
}
else if(val == 'e')
{
  digitalWrite(pin[6], HIGH);
}
else if(val == 'f')
{
  digitalWrite(pin[7], HIGH);
}
else if(val == 'g')
{
  digitalWrite(pin[8], HIGH);
}
else if(val == 'h')
{
  digitalWrite(pin[9], HIGH);
}
else if(val == 'i')
{
  digitalWrite(pin[2], LOW);
}
else if(val == 'j')
{
  digitalWrite(pin[3], LOW);
}
else if(val == 'k')
{
  digitalWrite(pin[4], LOW);
}
else if(val == 'l')
{
  digitalWrite(pin[5], LOW);
}
else if(val == 'm')
{
  digitalWrite(pin[6], LOW);
}
else if(val == 'n')
{
  digitalWrite(pin[7], LOW);
}
else if(val == 'o')
{
  digitalWrite(pin[8], LOW);
}
else if(val == 'p')
{
  digitalWrite(pin[9], LOW);
}


//new
else if(val == 'q')
{
  digitalWrite(pin[10], HIGH);
}
else if(val == 'r')
{
  digitalWrite(pin[11], HIGH);
}
else if(val == 's')
{
  digitalWrite(pin[10], LOW);
}
else if(val == 't')
{
  digitalWrite(pin[11], LOW);
}

}//void loop
