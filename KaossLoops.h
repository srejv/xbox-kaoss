
#ifndef __KAOSS_LOOPS__
#define __KAOSS_LOOPS__

#include "KaossMisc.h"

class KaossLoops
{
public:
	KaossLoops();
	~KaossLoops();

	void initialize(const PortMidiStream *_messageStream);

	void activate(uint8_t loop);
	void deactivate(uint8_t loop);
	void toggle(uint8_t loop);

	static const uint8_t LoopA = 36;
	static const uint8_t LoopB = 37;
	static const uint8_t LoopC = 38;
	static const uint8_t LoopD = 39;

private:
	bool isActive[4];
	PortMidiStream *messageStream;

	int loopToId(Loop loop);
	int loopToNote(Loop loop);
};

KaossLoops::KaossLoops() {
	isActive[0] = false;
	isActive[1] = false;
	isActive[2] = false;
	isActive[3] = false;
}

KaossLoops::~KaossLoops() {
}

KaossLoops::initialize(const PortMidiStream *_messageStream) {
	messageStream = _messageStream
}
KaossLoops::cleanup() {

}

void KaossLoops::activate(Loop loop) {
	int id = loopToId(loop);
	if(!isActive[id]) {
		toggle(loop);
	}
}

void  KaossLoops::deactivate(Loop loop) {
	int id = loopToId(loop);
	if(isActive[id]) {
		toggle(loop);
	}
}

void KaossLoops::toggle(Loop loop) {
	uint32_t msg = Pm_Message(MD_NOTEON, loopToNote(loop), 127);
	Pm_WriteShort(messageStream, 0, msg);
	isActive[id] = !isActive[id];
}

int KaossLoops::loopToId(Loop loop) {
	return loop - 35;
}

int KaossLoops::loopToNote(Loop loop) {
	return loop;
}

#endif