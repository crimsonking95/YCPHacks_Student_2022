Presentation: https://docs.google.com/presentation/d/1Rg98W_rXg883IeQwlbPvUz6w47ojJR7W7rojewSRaTU/edit?usp=sharing 

DIRECTIONS:
1. Install Arduino Studio IDE if you don't have it already
2. In Arduino, go to File->Preferences and click the button on the right of "Add Additional Boards Manager URLs"
3. Paste the following link in there "https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json"
4. Click OK and then OK again to close out preferences.
5. Go to Tools->Manage Libraries
6. Search "Adafruit NeoPixel" and install Adafruit NeoPixel by Adafruit
7. Search "EspMQTT" and install "EspMQTTClient" by Patrick Lapointe
8. Go to Tools->Boards->Boards Manager
9. Search esp32 and install esp32 by Espressif Systems
10. Download the appropriate driver from https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers
(I used the windows driver, not the windows universal driver)
11. Open the MQTT_Student.ino file in Arduino, for Board Type select "ESP32 Feather" and the appropriate COM port, then make sure it compiles!