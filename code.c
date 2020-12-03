
//CROWD PREVENTION ALARM

#include<LiquidCrystal.h>
const int rs = 12, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7 ;
const int in = 8, out = 9;
int temp = 0;


LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {

  lcd.begin(16, 2);
  pinMode(13,OUTPUT);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  lcd.print("Visitor Counter");

}

void loop() {
  
  if (digitalRead(in) == 1)
  {
   
    temp = temp + 1;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No.of people inside the room");
    lcd.setCursor(0, 1);
    lcd.print(temp);
    delay(500);
  }
  else if (digitalRead(out) == 1)
  {
    temp = temp - 1;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No.of people inside the room");
    lcd.setCursor(0, 1);
    lcd.print(temp);
    delay(500);
  }
  else if (temp >= 2)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("MAX LIMIT REACHED");
    lcd.setCursor(0,1);
    lcd.print("Please wait untill some one  comes out");
    digitalWrite(13,HIGH);
    delay(1000);
  }
  else if(temp<2)
  {
     digitalWrite(13,LOW);
  }

}
