/*
    This file is part of flexOS and The Open Source Protogen Collection (OSPC).
    flexOS is free software under the MIT license. Please see https://opensource.org/licenses/MIT for more info
*/

/*                 _       _
     /\           | |     (_)
    /  \   _ __ __| |_   _ _ _ __ ______ _____      _____
   / /\ \ | '__/ _` | | | | | '_ \______/ _ \ \ /\ / / _ \
  / ____ \| | | (_| | |_| | | | | |    | (_) \ V  V / (_) |
 /_/    \_\_|  \__,_|\__,_|_|_| |_|     \___/ \_/\_/ \___/ */

#include "config.h" // this file includes our libraries and device-specific variables
#include "declarations.h" // this file includes variables for LED patterns

// creating the matrix using LEDMatrix
// note that height and width are flipped in this example due to TILE_TYPE
cLEDMatrix <MATRIX_TILE_HEIGHT, MATRIX_TILE_WIDTH, MATRIX_TILE_TYPE> ledmatrix;
// creating a pointer to the matrix so FastLED can still operate
CRGB *leds = ledmatrix[0];
// declaring LEDText
cLEDText ScrollingMsg;

// Purpose: Draws a single LED, then delays. Good for particle effects.
// Accepts: int index of LED, long int hex code, int time to delay after drawing (optional)
// Returns: Nothing
void singleLED(int number, long int colour, int delaytime = 0) {
  leds[number] = colour;
  if (delaytime > 0) {
    FastLED.show();
    FastLED.delay(delaytime);
  }
}

// Purpose: Draws LEDs by running through the pixels, one by one, and seeing if they should be lit up according to their array
// Accepts: uint16_t[] of your desired pattern, int size of the pattern array, long int hex code
// Returns: nothing
// For more details on how this works, see https://github.com/OpenSourceProtogenCollection/flexOS/wiki/Notes:-PROGMEM
void drawPattern(uint16_t patternArray[], int patternSize, long int colour) {
  // PGM comes into play here. For more info about PGM, see the declarations header or the wiki
  uint16_t nextPixel; // holds current RAM value from PGM
  int pixelCounter = 0; // increments when a pixel is placed
  for (int i = 0; i < NUM_LEDS; i++) { // loop through LED in the matrix
    for (int j = 0; j < patternSize; j++) { // check every element in the pattern array for the current LED
      nextPixel = pgm_read_word(&patternArray[pixelCounter]); // pull element into RAM
      if (i == nextPixel) { // if the pixel in the matrix matches the array element
        leds[i] = colour; // turn the pixel the specified colour
        pixelCounter++; // move to the next pixel
      }
    }
  }
}

// pattern-writing functions start here

void writeAttnEyes() {
  FastLED.clear();
  drawPattern(attentionEyes, ATTN_EYES, CRGB::Red);
  FastLED.show();
  FastLED.delay(500);
  FastLED.clear();
  FastLED.show();
  FastLED.delay(500);
}

void writeChgEyes() {
  FastLED.clear();
  drawPattern(chargeEyes, CHG_EYES, CRGB::Yellow);
  FastLED.show();
  FastLED.delay(500);
  for (int i = 0; i < 2; i++) {
    drawPattern(chargeEyesRemove, CHG_EYES_R, CRGB::Black);
    drawPattern(chargeEyesAdd, CHG_EYES_R, CRGB::Yellow);
    FastLED.show();
    FastLED.delay(500)
    FastLED.clear();
    drawPattern(chargeEyes, CHG_EYES, CRGB::Yellow);
    FastLED.show();
    FastLED.delay(500)
  }
    singleLED(12, CRGB::Yellow, 100);
    singleLED(62, CRGB::Yellow, 100);
    singleLED(88, CRGB::Yellow, 100);
    singleLED(161, CRGB::Yellow, 100);
    singleLED(234, CRGB::Yellow, 100);
    singleLED(167, CRGB::Yellow, 500);
    FastLED.clear();
}

