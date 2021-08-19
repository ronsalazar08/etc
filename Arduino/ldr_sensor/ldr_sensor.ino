
void setup() {
  // put your setup code here, to run once:
pinMode(A0, INPUT);
pinMode(2, OUTPUT);

Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
int val = analogRead(A0);

if (val <=300)
{
  digitalWrite(2,1);
}
else
{
  digitalWrite(2,0);
}
Serial.println(val);
delay(200);




}
