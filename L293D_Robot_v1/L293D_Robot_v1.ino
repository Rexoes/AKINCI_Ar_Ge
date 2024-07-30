#include <AFMotor.h>

AF_DCMotor solOn(4);
AF_DCMotor sagOn(3);
AF_DCMotor sagArka(2);
AF_DCMotor solArka(1);


void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  solOn.setSpeed(200);
  sagOn.setSpeed(200);
  sagArka.setSpeed(200);
  solArka.setSpeed(200);
 
  solOn.run(RELEASE);
  sagOn.run(RELEASE);
  sagArka.run(RELEASE);
  solArka.run(RELEASE);
}

void loop() {
  ILERI(4000);
  DUR(500);
  
  SAG(500);
  DUR(500);
  
  ILERI(3000);
  DUR(500);
  
  SOL(500);
  DUR(500);
  
  ILERI(2000);
  DUR(500);
  
  GERI(1500);
  DUR(8000);
}

void SOL(int beklemeSuresi){
  sagOn.run(FORWARD);
  sagArka.run(FORWARD);
  solOn.run(BACKWARD);
  solArka.run(BACKWARD);
  delay(beklemeSuresi);
}

void SAG(int beklemeSuresi){
  sagOn.run(BACKWARD);
  sagArka.run(BACKWARD);
  solOn.run(FORWARD);
  solArka.run(FORWARD);
  delay(beklemeSuresi);
}

void DUR(int beklemeSuresi){
  solOn.run(RELEASE);
  sagOn.run(RELEASE);
  sagArka.run(RELEASE);
  solArka.run(RELEASE);
  delay(beklemeSuresi);
}

void ILERI(int beklemeSuresi){
  solOn.run(FORWARD);
  sagOn.run(FORWARD);
  sagArka.run(FORWARD);
  solArka.run(FORWARD);
  delay(beklemeSuresi);
}

void GERI(int beklemeSuresi){
  solOn.run(BACKWARD);
  sagOn.run(BACKWARD);
  sagArka.run(BACKWARD);
  solArka.run(BACKWARD);
  delay(beklemeSuresi);
}
