#include <Servo.h>

/*
Runs servo with 24h delay.
Used to start heating before wake up.
When started, initialises servo (use for servo test) 
and starts waiting for timeWait hours.
To reschedule, use setup - long press button until constant led,
rescedule by clicks - one click is one hour (blinks to confirm each click).
When successfuly resceduled, blinks new hours after 15 seconds.
After scheduled run, runs servo each 24 hours.  
*/

Servo myservo;
long timeWait = 5; // initial wait time in hours
unsigned long next_run = 0; // keeps time of next run in millis
unsigned long inputTimer = 0; // keeps input timeout
int ledPin = 13; // indicator led pin
int servoPin = 9; // servo drive pin
int buttonPin = 8; // setup button pin

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(buttonPin, INPUT);
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
  processSetup();
  processMain();
}

void processSetup(){
  boolean setupPressed = false;
  int newWait = 0;
  if(digitalRead(buttonPin) == HIGH){
    inputTimer = millis() + 15000;
    setupPressed = true;
    ledOn();
    Serial.println("Entering setup");
  }else{
    return;
  }
  while(inputTimer > millis()){
    if(setupPressed){
      if(digitalRead(buttonPin) == LOW){
        setupPressed = false;
      }
    }else{
      if(digitalRead(buttonPin) == HIGH){
        ledOff();
        setupPressed = true;
        newWait++;
        inputTimer = millis() + 15000;
        delay(100);
        Serial.print("Setup :");
        Serial.println(newWait);
        ledOff();
      }
    }
  }
  if(newWait > 0){
    next_run = millis() + 3600000 * newWait;
    for(int i = 0; i < newWait; i++){
      blinky(500);
      delay(500);
    }
  }
  ledOff();
}

void processMain(){
  if (next_run > millis()) {
    Serial.print("Time :");
    Serial.print(millis());
    Serial.print("  Next run in :");
    Serial.println(next_run);
    delay(5000);
    blinky(1000);
  } else {
    Serial.print("----- RUN at ");
    Serial.println(millis());
    servo_run();
    next_run = next_run + (3600000 * 24);
  }
}

void servo_run() {
  ledOn();
  myservo.attach(servoPin);
  myservo.write(0);
  delay(1000);
  myservo.write(120);
  delay(1000);
  myservo.detach();
  ledOff();
}

void blinky(int interval) {
  ledOn();
  delay(interval);
  ledOff();
}

void ledOn() {
  digitalWrite(ledPin, HIGH);
}

void ledOff() {
  digitalWrite(ledPin, LOW);
}
