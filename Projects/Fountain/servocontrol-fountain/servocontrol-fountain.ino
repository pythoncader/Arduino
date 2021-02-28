/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  Servo test - this will drive 16 servos, one after the other

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815

  These displays use I2C to communicate, 2 pins are required to  
  interface. For Arduino UNOs, thats SCL -> Analog 5, SDA -> Analog 4

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/
//Written by Cade Rigby

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
// Watch video V1 to understand the two lines below: http://youtu.be/y8X9X10Tn1k
#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)

int broken1 = 12;
int broken2 = 4;
int broken3 = 8;
int broken4 = 7;

// our servo # counter
uint8_t servonum = 0;
int myrandom = 0;
int pass = 0;
int top3 = 0;
int top1 = 1;
int bottom3 = 2;
int top4 = 3;
int bottom4 = 4;
int bottom2 = 5;
int bottom1 = 6;
int top2 = 7;

int min0 = 30;
int max0 = 100;
int min1 = 30;
int max1 = 80;
int min2 = 85;
int max2 = 180;

int min3 = 95;
int max3 = 180;
int min4 = 40;
int max4 = 100;

int min5 = 85;
int max5 = 180;
int min6 = 25;
int max6 = 110;
int min7 = 5;
int max7 = 80;
int currentAngles[] = {0, 0, 0, 0, 0, 0, 0, 0};

int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   return pulse;
}
void set_angle(int channel, int myangle, float servowait=1000){
  currentAngles[channel] = myangle;
  pwm.setPWM(channel, 0, angleToPulse(myangle));
  delay(servowait);
}
int pickrandom(int channel){
  switch (channel) {
  case 0:
    myrandom = random(min0, max0);
    return myrandom;
  case 1:
    myrandom = random(min1, max1);
    return myrandom;
  case 2:
    myrandom = random(min2, max2);
    return myrandom;
  case 3:
    myrandom = random(min3, max3);
    return myrandom;
  case 4:
    myrandom = random(min4, max4);
    return myrandom;
  case 5:
    myrandom = random(min5, max5);
    return myrandom;
  case 6:
    myrandom = random(min6, max6);
    return myrandom;
  case 7:
    myrandom = random(min7, max7);
    return myrandom;
}
}
int settorandom(int channel, float servowait=0){
  set_angle(channel, pickrandom(channel), servowait);
}

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  pinMode(broken1, OUTPUT);
  pinMode(broken3, OUTPUT);
  pinMode(broken4, OUTPUT);
  pinMode(broken2, OUTPUT);
  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  //yield();
}


void allmax(int delay_value){
  for(int i = 0; i<5; i++){
    set_angle(i, 38, 0);
  }
  delay(delay_value);
}

void allmin(int delay_value){
  for(int i = 0; i<5; i++){
    set_angle(i, 22, 0);
  }
  delay(delay_value);
}

void allmid(int delay_value){
  for(int i = 0; i<5; i++){
    set_angle(i, 30, 0);
  }
  delay(delay_value);
}

void Allon(int delay_value){
  digitalWrite(broken1, 1);
  digitalWrite(broken2, 1);
  digitalWrite(broken3, 1);
  digitalWrite(broken4, 1);
  delay(delay_value);
}

void Firstoff(int delay_value){
  //First
  digitalWrite(broken1, LOW);
  
  digitalWrite(broken2, HIGH);

  digitalWrite(broken3, HIGH);
 
  digitalWrite(broken4, HIGH);

  delay(delay_value);

  Allon(1000);
}

void Secondoff(int delay_value){
  //Second
  digitalWrite(broken1, HIGH);
  
  digitalWrite(broken2, LOW);

  digitalWrite(broken3, HIGH);
 
  digitalWrite(broken4, HIGH);

  delay(delay_value);

  Allon(1000);
}

void Thirdoff(int delay_value){
  //Third
  digitalWrite(broken1, HIGH);
  
  digitalWrite(broken2, HIGH);

  digitalWrite(broken3, LOW);
 
  digitalWrite(broken4, HIGH);

  delay(delay_value);

  Allon(1000);
}

void Fourthoff(int delay_value){
  //Fourth
  digitalWrite(broken1, HIGH);
  
  digitalWrite(broken2, HIGH);

  digitalWrite(broken3, HIGH);
 
  digitalWrite(broken4, LOW);

  delay(delay_value);

  Allon(1000);
}

void loop() {
  Allon(0);
  Serial.println("ON");
   set_angle(1, 32);
   set_angle(1, 25);
  /*//Allon(3000);
  //Firstoff(5000);
  allmin(3000);
  //Secondoff(5000);
  allmid(3000);
  //Thirdoff(5000);
  //Fourthoff(5000);
  allmax(3000);*/
}
