#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

int motor1Pin1 = 9;
int motor1Pin2 = 10;
int motor2Pin1 = 6;
int motor2Pin2 = 5;

float kp = 20.0;
float ki = 1.0;
float kd = 0.8;

float setPoint = 0;
float error, previous_error = 0;
float integral = 0;
float derivative;
float output;

float angle = 0;
unsigned long lastTime = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  mpu.initialize();

  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  lastTime = millis();
}

void loop() {
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  float acc_angle = atan2(ax, az) * 180 / PI;
  float gyro_rate = gx / 131.0;

  unsigned long currentTime = millis();
  float dt = (currentTime - lastTime) / 1000.0;
  lastTime = currentTime;

  angle = 0.98 * (angle + gyro_rate * dt) + 0.02 * acc_angle;

  if (abs(angle) > 45) {
    stopMotors();
    return;
  }

  error = setPoint - angle;
  integral += error * dt;
  derivative = (error - previous_error) / dt;
  output = kp * error + ki * integral + kd * derivative;
  previous_error = error;

  output = constrain(output, -255, 255);

  if (output > 0) {
    analogWrite(motor1Pin1, output);
    analogWrite(motor1Pin2, 0);
    analogWrite(motor2Pin1, output);
    analogWrite(motor2Pin2, 0);
  } else {
    output = -output;
    analogWrite(motor1Pin1, 0);
    analogWrite(motor1Pin2, output);
    analogWrite(motor2Pin1, 0);
    analogWrite(motor2Pin2, output);
  }

  delay(10);
}

void stopMotors() {
  analogWrite(motor1Pin1, 0);
  analogWrite(motor1Pin2, 0);
  analogWrite(motor2Pin1, 0);
  analogWrite(motor2Pin2, 0);
}