void writeCoffeeEyes() {
    FastLED.clear();
    drawPattern(coffeeEyesBlue, COF_EYES_B, purpleblue);
    drawPattern(coffeeEyesWhite, COF_EYES_W, CRGB::White);
    FastLED.show(); FastLED.delay(750);
    drawPattern(coffeeEyesRemove, COF_EYES_R, CRGB::Black);
    drawPattern(coffeeEyesAdd, COF_EYES_R, CRGB::White);
    FastLED.show();
    FastLED.delay(500);
}

void writeDniEyes() {
    FastLED.clear();
    drawPattern(dniEyes, DNI_EYES, CRGB::Red);
    FastLED.show();
    FastLED.delay(1000);
    drawPattern(dniEyes, DNI_EYES, CRGB::White);
    FastLED.show();
    delay (1000);
}

void writeError() {
  while (true) {
    FastLED.clear();
    drawPattern(errSt, ERR_S, CRGB::Red);
    FastLED.show();
    FastLED.delay(1000);
    drawPattern(errR1, ERR_1, CRGB::Black);
    drawPattern(errA, ERR_1, CRGB::Red);
    FastLED.show();
    FastLED.delay(250);
    FastLED.clear();
    drawPattern(errSt, ERR_S, CRGB::Red);
    FastLED.show();
    FastLED.delay(250);
    drawPattern(errR1, ERR_1, CRGB::Black);
    drawPattern(errA, ERR_1, CRGB::Red);
    drawPattern(errAGn, ERR_2, seafoam);
    drawPattern(errAB, ERR_2, CRGB::Blue);
    FastLED.show();
    FastLED.delay(100);
    FastLED.clear();
    drawPattern(errSt, ERR_S, CRGB::Red);
    drawPattern(errAGn, ERR_2, seafoam);
    drawPattern(errAB, ERR_2, CRGB::Blue);
    drawPattern(errAY, ERR_Y, CRGB::Yellow);
    drawPattern(errAGr, ERR_3, bluegray);
    drawPattern(errAP, ERR_3, CRGB::Purple);
    FastLED.show();
    FastLED.delay(250);
    drawPattern(errR2, ERR_2, CRGB::Black);
    FastLED.show();
    FastLED.delay(250);
}

void writeCheckEyes() {
    FastLED.clear();
    drawPattern(checkEyes1, CHK_EYES_1, CRGB::Green);
    FastLED.show();
    FastLED.delay(250);
    drawPattern(checkEyes2, CHK_EYES_M, CRGB::Green);
    FastLED.show();
    FastLED.delay(250);
    drawPattern(checkEyes3, CHK_EYES_M, CRGB::Green);
    FastLED.show();
    FastLED.delay(250);
    drawPattern(checkEyes4, CHK_EYES_L, CRGB::Green);
    FastLED.show();
    FastLED.delay(1000);
}

void writeWrongEyes() {
    FastLED.clear();
    ledmatrix.DrawLine(13, 7, 20, 0, CRGB::Red);
    ledmatrix.DrawLine(13, 0, 15, 2, CRGB::Red);
    ledmatrix.DrawLine(20, 7, 18, 5, CRGB::Red);
    FastLED.show();
    FastLED.delay(150);
    FastLED.clear();
    FastLED.show();
    FastLED.delay(150);
    ledmatrix.DrawLine(13, 7, 20, 0, CRGB::Red);
    ledmatrix.DrawLine(13, 0, 15, 2, CRGB::Red);
    ledmatrix.DrawLine(20, 7, 18, 5, CRGB::Red);
    FastLED.show();
    FastLED.delay(150);
    FastLED.clear();
    FastLED.show();
    FastLED.delay(150);
    ledmatrix.DrawLine(13, 7, 20, 0, CRGB::Red);
    ledmatrix.DrawLine(13, 0, 15, 2, CRGB::Red);
    ledmatrix.DrawLine(20, 7, 18, 5, CRGB::Red);
    FastLED.show();
    FastLED.delay(1000);
}

void writeIdleEyes() {
    FastLED.clear();
    ledmatrix.DrawRectangle(3, 4, 4, 6, CRGB::White);
    ledmatrix.DrawRectangle(27, 4, 28, 6, CRGB::White);
    FastLED.show();
    FastLED.delay(3000);
    FastLED.clear();
    ledmatrix.DrawRectangle(3, 4, 4, 5, CRGB::White);
    ledmatrix.DrawRectangle(27, 4, 28, 5, CRGB::White);
    FastLED.show();
    delay(100);
    FastLED.clear();
    ledmatrix.DrawRectangle(3, 4, 4, 4, CRGB::White);
    ledmatrix.DrawRectangle(27, 4, 28, 4, CRGB::White);
    FastLED.show();
    delay(100);
    FastLED.clear();
    ledmatrix.DrawRectangle(3, 4, 4, 5, CRGB::White);
    ledmatrix.DrawRectangle(27, 4, 28, 5, CRGB::White);
    FastLED.show();
    delay(100);
}

void writeCryingEyes() {
  // this will probably just be shorter if I write it with int arrays
  while (true) {
    FastLED.clear();
    ledmatrix.DrawRectangle(3, 4, 4, 5, CRGB::White);
    ledmatrix.DrawRectangle(27, 4, 28, 5, CRGB::White);
    FastLED.show();
    FastLED.delay(1000);
    ledmatrix.DrawLine(3, 3, 4, 3, CRGB::Blue);
    ledmatrix.DrawLine(27, 3, 28, 3, CRGB::Blue);
    FastLED.show();
    delay(200);
    FastLED.clear();
    ledmatrix.DrawRectangle(3, 4, 4, 5, CRGB::White);
    ledmatrix.DrawRectangle(27, 4, 28, 5, CRGB::White);
    ledmatrix.DrawLine(3, 2, 4, 2, CRGB::Blue);
    ledmatrix.DrawLine(27, 2, 28, 2, CRGB::Blue);
    FastLED.show();
    delay(200);
    FastLED.clear();
    ledmatrix.DrawRectangle(3, 4, 4, 5, CRGB::White);
    ledmatrix.DrawRectangle(27, 4, 28, 5, CRGB::White);
    ledmatrix.DrawLine(3, 3, 4, 3, CRGB::Blue);
    ledmatrix.DrawLine(27, 3, 28, 3, CRGB::Blue);
    ledmatrix.DrawLine(3, 1, 4, 1, CRGB::Blue);
    ledmatrix.DrawLine(27, 1, 28, 1, CRGB::Blue);
    FastLED.show();
    delay(200);
    FastLED.clear();
    ledmatrix.DrawRectangle(3, 4, 4, 5, CRGB::White);
    ledmatrix.DrawRectangle(27, 4, 28, 5, CRGB::White);
    ledmatrix.DrawLine(3, 2, 4, 2, CRGB::Blue);
    ledmatrix.DrawLine(27, 2, 28, 2, CRGB::Blue);
    ledmatrix.DrawLine(3, 0, 4, 0, CRGB::Blue);
    ledmatrix.DrawLine(27, 0, 28, 0, CRGB::Blue);
    FastLED.show();
    delay(200);
    FastLED.clear();
    ledmatrix.DrawRectangle(3, 4, 4, 5, CRGB::White);
    ledmatrix.DrawRectangle(27, 4, 28, 5, CRGB::White);
    ledmatrix.DrawLine(3, 1, 4, 1, CRGB::Blue);
    ledmatrix.DrawLine(27, 1, 28, 1, CRGB::Blue);
    FastLED.show();
    delay(200);
    FastLED.clear();
    ledmatrix.DrawRectangle(3, 4, 4, 5, CRGB::White);
    ledmatrix.DrawRectangle(27, 4, 28, 5, CRGB::White);
    ledmatrix.DrawLine(3, 0, 4, 0, CRGB::Blue);
    ledmatrix.DrawLine(27, 0, 28, 0, CRGB::Blue);
    FastLED.show();
    delay(200);
  }
}

void writeIdEyes() {
  while (true) {
    FastLED.clear();
    ledmatrix.DrawRectangle(6, 0, 25, 7, CRGB::Blue);
    ledmatrix.DrawLine(19, 3, 15, 3, CRGB::Blue);
    ledmatrix.DrawLine(15, 5, 23, 5, CRGB::Blue);
    ledmatrix.DrawRectangle(9, 4, 10, 5, CRGB::Blue);
    ledmatrix.DrawRectangle(8, 1, 11, 2, CRGB::Blue);
    FastLED.show(); FastLED.delay(500);
    FastLED.clear();
    FastLED.show();
    FastLED.delay(750);
  }
}

void writeJoyEyes(bool laughing) {
  int eyeSpeed1;
  int eyeSpeed2;

  if (laughing) {
    eyeSpeed1 = 200;
    eyeSpeed2 = 150;
  }
  else {
    eyeSpeed1 = 1000;
    eyeSpeed2 = 1000;
  }
  
    FastLED.clear();
    ledmatrix.DrawLine(3, 4, 5, 6, 0xFFFFFF);
    ledmatrix.DrawLine(7, 4, 6, 5, 0xFFFFFF);
    ledmatrix.DrawLine(24, 4, 26, 6, 0xFFFFFF);
    ledmatrix.DrawLine(28, 4, 27, 5, 0xFFFFFF);
    FastLED.show();
    FastLED.delay(eyeSpeed1);
    FastLED.clear();
    ledmatrix.DrawLine(3, 5, 5, 7, 0xFFFFFF);
    ledmatrix.DrawLine(7, 5, 6, 6, 0xFFFFFF);
    ledmatrix.DrawLine(24, 5, 26, 7, 0xFFFFFF);
    ledmatrix.DrawLine(28, 5, 27, 6, 0xFFFFFF);
    FastLED.show();
    FastLED.delay(eyeSpeed2);
  }
}

