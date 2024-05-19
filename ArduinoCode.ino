#include <LiquidCrystal.h>
LiquidCrystal lcd(6, 7, 2, 3, 4, 5);
#include <SoftwareSerial.h>
SoftwareSerial myserial(8, 9); // RX, TX

int mq3, acc=0;
String finalCode;
String a1,b1,c1,d1;
int a=0, b=0, c=0;
int sleep=0;
const int trigPin = A3;
const int echoPin = A4;
long duration;
int distance;

void setup() {
    pinMode(A0,OUTPUT); // DC MOTOR
    pinMode(A1,OUTPUT);// DC MOTOR
    pinMode(12,OUTPUT);// INDICATOR

    pinMode(13,OUTPUT);// BUZZER & INDICATOR
 
    digitalWrite(A0,LOW); // MOTOR OFF
    digitalWrite(A1,LOW); // MOTOR OFF
 
    digitalWrite(13,LOW); // BUZZER OFF
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
 
    // Serial.begin(9600); // BEGIN SERIAL MONITOR WITH 9600 BAUDRATE
    myserial.begin(115200);
 
    // LCD 2X16 SETUP
    lcd.begin(16, 2);
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("DRIVER MONITORNG");
    lcd.setCursor(0, 1);
    lcd.print("& VEHICLE CONTRL");
    delay(1000);
    lcd.clear();

    lcd.print(" USING ");
    lcd.setCursor(0, 1);
    lcd.print(" IOT ");
    delay(1000); 
    lcd.clear();

    lcd.print("INITIALIZING...");
    lcd.setCursor(0, 1);
    lcd.print(" SENSORS ");
    delay(7000); 
    digitalWrite(12,HIGH); // INDICATOR On
    analogWrite(10,255); // FULL SPEED
    delay(300);
    digitalWrite(A0,HIGH); //
    digitalWrite(A1,LOW); // 
    lcd.clear();

    lcd.print(" VEHICLE ");
    lcd.setCursor(0, 1);
    lcd.print(" IGN. ON ");
    delay(1000); 
}
void loop() {
    acc = analogRead(A5);
    mq3 = analogRead(A2);
    //Serial.println(acc);
    //Serial.println(mq3);
    checkdistance();

    if(acc < 290) {
        sleep=sleep+1;
        delay(1000);
        if(sleep>5) {
            drowsiness(); 
        }
    }
    else {
        sleep=0; 
    }
    lcd.clear();
    
    lcd.setCursor(0, 0);
    lcd.print("ACC=");
    lcd.setCursor(9, 0);
    lcd.print("USS=");
    lcd.setCursor(0, 1);
    lcd.print("MQ3 =");
 
    lcd.setCursor(5, 0);
    lcd.print(acc);
    lcd.setCursor(13, 0);
    lcd.print(distance);
    lcd.setCursor(5, 1);
    lcd.print(mq3);
    senddata();
    
    if(distance<=3) {
        if(a==0) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(" OBSTACLE ");
            lcd.setCursor(0, 1);
            lcd.print(" DETECTED ");
            a=1; 
            analogWrite(10,0);
            delay(100);
            digitalWrite(A0,LOW); // MOTOR OFF
            digitalWrite(A1,LOW); // MOTOR OFF
            digitalWrite(12,LOW); 
            digitalWrite(13,HIGH);
            delay(1000);
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("VEHCILE IGN. OFF");
            while(1);
        }
    }
    else {
        if(a==1) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(" NO OBSTACLE ");
            a=0;
        
            analogWrite(10,255);
            digitalWrite(A0,HIGH); //
            digitalWrite(A1,LOW); // 
            digitalWrite(12,HIGH); // 
            digitalWrite(13,LOW); // 
        
        }
    }

    if(mq3>900) {
        if(b==0) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(" DRIVER DURNKED ");
            lcd.setCursor(0, 1);
            lcd.print(" SLOWING SPEED ");
            
            digitalWrite(12,LOW); 
            digitalWrite(13,HIGH);
            
            analogWrite(10,180);
            delay(1000);
            analogWrite(10,130);
            delay(2000);
            analogWrite(10,80);
            delay(2000);

            analogWrite(10,0);
            
            lcd.setCursor(0, 1);
            lcd.print("VEHICLE IGN. OFF");
            b=1;
            delay(1000);
            while(1);
        
        }
    }
    else {
        if(b==1) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("ALCOHOL SENSOR");
            lcd.setCursor(0, 1);
            lcd.print("NORMAL");
            b=0;
            
            analogWrite(10,255);
            delay(100);
            digitalWrite(A0,HIGH); //
            digitalWrite(A1,LOW); // 
            digitalWrite(12,HIGH); // 
            digitalWrite(13,LOW); // 
        
        }
    }
}


void drowsiness() {
    if(c==0) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("DRIVER SLEEPING ");
        lcd.setCursor(0, 1);
        lcd.print(" SLOWING SPEED ");
        
        digitalWrite(12,LOW); 
        digitalWrite(13,HIGH);
        
        analogWrite(10,180);
        delay(1000);
        analogWrite(10,130);
        delay(2000);
        analogWrite(10,80);
        delay(2000);
        analogWrite(10,0);
        
        lcd.setCursor(0, 1);
        lcd.print("DROWSINES DETECT");
        lcd.setCursor(0, 1);
        lcd.print("VEHICLE IGN. OFF");
        c=1;
        delay(1000);
        while(1);
    }
    else {
        if(c==1) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("ACCELEROMETER");
            lcd.setCursor(0, 1);
            lcd.print("NORMAL");
            c=0;
            
            analogWrite(10,255);
            digitalWrite(A0,HIGH); //
            digitalWrite(A1,LOW); // 
            digitalWrite(12,HIGH); // 
            digitalWrite(13,LOW); // 
            
        }
    }
}


void checkdistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance= duration*0.034/2;

    if(distance<100) {
        Serial.print("Distance: ");
        Serial.println(distance);
        delay(300); 
    }
    if(distance>100) {
        distance = 100;
    }
}


void senddata()
{
    // SEND DATA TO NODE MCU
    a1=String(mq3); // 
    b1=String(distance); // 
    c1=String(acc); // 
    
    finalCode = a1 + "@" + b1 + "*" + c1 + "#";
    myserial.print(finalCode);
}