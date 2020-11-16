#include <LiquidCrystal.h> //It enables user to interface an LCD
LiquidCrystal lcd(5,6,8,9,10,11); //Pin numbers of Arduino connected with LCD
//order Register Select, Enable, DB 4,5,6,7

//pin numbers
int redled = 2;
int greenled = 3;
int buzzer = 4;
int sensor = A0; //Gas sensor
int sensorThresh = 400; //Threshold gas concentration

void setup() //executed once
{
pinMode(redled, OUTPUT);
pinMode(greenled,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(sensor,INPUT);
Serial.begin(9600); //Serial communication between and computer 9600 is baud rate i.e transfer 9600 bits per second
lcd.begin(16,2); //dimensions of LCD 16 columns and 2 rows
}

void loop() //repeated
{
  int analogValue = analogRead(sensor); //read analog output of the gas sensor
  Serial.print(analogValue);
  if(analogValue>sensorThresh)
  {
    digitalWrite(redled,HIGH); //Red LED ON
    digitalWrite(greenled,LOW); //Green LED OFF
    tone(buzzer,1000,10000); //frequency of buzzer 1000Hz and 10k miliseconds
    lcd.clear(); //Clear LCD
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
    digitalWrite(greenled,HIGH); //Green LED ON
    digitalWrite(redled,LOW); //RED LED OFF
    noTone(buzzer); //Silent
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
