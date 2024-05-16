TB612FNG::TB612FNG(int PWMA, int PWMB, int AIN1, int AIN2, int BIN1, int BIN2, int STBY) {
  this->STBY = STBY;
  this->PWMA = PWMA;
  this->PWMB = PWMA;
  this->AIN1 = AIN1;
  this->AIN2 = AIN2;
  this->BIN1 = BIN1;
  this->BIN2 = BIN2;

  pinMode(STBY, OUTPUT);
  
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
}

void run(int motor, int speed) {
  //Move specific motor at speed and direction
  //motor: 0 for B 1 for A
  //speed: 0 is off, and 255 is full speed

  digitalWrite(STBY, HIGH); //disable standby

  // set direction based on speed 
  if (speed > 0) {
    boolean inPin1 = HIGH;
    boolean inPin2 = LOW;
  } else if (speed < 0) {
    boolean inPin1 = LOW;
    boolean inPin2 = HIGH;
  } else {
    this->stop;
  }

  // set speed based on motor
  if(motor == 1){
    digitalWrite(AIN1, inPin1);
    digitalWrite(AIN2, inPin2);
    analogWrite(PWMA, speed);
  } else if (motor == 2) {
    digitalWrite(BIN1, inPin1);
    digitalWrite(BIN2, inPin2);
    analogWrite(PWMB, speed);
  }
}

void stop(int motor) {
  if (motor == 1) {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);    
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
  } else if (motor == 2) {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
  }
}


// stop both motors connected to controller
void standby(){
  digitalWrite(STBY, LOW); 
}