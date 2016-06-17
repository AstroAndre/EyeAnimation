#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "anim.h"

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();
Adafruit_8x8matrix matrixLeft = Adafruit_8x8matrix();

int shortDelay = 2500;
int longDelay = 5000;
int blinkDelay = 100;
int modeLength = 0;
int animSelection = 0;
int blinkChance;
int animVariation = 0;
int delayVariation = 0;
const int buttonPin = 3;
int buttonState; 

void setup() 
{
   matrix.begin(0x70);
   matrix.setBrightness(1);
   matrix.setRotation(3);
   matrix.blinkRate(0);
   animVariation = random(4);
   delayVariation = random(2);
   pinMode(buttonPin, INPUT);   
Serial.begin(9600);  
}

void ledUpdate()
{
    matrix.writeDisplay();

    buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
    if(buttonState == 0){
         matrix.setBrightness(1);
    } else {
         matrix.setBrightness(10);
    }

    if(delayVariation == 0){
      delay(longDelay);
    }else{
      delay(shortDelay);
    }
   matrix.clear();
   blinkAnim();
}

void newAnimMode()
{
   animVariation = random(4);
   modeLength = random(10);
   animSelection = 0;
}

void blinkAnim()
{
   blinkChance = random(10);

   if(blinkChance > 8){
        matrix.drawBitmap(0, 0, eyesclosed_bmp, 8, 8, LED_ON);
        matrix.writeDisplay();
        matrix.clear();
        delay(blinkDelay);
   }
}

void newDelayMode()
{
   delayVariation = random(2);
}

void loop() 
{

//standard mode
if (animVariation == 0){
  for (int i = 0; i <= modeLength; i++){
    animSelection = random(9);
    if (animSelection == 0){
        matrix.drawBitmap(0, 0, eyes1_bmp, 8, 8, LED_ON);
    }
    if (animSelection == 1){
        matrix.drawBitmap(0, 0, eyes2_bmp, 8, 8, LED_ON);
    }
    if (animSelection == 2){
        matrix.drawBitmap(0, 0, eyes3_bmp, 8, 8, LED_ON);
    }
    if (animSelection == 3){
        matrix.drawBitmap(0, 0, eyes4_bmp, 8, 8, LED_ON);
    }
    if (animSelection == 4){
        matrix.drawBitmap(0, 0, eyes5_bmp, 8, 8, LED_ON);
    }
    if (animSelection == 5){
        matrix.drawBitmap(0, 0, eyes6_bmp, 8, 8, LED_ON);
    }
    if (animSelection == 6){
        matrix.drawBitmap(0, 0, eyes7_bmp, 8, 8, LED_ON);
    }
    if (animSelection == 7){
        matrix.drawBitmap(0, 0, eyes8_bmp, 8, 8, LED_ON);
    }
    if (animSelection == 8){
        matrix.drawBitmap(0, 0, eyes9_bmp, 8, 8, LED_ON);
    }
    ledUpdate();
  }
}

//bored mode
if (animVariation == 1 && buttonState == 1){
  for (int i = 0; i <= modeLength; i++){
    animSelection = random(4);
    if (animSelection == 0){
      matrix.drawBitmap(0, 0, eyesbored_bmp, 8, 8, LED_ON);

    }
    if (animSelection == 1){
      matrix.drawBitmap(0, 0, eyesboredright_bmp, 8, 8, LED_ON);

    }
    if (animSelection == 2){
      matrix.drawBitmap(0, 0, eyesboredleft_bmp, 8, 8, LED_ON);

    }
    if (animSelection == 3){
      matrix.drawBitmap(0, 0, eyesclosed_bmp, 8, 8, LED_ON);

    }
    ledUpdate();
  }
}

//happy mode
if (animVariation == 2 && buttonState == 1){
  for (int i = 0; i <= modeLength; i++){
    animSelection = random(3);
    if (animSelection == 0){
      matrix.drawBitmap(0, 0, eyeshappy1_bmp, 8, 8, LED_ON);

    }
    if (animSelection == 1){
      matrix.drawBitmap(0, 0, eyeshappy2_bmp, 8, 8, LED_ON);

    }
    if (animSelection == 2){
      matrix.drawBitmap(0, 0, eyeshappy3_bmp, 8, 8, LED_ON);

    }
    ledUpdate();
  }
}

//angry mode
if (animVariation == 3 && buttonState == 1){
  for (int i = 0; i <= modeLength; i++){
    animSelection = random(4);
    if (animSelection == 0){
      matrix.drawBitmap(0, 0, eyesangry1_bmp, 8, 8, LED_ON);

    }
    if (animSelection == 1){
      matrix.drawBitmap(0, 0, eyesangry2_bmp, 8, 8, LED_ON);

    }
    if (animSelection == 2){
      matrix.drawBitmap(0, 0, eyesangry3_bmp, 8, 8, LED_ON);

    }
    if (animSelection == 3){
      matrix.drawBitmap(0, 0, eyesangry4_bmp, 8, 8, LED_ON);

    }
    ledUpdate();
  }
}

//stoned mode
if (animVariation == 4 && buttonState == 1){
  for (int i = 0; i <= modeLength; i++){
    animSelection = random(3);
    if (animSelection == 0){
      matrix.drawBitmap(0, 0, eyesghosty1_bmp, 8, 8, LED_ON);

    }
    if (animSelection == 1){
      matrix.drawBitmap(0, 0, eyesghosty2_bmp, 8, 8, LED_ON);

    }
    if (animSelection == 2){
      matrix.drawBitmap(0, 0, eyesghosty3_bmp, 8, 8, LED_ON);

    }
    ledUpdate();
  }
}

  newAnimMode();
  newDelayMode();
}
