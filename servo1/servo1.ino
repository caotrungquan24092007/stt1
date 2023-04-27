#include <SoftwareSerial.h> 
#include <Servo.h>
SoftwareSerial mybluetooth(0,1); // Khai báo tên Bluetooth và chân TX RX (2-TX, 3-RX)
Servo servo1;
Servo servo2;

String incomingByte ; 
int led = 9;   
int triggerPin = 7; 
int echoPin = 8; 
char docgiatri; 
int pos1 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo1.attach(6);
  mybluetooth.begin(9600); 
}
void loop() {
  sensor();
  if(mybluetooth.available() > 0) {
    docgiatri = mybluetooth.read(); 
    if (docgiatri == ('1')) {digitalWrite(led,HIGH);}
    if (docgiatri == ('2')) {digitalWrite(led,LOW);}
    if (docgiatri == ('3')) {servo1.write(180);}
    if (docgiatri == ('4')) {servo1.write(90);}
    Serial.println(docgiatri);
  }
  
}

void sensor() { 
  
  int duration, distance;   
  
  digitalWrite(triggerPin, HIGH); 
  delay(10);
  digitalWrite(triggerPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); 
  distance = (duration/2) / 29.1; 
  
  Serial.print(distance);    
  Serial.print("cm");       
  Serial.println(" ");     
  
}
