#include <Scheduler.h>
#include <dmx.h>
#include <fastspi_nop.h>
#include <fastled_config.h>
#include <fastled_delay.h>
#include <pixeltypes.h>
#include <pixelset.h>
#include <controller.h>
#include <FastLED.h>
#include <fastspi_ref.h>
#include <cpp_compat.h>
#include <hsv2rgb.h>
#include <led_sysdefs.h>
#include <bitswap.h>
#include <colorutils.h>
#include <fastspi_bitbang.h>
#include <fastled_progmem.h>
#include <color.h>
#include <fastspi_dma.h>
#include <fastspi_types.h>
#include <fastpin.h>
#include <noise.h>
#include <platforms.h>
#include <power_mgt.h>
#include <lib8tion.h>
#include <chipsets.h>
#include <fastspi.h>
#include <colorpalettes.h>
//#include <future>
//#include <Scheduler.h>

#define NUM_LEDS 30
#define DATA_PIN 6

#define ARMENIA 0
#define ETHIOPIA 1
#define HONDURAS 2
#define INDIA 3
#define USA 4
#define ZAMBIA 5

//
//int led = 13;
CRGB leds[NUM_LEDS];
//int populationDensity[3][13];
int bees[6][15];
int malnutrition[6][15];

//
void setup() {
  //	pinMode(led, OUTPUT);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);	
  //FastLED.setBrightness(5);

  setUpBees();
  setUpMalnutrition();
}

void loop() {
  //  prettyColourScrolling();

  for(int i=1; i<15; i++)
  {
    //call_async_threads();
    for(int region=0; region<4; region++)
    {
      int beesDensity = bees[region][i];
      int redBees = beesDensity;
      int greenBees = 255 - beesDensity;

      leds[region*2] = CRGB(redBees, greenBees, 0);

      int malDensity = malnutrition[region][i];
      int redMalnutrition = malDensity;
      int greenMalnutrition = 255 - malDensity;

      leds[region*2+1] = CRGB(redMalnutrition, greenMalnutrition, 0);
      FastLED.show(); 

    }
    delay(600);
  }
}

// This function simply sets up the Array of Bee Data
void setUpBees()
{
bees[ARMENIA][1] = 46;
bees[ARMENIA][2] = 61;
bees[ARMENIA][3] = 102;
bees[ARMENIA][4] = 98;
bees[ARMENIA][5] = 96;
bees[ARMENIA][6] = 116;
bees[ARMENIA][7] = 158;
bees[ARMENIA][8] = 175;
bees[ARMENIA][9] = 187;
bees[ARMENIA][10] = 201;
bees[ARMENIA][11] = 209;
bees[ARMENIA][12] = 215;
bees[ARMENIA][13] = 228;
bees[ARMENIA][14] = 247;
bees[ETHIOPIA][1] = 100;
bees[ETHIOPIA][2] = 133;
bees[ETHIOPIA][3] = 127;
bees[ETHIOPIA][4] = 137;
bees[ETHIOPIA][5] = 121;
bees[ETHIOPIA][6] = 147;
bees[ETHIOPIA][7] = 141;
bees[ETHIOPIA][8] = 155;
bees[ETHIOPIA][9] = 139;
bees[ETHIOPIA][10] = 155;
bees[ETHIOPIA][11] = 150;
bees[ETHIOPIA][12] = 157;
bees[ETHIOPIA][13] = 154;
bees[ETHIOPIA][14] = 177;
bees[HONDURAS][1] = 4;
bees[HONDURAS][2] = 4;
bees[HONDURAS][3] = 4;
bees[HONDURAS][4] = 4;
bees[HONDURAS][5] = 4;
bees[HONDURAS][6] = 4;
bees[HONDURAS][7] = 4;
bees[HONDURAS][8] = 4;
bees[HONDURAS][9] = 4;
bees[HONDURAS][10] = 4;
bees[HONDURAS][11] = 4;
bees[HONDURAS][12] = 4;
bees[HONDURAS][13] = 4;
bees[HONDURAS][14] = 4;
bees[INDIA][1] = 23;
bees[INDIA][2] = 23;
bees[INDIA][3] = 23;
bees[INDIA][4] = 23;
bees[INDIA][5] = 23;
bees[INDIA][6] = 23;
bees[INDIA][7] = 23;
bees[INDIA][8] = 25;
bees[INDIA][9] = 25;
bees[INDIA][10] = 27;
bees[INDIA][11] = 27;
bees[INDIA][12] = 27;
bees[INDIA][13] = 27;
bees[INDIA][14] = 28;
bees[USA][1] = 24;
bees[USA][2] = 24;
bees[USA][3] = 25;
bees[USA][4] = 24;
bees[USA][5] = 23;
bees[USA][6] = 23;
bees[USA][7] = 22;
bees[USA][8] = 22;
bees[USA][9] = 24;
bees[USA][10] = 26;
bees[USA][11] = 24;
bees[USA][12] = 24;
bees[USA][13] = 25;
bees[USA][14] = 26;
bees[ZAMBIA][1] = 7;
bees[ZAMBIA][2] = 8;
bees[ZAMBIA][3] = 9;
bees[ZAMBIA][4] = 10;
bees[ZAMBIA][5] = 10;
bees[ZAMBIA][6] = 10;
bees[ZAMBIA][7] = 10;
bees[ZAMBIA][8] = 10;
bees[ZAMBIA][9] = 10;
bees[ZAMBIA][10] = 10;
bees[ZAMBIA][11] = 11;
bees[ZAMBIA][12] = 11;
bees[ZAMBIA][13] = 11;
bees[ZAMBIA][14] = 11;

}

