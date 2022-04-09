#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define MQ3pin 0

LiquidCrystal_I2C lcd(0x27, 16, 2);
float sensorValue;

void setup() {
  Serial.begin(9600);
  Serial.println("MQ3 warming up!");
    
  //initialize lcd screen
  lcd.init();
  
  // turn on the backlight
  lcd.backlight();

  // warm up
  waitTime();  
}

// Allows MQ3 to warm up and writes to LCD
void waitTime()
{
  for (int i = 20; i > 0; i--)
  {
    lcd.print("Warming up!");
    lcd.setCursor(0,1);
    lcd.print("Please wait ");
    lcd.print(i);
    lcd.print("s");
    delay(1000);
    lcd.clear();
  }
}
void loop() {
  lcd.setCursor(0,0);

  //for (int i = 10; i > 0; i--)
  //{
    sensorValue += analogRead(MQ3pin);
    delay(10);
  //}

  sensorValue = (sensorValue/10)*(5.0/1024.0);
  
  sensorValue = sensorValue - 0.25;
  if (sensorValue <= 0)
  {
    sensorValue = 0.0;
  }
  
  lcd.print("BAC: ");
  lcd.print(sensorValue);
  /* DEBUG */
  Serial.print("BAC: "); 
  Serial.print(sensorValue);
  Serial.print("\n");
  
  //lcd.setCursor(0,1);
  delay(1000);
  lcd.clear();
}
