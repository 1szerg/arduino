#include <Time.h>
#include <TimeLib.h>

int led1 = 7;
int led2 = 8;
int led3 = 12;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  
  int h = hour();
  if(h < 1){
    blinky(led2, 1000);
  }else{
    if(h < 7){
      blinky(led1, 1000);
    }else{
      blinky(led3, 1000);
    }
  }
  for(int i = 0; i < h; i++){
    blinky(13, 100);
    delay(100);
  }

  delay(1000);
}

void blinky(int led, int interval){
  digitalWrite(led, HIGH);
  delay(interval);
  digitalWrite(led, LOW);
}
