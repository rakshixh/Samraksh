# Samraksh: IoT Based Women Safety Device

### Abstract
* Despite the fact that our country is a powerhouse with a developing economy, it nevertheless has a number of crimes against women.
* To address this big issue, we offer "Samraksh" as a solution.
* This is a safety mechanism designed exclusively for women who are in difficulties, stress, etc.
* Our system contains GPS Module, ESP8266, LED, Thingspeak Cloud service, Button & Beep Buzzar.
* When a person is in distress, she must hit the button on the system provided.
* The location of the device is determined in terms of longitude & latitude along with date and time. Then this data is sent to the Real-Time Cloud Service.
* Now trusted person/family can access the location by copy-pasting that longitude & latitude into the Google Map followed by "," as soon as they are alerted by our system. 

### Introduction
* Safety being one of the most concerning issues, it is necessary to find an efficient way to ensure the safety of the people and the society.
* Women's safety is considered to be one of the most critical issues in a country like India, where the rate of crime is thought to be higher than the pace of population increase.
* NCRB states that as many as 39 crimes are reported every hour in the country. This adverse crime situation has embedded fear in the mind of people. If statistics are to be seen, around 20,532 cases are registered every year.
* We come across many headlines reporting cases of molestation, trafficking, ill-treatment, ragging, kidnapping, missing and etc.
* After identifying a hazard, existing handheld gadgets for human protection require human safety, such as pressing a button.

### Objectives
* To build a safety device for women.
* To facilitate quick action and hence reduce the harm.
* To ensure the security of woman in the society and hence to promote Woman Empowerment.

### Problem Statement
* Among all of the heinous crimes that have been witnessed recently, ensuring the safety of women has become a challenge, and thus a major source of concern in society.

### Methodology
* The system comprises of two devices: Device 1 & Device 2, where Device 1 will be with the individual whose position is to be tracked, and Device 2 will be with a trustworthy person or family member, and this device will notify using a beeping buzzer.
* The system includes a NEO 6M-GPS Module, as well as an LED, a push button, and a buzzer.
* When the push button is pressed LED turns on for indication purposes and an email is sent to the trustworthy person or family members. The location of the device in terms of latitude & longitude is determined along with LED status.
* Now, this data from GPS Module along with LED status is uploaded or updated in the cloud by ESP8266 Node MCU for further use. As soon as LED status in the cloud is set to 1 Beeping buzzer in Device 2 will start to Beep for indication purposes. That time display of the data in the cloud is accessed by the trusted person or family members so that they can take further action.

## Block Daigram
* Device 1 - Using NEO 6M GPS Module
![Swasthya Final Implementation (GPS)](https://user-images.githubusercontent.com/83587918/192152053-5e4f3843-8bb1-44d8-abe9-a2952fd82ad8.png)
* Device 2 - Using Beep Buzzer
![Device 2 Samraksh](https://user-images.githubusercontent.com/83587918/192152137-7ffc645a-226e-4b61-800c-b937dc6e55bb.png)

## Requirements

#### Software Requirements
* Arduino IDE
* Thingspeak Cloud Service

#### Hardware Requirements
* NEO 6M GPS Module
* ESP8266 Node MCU
* Power Supply
* Push Button
* Beep Buzzer
* General PCB
* Resistor
* LED

#### Data Used
* Longitude and Latitude
* LED Status (0 & 1)
* Date and Time

## Images
<h3> ESP8266 Node MCU </h3>

![NicePng_simba-png_5011059](https://user-images.githubusercontent.com/83587918/192152704-cc5d257a-1df7-4054-b8ff-9030268eae17.png)

<h3> NEO 6M GPS Module </h3>

![2cropped](https://user-images.githubusercontent.com/83587918/192152759-978363d2-7ab4-45fb-9162-d1942d3743ea.png)

<h3> Beep Buzzer </h3>

![2 (2)](https://user-images.githubusercontent.com/83587918/192153227-51d5709d-2509-4539-b05f-410333a294f2.png)

<h3> LED </h3>

![ledd full](https://user-images.githubusercontent.com/83587918/192153523-6cbf3cee-493c-4d28-9390-c82958df5cf7.png)

<h3> Power Supply </h3>

![4](https://user-images.githubusercontent.com/83587918/192153297-5bf81667-bd8a-485b-93ff-c1b557a5641c.png)

## Project Setup

#### Step 1

#### Step 2
Install and setup Arduino IDE in your PC. Download and install all required libraries. Check and set the port in Arduino IDE and connect the NodeMCU ESP8266 using USB cable. Copy the code given above to a ESP8266 Node MCU of Device 1 and Device 2 respectively, in your Arduino IDE and make required changes in the code.
Such As:
* Wifi Name
* Wifi Password
* Channel ID
* Thingspeak API Key

    #### Note
    Create an account in Thingspeak Cloud service then create one channel, give a name for that particular channel. When you open that channel you will get option called "API KEYS" here you will get the API key of your channel which you will need to copy in the code! Also make sure to create 3 fields in "Channel Setting" section. And set the channel access to the public.

## Output

![Screenshot (285)](https://user-images.githubusercontent.com/83587918/192154265-6818ed7b-6df4-4b6b-a193-fa6851711153.png)

![Screenshot (286)](https://user-images.githubusercontent.com/83587918/192154277-cf07ccda-2511-4b30-9506-9d59a3d9bfbb.png)

![Screenshot (287)](https://user-images.githubusercontent.com/83587918/192154281-4b4d59c7-4e50-499f-b3ab-88b158310c93.png)

![msg1794739563-10150](https://user-images.githubusercontent.com/83587918/192154383-61b5a74a-0083-496a-9367-79b2c1905712.jpg)

## Result and Discussion

* Once the trusted person/family member gets the output in Thingspeak (Cloud) they have to copy the Latitude & Longitude Values then paste it to the Google Map followed by " , "  
* Example: Latitude=52.4512 & longitude=65.2165 then 52.4512,65.2165 is to be entered in Google Map.
* That time in Google Map Trusted person/family member will get the exact location of that co-ordinates.
* So that they can take further action.

![Screenshot (26)](https://user-images.githubusercontent.com/83587918/192154453-a961c9af-86c6-4d5b-8996-1b0d84431fc5.png)

![Screenshot (27)](https://user-images.githubusercontent.com/83587918/192154464-ecd129c9-d704-4e6a-85f6-d7a400b218f7.png)

## End Customers
* Common Proplr
* Police Department
* Government

## Application
* Girls when in suspicious environments or when in danger can share their location and hence ask for help from the known ones.
* Aged people when away from home or are remote, can ask for help in case of any threats or health issues.
* Children notify their guardians about the need for help when in trouble.
* Getting notified about the location and the need for help facilitates quick action. 

## Conclusion
* Primary goal of this project is to ensure every woman in our society to feel safe and secured. According to the survey in India 53% of working women are not feeling safe.
* Implementing real time application and a device, we can solve the problems to an extent.
* With furthur research and innovation, this project is used as a small wearable device. 



https://user-images.githubusercontent.com/83587918/192154887-5925bb24-6981-42fc-86ea-69c0e90c0d1c.mp4




