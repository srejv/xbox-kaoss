
#ifndef __KAOSS_GATE__
#define __KAOSS_GATE__

uint8_t timeTable[] = {
};

uint8_t speedTable[] = {
};

class KaossGate {
public:
	KaossGate();
	~KaossGate();

	void setTime(uint8_t value);
	void increaseTime();
	void decreaseTime();
	void uploadTime();

	void setSpeed(uint8_t value);
	void increaseSpeed();
	void decreaseSpeed();
	void uploadSpeed();

	void activate();
	void deactivate();
	void toggle();
private:
	static uint8_t GateTime = 93;
	static uint8_t GateSpeed = 91;
	static uint8_t GateArp = 90;

	uint8_t currentSpeed;
	uint8_t currentTime;
	bool isActive;

	bool isActive();

	MidiMessageStream *messageStream;
};

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

#endif
