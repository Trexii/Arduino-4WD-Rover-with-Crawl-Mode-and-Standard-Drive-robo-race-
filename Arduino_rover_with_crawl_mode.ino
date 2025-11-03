#include <AFMotor.h>

// Define motors (1 & 2 = Left side, 3 & 4 = Right side)
AF_DCMotor motor1(1, MOTOR12_8KHZ);
AF_DCMotor motor2(2, MOTOR12_8KHZ);
AF_DCMotor motor3(3, MOTOR34_8KHZ);
AF_DCMotor motor4(4, MOTOR34_8KHZ);

char command;
int currentSpeed = 200;
bool preciseMode = false;

void setup() {
  Serial.begin(9600);
  setSpeed(currentSpeed);
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();

    switch (command) {
      case 'F': forward(); break;
      case 'B': back(); break;
      case 'L': left(); break;
      case 'R': right(); break;
      case 'S': Stop(); break;

      // Speed presets
      case '1': setSpeed(200); break;
      case '2': setSpeed(10); break;
      case '3': setSpeed(50); break;
      case '4': setSpeed(75); break;
      case '5': setSpeed(100); break;
      case '6': setSpeed(125); break;
      case '7': setSpeed(150); break;
      case '8': setSpeed(175); break;
      case '9': setSpeed(200); break;
      case 'q': setSpeed(255); break;

      // Toggle precise turn mode
      case 'X':
      case 'x':
        preciseMode = !preciseMode;
        Serial.print("Precise mode: ");
        Serial.println(preciseMode ? "ON" : "OFF");
        break;
    }
  }
}

void forward() {
  setAllSpeeds(currentSpeed);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void back() {
  setAllSpeeds(currentSpeed);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void left() {
  if (preciseMode) {
    setAllSpeeds(180); // slower precise turning
    motor1.run(BACKWARD);  // right side only
    motor2.run(BACKWARD);
    motor3.run(RELEASE);  // left side off
    motor4.run(RELEASE);
  } else {
    setAllSpeeds(currentSpeed);
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }
}

void right() {
  if (preciseMode) {
    setAllSpeeds(180); // slower precise turning
    motor3.run(BACKWARD);  // left side only
    motor4.run(BACKWARD);
    motor1.run(RELEASE);  // right side off
    motor2.run(RELEASE);
  } else {
    setAllSpeeds(currentSpeed);
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
  }
}

void Stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void setSpeed(int spd) {
  currentSpeed = spd;
  setAllSpeeds(currentSpeed);
}

void setAllSpeeds(int spd) {
  motor1.setSpeed(spd);
  motor2.setSpeed(spd);
  motor3.setSpeed(spd);
  motor4.setSpeed(spd);
}
