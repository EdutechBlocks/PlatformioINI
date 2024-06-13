// Gerado por EduTech Blocks
// Programa Educacional

#include <Arduino.h>
#include <Wire.h>

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <colors.h>
#include <pantera.h>
#include <tone.h>

#define TFT_SCLK 19
#define TFT_MOSI 21
#define TFT_DC 23
#define TFT_CS 13
#define TFT_RST 22
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
#define pino_som_buzzer 2
TONE tom;

//Exibe a imagem pantera
void funcao_desenha_imagem_pantera()
{
    int h = 128, w = 160, row, col, buffidx = 0;
    for (row = 0; row < h; row++) {
        for (col = 0; col < w; col++) {
            tft.drawPixel(col, row, pgm_read_word(pantera+ buffidx));
            buffidx++;
        };
    };
}



void setup() {
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);
  tft.fillScreen(ST7735_BLACK);
  tft.setTextWrap(false);
  pinMode(pino_som_buzzer, OUTPUT);

  funcao_desenha_imagem_pantera();
  tom.playPinkPanther(pino_som_buzzer,8);

}

void loop() {

}
