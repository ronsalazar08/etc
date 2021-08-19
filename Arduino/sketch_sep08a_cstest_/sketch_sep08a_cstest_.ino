int pin = 7;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int basa = digitalRead(pin);

if (basa == HIGH)
{
  Serial.write("olo");
  delay(500);
}
else 
{
  Serial.write("mo");
  
  delay(500);
}
}
