int trigPin = 10;
int echoPin = 11;
int led = 3;
long duration;
int distance ;
#include <LiquidCrystal.h>

const byte rs = 9;
const byte en = 8;
const byte d4 = 7;
const byte d5 = 6;
const byte d6 = 5;
const byte d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600); 
   pinMode(led, OUTPUT);
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  return distance;
}

void loop() {
  for(int i=165; i>=1; i--)
 {
  calculateDistance();
  Serial.print(distance);
 }
 
 if((calculateDistance()<=10)) 
  {
    digitalWrite(led, HIGH);
}
   else if(calculateDistance()>10)
 {
     digitalWrite(led, LOW);
 }
  lcd.begin(16,2);
  lcd.print(distance);
}