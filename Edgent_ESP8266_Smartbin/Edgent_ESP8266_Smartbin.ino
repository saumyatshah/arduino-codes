#include <DHT.h>
#include <DHT_U.h>


// Fill-in information from your Blynk Template here
//#define BLYNK_TEMPLATE_ID           "TMPLxxxxxx"
//#define BLYNK_DEVICE_NAME           "Device"
#define BLYNK_TEMPLATE_ID "TMPLnuxhWQin"
#define BLYNK_DEVICE_NAME "smart bin"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI
#define DHTPIN 2          // What digital pin we're connected to
int X;
// Uncomment whatever type you're using!
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
#include "BlynkEdgent.h"
BLYNK_WRITE(V2) {
  int x = param[0].asInt();
  int y = param[1].asInt();
X=x;
  // Do something with x and y
  Serial.print("X = ");
  Serial.print(x);
  Serial.print("; Y = ");
  Serial.println(y);
}
int h;
void sendSensor()
{
  h = dht.readHumidity();
 

 Serial.println(h);
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V1, h);
 
}


void setup()
{
  Serial.begin(115200);
  delay(100);
  dht.begin();
  BlynkEdgent.begin();
  
}

void loop() {
  BlynkEdgent.run();
  sendSensor();
  
  if(X==2)
  Serial.write(0); //stop
  else if(X==0)
  Serial.write(1); //back
  else if(X==4)
  Serial.write(2); //front
  else if(X==3)
  Serial.write(3); //left
  else if(X==1)
  Serial.write(4); //right

  
}
