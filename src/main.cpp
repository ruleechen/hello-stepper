#include <Arduino.h>
#include <AccelStepper.h>

AccelStepper myStepper(AccelStepper::FULL4WIRE, D1, D5, D2, D6);

void setup() {
  Serial.begin(115200);

  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);

	myStepper.setMaxSpeed(512);
	myStepper.setAcceleration(32);
	myStepper.setSpeed(256);
	myStepper.moveTo(1024);

  Serial.println("setup complete");
}

void loop() {
	// Change direction once the motor reaches target position
	if (myStepper.distanceToGo() == 0) {
		myStepper.moveTo(-myStepper.currentPosition());
    Serial.println("turn back");
  }

	// Move the motor one step
	myStepper.run();
}
