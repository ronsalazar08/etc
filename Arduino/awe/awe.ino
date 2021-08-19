int guard = false;
int guard1 = false;
const int b = 3;
const int d = 5;
void setup() {
  // put your setup code here, to run once:
pinMode(9,INPUT);
pinMode(d,OUTPUT);
pinMode(b,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
int btn = digitalRead(9);
if(b == HIGH)
{
  guard = true;
  if  ((b=HIGH) and (guard = true))
  {
    digitalWrite(b,HIGH);
    digitalWrite(d,LOW);
  }
  
  else  if ((b = HIGH) and (guard = true))
    {guard1 = true;
    if ((b=HIGH)and (guard = true) and (guard1 = true))
    {
       digitalWrite(3,LOW);
    digitalWrite(5,HIGH);
      }
   
    }
      digitalWrite(3,LOW);
    digitalWrite(5,LOW);
  }
 
}
