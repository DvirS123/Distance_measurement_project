#include <LiquidCrystal.h>
LiquidCrystal lcd(1,2,4,5,6,7);
#include <SR04.h>
#define TRIG_PIN 12 //Pin to Arduino Digital Pin 12
#define ECHO_PIN 11 //Pin to Arduino Digital Pin 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);//defines variables
long Length;
int greenled = 9;
int redled = 8;
void setup() {
  lcd.begin(16,2);
delay(1000);
pinMode(redled,OUTPUT);
pinMode(greenled,OUTPUT);
}
void loop() {
Length=sr04.Distance();
lcd.setCursor(0,1);
lcd.print("Object in ");
lcd.print(Length);
lcd.print(" CM");
if(Length <= 50){
  lcd.setCursor(5,0);
  lcd.print("WARNING!");
  digitalWrite(redled,HIGH);
  digitalWrite(greenled,LOW);
}else{
  digitalWrite(greenled,HIGH);
  digitalWrite(redled,LOW);
  lcd.setCursor(5,0);
  lcd.print("Safe");
}
  delay(500);
lcd.clear();
}
