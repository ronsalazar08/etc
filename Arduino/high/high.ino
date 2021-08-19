
const int buttonPin = 9;
const int ledPin = 3;   
const int ledPin1 = 5;
int ledState = LOW;        
int buttonState;           
int lastButtonState = HIGH;  
long lastDebounceTime = 0;  
long debounceDelay = 50;    
bool olo = false;
void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
pinMode(ledPin1, OUTPUT);
  // set initial LED state
  digitalWrite(ledPin, ledState);
}

void loop() {

  int reading = digitalRead(buttonPin);

  
  if (reading != lastButtonState) {
    
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
   
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        ledState = !ledState;
        
        
      }
    }
  }

  digitalWrite(ledPin, ledState);
  lastButtonState = reading;
}

