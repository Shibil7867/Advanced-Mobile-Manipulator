#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
#define ENA D4
#define IN1 D6
#define IN2 D7
#define IN3 D8
#define IN4 D9
#define ENB D5

bool forward = 0;
bool backward = 0;
bool left = 0;
bool right = 0;
int Speed;
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

char auth[] = "XaFLqNxH62ZuIrlVeXdVpQXVvBUISkFE";  //Paste your Auth Token Here

// Your WiFi credentials.
// Set password to "" for open networks.

char ssid[] = "OnePlus"; //Enter your Wifi User Name
char pass[] = "shibil123"; //Enter your Wifi Password

Servo servo;
Servo servo1;
Servo servo2;
Servo servo3;

BLYNK_WRITE(V7)
{
  servo.write(param.asInt());
}

BLYNK_WRITE(V4)
{
  servo1.write(param.asInt());
}

BLYNK_WRITE(V5)
{
  servo2.write(param.asInt());
}

BLYNK_WRITE(V6)
{
  servo3.write(param.asInt());
}
BLYNK_WRITE(V3) {
  forward = param.asInt();
}

BLYNK_WRITE(V8) {
  backward = param.asInt();
}

BLYNK_WRITE(V1) {
  left = param.asInt();
}

BLYNK_WRITE(V0) {
  right = param.asInt();
}

BLYNK_WRITE(V2) {
  Speed = param.asInt();
}


void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  Blynk.begin(auth, ssid, pass);


  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  servo.attach(D0);
  servo1.attach(D1);
  servo2.attach(D2);
  servo3.attach(D3);
}
void smartcar() {
  if (forward == 1) {
    carforward();
    Serial.println("carforward");
  } else if (backward == 1) {
    carbackward();
    Serial.println("carbackward");
  } else if (left == 1) {
    carturnleft();
    Serial.println("carfleft");
  } else if (right == 1) {
    carturnright();
    Serial.println("carright");
  } else if (forward == 0 && backward == 0 && left == 0 && right == 0) {
    carStop();
    Serial.println("carstop");
  }
}
void loop()
{
  Blynk.run();
  smartcar();
}
void carforward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carbackward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carturnleft() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carturnright() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
