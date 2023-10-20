const int rInput = A2;
const int gInput =A1;
const int bInput = A0;
const int RLed = 11;
const int GLed = 10;
const int BLed = 9;
int R;
int G;
int B;
const int maxInValue  = 1023;
const int maxValue = 255;
const int minInValue = 0;
const int minValue = 0;


void setup() {
  pinMode(rInput, INPUT);
  pinMode(gInput, INPUT);
  pinMode(bInput, INPUT);

  pinMode(RLed, OUTPUT);
  pinMode(GLed, OUTPUT);
  pinMode(BLed, OUTPUT);
}

void loop(){
  R = map(analogRead(rInput), minInValue, maxInValue, minValue, maxValue);
  G = map(analogRead(gInput), minInValue, maxInValue, minValue, maxValue);
  B = map(analogRead(bInput), minInValue, maxInValue, minValue, maxValue);
  analogWrite(RLed, R); 
  analogWrite(GLed, G);
  analogWrite(BLed, B);
}