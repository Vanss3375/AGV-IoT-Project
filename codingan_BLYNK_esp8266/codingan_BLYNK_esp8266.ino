#define BLYNK_TEMPLATE_ID "TMPL6sX86USEw"
#define BLYNK_TEMPLATE_NAME "AGVcontrol wifi"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

int a = 0;

#define m1 D8
#define m2 D7
#define m3 D6
#define m4 D5

#define enA D3
#define enB D4

char auth[] = "ejgdo13y0bvi-a2KB9m_hYlLZ5LUzDqd"; // Replace with your Blynk Auth Token
char ssid[] = "zebe";      // Replace with your WiFi SSID
char pass[] = "zebezevan";  // Replace with your WiFi Password

// Define mode variable
int mode = 0; // 0 = line following, 1 = manual control

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  pinMode(D0, INPUT);
  pinMode(D1, INPUT);
}

// Virtual pin V0 for mode selection
BLYNK_WRITE(V0) {
  mode = param.asInt(); // Get the mode from Blynk app
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}

// Virtual pins for manual control
BLYNK_WRITE(V1) {
  int action = param.asInt(); // Get the action from Blynk app
  if (mode == 1) {
    switch (action) {
      case 1: // Forward
        analogWrite(enA, 120);
        analogWrite(enB, 120);
        digitalWrite(m1, HIGH);
        digitalWrite(m2, LOW);
        digitalWrite(m3, LOW);
        digitalWrite(m4, HIGH);
        break;
      case 2: // Backward
        analogWrite(enA, 120);
        analogWrite(enB, 120);
        digitalWrite(m1, LOW);
        digitalWrite(m2, HIGH);
        digitalWrite(m3, HIGH);
        digitalWrite(m4, LOW);
        break;
      case 3: // Left
        analogWrite(enA, 60);
        analogWrite(enB, 200);
        digitalWrite(m1, LOW);
        digitalWrite(m2, HIGH);
        digitalWrite(m3, LOW);
        digitalWrite(m4, HIGH);
        break;
      case 4: // Right
        analogWrite(enA, 200);
        analogWrite(enB, 60);
        digitalWrite(m1, HIGH);
        digitalWrite(m2, LOW);
        digitalWrite(m3, HIGH);
        digitalWrite(m4, LOW);
        break;
      default:
        // Stop
        analogWrite(enA, 0);
        analogWrite(enB, 0);
        digitalWrite(m1, LOW);
        digitalWrite(m2, LOW);
        digitalWrite(m3, LOW);
        digitalWrite(m4, LOW);
        break;
    }
  }
}

void lineFollowingMode() {
  int lsen = digitalRead(D0);
  int rsen = digitalRead(D1);

  if ((lsen == HIGH) && (rsen == HIGH)) {
    analogWrite(enA, 120);
    analogWrite(enB, 120);

    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
  } else if (lsen == LOW && rsen == HIGH) {
    // Left
    analogWrite(enA, 60);
    analogWrite(enB, 200);

    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
    a = 1;
  } else if (lsen == HIGH && rsen == LOW) {
    // Right
    analogWrite(enA, 200);
    analogWrite(enB, 60);

    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
    a = 2;
  }

  if (lsen == LOW && rsen == LOW) {
    if (a == 1) {
      analogWrite(enA, 60);
      analogWrite(enB, 200);

      digitalWrite(m1, LOW);
      digitalWrite(m2, HIGH);
      digitalWrite(m3, LOW);
      digitalWrite(m4, HIGH);
      a = 0;
    }
    if (a == 2) {
      analogWrite(enA, 200);
      analogWrite(enB, 60);

      digitalWrite(m1, HIGH);
      digitalWrite(m2, LOW);
      digitalWrite(m3, HIGH);
      digitalWrite(m4, LOW);
      a = 0;
    }
  }
}

void manualControlMode() {
  // Manual control is handled by Blynk virtual pin handlers
}

void loop() {
  Blynk.run();

  switch (mode) {
    case 0:
      lineFollowingMode();
      break;
    case 1:
      manualControlMode();
      break;
  }
}
