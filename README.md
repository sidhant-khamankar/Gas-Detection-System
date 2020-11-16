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

There are different types of electric chemical sensors, which are used in detection of harmful and toxic gases.
For example, MQ2 sensor is sensitive for methane, butane LPG, smoke and flammable and combustible gases and MQ3 sensor is used for sensing alcohol, ethanol and smoke. 
Here MQ2 sensor is used to detect smoke. 
When gas interacts with the sensor, it is first ionized into its constituents and is then adsorbed by the sensing element. This adsorption creates a potential difference on the element i.e., the sensor outputs the voltage that is proportional to the concentration of smoke or gas. In other words, the greater the concentration of gas, the greater is the output voltage. The resistance of this sensor is different depending on the type of the gas and its sensitivity can also be adjusted using a built-in potentiometer, depending on how accurate the gas is to be detected. The output can be an analog signal that can be read with an analog input of the Arduino or additional output that can be read with the digital input of the Arduino.

## Circuit:
![Gas Detection System](https://user-images.githubusercontent.com/63101268/98551239-1880e680-22c3-11eb-8395-8950deb6a281.png)

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
