#include <Servo.h>

Servo myservo;
long timeWait = 7;
unsigned long next_run = 0;

/*when started at 12AM it waits timeWait minutes and then call servo_on() */
void setup() 
{ 
  pinMode(13, OUTPUT);
  servo_run();
  next_run = millis() + 3600000 * timeWait;
  Serial.begin(9600);
  Serial.print("Initial wait = ");
  Serial.println(timeWait);
  Serial.print("Start time :");
  Serial.print(millis());
  Serial.print("  Next run in :");
  Serial.println(next_run);
} 

void loop() {
  if(next_run > millis()){
    Serial.print("Time :");
    Serial.print(millis());
    Serial.print("  Next run in :");
    Serial.println(next_run);
    delay(5000);
    blinky(1000);
  }else{
    Serial.print("----- RUN at ");
    Serial.println(millis());
    servo_run();
    next_run = next_run + (3600000*24);
  }
} 

void servo_run(){
  ledOn();
  myservo.attach(9);
  myservo.write(0);
  delay(1000);
  myservo.write(120);
  delay(1000);
  myservo.detach();
  ledOff();
}

void blinky(int interval){
  ledOn();
  delay(interval);
  ledOff();
}

void ledOn(){
  digitalWrite(13, HIGH);
}

void ledOff(){
  digitalWrite(13, LOW);
}
