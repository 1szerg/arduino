#include <Servo.h> 

Servo myservo;
int start=120;
int shift=0;
void setup() 
{ 
  myservo.attach(9);
  myservo.write(start);  // set servo to mid-point
  pinMode(13, OUTPUT);
  delay(1000);
  myservo.detach();
} 

void loop() {
  delay(1000);
    blinky(13,100);
    servo_run();
    delay(2000);
    blinky(13,100);
  } 


  void servo_run(){
    myservo.attach(9);
    myservo.write(shift);
    delay(1000);
    myservo.write(start);
    delay(1000);
    myservo.detach();
  }
  
  void blinky(int led, int interval){
  digitalWrite(led, HIGH);
  delay(interval);
  digitalWrite(led, LOW);
}
