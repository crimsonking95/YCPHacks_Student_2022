#include "EspMQTTClient.h"
#include "Adafruit_NeoPixel.h"

// Hardware defines
#define HB_LED_PIN 13
#define BAUD 115200
#define NUM_NEOPIXELS 1
#define NEOPIXEL_PIN 21

// RGB defines
#define ON_CMD 1
#define OFF_CMD 0

// MQTT connection constants
const char* ssid = "NETGEAR33";
const char* password = "wittystar213";
const char* mqtt = "192.168.1.14";
const char* clientId = "esp32";

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
  });
}

void loop() 
{
  client.loop();
  digitalWrite(HB_LED_PIN, !digitalRead(HB_LED_PIN));
  delay(500);
}