// This function sets up the malnutrition Array
void setUpMalnutrition()
{
malnutrition[ARMENIA][1] = 86;
malnutrition[ARMENIA][2] = 92;
malnutrition[ARMENIA][3] = 89;
malnutrition[ARMENIA][4] = 77;
malnutrition[ARMENIA][5] = 59;
malnutrition[ARMENIA][6] = 44;
malnutrition[ARMENIA][7] = 33;
malnutrition[ARMENIA][8] = 27;
malnutrition[ARMENIA][9] = 24;
malnutrition[ARMENIA][10] = 24;
malnutrition[ARMENIA][11] = 26;
malnutrition[ARMENIA][12] = 27;
malnutrition[ARMENIA][13] = 27;
malnutrition[ARMENIA][14] = 27;
malnutrition[ETHIOPIA][1] = 232;
malnutrition[ETHIOPIA][2] = 219;
malnutrition[ETHIOPIA][3] = 208;
malnutrition[ETHIOPIA][4] = 200;
malnutrition[ETHIOPIA][5] = 191;
malnutrition[ETHIOPIA][6] = 184;
malnutrition[ETHIOPIA][7] = 175;
malnutrition[ETHIOPIA][8] = 170;
malnutrition[ETHIOPIA][9] = 164;
malnutrition[ETHIOPIA][10] = 158;
malnutrition[ETHIOPIA][11] = 150;
malnutrition[ETHIOPIA][12] = 144;
malnutrition[ETHIOPIA][13] = 140;
malnutrition[ETHIOPIA][14] = 136;
malnutrition[HONDURAS][1] = 76;
malnutrition[HONDURAS][2] = 74;
malnutrition[HONDURAS][3] = 71;
malnutrition[HONDURAS][4] = 68;
malnutrition[HONDURAS][5] = 67;
malnutrition[HONDURAS][6] = 67;
malnutrition[HONDURAS][7] = 66;
malnutrition[HONDURAS][8] = 64;
malnutrition[HONDURAS][9] = 61;
malnutrition[HONDURAS][10] = 60;
malnutrition[HONDURAS][11] = 60;
malnutrition[HONDURAS][12] = 58;
malnutrition[HONDURAS][13] = 55;
malnutrition[HONDURAS][14] = 51;
malnutrition[INDIA][1] = 68;
malnutrition[INDIA][2] = 70;
malnutrition[INDIA][3] = 74;
malnutrition[INDIA][4] = 80;
malnutrition[INDIA][5] = 84;
malnutrition[INDIA][6] = 85;
malnutrition[INDIA][7] = 82;
malnutrition[INDIA][8] = 76;
malnutrition[INDIA][9] = 69;
malnutrition[INDIA][10] = 65;
malnutrition[INDIA][11] = 63;
malnutrition[INDIA][12] = 62;
malnutrition[INDIA][13] = 62;
malnutrition[INDIA][14] = 62;
malnutrition[ZAMBIA][1] = 172;
malnutrition[ZAMBIA][2] = 182;
malnutrition[ZAMBIA][3] = 188;
malnutrition[ZAMBIA][4] = 193;
malnutrition[ZAMBIA][5] = 194;
malnutrition[ZAMBIA][6] = 198;
malnutrition[ZAMBIA][7] = 203;
malnutrition[ZAMBIA][8] = 210;
malnutrition[ZAMBIA][9] = 214;
malnutrition[ZAMBIA][10] = 212;
malnutrition[ZAMBIA][11] = 207;
malnutrition[ZAMBIA][12] = 201;
malnutrition[ZAMBIA][13] = 198;
malnutrition[ZAMBIA][14] = 195;
malnutrition[USA][1] = 0;
malnutrition[USA][2] = 0;
malnutrition[USA][3] = 0;
malnutrition[USA][4] = 0;
malnutrition[USA][5] = 0;
malnutrition[USA][6] = 0;
malnutrition[USA][7] = 0;
malnutrition[USA][8] = 0;
malnutrition[USA][9] = 0;
malnutrition[USA][10] = 0;
malnutrition[USA][11] = 0;
malnutrition[USA][12] = 0;
malnutrition[USA][13] = 0;
malnutrition[USA][14] = 0;

}

void prettyColourScrolling()
{
  int rgbIncrement = 10;

  for(int i = 0; i< 255; i++)
  {
    for(int ledNum = 0; ledNum <30; ledNum ++)
    {
      int red = 255-i;
      int green = i;

      red = red - rgbIncrement * ledNum;
      green = green + rgbIncrement * ledNum;

      red = red%255;
      green = green%255;

      leds[ledNum] = CRGB(red, green, green);
    }
    FastLED.show(); 
    delay(5);
  }    
}












