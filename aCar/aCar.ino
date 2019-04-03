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


/* May or may not be correct
    A corresponds to in5 and in6 and speedA
    B corresponds to in1 and in2 and speedB
    C corresponds to in3 and in4 and speedC
    D corresponds to in7 and in8 and speedD
*/
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

int speedA = 100;
int speedB = 100;
int speedC = 100;
int speedD = 100;

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
void turnLeft(int a, int b, int c, int d) {

  //decrease speed on left side of car
  a -= 4;
  b -= 4;
  c += 4;
  d += 4;


} void turnRight(int a, int b, int c, int d) {
  //decrease speed on right side
  a -= 4;
  b -= 4;
  c += 4;
  d += 4;

}void goForwards(int speedA, int speedB, int speedC, int speedD) {
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
void loop() {

 /* int res;
  res = pixy.line.getMainFeatures();
  if (res >= 0) {
    goForwards(speedA, speedB, speedC, speedD);
    while (res >= 0) {
      //pixy.setLED(0,0,250);
      pixy.line.getAllFeatures();
      error = (int32_t)pixy.line.vectors->m_x1 - (int32_t)X_CENTER;
      Serial.print("Error: "); Serial.println(error);
      //Serial.println(speedA); Serial.println(speedB); Serial.println(speedC); Serial.println(speedD);
      Serial.print("SpeedA: "); Serial.println(speedA); Serial.print("SpeedB: "); Serial.println(speedB); Serial.print("SpeedC: "); Serial.println(speedC); Serial.print("SpeedD: " ); Serial.println(speedD);
      delay(250);

      if (error > tolerance) {

        //Turn left
        speedA -= 4;
        speedB -= 4;
        speedC += 4;
        speedD += 4;

        if (speedA < 60) {
          speedA = 60;
        }
        if (speedB < 60) {
          speedB = 60;
        }
        if (speedC > 100) {
          speedC = 100;
        }
        if (speedD > 100) {
          speedD = 100;
        }
        delay(200);
        pixy.setLED(0, 0, 250);
      } if (error < tolerance) {

        //Turn Right
        speedA += 4;
        speedB += 4;
        speedC -= 4;
        speedD -= 4;
        if (speedA > 100) {
          speedA = 100;
        }
        if (speedB > 100) {
          speedB = 100;
        }
        if (speedC < 60) {
          speedC = 60;
        }
        if (speedD < 60) {
          speedD = 60;
        }

        delay(200);
        pixy.setLED(0, 250, 0);

      }
    }
    
  }
  else {
    //rotate();

   
    pixy.setLED(250, 0, 0);

  }*/goForwards(100, 100, 100, 100);


}
void stop() {


}





void rotate() {
  //rotate the robot
}
