#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <Led_Modes.h>

int PIN=5;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(107, PIN, NEO_GRB + NEO_KHZ800);

volatile int mode = 2;
volatile bool changeMode = true;

int R=0;
int G=255;
int B=0;
int tecnoTime=200;
int velocidadKid=0;
int velocidadKidApagado=1;
int ledsEfectoKid=50;

//tecno
uint32_t RT1 = 255;
uint32_t GT1 = 0;
uint32_t BT1 = 0;

uint32_t RT2 = 0;
uint32_t GT2 = 0;
uint32_t BT2 = 255;

uint32_t RT3 = 0;
uint32_t GT3 = 255;
uint32_t BT3 = 0;

void setup() {
  pinMode(PIN, OUTPUT);
   Serial.begin(9600); 

}

void loop() {
  switch (mode)
  {
    case 1:
        Serial.println("MODO 1");
        redMode(strip);
      break;
    case 2:
        Serial.println("MODO 2");
        staticColorMode(strip,strip.Color(R, G, B));
      break;
    case 3:
        Serial.println("MODO 3");
        rainbow(strip,changeMode);
      break;
    default:
      break;
  }
}