void writePhoneEyes() {
    FastLED.clear();
    ledmatrix.DrawFilledRectangle(8, 1, 11, 3, CRGB::Blue);
    ledmatrix.DrawFilledRectangle(20, 1, 23, 3, CRGB::Blue);
    ledmatrix.DrawFilledRectangle(21, 3, 10, 5, CRGB::Blue);
    leds[180] = CRGB::Blue;
    leds[75] = CRGB::Blue;
    FastLED.show();
    delay(250);
    leds[51] = CRGB::Green;
    leds[52] = CRGB::Green;
    leds[58] = CRGB::Green;
    leds[70] = CRGB::Green;
    leds[73] = CRGB::Green;
    leds[182] = CRGB::Green;
    leds[185] = CRGB::Green;
    leds[197] = CRGB::Green;
    leds[203] = CRGB::Green;
    leds[204] = CRGB::Green;
    FastLED.show();
    delay(250);
    ledmatrix.DrawLine(26, 5, 26, 6, CRGB::Green);
    ledmatrix.DrawLine(25, 7, 24, 7, CRGB::Green);
    ledmatrix.DrawLine(6, 7, 7, 7, CRGB::Green);
    ledmatrix.DrawLine(5, 6, 5, 5, CRGB::Green);
    FastLED.show();
    delay(250);
  }
}

