#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN            6
#define NUMPIXELS      40

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 20; // delay for half a second

const int vib_motor_pin = 9;
const int vib_motor_pin2 = 8;

int state=0;

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
  pinMode(2, INPUT);
}

void loop() {

    if (digitalRead(2) == LOW) {
      if(state==0){
        state=1;
        dalayval+=3;
      }else{
      }
      } else {
        if(state==0){
        }else{
          state=0;
        }
    }

  
  analogWrite( vib_motor_pin, 250 );
  analogWrite( vib_motor_pin2, 250 );
    
  for(int i=0;i <NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
  }

  for(int i=0;i <NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
  }


 // This sends the updated pixel color to the hardware.
   
}
