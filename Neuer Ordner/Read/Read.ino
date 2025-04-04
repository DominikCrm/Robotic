#include <C:\Users\dominik.cremer\Downloads\Neuer Ordner\Read\Joystick.h>
#include <LiquidCrystal.h>


Joystick joystick(A0, A1, A2);

int relais1pin = 7;
int relais2pin = 10;
int relais3pin = 11;
int relais4pin = 12;

int rechts = 0;
int links = 0;

int maxwert = 10000;
int minwert = -10000;

int richtung = 0;

void setup() {
  Serial.begin(9600);
  pinMode(relais1pin,OUTPUT);
  pinMode(relais2pin,OUTPUT);
  pinMode(relais3pin,OUTPUT);
  pinMode(relais4pin,OUTPUT);
}

void loop() {
  int joyX = joystick.printX("", minwert, maxwert);
  if ((joyX < maxwert/20 && joyX > 0) || (joyX > minwert/20 && joyX < 0)) {
    joyX = 0;
  };
  int joyY = joystick.printY("", minwert, maxwert);
  if ((joyY < maxwert/20 && joyY > 0) || (joyY > minwert/20 && joyY < 0)) {
    joyY = 0;
  };
  Serial.println(joyX);
  if  (joyX > 5000) {
    digitalWrite(relais1pin,HIGH);
    digitalWrite(relais3pin,HIGH);
    digitalWrite(relais2pin,LOW);
    digitalWrite(relais4pin,LOW);
  } else if  (joyX < -5000) {
    digitalWrite(relais1pin,LOW);
    digitalWrite(relais3pin,LOW);
    digitalWrite(relais2pin,HIGH);
    digitalWrite(relais4pin,HIGH);
  } else {
    digitalWrite(relais1pin,LOW);
    digitalWrite(relais2pin,LOW);
    digitalWrite(relais3pin,LOW);
    digitalWrite(relais4pin,LOW);
  };
}
