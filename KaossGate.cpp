
#include "KaossGate.h"

KaossGate::KaossGate() 
	: isActive(false) {}

KaossGate::~KaossGate() {}

void KaossGate::setTime(uint8_t _time) {
	currentTime = _time;
	uploadTime();
}

void KaossGate::increaseTime() {
	currentTime += 1;
	uploadTime();
}

void KaossGate::decreaseTime() {
	currentTime -= 1;
	uploadTime();
}

void KaossGate::uploadTime() {
	uint32_t msg = Pm_Message(MD_CC, KaossGate::GateTime, currentTime);
	Pm_WriteShort(mstream, 0, msg);
}


void KaossGate::setSpeed(uint8_t _speed) {
	currentSpeed = _speed;
	uploadSpeed();
}

void KaossGate::increaseSpeed() {
	currentSpeed += 1;
	uploadSpeed();
}

void KaossGate::decreaseSpeed() {
	currentSpeed -= 1;
	uploadSpeed();
}

void KaossGate::uploadSpeed() {
	uint32_t msg = Pm_Message(MD_CC, KaossGate::GateSpeed, currentSpeed);
	Pm_WriteShort(mstream, 0, msg);
}

void KaossGate::activate() {
	if(!isActive) {
		toggle();
	}
}

void KaossGate::deactivate() {
	if(isActive) {
		toggle();
	}
}
void KaossGate::toggle() {
	uint8_t value = isActive ? 0 : 127;
	uint32_t msg = Pm_Message(MD_CC, KaossGate::GateArp, value);
	Pm_WriteShort(messageStream, 0, msg);
	isActive = !isActive;
}