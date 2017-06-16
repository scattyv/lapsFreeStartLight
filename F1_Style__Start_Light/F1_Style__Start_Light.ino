#include <Adafruit_NeoPixel.h>

const int PIN = 6;

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(38, PIN, NEO_GRB + NEO_KHZ800);

const byte numChars = 10;
char receivedChars[numChars];
boolean newData = false;

void setup() {
  strip.begin();
  strip.setBrightness(128);
  strip.show(); // Initialize all pixels to 'off'
  // Start up serial monitor
  Serial.begin(9600);
  //  Serial.println("Ready to receive.");
}

void loop()
{
  recvWithStartEndMarkers();
  if (newData == true)
  {
    if (strcmp(receivedChars, "@311") == 0)
    {
      lightClusterOne();
      newData = false;
    }
    else if (strcmp(receivedChars, "@321") == 0)
    {
      lightClusterTwo();
      newData = false;
    }
    else if (strcmp(receivedChars, "@331") == 0)
    {
      lightClusterThree();
      newData = false;
    }
    else if (strcmp(receivedChars, "@341") == 0)
    {
      lightClusterFour();
      newData = false;
    }
    else if (strcmp(receivedChars, "$00-000") == 0)
    {
      lightClusterFive();
      newData = false;
    }
    else if (strcmp(receivedChars, "@00") == 0)
    {
      lightsOut();
      newData = false;
    }
  }
}


void recvWithStartEndMarkers() {
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char startMarker = '#';
  char endMarker = '\r';
  char rc;

  while (Serial.available() > 0 && newData == false) {
    rc = Serial.read();

    if (recvInProgress == true) {
      if (rc != endMarker) {
        receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= numChars) {
          ndx = numChars - 1;
        }
      }
      else {
        receivedChars[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        ndx = 0;
        newData = true;
      }
    }

    else if (rc == startMarker) {
      recvInProgress = true;
    }
  }
}


void lightClusterOne() {
  for (uint16_t i = 0; i < 8; i++) {
    strip.setPixelColor(i, 255, 0, 0);
    strip.show();
  }
}

void lightClusterTwo() {
  for (uint16_t i = 0; i < 16; i++) {
    strip.setPixelColor(i, 255, 0, 0);
    strip.show();
  }
}

void lightClusterThree() {
  for (uint16_t i = 0; i < 24; i++) {
    strip.setPixelColor(i, 255, 0, 0);
    strip.show();
  }
}

void lightClusterFour() {
  for (uint16_t i = 0; i < 32; i++) {
    strip.setPixelColor(i, 255, 0, 0);
    strip.show();
  }
}

void lightClusterFive() {
  for (uint16_t i = 0; i < 38; i++) {
    strip.setPixelColor(i, 255, 0, 0);
    strip.show();
  }
}

void lightsOut() {
  strip.clear();
  strip.show();
}