void writeSleepyEyes() {
  while (true) {
    FastLED.clear();
    ledmatrix.DrawLine(28, 5, 25, 5, CRGB::White);
    ledmatrix.DrawLine(6, 5, 3, 5, CRGB::White);
    FastLED.show();
    FastLED.delay(1000);
    FastLED.clear();
    drawPattern(zzzEyes1, ZZZ_EYES_S, CRGB::White);
    FastLED.show();
    FastLED.delay(300);
    drawPattern(zzzEyesA1, ZZZ_EYES_M, CRGB::White);
    drawPattern(zzzEyesR1, ZZZ_EYES_M, CRGB::Black);
    FastLED.show();
    FastLED.delay(300);
    FastLED.clear();
    drawPattern(zzzEyes1, ZZZ_EYES_S, CRGB::White);
    drawPattern(zzzEyesA2, ZZZ_EYES_M, CRGB::White);
    drawPattern(zzzEyesR2, ZZZ_EYES_M, CRGB::Black);
    FastLED.show();
    FastLED.delay(300);
    FastLED.clear();
    drawPattern(zzzEyes1, ZZZ_EYES_S, CRGB::White);
    drawPattern(zzzEyesA3, ZZZ_EYES_M, CRGB::White);
    drawPattern(zzzEyesR3, ZZZ_EYES_M, CRGB::Black);
    FastLED.show();
    if (Serial.available() > 0)
      break;
    FastLED.delay(300);
    FastLED.clear();
    drawPattern(zzzEyes1, ZZZ_EYES_S, CRGB::White);
    FastLED.show();
    FastLED.delay(1000);
  }
}

