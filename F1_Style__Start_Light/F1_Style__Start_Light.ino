#include <Adafruit_NeoPixel.h>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(32, PIN, NEO_GRB + NEO_KHZ800);

const byte numChars = 32;
char receivedChars[numChars];
boolean newData = false;

void setup() {
  strip.begin();
  strip.setBrightness(128);
  strip.show(); // Initialize all pixels to 'off'
  // Start up serial monitor
  Serial.begin(9600);
}

void loop()
{
  recvWithStartEndMarkers();
  if (newData == true)
  {
    if (strcmp(receivedChars, "$00-005") == 0)
    {
      lightClusterOne();
      newData = false;
    }
    else if (strcmp(receivedChars, "$00-004") == 0)
    {
      lightClusterTwo();
      newData = false;
    }
    else if (strcmp(receivedChars, "$00-003") == 0)
    {
      lightClusterThree();
      newData = false;
    }
    else if (strcmp(receivedChars, "$00-002") == 0)
    {
      lightClusterFour();
      newData = false;
    }
    else if (strcmp(receivedChars, "$00-001") == 0)
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
  char endMarker = '.';
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
  strip.setPixelColor(0, 255, 0, 0);
  strip.setPixelColor(1, 255, 0, 0);
  strip.setPixelColor(2, 255, 0, 0);
  strip.setPixelColor(3, 255, 0, 0);
  strip.setPixelColor(4, 255, 0, 0);
  strip.setPixelColor(5, 255, 0, 0);
  strip.setPixelColor(6, 255, 0, 0);
  strip.setPixelColor(7, 255, 0, 0);
  strip.show();
}

void lightClusterTwo() {
  strip.setPixelColor(0, 255, 0, 0);
  strip.setPixelColor(1, 255, 0, 0);
  strip.setPixelColor(2, 255, 0, 0);
  strip.setPixelColor(3, 255, 0, 0);
  strip.setPixelColor(4, 255, 0, 0);
  strip.setPixelColor(5, 255, 0, 0);
  strip.setPixelColor(6, 255, 0, 0);
  strip.setPixelColor(7, 255, 0, 0);
  strip.setPixelColor(8, 255, 0, 0);
  strip.setPixelColor(9, 255, 0, 0);
  strip.setPixelColor(10, 255, 0, 0);
  strip.setPixelColor(11, 255, 0, 0);
  strip.setPixelColor(12, 255, 0, 0);
  strip.setPixelColor(13, 255, 0, 0);
  strip.setPixelColor(14, 255, 0, 0);
  strip.setPixelColor(15, 255, 0, 0);
  strip.show();
}

void lightClusterThree() {
  strip.setPixelColor(0, 255, 0, 0);
  strip.setPixelColor(1, 255, 0, 0);
  strip.setPixelColor(2, 255, 0, 0);
  strip.setPixelColor(3, 255, 0, 0);
  strip.setPixelColor(4, 255, 0, 0);
  strip.setPixelColor(5, 255, 0, 0);
  strip.setPixelColor(6, 255, 0, 0);
  strip.setPixelColor(7, 255, 0, 0);
  strip.setPixelColor(8, 255, 0, 0);
  strip.setPixelColor(9, 255, 0, 0);
  strip.setPixelColor(10, 255, 0, 0);
  strip.setPixelColor(11, 255, 0, 0);
  strip.setPixelColor(12, 255, 0, 0);
  strip.setPixelColor(13, 255, 0, 0);
  strip.setPixelColor(14, 255, 0, 0);
  strip.setPixelColor(15, 255, 0, 0);
  strip.setPixelColor(16, 255, 0, 0);
  strip.setPixelColor(17, 255, 0, 0);
  strip.setPixelColor(18, 255, 0, 0);
  strip.setPixelColor(19, 255, 0, 0);
  strip.setPixelColor(20, 255, 0, 0);
  strip.setPixelColor(21, 255, 0, 0);
  strip.setPixelColor(22, 255, 0, 0);
  strip.setPixelColor(23, 255, 0, 0);
  strip.show();
}

void lightClusterFour() {
  strip.setPixelColor(0, 255, 0, 0);
  strip.setPixelColor(1, 255, 0, 0);
  strip.setPixelColor(2, 255, 0, 0);
  strip.setPixelColor(3, 255, 0, 0);
  strip.setPixelColor(4, 255, 0, 0);
  strip.setPixelColor(5, 255, 0, 0);
  strip.setPixelColor(6, 255, 0, 0);
  strip.setPixelColor(7, 255, 0, 0);
  strip.setPixelColor(8, 255, 0, 0);
  strip.setPixelColor(9, 255, 0, 0);
  strip.setPixelColor(10, 255, 0, 0);
  strip.setPixelColor(11, 255, 0, 0);
  strip.setPixelColor(12, 255, 0, 0);
  strip.setPixelColor(13, 255, 0, 0);
  strip.setPixelColor(14, 255, 0, 0);
  strip.setPixelColor(15, 255, 0, 0);
  strip.setPixelColor(16, 255, 0, 0);
  strip.setPixelColor(17, 255, 0, 0);
  strip.setPixelColor(18, 255, 0, 0);
  strip.setPixelColor(19, 255, 0, 0);
  strip.setPixelColor(20, 255, 0, 0);
  strip.setPixelColor(21, 255, 0, 0);
  strip.setPixelColor(22, 255, 0, 0);
  strip.setPixelColor(23, 255, 0, 0);
  strip.setPixelColor(24, 255, 0, 0);
  strip.setPixelColor(25, 255, 0, 0);
  strip.setPixelColor(26, 255, 0, 0);
  strip.setPixelColor(27, 255, 0, 0);
  strip.setPixelColor(28, 255, 0, 0);
  strip.setPixelColor(29, 255, 0, 0);
  strip.setPixelColor(30, 255, 0, 0);
  strip.setPixelColor(31, 255, 0, 0);
  strip.show();
}

void lightClusterFive() {
  strip.setPixelColor(0, 255, 0, 0);
  strip.setPixelColor(1, 255, 0, 0);
  strip.setPixelColor(2, 255, 0, 0);
  strip.setPixelColor(3, 255, 0, 0);
  strip.setPixelColor(4, 255, 0, 0);
  strip.setPixelColor(5, 255, 0, 0);
  strip.setPixelColor(6, 255, 0, 0);
  strip.setPixelColor(7, 255, 0, 0);
  strip.setPixelColor(8, 255, 0, 0);
  strip.setPixelColor(9, 255, 0, 0);
  strip.setPixelColor(10, 255, 0, 0);
  strip.setPixelColor(11, 255, 0, 0);
  strip.setPixelColor(12, 255, 0, 0);
  strip.setPixelColor(13, 255, 0, 0);
  strip.setPixelColor(14, 255, 0, 0);
  strip.setPixelColor(15, 255, 0, 0);
  strip.setPixelColor(16, 255, 0, 0);
  strip.setPixelColor(17, 255, 0, 0);
  strip.setPixelColor(18, 255, 0, 0);
  strip.setPixelColor(19, 255, 0, 0);
  strip.setPixelColor(20, 255, 0, 0);
  strip.setPixelColor(21, 255, 0, 0);
  strip.setPixelColor(22, 255, 0, 0);
  strip.setPixelColor(23, 255, 0, 0);
  strip.setPixelColor(24, 255, 0, 0);
  strip.setPixelColor(25, 255, 0, 0);
  strip.setPixelColor(26, 255, 0, 0);
  strip.setPixelColor(27, 255, 0, 0);
  strip.setPixelColor(28, 255, 0, 0);
  strip.setPixelColor(29, 255, 0, 0);
  strip.setPixelColor(30, 255, 0, 0);
  strip.setPixelColor(31, 255, 0, 0);
  strip.setPixelColor(32, 255, 0, 0);
  strip.setPixelColor(33, 255, 0, 0);
  strip.setPixelColor(34, 255, 0, 0);
  strip.setPixelColor(35, 255, 0, 0);
  strip.setPixelColor(36, 255, 0, 0);
  strip.setPixelColor(37, 255, 0, 0);
  strip.setPixelColor(38, 255, 0, 0);
  strip.setPixelColor(39, 255, 0, 0);
  strip.show();
}

void lightsOut() {
  strip.setPixelColor(0, 0, 0, 0);
  strip.setPixelColor(1, 0, 0, 0);
  strip.setPixelColor(2, 0, 0, 0);
  strip.setPixelColor(3, 0, 0, 0);
  strip.setPixelColor(4, 0, 0, 0);
  strip.setPixelColor(5, 0, 0, 0);
  strip.setPixelColor(6, 0, 0, 0);
  strip.setPixelColor(7, 0, 0, 0);
  strip.setPixelColor(8, 0, 0, 0);
  strip.setPixelColor(9, 0, 0, 0);
  strip.setPixelColor(10, 0, 0, 0);
  strip.setPixelColor(11, 0, 0, 0);
  strip.setPixelColor(12, 0, 0, 0);
  strip.setPixelColor(13, 0, 0, 0);
  strip.setPixelColor(14, 0, 0, 0);
  strip.setPixelColor(15, 0, 0, 0);
  strip.setPixelColor(16, 0, 0, 0);
  strip.setPixelColor(17, 0, 0, 0);
  strip.setPixelColor(18, 0, 0, 0);
  strip.setPixelColor(19, 0, 0, 0);
  strip.setPixelColor(20, 0, 0, 0);
  strip.setPixelColor(21, 0, 0, 0);
  strip.setPixelColor(22, 0, 0, 0);
  strip.setPixelColor(23, 0, 0, 0);
  strip.setPixelColor(24, 0, 0, 0);
  strip.setPixelColor(25, 0, 0, 0);
  strip.setPixelColor(26, 0, 0, 0);
  strip.setPixelColor(27, 0, 0, 0);
  strip.setPixelColor(28, 0, 0, 0);
  strip.setPixelColor(29, 0, 0, 0);
  strip.setPixelColor(30, 0, 0, 0);
  strip.setPixelColor(31, 0, 0, 0);
  strip.setPixelColor(32, 0, 0, 0);
  strip.setPixelColor(33, 0, 0, 0);
  strip.setPixelColor(34, 0, 0, 0);
  strip.setPixelColor(35, 0, 0, 0);
  strip.setPixelColor(36, 0, 0, 0);
  strip.setPixelColor(37, 0, 0, 0);
  strip.setPixelColor(38, 0, 0, 0);
  strip.setPixelColor(39, 0, 0, 0);
  strip.show();
}

