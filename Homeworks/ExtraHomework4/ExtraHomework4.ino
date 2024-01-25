#include <Wire.h>
#include <LiquidCrystal.h>
#include<Tone.h>

LiquidCrystal   lcd( A0, A1, A2, A3, A4, A5);
Tone speakerpin;
int starttune[] = {NOTE_E4,   NOTE_E4, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_G4};
int duration2[] = {100, 200, 100,   200, 100, 400};
int note[] = {NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4};
int duration[] = {100, 100, 100, 300, 100, 300};
int button[] = {2, 3, 4, 5}; //The four button input pins
int ledpin[] = {8, 9, 10, 11};  // LED pins
int turn   = 0;  // turn counter
int buttonstate = 0;  // button state checker
int randomArray[50];
int inputArray[50];
int highscore = 0;
int MyScore;

void setup() 
{
Serial.begin(9600);
lcd.begin(16,2);

lcd.setCursor(0,0);   
lcd.print("Memory Game"); 
lcd.setCursor(0,1);
lcd.print("Simon Says");
delay(3000);
lcd.clear();

 lcd.setCursor(0, 1);
 lcd.print("Your Score: 0");
 lcd.setCursor(0, 0);
 lcd.print("High Score: 0");
  Serial.begin(9600);
  speakerpin.begin(6); // speaker is on pin 6

  for(int i=0; i<4; i++)  //   LED pins are outputs
  {
    pinMode(ledpin[i], OUTPUT);
  }
  
   for(int i=0; i<4; i++) 
  {
    pinMode(button[i],INPUT);  
    digitalWrite(button[i],   HIGH);  
  }

  randomSeed(analogRead(0)); 
  for (int thisNote = 0; thisNote < 6; thisNote ++) {
    
     speakerpin.play(starttune[thisNote]);
     
     if (thisNote == 0 || thisNote == 2)
     {
       digitalWrite(ledpin[0],   HIGH);
     }
     if (thisNote == 1 || thisNote == 3 )
     {
       digitalWrite(ledpin[1],   HIGH);
     }
     if (thisNote == 4 || thisNote == 5)
     {
       digitalWrite(ledpin[2],   HIGH);
     }  
     if (thisNote == 6)
     {   
       digitalWrite(ledpin[3],   HIGH);
     }
     delay(duration2[thisNote]);
     
     speakerpin.stop();
     digitalWrite(ledpin[0], LOW);
     digitalWrite(ledpin[1], LOW);
     digitalWrite(ledpin[2], LOW);
     digitalWrite(ledpin[3], LOW);
     delay(25);
    }
  delay(1000);
}
   
void loop() 
{   
  for (int i=0; i<=2; i++)
  {
    
    digitalWrite(ledpin[0], HIGH);
    digitalWrite(ledpin[1], HIGH);
    digitalWrite(ledpin[2], HIGH);
    digitalWrite(ledpin[3], HIGH);
    for (int thisNote = 0; thisNote < 6; thisNote ++) {
     speakerpin.play(note[thisNote]);
     delay(duration[thisNote]);
     speakerpin.stop();
     delay(25);
    }
    
    digitalWrite(ledpin[0], LOW);
    digitalWrite(ledpin[1], LOW);
    digitalWrite(ledpin[2], LOW);
    digitalWrite(ledpin[3], LOW);
    delay(1000);
    for (int i = turn; i <= turn; i++) 
    { 
      Serial.println(""); 
      Serial.print("Turn: ");
      Serial.print(i);
      Serial.println("");
      lcd.clear();
   MyScore=i;
 lcd.setCursor(0, 1);  //(Column,Row)
 lcd.print("Your Score:   ");
 lcd.setCursor(12, 1); 
 lcd.print(MyScore);
 if(MyScore > highscore)   {
                            highscore = i;
                          }
 lcd.setCursor(0, 0);
 lcd.print("High Score:" + (String)(highscore));
 Serial.print(i);
 Serial.println("");
 delay(1000);
       randomArray[i] = random(1, 5); 
      for (int j = 0; j <= turn; j++)
       {
        Serial.print(randomArray[j]);
      
        for(int y=0;   y<4; y++)
        {
      
          if (randomArray[j] == 1 && ledpin[y]   == 8) 
          {  
            digitalWrite(ledpin[y], HIGH);
            speakerpin.play(NOTE_G3,   100);
            delay(400);
            digitalWrite(ledpin[y], LOW);
             delay(100);
          }

          if (randomArray[j] == 2   && ledpin[y] == 9) 
          {
            digitalWrite(ledpin[y], HIGH);
             speakerpin.play(NOTE_A3, 100);
            delay(400);
            digitalWrite(ledpin[y],   LOW);
            delay(100);
          }
  
          if (randomArray[j]   == 3 && ledpin[y] == 10) 
          {
            digitalWrite(ledpin[y],   HIGH);
            speakerpin.play(NOTE_B3, 100);
            delay(400);
             digitalWrite(ledpin[y], LOW);
            delay(100);
          }

           if (randomArray[j] == 4 && ledpin[y] == 11) 
          {
            digitalWrite(ledpin[y],   HIGH);
            speakerpin.play(NOTE_C4, 100);
            delay(400);
             digitalWrite(ledpin[y], LOW);
            delay(100);
          }
         }
      }
    }
    input();
    
  } 
}
   
