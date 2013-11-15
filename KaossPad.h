/* 
*	Author: Oscar Dragén
*/

#ifndef __KAOSS_PAD__
#define __KAOSS_PAD__

#include <portmidi.h>

class KaossPad {
public:
	KaossPad();
	~KaossPad();

	void initialize(PortMidiStream *_messageStream); 

	void setPosition(uint8_t _x, uint8_t _y);
	void addToX(uint8_t deltaX);
	void addToY(uint8_t deltaY);

	void touch(uint8_t velocity);
	void release(); 
private:
	void sendX();
	void sendY();

	uint8_t x, y;
	PortMidiStream *messageStream;
};

#endif