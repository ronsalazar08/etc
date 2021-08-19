#include <LiquidCrystal.h>

int Contrast=25;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  analogWrite(6,Contrast);
  lcd.begin(16, 2);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("   TTech NAVI");
  lcd.setCursor(0,1);
  lcd.print("      SP17    ");
  delay(3000);
    
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  LOADING....    ");
  lcd.setCursor(0,1);
  lcd.print("  Please Wait   ");
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("    S C A N  ");
  lcd.setCursor(0,1);
  lcd.print("    BARCODE     ");
  
  Serial.begin(115200);
}

void loop() {

  if (Serial.available()) {
       lcd.clear();

     String Str =  Serial.readString();

       if(Str == "prod1")
       {
     
         lcd.setCursor(0,0);
         lcd.print("Model 1");
         lcd.setCursor(0,1);
         lcd.print("Product 1");
         
       }
     else if(Str == "prod2")
       {
       
         lcd.setCursor(0,0);
         lcd.print("Model 2");
         lcd.setCursor(0,1);
         lcd.print("Product 2");
         
       }
       else if(Str == "prod3")
       {
       
         lcd.setCursor(0,0);
         lcd.print("Model 3");
         lcd.setCursor(0,1);
         lcd.print("Product 3");
         
       }
        else if(Str == "prod4")
       {
       
         lcd.setCursor(0,0);
         lcd.print("Model 4");
         lcd.setCursor(0,1);
         lcd.print("Product 4");
         
       }
       else 
       {
       
         lcd.setCursor(0,0);
         lcd.print("  No Data Found");
         lcd.setCursor(0,1);
         lcd.print("   REPEAT SCAN ");
         
       }
        }
        
          
    }




