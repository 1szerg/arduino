int led1 = 7;
int led2 = 8;
int led3 = 12;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  long i = random(30);
  if(i < 10){
    blinky(led1, 100);
  }else{
    if(i < 20 ){
      blinky(led2, 100);
    }else{
       blinky(led3, 100);
    }
  }

}

void blinky(int led, int interval){
  digitalWrite(led, HIGH);
  delay(interval);
  digitalWrite(led, LOW);
}
