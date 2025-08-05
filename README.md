# Self-Balancing-Robot
Designed and developed a two-wheeled self-balancing robot using a PID controller for stability. Implemented sensor fusion with IMU (Inertial Measurement Unit) for real-time balance adjustments.
# Objective
The aim of this project is to design and develop a self-balancing two-wheeled robot capable
of maintaining its upright position using real-time sensor data and feedback control.
# Materials and Components
• Microcontroller: Arduino Uno
• IMU Sensor: MPU6050 (Accelerometer + Gyroscope)
• Motor Driver: L298N Dual H-Bridge Motor Driver
• Motors: 2x Geared DC Motors (100 RPM, 6V)
• Wheels: 2x Plastic wheels
• Power Supply: 3.7V, 360 mAh Lithium-ion battery
• Chassis: Lightweight thermocol-based material (PET derived, recycled from packag-
ing)
• Miscellaneous: Jumper wires, switch, cardboard base
# System Overview
The robot uses an MPU6050 IMU sensor to measure its tilt angle and angular velocity. An
Arduino Uno reads this data and runs a PID control algorithm to compute corrective signals.
These signals are sent to an L298N motor driver which drives the two motors, keeping the
robot balanced.
# Link of Report
https://drive.google.com/file/d/1_QKeiG6s6SoUNiaWwwseHje50wKWw2GT/view?usp=sharing
