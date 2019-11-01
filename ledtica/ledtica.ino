#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN            6
#define NUMPIXELS      2

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 20; // delay for half a second

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
//  for(int i=0;i <NUMPIXELS; i++){
//    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.
//    pixels.show(); // This sends the updated pixel color to the hardware.
//    delay(delayval); // Delay for a period of time (in milliseconds).
//  }

pixels.setPixelColor(0, pixels.Color(0,0,0)); // Moderately bright green color.
pixels.setPixelColor(1, pixels.Color(0,0,0));
pixels.show();
delay(delayval);


pixels.setPixelColor(0, pixels.Color(0,150,0)); // Moderately bright green color.
pixels.setPixelColor(1, pixels.Color(0,150,0));
pixels.show();
delay(delayval);

 // This sends the updated pixel color to the hardware.
   
}
