# Gas-Detection-System

## Description: 
Gas detectors can be used to detect combustible, flammable and toxic gases, and oxygen depletion. This type of device is used widely in industry and can be found in locations, such as on oil rigs, to monitor manufacturing processes and in emerging technologies such as photovoltaic.
This Device detects these gases and flashes a red led ON , beep the buzzer and display an alert and evacuate message on the LCD display. Tinkercad an online circuit simulation software by Autodesk is used to demonstrate its working.

## Tinkercad: 
https://www.tinkercad.com/things/bS46B3htHic

## Components:
1.	Gas Sensor 
2.	Breadboard 
3.	Arduino
4.	2 Resistors
5.	Red & Green LED
6.	Buzzer
7.	LCD

![Screenshot (6)](https://user-images.githubusercontent.com/63101268/99223829-44442500-280b-11eb-9e03-57cf8cbfe633.png)

There are different types of electric chemical sensors, which are used in detection of harmful and toxic gases.
For example, MQ2 sensor is sensitive for methane, butane LPG, smoke and flammable and combustible gases and MQ3 sensor is used for sensing alcohol, ethanol and smoke. 
Here MQ2 sensor is used to detect smoke. 

When gas interacts with the sensor, it is first ionized into its constituents and is then adsorbed by the sensing element. This adsorption creates a potential difference on the element i.e., the sensor outputs the voltage that is proportional to the concentration of smoke or gas. In other words, the greater the concentration of gas, the greater is the output voltage. The resistance of this sensor is different depending on the type of the gas and its sensitivity can also be adjusted using a built-in potentiometer, depending on how accurate the gas is to be detected. The output can be an analog signal that can be read with an analog input of the Arduino or additional output that can be read with the digital input of the Arduino.

## Circuit:
![Gas Detection System](https://user-images.githubusercontent.com/63101268/98551239-1880e680-22c3-11eb-8395-8950deb6a281.png)

## Setup:

![Screenshot (8)](https://user-images.githubusercontent.com/63101268/99223875-558d3180-280b-11eb-9bc2-973f1b9ec867.png)
![Screenshot (7)](https://user-images.githubusercontent.com/63101268/99223893-5c1ba900-280b-11eb-963e-66a2dc61ed73.png)

The sensor has 6 pins. Two pins A and Two pins B. Two H pins are used for heating the system. One is connected to power and the other to ground. Pins A connects to 5v. B1 pin is connected to analog input A0 of the Arduino and b2 is connected to ground using register.
A sensor module can also be used. It simplifies the interface of the gas sensor from six pins to four pins. 

The positive bit of the buzzer is connected to digital pin number four of Arduino, the negative pin has to be connected to the ground through a register. Connect the input and the ground to the breadboard through the Arduino. 

The anode or the positive leg of the led has to be connected to the pin 2 of Arduino. We can connect it to any other pin. We should never connect an LED  alone, as it basically has no resistance. and hence will pull up maximum current available to resistors causing it to burst. Connect cathode of led to ground through the resistor.

![Screenshot (9)](https://user-images.githubusercontent.com/63101268/99223906-60e05d00-280b-11eb-8d15-e34e835ea633.png)
The LCD display has got 16 pins, 14 digital pins. All of these are digital pins and two pins control the backlight. In 14 pins there are 8 data pins from pin DB 0 to 7, two power supply pins VSS and VDD. Third one is for contrast control and there are three controlled pins register select, read-write and enable. The pin 1 or VSS is connected to ground. Pin 2 or VDD is connected to 5v power supply. Pin 3  is connected to ground because it gives maximum contrast. We can also control it by connecting it to a potentiometer. The register select pin is connected to any digital pin of the Arduino. Read/Write pin is connected to ground for setting it to read mode, which is mostly used then we can display whatever we want to the LCD.  The next eight pins that is from DB0 to DB7 are used for communication with the computer , 8 digital bit pins are used for eight-bit communication. But for just four bit communication we can use 4 data pins. The backlight pin of LCD display is grounded and the led anode pin is connected to input 5v through a register. Enable pin can be connected to digital pin six of Arduino.

## Code: 
Also present in Github Repository
```Arduino
#include <LiquidCrystal.h>
LiquidCrystal lcd(5,6,8,9,10,11);
  
int redled = 2;
int greenled = 3;
int buzzer = 4;
int sensor = A0;
int sensorThresh = 400;

void setup()
{
pinMode(redled, OUTPUT);
pinMode(greenled,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(sensor,INPUT);
Serial.begin(9600);
lcd.begin(16,2);
}

void loop()
{
  int analogValue = analogRead(sensor);
  Serial.print(analogValue);
  if(analogValue>sensorThresh)
  {
    digitalWrite(redled,HIGH);
    digitalWrite(greenled,LOW);
    tone(buzzer,1000,10000);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("ALERT");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("EVACUATE");
    delay(1000);
  }
  else
  {
    digitalWrite(greenled,HIGH);
    digitalWrite(redled,LOW);
    noTone(buzzer);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SAFE");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("ALL CLEAR");
    delay(1000);
  }      
}
```
