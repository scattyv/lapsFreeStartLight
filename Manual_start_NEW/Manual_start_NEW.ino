#include <Adafruit_NeoPixel.h>

#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(38, PIN, NEO_GRB + NEO_KHZ800);
long randNumber;

void setup() {
  strip.begin();
  strip.show();
  randomSeed(analogRead(0));
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);

}

void loop() {
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(2);
  //print out the value of the pushbutton
  Serial.println(sensorVal);
  if (sensorVal == HIGH) {
    digitalWrite(13, LOW);


  } else {
    digitalWrite(13, HIGH);
    lightSequence();
    randNumber = random(1500);  //Generatea random number form 0-1500 for delay befor lights out.
    delay(randNumber);
    Serial.print(randNumber);
    strip.clear();
    strip.show();
  }
}

void lightSequence() {
  for (uint16_t i = 0; i < 8; i++) {
    strip.setPixelColor(i, 255, 0, 0);
    strip.show();
    delay(125);
    Serial.print(i);
  }
  for (uint16_t i = 8; i < 16; i++) {
    strip.setPixelColor(i, 255, 0, 0);
    strip.show();
    delay(125);
    Serial.print(i);
  }
  for (uint16_t i = 16; i < 24; i++) {
    strip.setPixelColor(i, 255, 0, 0);
    strip.show();
    delay(125);
    Serial.print(i);
  }
  for (uint16_t i = 24; i < 32; i++) {
    strip.setPixelColor(i, 255, 0, 0);
    strip.show();
    delay(125);
    Serial.print(i);
  }
  for (uint16_t i = 32; i < 39; i++) {
    strip.setPixelColor(i, 255, 0, 0);
    strip.show();
    delay(166);
    Serial.print(i);
  }
}


