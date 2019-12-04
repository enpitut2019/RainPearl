#include <Adafruit_NeoPixel.h>
//#include <avr/power.h>

#define PIN            6
#define NUMPIXELS      24

#define DUTY_INPUT     10
#define VIB_MOTOR_PIN1 9
#define VIB_MOTOR_PIN2 8

#define PIR_IN 15

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int frequency = 60;
float duty_ratio = 0.1;

int state = 0;

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
  pinMode(DUTY_INPUT, INPUT);
  pinMode(PIR_IN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  if (digitalRead(DUTY_INPUT) == HIGH) {
    if( state == 0 ){
//      duty_ratio = (((int)(duty_ratio * 10) + 1) % 10) / 10.0;
        frequency = (frequency + 5) % 50 + 50;
    }
    state = 1;
  } else {
    state = 0;
  }
  
  //analogWrite( VIB_MOTOR_PIN1, 250 );
  //analogWrite( VIB_MOTOR_PIN2, 250 );

  float delaytime = 1.0 / frequency * 1000;
  int i = 0;

  if(digitalRead(PIR_IN) == HIGH){
    //Serial.println("1");
    while(i < 30){
      led_flush(delaytime);
      i += 1;
    }
  }else{
    //Serial.println("0");
  }
  //delay(100);
}

void led_flush(double delaytime){
  
  for(int i=0;i <NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(150,150,150)); // Moderately bright green color.
  }
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(delaytime * duty_ratio); // Delay for a period of time (in milliseconds).

  for(int i=0;i <NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.
  }
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(delaytime * (1.0 - duty_ratio)); // Delay for a period of time (in milliseconds).     
  
}
