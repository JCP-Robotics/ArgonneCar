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
#include <SPI.h>
#define X_CENTER (pixy.frameWidth/2)
#define LINE_MODE_TURN_DELAYED

Pixy2 pixy;
int32_t error;
int tolerance = 6;

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

int speedA;
int speedB;
int speedC;
int speedD;

void setup() {
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

  Serial.print("Starting...\n");
  pixy.init();
  pixy.changeProg("line");


}

void loop() {
  int speedA;
  int speedB;
  int speedC;
  int speedD;
  int res;
  res = pixy.line.getMainFeatures();
  if (res >= 0) {
    //pixy.setLED(0,0,250);
    pixy.line.getAllFeatures();
    error = (int32_t)pixy.line.vectors->m_x1 - (int32_t)X_CENTER;
    Serial.print("Error: "); Serial.println(error);
    delay(500);
    if (error > tolerance) {
      while (error > tolerance) {
        //Turn left
      }
      pixy.setLED(0, 0, 250);
    } else if (error < tolerance) {
      while (error < tolerance) {
        //Turn Right
        pixy.setLED(0, 250, 0);
      }
    }
  } else {
    goForwards(speedA, speedB, speedC, SpeedD) {

    }
    pixy.setLED(250, 0, 0);
  }


}

void goForwards(int speedA, int speedB, int speedC, int speedD) {
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

void turnLeft() {

  //decrease speed on left side of car

}
void turnRight() {
  //decrease speed on right side
}
