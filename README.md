# IV Monitoring System using Ultrasonic and LDR

##Overview
This project monitors IV fluid level and drip flow using an ultrasonic sensor and an LDR sensor.  
Alerts are generated when the IV bottle is nearly empty or when fluid flow stops.

##Components Used
- Arduino UNO
- Ultrasonic Sensor (HC-SR04)
- LDR + 10kΩ resistor
- Buzzer
- IV stand & drip chamber

##Working Principle
- Ultrasonic sensor measures remaining fluid level
- LDR detects drip flow interruptions
- Buzzer alerts nursing staff during abnormal conditions

##Alert Conditions
- IV fluid level low
- No drip detected for more than 5 seconds

##Code
Source code is located in `Arduino_Code/iv_monitoring.ino`

##Applications
- Hospitals
- ICU monitoring
- Medical IoT projects

##License
This project is licensed under the MIT License