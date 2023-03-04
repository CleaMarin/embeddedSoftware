const int Enable_B = 9;
const int inputA2 = 4;
const int inputB2 = 6;

void setup()
{
pinMode(Enable_B, OUTPUT);
pinMode(inputA2, OUTPUT);
pinMode(inputB2, OUTPUT);
Serial.begin(9600);
}
void loop(){
digitalWrite(Enable_B, HIGH);

digitalWrite(inputA2,HIGH);
digitalWrite(inputB2,HIGH);

for(int i=0; i<=255;i++){
  analogWrite(Enable_B,i);
  Serial.println(i);
  delay(50);
}
}
