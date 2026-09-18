#include <AFMotor_R4.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

const int iresq = 49;
const int irdir = 50;
const int ircen = 48;
int velo = 200;
int ul = 0;

void frente(){
  int velo = 200;
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void direita(){
  int velo = 255;
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

void esquerda(){
  int velo = 255;
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

void ultimo(){
  if (ul = 2){
    direita();
  } else if (ul = 1){
    esquerda();
  }
}


void setup() {
  Serial.begin(9600);
  pinMode(iresq, INPUT);
  pinMode(irdir, INPUT);
  pinMode(ircen, INPUT);



  motor1.setSpeed(velo);
  motor2.setSpeed(velo);
  motor3.setSpeed(velo);
  motor4.setSpeed(velo);

}

void loop() {
  int esq = digitalRead(iresq);
  int cen = digitalRead(ircen);
  int dir = digitalRead(irdir);
  if (dir == LOW && esq == LOW && cen == HIGH00
    frente();
} else if (esq == LOW && dir == HIGH && cen == LOW) {
  direita();
  ul = 2;
} else if (esq == HIGH && dir == LOW && cen == LOW) {
  esquerda();
  ul = 1;
} else if (esq == LOW && cen == LOW && dir == LOW){
  ultimo();
} else if (esq == HIGH && cen == HIGH && dir == HIGH){
  ultimo();
} else if  (esq == LOW && dir == HIGH && cen == HIGH) {
  direita();
} else if(esq == HIGH && dir == LOW && cen == HIGH) {
  esquerda();
}
}