/* 
*	Author: Oscar Dragén
*/

#include "KaossGate.h"
#include "KaossMisc.h"

KaossGate::KaossGate() 
	: isActive(false) {}

KaossGate::~KaossGate() {}

void KaossGate::initialize(PortMidiStream *_messageStream) {
	messageStream = _messageStream;
}

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
	uint32_t msg = Pm_Message(MidiConstants::ControlChange, MidiConstants::GateTime, currentTime);
	Pm_WriteShort(messageStream, 0, msg);
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
	uint32_t msg = Pm_Message(MidiConstants::ControlChange, MidiConstants::GateSpeed, currentSpeed);
	Pm_WriteShort(messageStream, 0, msg);
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
	uint32_t msg = Pm_Message(MidiConstants::ControlChange, MidiConstants::GateArp, value);
	Pm_WriteShort(messageStream, 0, msg);
	isActive = !isActive;
}