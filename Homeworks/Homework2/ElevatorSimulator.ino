int groundFloor = 8;
int secondFloor = 5;
int LED = 4;
int thirdFloor = 2;
int groundFloorbutton = 9;
int secondFloorbutton = 10;
int thirdFloorbutton = 11;
int buttonStateGF = 0;
int buttonState2F = 0;
int buttonState3F = 0;


void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(thirdFloor, OUTPUT);
  pinMode(secondFloor, OUTPUT);
  pinMode(groundFloor, OUTPUT);
  pinMode(groundFloorbutton, INPUT_PULLUP);
  pinMode(secondFloorbutton, INPUT_PULLUP);
  pinMode(thirdFloorbutton, INPUT_PULLUP);
}

void loop()
{
  buttonStateGF = digitalRead(groundFloorbutton);
  buttonState2F = digitalRead(secondFloorbutton);
  buttonState3F = digitalRead(thirdFloorbutton);
  digitalWrite(groundFloor, HIGH);
  if(buttonState2F == 1)
  {
    if(digitalRead(groundFloor)==HIGH)
    {
      digitalWrite(groundFloor, LOW);
      delay(500);
      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED, LOW);
      delay(500);
      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED, LOW);
      delay(500);
      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED, LOW);
      delay(500);
      digitalWrite(secondFloor, HIGH);
      delay(1000);
      digitalWrite(secondFloor, LOW);
      delay(500);
      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED, LOW);
      delay(500);
      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED, LOW);
      delay(500);
      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED, LOW);
      delay(500);
    }
  }
  
  if(buttonState3F == 1)
  {
    if(digitalRead(groundFloor)==HIGH)
    {
      digitalWrite(groundFloor, LOW);
      delay(500);
      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED, LOW);
      delay(500);
      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED, LOW);
      delay(500);
      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED, LOW);
      delay(500);
      digitalWrite(secondFloor, HIGH);
      delay(1000);
      digitalWrite(secondFloor, LOW);
      delay(500);
      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED, LOW);
      delay(500);
      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED, LOW);
      delay(500);
      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED, LOW);
      delay(500);
      digitalWrite(thirdFloor, HIGH);
      delay(1000);
      digitalWrite(thirdFloor, LOW);
      delay(500);
      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED, LOW);
      delay(500);
      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED, LOW);
      delay(500);
      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED, LOW);
      delay(500);

    }
  }
}
