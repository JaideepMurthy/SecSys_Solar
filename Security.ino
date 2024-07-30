// This Code is for an Arduino Processor, It has two Sensors - LDR & PIR. When PIR detects anything it displays output - Light is On ; and - light if is Off; lighting on andf off a bulb. 
// The LDR Detects objects pssing through the light and wgen something does pass, the buzzer makes a buss noise. 

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 9, en = 8, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int PIR_PIN = 3;
const int LDR_PIN = 11;
const int BUZ_PIN = 10;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("BUILDING SECURITY");
  lcd.setCursor(5, 1);
  lcd.print("SYSTEM");
  // initialize the pushbutton pin as an input:
  pinMode(PIR_PIN, INPUT);
  pinMode(LDR_PIN, INPUT);
  pinMode(BUZ_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  delay(2000);
  lcd.clear();
}

void loop() {

 // for PIR pin , Passive Infra Red Pin
 
  if (digitalRead(PIR_PIN))  {
    
    digitalWrite(13, LOW);

    lcd.setCursor(0, 0);
    lcd.print("  Light is on   ");
  } 
 
else  {
    digitalWrite(13, HIGH);

    lcd.setCursor(0, 0);
    lcd.print("  Light is off  ");
  } 

  // For LDR Pin

  if (digitalRead(LDR_PIN))  {
    lcd.setCursor(0, 1);
    lcd.print(" Intruder Alert ");

    digitalWrite(BUZ_PIN, HIGH);
  } 
else  {
    lcd.setCursor(0, 1);
    lcd.print(" System Normal  ");
    
    digitalWrite(BUZ_PIN, LOW); //If you dont want continuous sound use this line of code, if you want it comment this line
  } 

}

