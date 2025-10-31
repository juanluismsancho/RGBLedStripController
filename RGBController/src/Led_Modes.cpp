#include "Led_Modes.h"
#include <Adafruit_NeoPixel.h>

// ---------------- MODO ROJO ----------------
void redMode(Adafruit_NeoPixel &strip)
{
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(255, 0, 0));
  }
  strip.show();
}

// ---------------- COLOR ESTÁTICO ----------------
void staticColorMode(Adafruit_NeoPixel &strip, uint32_t c)
{
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
  }
  strip.show();
}

// ---------------- ARCOIRIS CONTINUO ----------------
void rainbow(Adafruit_NeoPixel &strip, volatile bool &changeMode)
{
  for (long firstPixelHue = 0; firstPixelHue < 3L * 65536L; firstPixelHue += 256) {
    for (int i = 0; i < strip.numPixels(); i++) {
      if (changeMode == false)
        return;

      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show();
    delay(5);
  }
}

// ---------------- THEATER CHASE RAINBOW ----------------
void theaterChaseRainbow(Adafruit_NeoPixel &strip, int wait)
{
  int firstPixelHue = 0; // empieza rojo (hue 0)
  for (int a = 0; a < 30; a++) {        // repetir 30 veces
    for (int b = 0; b < 3; b++) {       // b: 0..2
      strip.clear();                   // apaga RAM
      for (int c = b; c < strip.numPixels(); c += 3) {
        int      hue   = firstPixelHue + c * 65536L / strip.numPixels();
        uint32_t color = strip.gamma32(strip.ColorHSV(hue));
        strip.setPixelColor(c, color);
      }
      strip.show();
      delay(wait);
      firstPixelHue += 65536 / 90; // avanza rueda color
    }
  }
}

// ---------------- TECNO ----------------
void tecno(
  Adafruit_NeoPixel &strip,
  uint32_t RT1, uint32_t GT1, uint32_t BT1,
  uint32_t RT2, uint32_t GT2, uint32_t BT2,
  uint32_t RT3, uint32_t GT3, uint32_t BT3,
  int tecnoTime
)
{
  for (int i = 0; i < 20; i++) {

    for (uint16_t j = 0; j < strip.numPixels(); j++) {
      strip.setPixelColor(j, strip.Color(RT1, GT1, BT1));
    }
    strip.show();
    delay(tecnoTime);

    for (uint16_t j = 0; j < strip.numPixels(); j++) {
      strip.setPixelColor(j, strip.Color(RT2, GT2, BT2));
    }
    strip.show();
    delay(tecnoTime);

    for (uint16_t j = 0; j < strip.numPixels(); j++) {
      strip.setPixelColor(j, strip.Color(RT3, GT3, BT3));
    }
    strip.show();
    delay(tecnoTime);
  }
}

// ---------------- KITT / BARRIDO ----------------
void kid(
  Adafruit_NeoPixel &strip,
  uint32_t c,
  int ledsEfectoKid,
  int velocidadKid,
  int velocidadKidApagado
)
{
  Serial.println("Inicio ida kid");

  // ida
  for (uint16_t i = 0; i < strip.numPixels(); i++) {

    strip.setPixelColor(i, c);

    // apaga el LED "cola"
    if (i >= ledsEfectoKid) {
      strip.setPixelColor(i - ledsEfectoKid, strip.Color(0, 0, 0));
    }

    // limpieza al final
    if (i == (strip.numPixels() - 1)) {
      for (uint16_t j = (i - ledsEfectoKid);
           j < strip.numPixels() - (ledsEfectoKid * 0.25);
           j++) {

        strip.setPixelColor(j, strip.Color(0, 0, 0));
        strip.show();
        delay(velocidadKidApagado);
      }
    }

    strip.show();
    delay(velocidadKid);
  }

  // vuelta
  for (int i = strip.numPixels() - 1; i >= 0; i--) {

    strip.setPixelColor(i, c);

    // apaga LED delante
    if (i + ledsEfectoKid < strip.numPixels()) {
      strip.setPixelColor(i + ledsEfectoKid, strip.Color(0, 0, 0));
    }

    // limpieza al inicio
    if (i == 0) {
      for (uint16_t j = (i + ledsEfectoKid);
           j > (ledsEfectoKid * 0.25);
           j--) {

        strip.setPixelColor(j, strip.Color(0, 0, 0));
        strip.show();
        delay(velocidadKidApagado);
      }
    }

    strip.show();
    delay(velocidadKid);
  }
}
