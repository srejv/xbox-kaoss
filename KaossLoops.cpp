
#include "KaossLoops.h"

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