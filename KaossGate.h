
#ifndef __KAOSS_GATE__
#define __KAOSS_GATE__

#include <portmidi.h>

/*uint8_t timeTable[] = {
};

uint8_t speedTable[] = {
};*/

class KaossGate {
public:
	KaossGate();
	~KaossGate();

	void initialize(PortMidiStream *_messageStream);

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
	uint8_t currentSpeed;
	uint8_t currentTime;
	bool isActive;

	PortMidiStream *messageStream;
};

#endif
