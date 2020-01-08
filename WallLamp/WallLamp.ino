#include <Adafruit_NeoPixel.h>

// PIN Settings
  // LED Tape Settings
  #define LED_PIN           2
  #define NUMPIXELS         40
  // Human sencing sensor Setting
  #define PIR_IN            16

// Constant values
  Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);
  int frequency     = 60;
  float duty_ratio  = 0.1;
  int span_time = 5;
  int wait_time = 3;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pixels.begin();
  pinMode(PIR_IN, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:

  bool detected = ReadPIR();

  if(detected){
    Serial.println("on");
    int i = 0;
    float delaytime = convertFreq2Delay();
    while(i < frequency * span_time) {
      led_flush(delaytime);
      i += 1;
    }
  }else{
    Serial.println("off");
    led_const();
    delay(wait_time * 1000);
  }
}

bool ReadPIR(){
  int pirStat = digitalRead(PIR_IN); 
  
  if(pirStat == HIGH) {
    return true;
  }else{
    return false;
  }
}

void led_const() {
  for(int i=0;i <NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(121,200,179));
  }
  pixels.show();
}

float convertFreq2Delay(){
  return 1000.0 / (float)frequency;
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
