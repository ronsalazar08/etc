
void setup() {
  // put your setup code here, to run once:
pinMode(5 ,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.available() == 0;

int val = Serial.read() - '0';

if (val == 1)
{
  digitalWrite(5,1);
}
if (val == 0)
{
  digitalWrite(5,0);
}

}
