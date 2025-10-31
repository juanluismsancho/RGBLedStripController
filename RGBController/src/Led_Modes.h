#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

// Modos básicos
void redMode(Adafruit_NeoPixel &strip);
void staticColorMode(Adafruit_NeoPixel &strip, uint32_t c);
void rainbow(Adafruit_NeoPixel &strip, volatile bool &changeMode);

// Extras / efectos
void theaterChaseRainbow(Adafruit_NeoPixel &strip, int wait);
void tecno(
  Adafruit_NeoPixel &strip,
  uint32_t RT1, uint32_t GT1, uint32_t BT1,
  uint32_t RT2, uint32_t GT2, uint32_t BT2,
  uint32_t RT3, uint32_t GT3, uint32_t BT3,
  int tecnoTime
);

void kid(
  Adafruit_NeoPixel &strip,
  uint32_t c,
  int ledsEfectoKid,
  int velocidadKid,
  int velocidadKidApagado
);
