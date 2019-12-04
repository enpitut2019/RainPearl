#define LED_OUT 10
#define PIR_IN 15

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_OUT, OUTPUT);
  pinMode(PIR_IN, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(PIR_IN) == HIGH){
    digitalWrite(LED_OUT, HIGH);
  } else {
    digitalWrite(LED_OUT, LOW);
  }
  delay(10);
}
