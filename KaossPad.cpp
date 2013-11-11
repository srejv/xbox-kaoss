
#include "KaossPad.h"

KaossPad::KaossPad()
	: x(0), y(0)
{
}

KaossPad::~KaossPad() 
{
}

void KaossPad::initialize(const PortMidiStream *_messageStream) {
	messageStream = _messageStream;
}

void setPosition(uint8_t _x, uint8_t _y) {
	x = _x;
	y = _y;
	sendX(); 
	sendY();
}

void KaossPad::addToX(uint8_t deltaX) {
	x += deltaX;
	sendX();
}

void KaossPad::addToY(uint8_t deltaY) {
	y += deltaY;
	sendY();
}

void KaossPad::sendX() {
	uint8_t msg = Pm_Message(MD_CC, KaossPad::PadX, x);
	Pm_WriteShort(mstream, 0, msg);
}

void KaossPad::sendY() {
	uint8_t msg = Pm_Message(MD_CC, KaossPad::PadY, y);
	Pm_WriteShort(mstream, 0, msg);	
}

void KaossPad::touch(uint8_t velocity) {
	msg = Pm_Message(MD_CC, KaossPad::PadTouch, velocity);
	Pm_WriteShort(mstream, 0, msg);
}

void KaossPad::release() {
	msg = Pm_Message(MD_CC, KaossPad::PadTouch, 0);
	Pm_WriteShort(mstream, 0, msg);	
}
