#include <EMailSender.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

//GPS PIN initializing
static const int RXPin = 12 , TXPin = 13;
static const uint32_t GPSBaud = 9600;

//Password Details
const char* ssid     = " "; //enter wifi name
const char* password = " "; //enter wifi password

//ThingSpeak Channel Details
unsigned long myChannelNumber = ;  //enter thingspeak Channel Number
const char * myWriteAPIKey = " ";  //enter thingspeak write API Key

//Button & LED Initializing
int LEDpin = 5;
int button = 4;
int buttonState = 0;
int ledState = 0;

TinyGPSPlus gps;
WiFiClient  client;
SoftwareSerial ss(RXPin, TXPin);

void setup()
{
  Serial.begin(9600);
  ss.begin(GPSBaud);
  Serial.println(F("DeviceExample.ino"));
  Serial.println(F("A simple demonstration of TinyGPS++ with an attached GPS module"));
  Serial.print(F("Testing TinyGPS++ library v. ")); 
  Serial.println(TinyGPSPlus::libraryVersion());
  Serial.println();

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
  pinMode(LEDpin, OUTPUT);
  digitalWrite(LEDpin, LOW);
  pinMode(button, INPUT);
}

void loop()
{
    while (ss.available() > 0)
          {
          if (gps.encode(ss.read()))
              displayInfo();
          if (millis() > 5000 && gps.charsProcessed() < 10)
              {
                Serial.println(F("No GPS detected: check wiring."));
                while(true);
              }
          }
          
           buttonState=digitalRead(button); 
              if (buttonState == 1)
                  {
                    digitalWrite(LEDpin, HIGH);
                    delay(10000); 

                    //EMAIL FUNCTION
                    
                    EMailSender emailSend(" /*enter your email here*/  ", " /*enter your email account password*/ ");
                    EMailSender::EMailMessage message;
                    message.subject = " /*enter the subject of email message*/ ";
                    message.message = " /*enter the message of the email*/ ";
                    EMailSender::Response resp = emailSend.send(" /*enter the email address to which you wanna send emailMessage to*/ ", message);
                    Serial.println("Sending status: ");
                    Serial.println(resp.code);
                    Serial.println(resp.desc);
                    Serial.println(resp.status);
                  }
                  
              if (buttonState==0)
                  {
                    digitalWrite(LEDpin, LOW); 
                  }

           displayLED();
}

void displayInfo()
{
     if (gps.location.isValid())
        {
           double latitude = (gps.location.lat());
           double longitude = (gps.location.lng());
    
           String latbuf;
           latbuf += (String(latitude, 6));
           Serial.println(latbuf);

           String lonbuf;
           lonbuf += (String(longitude, 6));
           Serial.println(lonbuf);
           
           //Write the sensor data to the channel field1 & field2 with delay of 20s
           ThingSpeak.setField(1, latbuf);
           ThingSpeak.setField(2, lonbuf);
           ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);  
           delay(20000);
    
        }
    else
       {
         Serial.print(F("INVALID"));
       }
    Serial.print(F(" \n Date/Time: "));
    if (gps.date.isValid())
       {
          Serial.print(gps.date.month());
          Serial.print(F("/"));
          Serial.print(gps.date.day());
          Serial.print(F("/"));
          Serial.print(gps.date.year());
       }
    else
       {
         Serial.print(F("INVALID"));
       }
    Serial.print(F(" "));
    if (gps.time.isValid())
        {
          if (gps.time.hour() < 10) Serial.print(F("0"));
             Serial.print(gps.time.hour());
          Serial.print(F(":"));
          if (gps.time.minute() < 10) Serial.print(F("0"));
             Serial.print(gps.time.minute());
          Serial.print(F(":"));
          if (gps.time.second() < 10) Serial.print(F("0"));
             Serial.print(gps.time.second());
          Serial.print(F("."));
          if (gps.time.centisecond() < 10) Serial.print(F("0"));
          Serial.print(gps.time.centisecond());
        }
    else
       {
          Serial.print(F("INVALID"));
       }
    Serial.println();
}

void displayLED()
{
     ledState = digitalRead(LEDpin);
     ThingSpeak.setField(3, ledState);
     ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
     
}
