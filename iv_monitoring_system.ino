/*
 IV Monitoring System using Ultrasonic & LDR
 Author: Your Name
 Platform: Arduino UNO
*/

#define TRIG 9
#define ECHO 10
#define LDR_PIN A0
#define BUZZER 8

float LOW_LEVEL_DISTANCE = 15.0;   // cm
int LDR_THRESHOLD = 400;

unsigned long lastDripTime = 0;
unsigned long dripTimeout = 5000;

float getDistance() {
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    long duration = pulseIn(ECHO, HIGH);
    return duration * 0.034 / 2;
}

void setup() {
    Serial.begin(9600);
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(BUZZER, OUTPUT);

    Serial.println("IV Monitoring System Started");
}

void loop() {
    float distance = getDistance();
    int ldrValue = analogRead(LDR_PIN);

    if (ldrValue < LDR_THRESHOLD) {
        lastDripTime = millis();   // drip detected
    }

    bool ivLow = (distance >= LOW_LEVEL_DISTANCE);
    bool noFlow = (millis() - lastDripTime > dripTimeout);

    if (ivLow || noFlow) {
        digitalWrite(BUZZER, HIGH);
    } else {
        digitalWrite(BUZZER, LOW);
    }

    delay(1000);
}