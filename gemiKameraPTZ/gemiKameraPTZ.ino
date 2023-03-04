#include <Servo.h>

#define xAxis 10 //UNO'nun PWM Herhangi Bir Pini
#define yAxis 11 //UNO'nun PWM Herhangi Bir Pini

#define potPin A0

Servo yAxisServo;

void setup() {
  Serial.begin(9600);
  yAxisServo.attach(yAxis);
  yAxisServo.write(66);
  delay(1000);
}

void loop() {
  // Kameranın Tam Tur Yukarı-Aşağı Hareketi
  int potDeger = analogRead(potPin);
  potDeger = map(potDeger, 0, 1023, 30, 100);
//  if (100 < potDeger < 30) {
//    yAxisServo.write(potDeger);
//    Serial.println(potDeger);
//  } else if(potDeger > 100) {
//    yAxisServo.write(100);
//  } else if(potDeger < 30){
//    yAxisServo.write(30);
//  }
  yAxisServo.write(potDeger);
  Serial.println(potDeger);
  delay(5);
}
