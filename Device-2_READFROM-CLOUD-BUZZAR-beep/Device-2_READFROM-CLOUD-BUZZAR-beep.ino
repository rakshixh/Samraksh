#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

const char* ssid     = "GURURAJ ACHARYA";
const char* password = "rachanaacharya";

//ThingSpeak Channel Details
unsigned long myChannelNumber = 1643186;
const char * myReadAPIKey = "QBFFR4EDSFEAM8VM";
const int FieldNumber3 = 3;
WiFiClient  client;

int LastStatus=0;
int frequency=1000; //Specified in Hz
int buzzPin=D5; 
int timeOn=1000; //specified in milliseconds
int timeOff=1000; //specified in millisecods


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

//Setting up LED & Button
  //pinMode(LEDpin, OUTPUT);
  //digitalWrite(LEDpin, LOW);
  //pinMode(button, INPUT);
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
