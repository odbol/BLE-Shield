/*
 * BLE Shield Serial Test Sketch for Arduino 1.0.1
 * v1.0.0 2012-10-25
 * 
 * Copyright (c) 2012 Dr. Michael Kroll
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this 
 * software and associated documentation files (the "Software"), to deal in the Software 
 * without restriction, including without limitation the rights to use, copy, modify, merge, 
 * publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons 
 * to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or 
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR 
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE 
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.mkroll.mobi
 * http://forum.mkroll.mobi
 */

// Pin 13 has an LED connected on most Arduino boards.
int led = 13;

long previousMillis = 0; 
long interval = 1000; 

int currentRhythmMultiplier = 1;

void setup()  
{
  // set the data rate for the Serial port
  Serial.begin(9600); //was 19200 for firmware v1.0.1
  randomSeed(analogRead(0));  
}

void loop() // run over and over
{ 
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    
    previousMillis = currentMillis;   
    
    for (int i = 0; i < 4; i++) {
      int randNumber1 = '0' + i;//random(255);
      int randNumber2 = '1';//random(255);
      int randNumber3 = '2';//random(255);
      int randNumber4 = '\n';//random(255);
      
      Serial.write(randNumber1);
      Serial.write(randNumber2);
      Serial.write(randNumber3);
      Serial.write(randNumber4);    
      Serial.flush();
    }
    int delayTime = 200 * currentRhythmMultiplier * 2;
    delay(delayTime);               // wait for a second
    // don't count the delay as our interval
    previousMillis += delayTime;
    
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    
    // lengthen the beat in measures of 3
    currentRhythmMultiplier = (currentRhythmMultiplier % 3) + 1;
  }
  
  if (Serial.available()) {
    int data = Serial.read();
  }
}



