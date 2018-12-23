/* Included libraries
 *  https://github.com/brianlow/Rotary
 *  https://github.com/etherkit/Si5351Arduino
 *  
 *  
 *  Author: Sojan James <sojan.james@gmail.com>
 */

#include <Rotary.h>

/* SSD1306 display connected over SPI */
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/* Si5351 https://github.com/etherkit/Si5351Arduino */
#include "si5351.h"


/* Rotary */
Rotary r = Rotary(2,3);

int gRotaryPos = 0;

/* Display */
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

/* Comment out above, uncomment this block to use hardware SPI. This is not tested.
#define OLED_DC     6
#define OLED_CS     7
#define OLED_RESET  8
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  &SPI, OLED_DC, OLED_RESET, OLED_CS);
*/

/* Si5351 */
Si5351 si5351(0x60);

unsigned long long gFreqA =  700000001ULL;
unsigned long long gFreqB = 1400000001ULL;
unsigned long long gFreqC = 1400000001ULL;


bool currentFreqSet = 0;
bool freqAChanged = true;
bool freqBChanged = true;
bool freqCChanged = true;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);


  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  
  display.clearDisplay();
  drawWelcome();



  bool i2c_found = false;
  i2c_found = si5351.init(SI5351_CRYSTAL_LOAD_8PF, 0, 0);

   /* Initialise the sensor */
  if (!i2c_found)
  {
    /* There was a problem detecting the IC ... check your connections */
    Serial.print("Si5351 not detected");
    //while(1);
  } else {
    Serial.println("Si5351 Init done");
  }

  //delay(250);
  
 // si5351.set_freq(14*1000*1000*100, SI5351_CLK0);
 // si5351.set_freq(1400000001ULL, SI5351_CLK1);
 // si5351.set_freq(1400000001ULL, SI5351_CLK2);

 // si5351.output_enable(SI5351_CLK0, 1);
    updateDisplay();
  //  updateClocks();


    PCICR |= (1 << PCIE2);
    PCMSK2 |= (1 << PCINT18) | (1 << PCINT19);
    sei();

}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.print("Loop");
  if(freqAChanged ) {
     // updateClocks();
      updateDisplay();

      freqAChanged = false;
  }



}

void drawWelcome(void) {
  
  display.setCursor(0,0);
  display.setTextSize(2);             // Draw 2X-scale text
  display.setTextColor(WHITE);
  display.println(F("  VFO  "));
  display.display();

}

/* Refresh the display */
void updateDisplay(void) {
   Serial.println("Update");
  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(2);             // Draw 2X-scale text
  display.setTextColor(WHITE);
  display.println((unsigned long)gFreqA/100);
  Serial.println((unsigned long)gFreqA/100);


  
  display.display();
  
}


void updateClocks() {
    si5351.set_freq(gFreqA, SI5351_CLK0);
}

ISR(PCINT2_vect) {
  unsigned char result = r.process();
  if (result == DIR_NONE) {
    // do nothing
  }
  else if (result == DIR_CW) {
    Serial.println("ClockWise");
    gFreqA = gFreqA + 100;
    freqAChanged = true;
  }
  else if (result == DIR_CCW) {
    Serial.println("CounterClockWise");
    gFreqA = gFreqA - 100;
    freqAChanged = true;
  }
}
