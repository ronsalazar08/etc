int pin1 = 2;
int pin2 = 4;
int pin3 = 6;
int mWord,mExcel,mPower;
void setup() {
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
mWord = digitalRead(pin1);
mExcel = digitalRead(pin2);
mPower = digitalRead(pin3);

if (mWord == HIGH){
  delay(1000);
  Serial.print("WORD");
  if (mWord == LOW){
    delay(1000);
    Serial.print("WORDOFF");
  }
}
else if (mExcel == HIGH){
  delay(1000);
  Serial.print("EXCEL");
}
else if(mPower == HIGH){
  delay(1000);
  Serial.print("POWER");
}

}
