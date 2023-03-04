/*
  Gemi Kumanda - Powered By CleaMarin
  Development By celikdev
  03/03/2023
*/

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

int mod = 0;
int butonPin = 2;

#define lcdRow 20

void setup() {
  Serial.begin(9600);
  pinMode(butonPin,INPUT_PULLUP);
  startLCD();
}

void loop() {
  bool butonDurum = digitalRead(butonPin);
  if(butonDurum == 0) {
    lcd.clear();
    mod++;
    if(mod > 2) {
      mod = 0;
    }
    Serial.println(mod);
    while(butonDurum == 0){
      butonDurum = digitalRead(butonPin);
    }
  }
  printMode();
}

void startLCD() {
  lcd.begin();
  lcd.backlight();
}

void printMode() {
    switch(mod){
    case 0:
      lcd.setCursor(
      lcd.print("Arac Kontrol");
      break;
    case 1:
      lcd.print("Kamera Kontrol");
      break;
    case 2:
      lcd.print("Cop Kontrol");
      break;
  }
}
