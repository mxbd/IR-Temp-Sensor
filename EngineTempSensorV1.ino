#include <Adafruit_MLX90614.h>


#include <Wire.h>

#include <Adafruit_SSD1306.h>
#include <splash.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>



Adafruit_SSD1306 display(-1); // Creates Display

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

// 'BanditLogo', 128x64px
const unsigned char BanditLogo [] PROGMEM = {
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xc0, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xc0, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xff, 
0xfc, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 
0xfc, 0x0f, 0xff, 0x8f, 0x00, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xf8, 0xff, 0x9f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xfe, 0x1c, 0x03, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xf1, 0xff, 0x38, 0x7f, 0xff, 0xff, 
0xff, 0xff, 0xf8, 0x70, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xe1, 0xfc, 0x00, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xe0, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0x1f, 0xc7, 0xf8, 0x03, 0xf7, 0x39, 0xcf, 
0xff, 0xfe, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xfe, 0x3f, 0x8f, 0xc0, 0x33, 0x46, 0x11, 0x8f, 
0xff, 0xc0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xfc, 0x7f, 0xff, 0x00, 0xf3, 0x46, 0x00, 0x0f, 
0xff, 0xc0, 0x3f, 0xf8, 0x1f, 0x1f, 0xff, 0xff, 0xe0, 0x7f, 0xcf, 0x03, 0xf2, 0x64, 0x84, 0x2f, 
0xff, 0xf0, 0x7f, 0xf8, 0x38, 0x0f, 0xce, 0x3f, 0x00, 0xff, 0x9f, 0x87, 0xf0, 0x67, 0x04, 0x4f, 
0xff, 0xe1, 0xff, 0xe0, 0x60, 0x0f, 0x88, 0x3c, 0x01, 0xfe, 0x1f, 0x0f, 0xe0, 0x6f, 0x08, 0x4f, 
0xff, 0x83, 0xff, 0x81, 0xc6, 0x1e, 0x00, 0x78, 0x41, 0xf8, 0x3e, 0x0f, 0xe0, 0xce, 0x48, 0x4f, 
0xff, 0x07, 0xfe, 0x07, 0x0c, 0x10, 0x00, 0x60, 0x81, 0xe0, 0x7c, 0x0f, 0x80, 0xce, 0x48, 0x4f, 
0xfe, 0x0f, 0xf0, 0x0e, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x70, 0x00, 0x00, 0xcc, 0x08, 0x1f, 
0xfc, 0x0f, 0x80, 0x7c, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6c, 0x88, 0x02, 0x1f, 
0xf8, 0x00, 0x01, 0xfc, 0x06, 0x08, 0xe0, 0x00, 0x80, 0x30, 0x04, 0x01, 0xcc, 0x00, 0x42, 0x3f, 
0xf0, 0x00, 0x07, 0xfc, 0x3e, 0x73, 0xf0, 0x47, 0xc1, 0xf0, 0x3e, 0x0f, 0xed, 0xff, 0xef, 0x7f, 
0xf0, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xe0, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xf0, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff

};


void setup() 

  {
    
    mlx.begin();
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    
    display.setTextColor(WHITE);
    display.clearDisplay();
    display.drawBitmap(0, 0, BanditLogo, 128, 64, WHITE);
    display.display();
    delay(3000);
    
    display.clearDisplay();
    display.setCursor(20,21);
    display.println("INITIALIZING...");
    display.display();
    delay(1250);

  }

void loop() 

  {

      
      display.clearDisplay();
      display.setTextSize(1.5);
      display.setCursor(0,0);
      display.drawRoundRect(0, 0, 128, 64, 8, WHITE);
      

      display.setCursor(10,10);
      display.println("ENGINE");
      display.setCursor(10,22);
      display.println("TEMP:");
      
      display.setCursor(10,38);
      display.println("AMBIENT");
      display.setCursor(10,50);
      display.println("TEMP:");
  

     
      display.setTextSize(2);
      
      display.setCursor(60, 10);
      display.print(round(mlx.readObjectTempC()));
      display.setCursor(105, 10);
      display.println("C");
      
      
      
      display.setCursor(60, 38);
      display.print(round(mlx.readAmbientTempC()));
      display.setCursor(105, 38);
      display.println("C");

      display.display();
    
  

  }