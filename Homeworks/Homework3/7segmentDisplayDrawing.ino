const int pinSW = 2;
const int pinX = A0;
const int pinY = A1;

const int pinA = 12;
const int pinB = 10;
const int pinC = 9;
const int pinD = 8;
const int pinE = 7;
const int pinF = 6;
const int pinG = 5;
const int pinDP = 4;
const int segSize = 8;
byte joystickPressed = LOW;
byte ledAstate = LOW;
byte ledBstate = LOW;
byte ledCstate = LOW;
byte ledDstate = LOW;
byte ledEstate = LOW;
byte ledFstate = LOW;
byte ledGstate = LOW;
byte ledDPstate = LOW;

int segments[segSize] = {
  pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDP
};

//declare variables for blinking
int currentBlinkPin = 4;
byte blinkLEDstate = LOW;
byte doNotBlink = LOW;

//declare variables for joystick 
int xvalue = 0;
int yvalue = 0;
int minhold = 400;
int maxhold = 600;
byte joybackMiddleYstate2 = LOW;
byte joybackMiddleYstate1 = LOW;
byte joybackMiddleX = LOW;

byte swState = LOW;
byte lastSwState = HIGH;
byte switchState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned int debounceDelay = 50;
unsigned int blinkInterval = 400;
unsigned long lastBlinkTime = 0;
unsigned long pressedtime;
unsigned long releasedtime;
unsigned long noOfPresses = 0;
const int longPressTime = 1000;
const int shortPressTime = 50;

int state = 1;

void setup()
{
  for(int i = 0; i < segSize; i++){
    pinMode(segments[i], OUTPUT);
  }
  pinMode(pinSW, INPUT_PULLUP);
  Serial.begin(9600);
}

//function for display the state of the segments
void displayLED(){
  if(currentBlinkPin != pinA)
    digitalWrite(pinA, ledAstate);
  if(currentBlinkPin != pinB)
    digitalWrite(pinB, ledBstate);
  if(currentBlinkPin != pinC)
    digitalWrite(pinC, ledCstate);
  if(currentBlinkPin != pinD)
    digitalWrite(pinD, ledDstate);
  if(currentBlinkPin != pinE)
    digitalWrite(pinE, ledEstate);
  if(currentBlinkPin != pinF)
    digitalWrite(pinF, ledFstate);
  if(currentBlinkPin != pinG)
    digitalWrite(pinG, ledGstate);
  if(currentBlinkPin != pinDP)
    digitalWrite(pinDP, ledDPstate);
  digitalWrite(currentBlinkPin, blinkLEDstate);
}

//reset the state of the segments
void resetLED(){
  ledAstate = LOW;
  ledBstate = LOW;
  ledCstate = LOW;
  ledDstate = LOW;
  ledEstate = LOW;
  ledFstate = LOW;
  ledGstate = LOW;
  ledDPstate = LOW;
  currentBlinkPin = pinDP;
}

//move the blinking segment - to the move of the joystick
void moveBlinkState1(){
  if (yvalue < minhold && joybackMiddleYstate1 == LOW && state == 1){
    if (currentBlinkPin == pinA){ 
      currentBlinkPin = pinF;
    }
    else if (currentBlinkPin == pinB){
       currentBlinkPin = pinF;
    }
    else if (currentBlinkPin == pinC){ 
      currentBlinkPin = pinE;
    }
    else if (currentBlinkPin == pinDP){
      currentBlinkPin = pinC;
    }
    else if (currentBlinkPin == pinD){
      currentBlinkPin = pinE;
    }
    joybackMiddleYstate1 = HIGH;
  }
  else if (yvalue > maxhold && joybackMiddleYstate1 == LOW && state ==1){
    if (currentBlinkPin == pinA || currentBlinkPin == pinF){ 
      currentBlinkPin = pinB;
    }
    else if (currentBlinkPin == pinF){ 
      currentBlinkPin = pinB;
    }
    else if (currentBlinkPin == pinC){ 
      currentBlinkPin = pinDP;
    }
    else if (currentBlinkPin == pinE){ 
      currentBlinkPin = pinC;
    }
    else if (currentBlinkPin == pinD){ 
      currentBlinkPin = pinC;
    }
    joybackMiddleYstate1 = HIGH;
  }
  else if (joybackMiddleYstate1 == HIGH &&yvalue < maxhold && yvalue > minhold && state == 1){
    joybackMiddleYstate1 = LOW;
  }

  if (xvalue < minhold && joybackMiddleX == LOW && state == 1) {
    if (currentBlinkPin == pinG){ 
      currentBlinkPin = pinD;
    }
    else if (currentBlinkPin == pinA){ 
      currentBlinkPin = pinG;
    }
    else if (currentBlinkPin == pinB){ 
      currentBlinkPin = pinG;
    }
    else if (currentBlinkPin == pinF){ 
      currentBlinkPin = pinG;
    }
    else if (currentBlinkPin == pinC){ 
      currentBlinkPin = pinD;
    }
    else if (currentBlinkPin == pinE){ 
      currentBlinkPin = pinD;
    }
    joybackMiddleX = HIGH;
  }

  else if (xvalue > maxhold &&joybackMiddleX == LOW && state == 1){
    if (currentBlinkPin == pinG) {
      currentBlinkPin = pinA;
    }
    else if (currentBlinkPin == pinD){ 
      currentBlinkPin = pinG;
    }
    else if (currentBlinkPin == pinE){ 
      currentBlinkPin = pinG;
    }
    else if (currentBlinkPin == pinC){ 
      currentBlinkPin = pinG;
    }
    else if (currentBlinkPin == pinB){ 
      currentBlinkPin = pinA;
    }
    else if (currentBlinkPin == pinF){ 
      currentBlinkPin = pinA;
    }
    joybackMiddleX = HIGH;
  }
  else if (joybackMiddleX == HIGH && xvalue < maxhold && xvalue > minhold && state == 1){
    joybackMiddleX = LOW;
  }
}

