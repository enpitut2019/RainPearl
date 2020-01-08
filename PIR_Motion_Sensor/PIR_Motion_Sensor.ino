int pirPin = 16;                 // PIR Out pin 
int pirStat = 0;                   // PIR status

void setup() {
 pinMode(pirPin, INPUT_PULLUP);     
 Serial.begin(9600);
}

void loop(){
  while(Serial.available() == 0);
  while(Serial.available() > 0){
    Serial.read();
  }
  
  pirStat = digitalRead(pirPin); 
  if(pirStat == HIGH) {
    Serial.println("HIGH");
  }else{
    Serial.println("LOW");
  }
} 