void writeLoadingEyes() {
  /* loading eyes - currently broken due to RAM usage */
    FastLED.clear();
    singleLED(151, rainbow[0]);
    singleLED(150, rainbow[1]);
    singleLED(149, rainbow[2]);
    singleLED(148, rainbow[3]);
    singleLED(147, rainbow[4]);
    singleLED(146, rainbow[5]);
    singleLED(145, rainbow[6]);

    // horrid manual method of doing things
    //    ledmatrix.ShiftUp();
    //    singleLED(topRow[0], rainbow[0], 150);
    //    ledmatrix.ShiftUp();
    //    singleLED(topRow[1], rainbow[0]);
    //    singleLED(topRow[0], rainbow[1], 150);
    //    ledmatrix.ShiftUp();
    //    singleLED(topRow[2], rainbow[0]);
    //    singleLED(topRow[1], rainbow[1]);
    //    singleLED(topRow[0], rainbow[2], 150);
    //    ledmatrix.ShiftUp();
    //    singleLED(topRow[3], rainbow[0]);
    //    singleLED(topRow[2], rainbow[1]);
    //    singleLED(topRow[1], rainbow[2]);
    //    singleLED(topRow[0], rainbow[3], 150);
    //    ledmatrix.ShiftUp();
    //    singleLED(topRow[4], rainbow[0]);
    //    singleLED(topRow[3], rainbow[1]);
    //    singleLED(topRow[2], rainbow[2]);
    //    singleLED(topRow[1], rainbow[3]);
    //    singleLED(topRow[0], rainbow[4], 150);
    //    ledmatrix.ShiftUp();
    //    singleLED(topRow[5], rainbow[0]);
    //    singleLED(topRow[4], rainbow[1]);
    //    singleLED(topRow[3], rainbow[2]);
    //    singleLED(topRow[2], rainbow[3]);
    //    singleLED(topRow[1], rainbow[4]);
    //    singleLED(topRow[0], rainbow[5], 150);
    //    ledmatrix.ShiftUp();
    //    singleLED(topRow[6], rainbow[0]);
    //    singleLED(topRow[5], rainbow[1]);
    //    singleLED(topRow[4], rainbow[2]);
    //    singleLED(topRow[3], rainbow[3]);
    //    singleLED(topRow[2], rainbow[4]);
    //    singleLED(topRow[1], rainbow[5]);
    //    singleLED(topRow[0], rainbow[6], 500);
    //    ledmatrix.ShiftRight();
    //    FastLED.show();

    // this is functional, but ShiftLeft and ShiftRight stall due to a lack of RAM. I'll have to rewrite it for manual shifting.
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j <= i; j++) {
        singleLED(sequence[i - j], rainbow[j]);
      }
      FastLED.show();
      FastLED.delay(1000);
  }
}

void writeLostHandlerEyes() {
    ledmatrix.DrawFilledRectangle(0, 0, 31, 7, CRGB::White);

    if (ScrollingMsg.UpdateText() == -1)
      ScrollingMsg.SetText((unsigned char *)handlerEyesText, sizeof(handlerEyesText) - 1);
    else
      FastLED.show();
    FastLED.delay(15);
  }
}

