#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library
#include <TouchScreen.h>

#include <SPI.h>
#include <SD.h>

#include "BMPReader.h"
#include "SDBmpReader.h"

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
// optional
#define LCD_RESET A4

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

const int chipSelect = 4;
Sd2Card card;

void setup() {
   
  Serial.begin(9600);
  Serial.println("Paint!");
  
  tft.reset();
  
  //Once again, need to hard code the code below
  uint16_t identifier = 0x9341;

  if(identifier == 0x9325) {
    Serial.println("Found ILI9325 LCD driver");
  } else if(identifier == 0x9328) {
    Serial.println("Found ILI9328 LCD driver");
  } else if(identifier == 0x7575) {
    Serial.println("Found HX8347G LCD driver");
  } else if(identifier == 0x9341) {
    Serial.println("Found ILI9341 LCD driver");
  } else if(identifier == 0x8357) {
    Serial.println("Found HX8357D LCD driver");
  } else {
    Serial.print("Unknown LCD driver chip: ");
    Serial.println(identifier, HEX);
   return;
  }

  tft.begin(identifier);
  tft.fillScreen(WHITE);

  pinMode(10, OUTPUT); 

  if (card.init(SPI_HALF_SPEED, chipSelect)) {
    Serial.println("correct present");
  }

   if (!SD.begin(4)) {
    Serial.println("initi failed!");
    return;
  }

  File bmpFile = SD.open("coopers.bmp", FILE_READ);
    if(bmpFile){

      SDBmpReader* fileReader = new SDBmpReader("coopers.bmp", &bmpFile); 
      BmpReader* bmpReader = new BmpReader(fileReader);
      uint32_t bmpHeight = bmpReader->height();
      uint32_t bmpWidth = bmpReader->width();
      
      Serial.println(bmpHeight, DEC);
      Serial.println(bmpWidth, DEC);
      
      for(int16_t y = 0; y < bmpHeight; y++){
        for(int16_t x = 0; x < bmpWidth; x++){
          uint16_t pixelColor = bmpReader->pixel565(x, y);
          tft.drawPixel(x, y, pixelColor);
          Serial.println(pixelColor, HEX);
        }
      }
      
  
      Serial.println("Close File");
      bmpFile.close();
    }
    
  
  
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}
