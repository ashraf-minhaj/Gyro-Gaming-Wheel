/*** PCB Steer Gaming Wheel ***
 *  
 *  Author: Ashraf Minhaj
 *  Mail: ashraf_minhaj@yahoo.com
 *  
 *  Licence: Copyright (C) Ashraf Minhaj
 *  GNU General Public License v3.0
 */

#include <Keyboard.h>
#include<Wire.h>

// Threshold value for steering
int THRESHOLD = 4000;

// Controller buttons
int brake = 5;
int nitro = 6;
int pedal = 4;

// Indicator LEDs
int left_led = 8;
int right_led = 9;

int x;
int y;
int z;
 
const int MPU_addr=0x68;  // I2C address of the MPU-6050

void indicator_blink()
{
  // blinks the leds - 5 times
  int i = 0;
  
  for(i=0; i<5; i++){
    digitalWrite(left_led, HIGH);
    digitalWrite(right_led, HIGH);
    delay(100);
    digitalWrite(left_led, LOW);
    digitalWrite(right_led, LOW);
    delay(100);
  }
}

void setup(){
  // set pin mode and initialize things
  pinMode(brake, INPUT);
  pinMode(nitro, INPUT);
  pinMode(pedal, INPUT);

  pinMode(left_led, OUTPUT);
  pinMode(right_led, OUTPUT);
  
  Serial.begin(9600); 
 
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);

  indicator_blink();
}

void loop()
{ // Main loop that runs forever
  
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true);  // request a total of 14 registers
  
  x = Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  y = Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  z = Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)


  if (digitalRead(brake)){
    Keyboard.release(KEY_UP_ARROW);
    Keyboard.press(KEY_DOWN_ARROW);
    //Keyboard.press(217);
  }
  
  if (digitalRead(nitro)){
    delay(10);
    Keyboard.press('z');
    if (digitalRead(nitro)){
      Keyboard.press('A');
    }
  }
    
  else if (digitalRead(pedal)){
    Keyboard.release(KEY_DOWN_ARROW);
    Keyboard.press(KEY_UP_ARROW);
    //Keyboard.press(218);
  
    if(y < -THRESHOLD){     
          Serial.print("    Left    ");
          Keyboard.release(KEY_RIGHT_ARROW);
          Keyboard.press(KEY_LEFT_ARROW);
          digitalWrite(left_led, HIGH);
      }
  
    else if(y > THRESHOLD){     
          Serial.print("    Right    ");
          Keyboard.release(KEY_LEFT_ARROW);
          Keyboard.press(KEY_RIGHT_ARROW);
          digitalWrite(right_led, HIGH);
      //Keyboard.press(37);
      }
     else{
          Keyboard.releaseAll();
     }
   }
   
  //Serial.println(y);
  delay(10);
    digitalWrite(left_led, LOW);
    digitalWrite(right_led, LOW);
}
