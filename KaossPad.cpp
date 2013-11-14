
#include "KaossPad.h"

#include "KaossMisc.h"

KaossPad::KaossPad()
	: x(0), y(0)
{
}

KaossPad::~KaossPad() 
{
}

void KaossPad::initialize(PortMidiStream *_messageStream) {
	messageStream = _messageStream;
}

void KaossPad::setPosition(uint8_t _x, uint8_t _y) {
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
	uint32_t msg = Pm_Message(MidiConstants::ControlChange, MidiConstants::PadX, x);
	Pm_WriteShort(messageStream, 0, msg);
}

void KaossPad::sendY() {
	uint32_t msg = Pm_Message(MidiConstants::ControlChange, MidiConstants::PadY, y);
	Pm_WriteShort(messageStream, 0, msg);	
}

void KaossPad::touch(uint8_t velocity) {
	uint32_t msg = Pm_Message(MidiConstants::ControlChange, MidiConstants::PadTouch, velocity);
	Pm_WriteShort(messageStream, 0, msg);
}

void KaossPad::release() {
	uint32_t msg = Pm_Message(MidiConstants::ControlChange, MidiConstants::PadTouch, 0);
	Pm_WriteShort(messageStream, 0, msg);	
}
