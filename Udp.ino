#include <WiFiUdp.h>

WiFiUDP udp;

void setupUdp()
{
  udp.begin(2323);
}

void loopUdp()
{
  int cb = udp.parsePacket();
  if (cb == NUMLEDS * 3)
  {
    udp.read((char*)leds, cb);
    mode = 4;
    FastLED.setBrightness(20);
    FastLED.show();
  }
}

