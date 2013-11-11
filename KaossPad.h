
#ifndef _KAOSS_PAD_
#define _KAOSS_PAD_

#include <portmidi.h>

class KaossPad {
public:
	KaossPad();
	~KaossPad();

	void initialize(const PortMidiStream *_messageStream); 

	void setPosition(uint8_t _x, uint8_t _y);
	void addToX(uint8_t deltaX);
	void addToY(uint8_t deltaY);

	void touch(uint8_t velocity);
	void release(); 
private:
	static const uint8_t PadX = 12;
	static const uint8_t PadY = 13;
	static const uint8_t PadTouch = 92;
	
	uint8_t x, y;
	PortMidiStream *messageStream;
};

#endif