#include "EspMQTTClient.h"
#include "Adafruit_NeoPixel.h"
#include <stdlib.h>

// Hardware defines
#define HB_LED_PIN 13
#define BAUD 115200
#define NUM_NEOPIXELS 1
#define NEOPIXEL_PIN 21

// RGB Defines
/* RGB is encoded in 32-bit unsigned integer as follows:
 MSB  XXXX XXX1 0000 0000 0000 0000 0000 0000 LSB
      '  CMD  ' '   Red ' ' Green ' ' Blue  '
Bit #   31-24     23-16     15-8      7-0

      CMD: 0 for off, 1 for on
      Red: 0-255, 255 being 100% red on
      Green: 0-255, 255 being 100% green on
      Blue: 0-255, 255 being 100% blue on*/
#define CMD_MASK_POS 24 // Mask off top 8
#define CMD_MASK (0xFF << CMD_MASK_POS)
#define RED_MASK_POS 16 // mask off upper mid 8
#define RED_MASK (0xFF << RED_MASK_POS)
#define GREEN_MASK_POS 8 // mask off lower mid 8
#define GREEN_MASK (0xFF << GREEN_MASK_POS)
#define BLUE_MASK_POS 0 // mask off lowest 8
#define BLUE_MASK (0xFF << BLUE_MASK_POS)

#define ON_CMD 1
#define OFF_CMD 0

// MQTT connection constants
const char* ssid = "NETGEAR33";
const char* password = "wittystar213";
const char* mqtt = "192.168.1.14";
const char* clientId = "esp32"; // TODO: give yourself a name

// MQTT connection obj
EspMQTTClient client(
  ssid,
  password,
  mqtt,  // MQTT Broker server ip
  clientId      // Client name that uniquely identify your device
);

// Adafruit NeoPixel obj
Adafruit_NeoPixel pixels(NUM_NEOPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup() 
{
  pinMode(HB_LED_PIN, OUTPUT);
  Serial.begin(BAUD);
  pixels.begin();
  client.enableDebuggingMessages(true);
}

void onConnectionEstablished() 
{
  client.subscribe("rgb", [] (const String &payload)  {
    // TODO: OUR CODE GOES HERE!
    // do some strtoul madness
  });
}

void loop() 
{
  client.loop();
  digitalWrite(HB_LED_PIN, !digitalRead(HB_LED_PIN));
  delay(500);
}