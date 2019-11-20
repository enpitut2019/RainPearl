#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN            6
#define NUMPIXELS      40

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 15; // delay for half a second

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  for(int i=0;i <NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.
    // This sends the updated pixel color to the hardware.
    // Delay for a period of time (in milliseconds).
  }
  pixels.show(); 
  delay(7);

  for(int i=0;i <NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(150,150,150)); // Moderately bright green color.
     // This sends the updated pixel color to the hardware.
     // Delay for a period of time (in milliseconds).
  }
  pixels.show();
  delay(15);


 // This sends the updated pixel color to the hardware.
   
}
