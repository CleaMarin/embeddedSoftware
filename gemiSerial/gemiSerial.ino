const int Enable_A = 10;
const int Enable_B = 9;
const int inputA2 = 4;
const int inputB2 = 6;
void setup() {
  Serial.begin(1000000);
  pinMode(inputA2,OUTPUT);
  pinMode(inputB2,OUTPUT);
}

void loop() {
//  digitalWrite(Enable_A, HIGH);
//  digitalWrite(Enable_B, HIGH); 
//    digitalWrite(inputA2,HIGH);
//    digitalWrite(inputB2,HIGH);
//  while(Serial.available()){ 
//    String data = Serial.readString();
//    int mappedData = map(data,0,100,0,255);
//    analogWrite(Enable_A,mappedData);
//    analogWrite(Enable_B,mappedData);
//    delay(50);

while(Serial.available()){
    String data = Serial.readString();
    Serial.println(data);
    delay(100);
}
}