//turn of and on - using the joystick on the y axis L - Off, R - On

void turnOnOffstate2(){
  if( joystickPressed == LOW && state == 2){
    blinkLEDstate = LOW;
    if (currentBlinkPin == pinA){ 
      ledAstate = LOW;
    }
    else if (currentBlinkPin == pinB){ 
      ledBstate = LOW;
    }
    else if (currentBlinkPin == pinC){ 
      ledCstate = LOW;
    }
    else if (currentBlinkPin == pinD){ 
      ledDstate = LOW;
    }
    else if (currentBlinkPin == pinE){ 
      ledEstate = LOW;
    }
    else if (currentBlinkPin == pinF){ 
      ledFstate = LOW;
    }
    else if (currentBlinkPin == pinG){ 
      ledGstate = LOW;
    }
    else if (currentBlinkPin == pinDP){ 
      ledDPstate = LOW;
    }
    joystickPressed = HIGH;
  }
  
  else if (joystickPressed == LOW && state == 2){
    blinkLEDstate = HIGH;
    if (currentBlinkPin == pinA){ 
      ledAstate = HIGH;
    }
    else if (currentBlinkPin == pinB){ 
      ledBstate = HIGH;
    }
    else if (currentBlinkPin == pinC){ 
      ledCstate = HIGH;
    }
    else if (currentBlinkPin == pinD){ 
      ledDstate = HIGH;
    }
    else if (currentBlinkPin == pinE){ 
      ledEstate = HIGH;
    }
    else if (currentBlinkPin == pinF){ 
      ledFstate = HIGH;
    }
    else if (currentBlinkPin == pinG){ 
      ledGstate = HIGH;
    }
    else if (currentBlinkPin == pinDP){ 
      ledDPstate = HIGH;
    }
    joystickPressed = HIGH;
  }
  
  else if (joystickPressed == HIGH && state == 2){
    blinkLEDstate = HIGH;
    if (currentBlinkPin == pinA){ 
      ledAstate = HIGH;
    }
    else if (currentBlinkPin == pinB){ 
      ledBstate = HIGH;
    }
    else if (currentBlinkPin == pinC){ 
      ledCstate = HIGH;
    }
    else if (currentBlinkPin == pinD){ 
      ledDstate = HIGH;
    }
    else if (currentBlinkPin == pinE){ 
      ledEstate = HIGH;
    }
    else if (currentBlinkPin == pinF){ 
      ledFstate = HIGH;
    }
    else if (currentBlinkPin == pinG){ 
      ledGstate = HIGH;
    }
    else if (currentBlinkPin == pinDP){ 
      ledDPstate = HIGH;
    }
    joystickPressed = LOW;
  }
  else if (joystickPressed == HIGH  && state == 2){
    joystickPressed = LOW;
  }
}

void changeState() {
  if( swState != lastSwState) { 
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay){
    if (swState != switchState){
      switchState = swState;
      if (switchState == LOW){ 
        pressedtime = millis();
      }
      else{
        releasedtime = millis();
      }
    long pressTime = releasedtime - pressedtime;
    if(pressTime > longPressTime and state == 1){
      resetLED();
    }
    else if (pressTime > shortPressTime) {
      noOfPresses ++;
      if(noOfPresses % 2 != 0){
        doNotBlink = HIGH;
        state = 2;
      }
      else {
        doNotBlink = LOW;
        state = 1;
      }
    }
    }
  }
  lastSwState = swState;
}

void blink() {
  if(millis() - lastBlinkTime > blinkInterval && doNotBlink == LOW){
    blinkLEDstate = !blinkLEDstate;
    lastBlinkTime = millis();
  }
}

void loop(){
  displayLED();
  xvalue = analogRead(pinX);
  yvalue = analogRead(pinY);

  blink();

  moveBlinkState1();
  turnOnOffstate2();
  swState = digitalRead(pinSW);
  changeState();
}




