//Paul Warmuth and Austen Lambert
//EE1301F18 IOT Lab 2

// This #include statement was automatically added by the Particle IDE.
#include <neopixel.h>

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D4
#define PIXEL_COUNT 3
#define PIXEL_TYPE WS2811
#define AN_MAX 4095

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

void setup() {
strip.begin();
}

//this function enables selected led with the color colorselected, and enables the non-selected LED's with the colorUnselected
void oneLight(int led, int colorSelected, int colorUnselected){
    if(led > PIXEL_COUNT)
    {
            return;
    }
    for(int i = 0; i<PIXEL_COUNT; i++)
    {
            strip.setPixelColor(i, colorUnselected);
    }
    strip.setPixelColor(led, colorSelected);
    strip.show();
}

void loop() {
//Setup some colors
int PixelColorRed = strip.Color( 80, 0, 4);
int PixelColorBlue = strip.Color( 0, 0, 128);
int targLED;
int step = AN_MAX/PIXEL_COUNT; //added to make this more general for any number of lights.

int potentiometerVoltage = analogRead(A0); //reading the voltage off the potentiometer.

//steps through and selects the target LED based upon the potentiometer voltage
for(int i = 0; i<PIXEL_COUNT; i++)
{
    if(step*i <= potentiometerVoltage && potentiometerVoltage <= (i+1)*step)
    {
            targLED = i;
    }
}
//Enables the LED selected by the preceeding for() loop.
oneLight(targLED, PixelColorRed, PixelColorBlue);
delay(100); //wait 0.1sec}
}
