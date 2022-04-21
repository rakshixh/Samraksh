//When pressed led remains on

#define LED 5                               // D1(gpio5)
#define BUTTON 4                            //D2(gpio4

//Let's say you have your push button on pin 4
int switchState = 0;                       // actual read value from pin4
int oldSwitchState = 0;                    // last read value from pin4
int lightsOn = 0;                          // is the switch on = 1 or off = 0

void setup() 
{ 
 pinMode(BUTTON, INPUT);                   // push button 
 pinMode(LED, OUTPUT);                     // anything you want to control using a switch e.g. a Led
}
void loop() 
{
 switchState = digitalRead(BUTTON);          // read the pushButton State
   if (switchState != oldSwitchState)        // catch change
     {
      oldSwitchState = switchState;
        if (switchState == HIGH)
         {
          // toggle
          lightsOn = !lightsOn;
         }
     }
           if(lightsOn)
           {
            digitalWrite(LED, HIGH);        // set the LED on
           } 
           else 
           {
            digitalWrite(LED, LOW);         // set the LED off
           }
 }
