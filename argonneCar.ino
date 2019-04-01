#include <PIDLoop.h>
#include <Pixy2.h>
#include <Pixy2CCC.h>
#include <Pixy2I2C.h>
#include <Pixy2Line.h>
#include <Pixy2SPI_SS.h>
//#include <Pixy2UART.h>
#include <Pixy2Video.h>
#include <TPixy2.h>
#include <ZumoBuzzer.h>
#include <ZumoMotors.h>

// connect motor controller pins to Arduino digital pins
// motor one
int enA = 10;
int in1 = 9;
int in2 = 8;
int in3 = 7;
int in4 = 6;
int enB = 5;

int enC = 3;
int in5 = 2;
int in6 = 4;
int enD = 11;
int in7 = 12;
int in8 = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(enA, OUTPUT );
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(enC, OUTPUT );
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(enD, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
  
  Serial.println("Hello");
}

void loop() {
  // this function will run the motors in both directions at a fixed speed
 // turn on motor A
 /*Serial.println("Hello");
 digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
 // set speed to 200 out of possible range 0~255
 analogWrite(enA, 200);
 // turn on motor B
 digitalWrite(in3, HIGH);
 digitalWrite(in4, LOW);
 // set speed to 200 out of possible range 0~255
 analogWrite(enB, 200);
 delay(2000);
 // now change motor directions
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
 digitalWrite(in3, LOW);
 digitalWrite(in4, HIGH);
 delay(2000);
 // now turn off motors
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 digitalWrite(in3, LOW);
 digitalWrite(in4, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 80);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 80);

  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  analogWrite(enC, 170);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  analogWrite(enD, 170);*/
  goForwards(120,120,120,120);
  delay(1000);
  goBackwards(120, 120, 120, 120);
  delay(1000);
  

 
}



void demoOne()
{
// this function will run the motors in both directions at a fixed speed
 // turn on motor A
 Serial.println("Hello");
 digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
 // set speed to 200 out of possible range 0~255
 analogWrite(enA, 200);
 // turn on motor B
 digitalWrite(in3, HIGH);
 digitalWrite(in4, LOW);
 // set speed to 200 out of possible range 0~255
 analogWrite(enB, 200);
 delay(2000);
 // now change motor directions
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
 digitalWrite(in3, LOW);
 digitalWrite(in4, HIGH);
 delay(2000);
 // now turn off motors
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 digitalWrite(in3, LOW);
 digitalWrite(in4, LOW);
}
void goBackwards(int speedA, int speedB, int speedC, int speedD){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, speedA);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, speedB);

  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  analogWrite(enC, speedC);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  analogWrite(enD, speedD);
}

void goForwards(int speedA, int speedB, int speedC, int speedD){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, speedA);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, speedB);

  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  analogWrite(enC, speedC);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  analogWrite(enD, speedD);
}