void input() { 

  for (int x=0; x <= turn;)
  { //Statement   controlled by turn count

    for(int y=0; y<4; y++)
    {
      
       buttonstate = digitalRead(button[y]);
    
      if (buttonstate ==   LOW && button[y] == 2)
      { 
        digitalWrite(ledpin[0], HIGH);
         speakerpin.play(NOTE_G3, 100);
        delay(200);
        digitalWrite(ledpin[0],   LOW);
        inputArray[x] = 1;
        delay(250);
        Serial.print("   ");
        Serial.print(1);
        if (inputArray[x] != randomArray[x])   { 
          fail();                             
        }                                     
         x++;
      }
       if (buttonstate == LOW && button[y] == 3)
       {
        digitalWrite(ledpin[1], HIGH);
        speakerpin.play(NOTE_A3,   100);
        delay(200);
        digitalWrite(ledpin[1], LOW);
        inputArray[x]   = 2;
        delay(250);
        Serial.print(" ");
        Serial.print(2);
         if (inputArray[x] != randomArray[x]) {
          fail();
        }
         x++;
      }

      if (buttonstate == LOW && button[y] == 4)
       {
        digitalWrite(ledpin[2], HIGH);
        speakerpin.play(NOTE_B3,   100);
        delay(200);
        digitalWrite(ledpin[2], LOW);
        inputArray[x]   = 3;
        delay(250);
        Serial.print(" ");
        Serial.print(3);
         if (inputArray[x] != randomArray[x]) {
          fail();
        }
         x++;
      }

      if (buttonstate == LOW && button[y] == 5)
       {
        digitalWrite(ledpin[3], HIGH);
        speakerpin.play(NOTE_C4,   100);
        delay(200);
        digitalWrite(ledpin[3], LOW);
        inputArray[x]   = 4;
        delay(250);
        Serial.print(" ");
        Serial.print(4);
         if (inputArray[x] != randomArray[x]) 
        {
          fail();
         }
        x++;
      }
    }
  }
  delay(500);
  turn++;   
}

void fail() { 
 
  for (int y=0; y<=3; y++)
  { 
     
    digitalWrite(ledpin[0], HIGH);
    digitalWrite(ledpin[1], HIGH);
     digitalWrite(ledpin[2], HIGH);
    digitalWrite(ledpin[3], HIGH);
    speakerpin.play(NOTE_G2, 300);
    delay(200);
    digitalWrite(ledpin[0], LOW);
    digitalWrite(ledpin[1], LOW);
    digitalWrite(ledpin[2], LOW);
    digitalWrite(ledpin[3], LOW);
     speakerpin.play(NOTE_C2, 300);
    delay(200);
    lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("You Lose");
 lcd.setCursor(0, 1);
 lcd.print("Game Over");
 }
 delay(2000);
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("High:  " + (String) (highscore));
 

 lcd.setCursor(9, 0);
 lcd.print("You:   ");
 lcd.setCursor(14, 0);
 lcd.print(MyScore);
 
 lcd.setCursor(0,   1);
 lcd.print("<-Press to play again!");
 {
 
 while (digitalRead(button[0]) > 0 &&digitalRead(button[1]) > 0 && digitalRead(button[2]) > 0 && digitalRead(button[3]) > 0 ){
digitalWrite(ledpin[0], HIGH);
digitalWrite(ledpin[1], HIGH);
digitalWrite(ledpin[2], HIGH);
digitalWrite(ledpin[3], HIGH);
delay(100);
digitalWrite(ledpin[0], LOW);
digitalWrite(ledpin[1], LOW);
digitalWrite(ledpin[2], LOW);
digitalWrite(ledpin[3], LOW);
delay(100);
 }
 delay(1000);
  
  turn = -1; 
}
}

