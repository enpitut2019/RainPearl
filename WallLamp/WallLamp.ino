#include <Adafruit_NeoPixel.h>
//#include <avr/power.h>

// PIN Settings
  // LED Tape Settings
  #define LED_PIN           2
  #define NUMPIXELS         40
  // Human sencing sensor Setting
  #define PIR_IN            9
  // Motor Setting
  //#define VIB_MOTOR_PIN1  9
  //#define VIB_MOTOR_PIN2  8
  #define FREQUENCY_SET_PIN 1

// Constant values
  Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);
  int frequency     = 60;
  float duty_ratio  = 0.1;
  bool led_state    = true;
  int freq_analog  = 0;
  
void setup() {
  // put your setup code here, to run once:
//  Serial.begin(9600);
  pixels.begin();
  pinMode(PIR_IN, INPUT);
  run_motor();
}

void loop() {
  // put your main code here, to run repeatedly:
  
//  if(digitalRead(PIR_IN) == HIGH){
    digitalRead(PIR_IN);
    if(true) {
//  if(true){
    led_state = false;
    int i = 0;
    float delaytime = convertFreq2Delay(analogRead(FREQUENCY_SET_PIN));
    while(i < frequency / 2) {
      led_flush(delaytime);
      i += 1;
    }
  }else{
    led_const();
    led_state = true;
    delay(500);
  }
}

void run_motor(){
  //analogWrite( VIB_MOTOR_PIN1, 250 );
  //analogWrite( VIB_MOTOR_PIN2, 250 );
}

void led_const() {
  if (!led_state){
    for(int i=0;i <NUMPIXELS; i++){
      pixels.setPixelColor(i, pixels.Color(121,200,179));
    }
    pixels.show();
  }
}

float convertFreq2Delay(int analog){
  int step_val = min(analog, 100);
  frequency = step_val;
  if (step_val <= 0) step_val = 1;
  return 1.0 / step_val * 1000;
}

void led_flush(float delaytime){
  for(int i=0;i <NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(150,150,150)); // Moderately bright green color.
  }
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(delaytime * duty_ratio); // Delay for a period of time (in milliseconds).

  for(int i=0;i <NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
  }
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(delaytime * (1.0 - duty_ratio)); // Delay for a period of time (in milliseconds).       
}

float* hsv2rgb(float h, float s, float b, float* rgb) {
  rgb[0] = b * mix(1.0, constrain(abs(fract(h + 1.0) * 6.0 - 3.0) - 1.0, 0.0, 1.0), s);
  rgb[1] = b * mix(1.0, constrain(abs(fract(h + 0.6666666) * 6.0 - 3.0) - 1.0, 0.0, 1.0), s);
  rgb[2] = b * mix(1.0, constrain(abs(fract(h + 0.3333333) * 6.0 - 3.0) - 1.0, 0.0, 1.0), s);
  return rgb;
}
float fract(float x) { return x - int(x); }
float mix(float a, float b, float t) { return a + (b - a) * t; }
