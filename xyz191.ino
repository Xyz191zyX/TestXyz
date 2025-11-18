// Added a new line of comment

#define BLYNK_TEMPLATE_ID "TMPL6CCBlGE1g"
#define BLYNK_TEMPLATE_NAME "191"
#define BLYNK_AUTH_TOKEN "bMz77xeHPNrL5iZNwuIt9oCHDKLyvgqj"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include <Servo.h>
Servo myservo;
Servo myservo1;

int Relay1 = D8;

int PWML = 0;
int LM_1 = D6;
int LM_2 = D1;

int PWMR = 0;
int RM_1 = D2;
int RM_2 = D5;

int servoPin = D3;
int servoPin1 = D7;
int Speed = 255;

char auth[] = "-0xoPHovslMFQ4Qp0qfH7mPjlQqV0VPl";
char ssid[] = "Chaynu";  //ชื่อไวไฟ
char pass[] = "12345678";   //รหัส
void setup() {
  pinMode(Relay1, OUTPUT);
  digitalWrite(Relay1, HIGH);
  Serial.begin(9600);
  myservo.attach(servoPin);
  myservo1.attach(servoPin1);
  myservo.write(60);
  myservo1.write(180);

  pinMode(PWML, OUTPUT);
  pinMode(LM_1, OUTPUT);
  pinMode(LM_2, OUTPUT);
  pinMode(PWMR, OUTPUT);
  pinMode(RM_1, OUTPUT);
  pinMode(RM_2, OUTPUT);

  digitalWrite(LM_1, HIGH);
  digitalWrite(LM_2, HIGH);
  digitalWrite(RM_1, HIGH);
  digitalWrite(RM_2, HIGH);

  
  Blynk.begin(auth, ssid, pass, IPAddress(43, 229, 135, 169), 8080);
  digitalWrite(Relay1, LOW);
}

BLYNK_WRITE(V5) {
  int pinValue = param. asInt();

  if (pinValue == 1) {

  } else if (pinValue == 0) {
  }

  Serial.print("V5 value is: ");  // printing value to serial monitor
  Serial.println(pinValue);
  myservo.write(pinValue);
}


BLYNK_WRITE(V6) {
  int pinValue = param.asInt();

  if (pinValue == 1) {
    myservo1.write(0);
  } else if (pinValue == 0) {
    myservo1.write(180);
  }
}
BLYNK_WRITE(V1) {
  int pinValue = param.asInt();

  if (pinValue == 1) {
    analogWrite(PWML, Speed);
    analogWrite(PWMR, Speed);
    digitalWrite(LM_1, HIGH);
    digitalWrite(LM_2, LOW);
    digitalWrite(RM_1, HIGH);
    digitalWrite(RM_2, LOW);
  } else if (pinValue == 0) {
    analogWrite(PWML, 0);
    analogWrite(PWMR, 0);
    digitalWrite(LM_1, HIGH);
    digitalWrite(LM_2, HIGH);
    digitalWrite(RM_1, HIGH);
    digitalWrite(RM_2, HIGH);
    ;
  }
}

BLYNK_WRITE(V2) {
  int pinValue = param.asInt();

  if (pinValue == 1) {
    analogWrite(PWML, Speed);
    analogWrite(PWMR, Speed);
    digitalWrite(LM_1, LOW);
    digitalWrite(LM_2, HIGH);
    digitalWrite(RM_1, LOW);
    digitalWrite(RM_2, HIGH);
  } else if (pinValue == 0) {
    analogWrite(PWML, 0);
    analogWrite(PWMR, 0);
    digitalWrite(LM_1, HIGH);
    digitalWrite(LM_2, HIGH);
    digitalWrite(RM_1, HIGH);
    digitalWrite(RM_2, HIGH);
  }
}
BLYNK_WRITE(V3) {
  int pinValue = param.asInt();

  if (pinValue == 1) {
    analogWrite(PWML, Speed);
    analogWrite(PWMR, Speed);
    digitalWrite(LM_1, HIGH);
    digitalWrite(LM_2, LOW);
    digitalWrite(RM_1, LOW);
    digitalWrite(RM_2, HIGH);
  } else if (pinValue == 0) {
    analogWrite(PWML, 0);
    analogWrite(PWMR, 0);
    digitalWrite(LM_1, HIGH);
    digitalWrite(LM_2, HIGH);
    digitalWrite(RM_1, HIGH);
    digitalWrite(RM_2, HIGH);
  }
}

BLYNK_WRITE(V4) {
  int pinValue = param.asInt();

  if (pinValue == 1) {
    analogWrite(PWML, Speed);
    analogWrite(PWMR, Speed);
    digitalWrite(LM_1, LOW);
    digitalWrite(LM_2, HIGH);
    digitalWrite(RM_1, HIGH);
    digitalWrite(RM_2, LOW);
  } else if (pinValue == 0) {
    analogWrite(PWML, 0);
    analogWrite(PWMR, 0);
    digitalWrite(LM_1, HIGH);
    digitalWrite(LM_2, HIGH);
    digitalWrite(RM_1, HIGH);
    digitalWrite(RM_2, HIGH);
  }
}
void loop() {
  delay(10);
  Blynk.run();
}
