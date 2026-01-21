
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

Servo myServo;

// LCD setup (I2C address 0x27, 16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Servo sweep limits
const int center = 90;
const int leftLimit = 45;
const int rightLimit = 135;

// Ultrasonic pins
const int trigPin = 9;
const int echoPin = 10;

// Buzzer and button pins
const int buzzerPin = 7;
const int buttonPin = 8;

// Variables
long duration;
int distance;
bool targetDetected = false;

// Setup
void setup() {
  myServo.attach(6);        
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // using internal pull-up
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.clear();
}

// Function to read ultrasonic distance
int readUltrasonic() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000); // 30ms timeout
  if (duration == 0) return -1;             // no echo

  int cm = duration * 0.034 / 2;

  if (cm > 20) return -1;                   // limit to 20 cm

  return cm;
}

// Function to beep short (fast)
void beepShort() {
  tone(buzzerPin, 1000);
  delay(100);
  noTone(buzzerPin);
}

// Function to beep medium
void beepMedium() {
  tone(buzzerPin, 1000);
  delay(300);
  noTone(buzzerPin);
}

// Function to beep long (for launching)
void beepLong() {
  tone(buzzerPin, 1000);
  delay(700);
  noTone(buzzerPin);
}

void loop() {

  // Sweep right: center → rightLimit
  for (int angle = center; angle <= rightLimit; angle++) {
    myServo.write(angle);
    distance = readUltrasonic();

    if (distance != -1) {  // target detected
      targetDetected = true;
      Serial.print("Angle: ");
      Serial.print(angle);
      Serial.print("  Distance: ");
      Serial.print(distance);
      Serial.println(" cm");

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Target Detected");
      lcd.setCursor(0,1);
      lcd.print("Dist: ");
      lcd.print(distance);
      lcd.print(" cm");

      beepMedium(); // beep when target detected
    } else {
      targetDetected = false;
      lcd.clear();
    }

    // Check button press for launching
    if (targetDetected && digitalRead(buttonPin) == LOW) { // pressed
      beepLong(); // long beep
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Launching!");
      delay(1000); // show message
      lcd.clear();
    }

    delay(50); // servo speed
  }

  delay(200);

  // Sweep left: rightLimit → leftLimit
  for (int angle = rightLimit; angle >= leftLimit; angle--) {
    myServo.write(angle);
    distance = readUltrasonic();

    if (distance != -1) {
      targetDetected = true;
      Serial.print("Angle: ");
      Serial.print(angle);
      Serial.print("  Distance: ");
      Serial.print(distance);
      Serial.println(" cm");

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Target Detected");
      lcd.setCursor(0,1);
      lcd.print("Dist: ");
      lcd.print(distance);
      lcd.print(" cm");

      beepMedium();
    } else {
      targetDetected = false;
      lcd.clear();
    }

    if (targetDetected && digitalRead(buttonPin) == LOW) {
      beepLong();
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Launching!");
      delay(1000);
      lcd.clear();
    }

    delay(50);
  }

  delay(200);

  // Sweep leftLimit → center
  for (int angle = leftLimit; angle <= center; angle++) {
    myServo.write(angle);
    distance = readUltrasonic();

    if (distance != -1) {
      targetDetected = true;
      Serial.print("Angle: ");
      Serial.print(angle);
      Serial.print("  Distance: ");
      Serial.print(distance);
      Serial.println(" cm");

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Target Detected");
      lcd.setCursor(0,1);
      lcd.print("Dist: ");
      lcd.print(distance);
      lcd.print(" cm");

      beepMedium();
    } else {
      targetDetected = false;
      lcd.clear();
    }

    if (targetDetected && digitalRead(buttonPin) == LOW) {
      beepLong();
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Launching!");
      delay(1000);
      lcd.clear();
    }

    delay(50);
  }

  delay(200);
}
