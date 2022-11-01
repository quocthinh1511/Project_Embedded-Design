
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define in A0
#define out A1
#define relay 3
int count=0;
void IN()
{
    count++;
    lcd.clear();
    lcd.print("SO NGUOI:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
}
void OUT()
{
  count--;
    lcd.clear();
    lcd.print("SO NGUOI:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
}
void setup()
{
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print(" HELLO ");
  delay(500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Person In Room:");
  lcd.print(count);
  delay(500);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  pinMode(relay, OUTPUT);
  
}
void loop()
{  
   if(!digitalRead(out))
    IN();
   if(!digitalRead(in))
    OUT();
  Serial.print(count);
  Serial.println("");
  
  if(count<=0)
  {
    lcd.clear();
    digitalWrite(relay, LOW);
    lcd.clear();
    lcd.print("KO CO NGUOI:");
    lcd.setCursor(0,1);
    lcd.print("Den Tat");
    delay(200);
  }
  else
    digitalWrite(relay, HIGH);
}