void writeLowBatteryEyes() {
  while (true) {
    FastLED.clear();
    ledmatrix.DrawRectangle(8, 0, 9, 6, CRGB::White);
    ledmatrix.DrawRectangle(10, 0, 11, 2, CRGB::White);
    ledmatrix.DrawRectangle(13, 0, 17, 6, CRGB::White);
    ledmatrix.DrawLine(14, 1, 14, 5, CRGB::White);
    ledmatrix.DrawLine(19, 6, 19, 2, CRGB::White);
    ledmatrix.DrawLine(20, 0, 20, 1, CRGB::White);
    ledmatrix.DrawLine(21, 2, 21, 3, CRGB::White);
    ledmatrix.DrawLine(22, 0, 22, 1, CRGB::White);
    ledmatrix.DrawLine(23, 6, 23, 2, CRGB::White);
    FastLED.show();
    FastLED.delay(1000);
    FastLED.clear();
    drawPattern(chargeMouthOutline, CHG_MOUTH_O, CRGB::White);
    FastLED.show();
    FastLED.delay(1000);
  }
}

void writeOwoEyes() {
  FastLED.clear();
  ledmatrix.DrawRectangle(3, 4, 5, 6, CRGB::White);
  ledmatrix.DrawRectangle(26, 4, 28, 6, CRGB::White);
  FastLED.show();
}

void writeOwoMouth() {
  FastLED.clear();
  ledmatrix.DrawLine(10, 4, 13, 1, CRGB::White);
  ledmatrix.DrawLine(13, 1, 15, 3, CRGB::White);
  ledmatrix.DrawLine(16, 3, 18, 1, CRGB::White);
  ledmatrix.DrawLine(18, 1, 21, 4, CRGB::White);
  FastLED.show();
}

void writeUwuEyes() {
  FastLED.clear();
  ledmatrix.DrawRectangle(3, 4, 5, 6, CRGB::White);
  leds[217] = CRGB::Black;
  ledmatrix.DrawRectangle(26, 4, 28, 6, CRGB::White);
  leds[38] = CRGB::Black;
  FastLED.show();
}

void writeHeartEyes() {
    FastLED.clear();
    drawPattern(heartEyes, HRT_EYES, CRGB::Red);
    FastLED.show();
    FastLED.delay(500);
    ledmatrix.ShiftUp();
    FastLED.show();
    FastLED.delay(500);
}

void writeHungryEyes() {
  FastLED.clear();
  ledmatrix.DrawLine(14, 7, 17, 7, orangebrown);
  ledmatrix.DrawLine(13, 6, 18, 6, orangebrown);
  ledmatrix.DrawLine(12, 5, 19, 5, orangebrown);
  ledmatrix.DrawLine(12, 4, 19, 4, CRGB::Red);
  ledmatrix.DrawLine(12, 3, 19, 3, darkbrown);
  ledmatrix.DrawLine(12, 2, 19, 2, CRGB::Green);
  ledmatrix.DrawLine(12, 1, 19, 1, orangebrown);
  ledmatrix.DrawLine(13, 0, 18, 0, orangebrown);
  FastLED.show();
}

void writeInternalError() {
    FastLED.clear();
    if (ScrollingMsg.UpdateText() == -1) {
      ScrollingMsg.SetText(internalErrorText, 28);
      ScrollingMsg.SetTextColrOptions(COLR_RGB | COLR_SINGLE, 0xFF, 0x00, 0x00);
    } else {
      FastLED.show();
      FastLED.delay(20);
    }
}

void setup() {

  // instantiate FastLED
  FastLED.addLeds<MATRIX_BOARD_CHIP, LED_PIN, COLOR_ORDER>(ledmatrix[0], ledmatrix.Size());
  FastLED.setBrightness(BRIGHTNESS);
  Serial.begin(9600);

  // instantiate LEDText
  ScrollingMsg.SetFont(MatriseFontData);
  ScrollingMsg.Init(&ledmatrix, ledmatrix.Width(), ScrollingMsg.FontHeight() + 1, 0, 0);

  // make sure the matrix is clear before we go any further
  FastLED.clear();
  FastLED.show();
}

void loop() {
 // place the emotes you want to loop here
}
