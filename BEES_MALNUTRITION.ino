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
  FastLED.setBrightness(5);

  setUpBees();
  setUpMalnutrition();
}

void loop() {
  //  prettyColourScrolling();

  for(int i=1; i<13; i++)
  {
    //call_async_threads();
    for(int region=0; region<3; region++)
    {
      int density = populationDensity[region][i];
      int red = density;
      int green = 255 - density;

      leds[region] = CRGB(red, green, 0);
      FastLED.show(); 

    }
    delay(1000);
  }
}

void setUpPopulationDensity()
{
  populationDensity[PEMBROKESHIRE][12] = 245;
  populationDensity[PEMBROKESHIRE][11] = 236;
  populationDensity[PEMBROKESHIRE][10] = 222;
  populationDensity[PEMBROKESHIRE][9] = 213;
  populationDensity[PEMBROKESHIRE][8] = 204;
  populationDensity[PEMBROKESHIRE][7] = 171;
  populationDensity[PEMBROKESHIRE][6] = 142;
  populationDensity[PEMBROKESHIRE][5] = 119;
  populationDensity[PEMBROKESHIRE][4] = 102;
  populationDensity[PEMBROKESHIRE][3] = 74;
  populationDensity[PEMBROKESHIRE][2] = 53;
  populationDensity[PEMBROKESHIRE][1] = 29;
  populationDensity[BIRMINGHAM][12] = 255;
  populationDensity[BIRMINGHAM][11] = 227;
  populationDensity[BIRMINGHAM][10] = 193;
  populationDensity[BIRMINGHAM][9] = 166;
  populationDensity[BIRMINGHAM][8] = 137;
  populationDensity[BIRMINGHAM][7] = 112;
  populationDensity[BIRMINGHAM][6] = 92;
  populationDensity[BIRMINGHAM][5] = 76;
  populationDensity[BIRMINGHAM][4] = 45;
  populationDensity[BIRMINGHAM][3] = 30;
  populationDensity[BIRMINGHAM][2] = 15;
  populationDensity[BIRMINGHAM][1] = 0;
  populationDensity[EXETER][12] = 255;
  populationDensity[EXETER][11] = 187;
  populationDensity[EXETER][10] = 148;
  populationDensity[EXETER][9] = 110;
  populationDensity[EXETER][8] = 103;
  populationDensity[EXETER][7] = 101;
  populationDensity[EXETER][6] = 73;
  populationDensity[EXETER][5] = 68;
  populationDensity[EXETER][4] = 2;
  populationDensity[EXETER][3] = 12;
  populationDensity[EXETER][2] = 0;
  populationDensity[EXETER][1] = 16;


}
void setUpBees()
{
}
void setUpMalnutrition();

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







