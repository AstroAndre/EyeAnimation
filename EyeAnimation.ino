#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "anim.h"

//Both Matrices are connect to the same pins
//We only need to initialize only one matrix here
Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

//Length of a animation
int shortDelay = 2500;
int longDelay = 5000;
int delayVariationTypes = 2;
int modeLength = 0;
int delayVariation = 0;

//Chance of a blink
int blinkDelay = 100;
int blinkChance = 10;
int blinkChanceResult;

//Selection of a current animation
int animSelection = 0;
int animVariation = 0;

void setup() 
{
   matrix.begin(0x70);
   matrix.setBrightness(10);
   matrix.setRotation(3);
   matrix.blinkRate(0);
   
   //Start with one of the four animation modes
   animVariation = random(5);
   //Delay is short or long
   delayVariation = random(delayVariationTypes);
}

void ledUpdate()
{
   matrix.writeDisplay();
   
   //Delay selection
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

//There is a slight chance of eye blinking
void blinkAnim()
{
   blinkChanceResult = random(blinkChance);

   if(blinkChanceResult > 8){
        matrix.drawBitmap(0, 0, eyesclosed_bmp, 8, 8, LED_ON);
        matrix.writeDisplay();
        matrix.clear();
        delay(blinkDelay);
   }
}

void newDelayMode()
{
   delayVariation = random(delayVariationTypes);
}

void loop() 
{
//SELECTION OF DIFFERENT ANIMATION TYPES
//Standard mode
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

//Bored mode
if (animVariation == 1){
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

//Happy mode
if (animVariation == 2){
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

//Angry mode
if (animVariation == 3){
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

//Stoned mode
if (animVariation == 4){
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

//Set a new animation mode and a new delay type
newAnimMode();
newDelayMode();
}
