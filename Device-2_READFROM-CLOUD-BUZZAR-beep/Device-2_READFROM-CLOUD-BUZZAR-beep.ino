#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

const char* ssid     = " "; //enter wifi name
const char* password = " "; //enter wifi passsword

//ThingSpeak Channel Details
unsigned long myChannelNumber = ; //enter thingspeak channel number
const char * myReadAPIKey = " ";  //enter thingspeak read API Key
const int FieldNumber3 = 3;
WiFiClient  client;

int LastStatus=0;
int frequency=1000; // in Hz
int buzzPin=D5; 
int timeOn=1000; // in milliseconds
int timeOff=1000; // in millisecods


void setup()
{
  Serial.begin(9600);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) 
         {
           delay(500);
           Serial.print(".");
         }
  
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
  ThingSpeak.begin(client);

}

void loop()
{
  long ledStatus = ThingSpeak.readLongField(myChannelNumber, FieldNumber3, myReadAPIKey);
  LastStatus = ThingSpeak.getLastReadStatus();
  if (ledStatus == 1)
  {
    tone(buzzPin, frequency);
    delay(timeOn);
    noTone(buzzPin);
    delay(timeOff);
    Serial.print("LED IS ON \n");
  }
  else
  {
    Serial.print("LED IS OFF \n");
  }
  
}
