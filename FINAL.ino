#include <PS2X_lib.h> //for v1.6
#include <Servo.h>

PS2X ps2x; // create PS2 Controller Class
Servo myservo;

const int CLK_PIN = 13;
const int CMD_PIN = 11;
const int ATT_PIN = 12;
const int DAT_PIN = 10;

const int MTR_PIN_1 = 5;
const int MTR_PIN_2 = 3;
const int SER_PIN = 2;

int SERIAL_RATE = 9600;
int error = 0;
byte type = 0;
byte vibrate = 0;

float servo_loc = 90; 
float power;


void setup(){
  Serial.begin(SERIAL_RATE);
  
  pinMode(MTR_PIN_1, OUTPUT);
  pinMode(MTR_PIN_2, OUTPUT);
  
  myservo.attach(SER_PIN);
  myservo.write(servo_loc);
  
  error = ps2x.config_gamepad(CLK_PIN, CMD_PIN, ATT_PIN, DAT_PIN, false, false);
  type = ps2x.readType();
}

void loop(){  
  if (error == 1) { 
    Serial.println("No controller found, check wiring");
  }

  ps2x.read_gamepad(false, false); //read controller
 
  int l_x = ps2x.Analog(PSS_LX);
  int r_x = ps2x.Analog(PSS_RX);
  int l_y = ps2x.Analog(PSS_LY);
  int r_y = ps2x.Analog(PSS_RY);
  

 Serial.print("L_X read:");
 Serial.print(l_x, DEC);
 Serial.print("L_Y read:");
 Serial.print(l_y, DEC);
 Serial.print("R_X lnread:");
 Serial.print(r_x, DEC);
 Serial.print("R_Y read:");
 Serial.println(r_y, DEC);
 
/*
  servo_loc = (.18*(r_x-128))+90;

  myservo.write(servo_loc);
   
  if(ps2x.Button(PSB_L1))
  {
    power = 255/2;
   analogWrite(MTR_PIN_1, power);
    analogWrite(MTR_PIN_2,power);
  }

  if(ps2x.Button(PSB_L2))
  { power = 255;
    analogWrite(MTR_PIN_1, power);
    analogWrite(MTR_PIN_2,power);
  }
  power = 0;
    analogWrite(MTR_PIN_1, power);
    analogWrite(MTR_PIN_2,power);
  //Serial.println(power);
  */

delay(50);
}
