#include <PS2X_lib.h> //for v1.6
#include <Servo.h>

PS2X ps2x; // create PS2 Controller Class
Servo myservo;
const int MTR_PIN = 8;
const int CLK_PIN = 13;
const int CMD_PIN = 11;
const int ATT_PIN = 10;
const int DAT_PIN = 12;
const int SER_PIN = 3;
int servo_loc = 45; 
int switchState = 0;
int error = 0;
byte type = 0;
byte vibrate = 0;

void setup(){
  Serial.begin(9600);
  pinMode(MTR_PIN, OUTPUT);
  myservo.attach(SER_PIN);
  myservo.write(servo_loc);
  error = ps2x.config_gamepad(13,11,10,12, false, false); //setup pins and settings: GamePad(clock,command, attention, data, Pressures?,Rumble?) check for error
  type = ps2x.readType();
  
}
void loop(){
  
  if (error == 1) { 
    Serial.println("No Controller Found,check wiring");
  }
 
  if(ps2x.Button(PSB_PAD_LEFT)){
    if(servo_loc == 0)
    {
      goto skip;
    }
    servo_loc-=5;
    skip:
    myservo.write(servo_loc);
    Serial.println(servo_loc,DEC);
    Serial.println("yay!");
  }
  if(ps2x.Button(PSB_PAD_RIGHT)){
    if(servo_loc == 180)
    {
      goto skippy;
    }

    servo_loc+=5;
    skippy:
    myservo.write(servo_loc);
    Serial.println(servo_loc,DEC);
    Serial.println("yay!");
  }
  if(ps2x.Button(PSB_L1) || ps2x.Button(PSB_R1)) // print stick values if either is TRUE
    {
        Serial.print("Stick Values:");
        Serial.print(ps2x.Analog(PSS_LY), DEC); //Left stick, Y axis. Other options: LX, RY, RX  
        Serial.print(",");
        Serial.print(ps2x.Analog(PSS_LX), DEC); 
        Serial.print(",");
        Serial.print(ps2x.Analog(PSS_RY), DEC); 
        Serial.print(",");
        Serial.println(ps2x.Analog(PSS_RX), DEC); 
    } 
  ps2x.read_gamepad(); //read controller

delay(50);
}
