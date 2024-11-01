/* Creates a Software Serial port (not using pins 0, 1) using the SoftwareSerial library */
#include <SoftwareSerial.h> 
SoftwareSerial mySerial(8, 9); // RX, TX

/* Defines motor control pins */
const int motorA1 = 3;  // Motor A Pin 1
const int motorA2 = 2;  // Motor A Pin 2
const int motorB1 = 4;  // Motor B Pin 1
const int motorB2 = 7;  // Motor B Pin 2

const int A_EN = 5;     // Enable Pin for Motor A
const int B_EN = 6;     // Enable Pin for Motor B

/* Defines variables used below */
int vSpeed = 200; // Base speed of the car (default is 200, max is 255)
char state;        // Variable to store received Bluetooth character

void setup() {
  /* Sets these motor-pins as output pins */
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(A_EN, OUTPUT);
  pinMode(B_EN, OUTPUT);

  /* Sets communication speed between Bluetooth and Arduino Uno to 9600 baud */
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  /* Reads Bluetooth signal if available and stores it in the 'state' variable (char) */
  if (mySerial.available() > 0) {
    state = mySerial.read();
    Serial.println(state);
  }

  /* Checks if the 'state' character is a speed command and sets it to the vSpeed variable */
  if (state == '0') vSpeed = 0;
  else if (state == '4') vSpeed = 100;
  else if (state == '6') vSpeed = 155;
  else if (state == '7') vSpeed = 180;
  else if (state == '8') vSpeed = 200;
  else if (state == '9') vSpeed = 230;
  else if (state == 'q') vSpeed = 255;


  /* Checks if the 'state' character is a movement command and controls the motors accordingly */
  // Forward
  if (state == 'F') {
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);

    analogWrite(A_EN, vSpeed);
    analogWrite(B_EN, vSpeed);
  }

  // Forward Left
  else if (state == 'G') {
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);

    analogWrite(A_EN, vSpeed);
    analogWrite(B_EN, 100);
  }

  // Forward Right
  else if (state == 'I') {
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);

    analogWrite(A_EN, 100);
    analogWrite(B_EN, vSpeed);
  }

  // Backward
  else if (state == 'B') {
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH);

    analogWrite(A_EN, vSpeed);
    analogWrite(B_EN, vSpeed);
  }

  // Backward Left
  else if (state == 'H') {
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH);

    analogWrite(A_EN, vSpeed);
    analogWrite(B_EN, 100);
  }

  // Backward Right
  else if (state == 'J') {  
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH);

    analogWrite(A_EN, 100);
    analogWrite(B_EN, vSpeed);
  }

  // Left
  else if (state == 'L') {   
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH);

    analogWrite(A_EN, vSpeed);
    analogWrite(B_EN, vSpeed);
  }

  // Right
  else if (state == 'R') {   
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);

    analogWrite(A_EN, vSpeed);
    analogWrite(B_EN, vSpeed);
  }

  // Stop
  else if (state == 'S') {   
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, LOW);

    analogWrite(A_EN, vSpeed);
    analogWrite(B_EN, vSpeed);
  }
}
